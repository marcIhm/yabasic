/*
Install-Program for yabasic
written by Marc Ihm in 1996.

  Date of last change:
*/
#define DOLC                     "November 5, 2016"
/*

This file is part of yabasic and may be copied under the terms of
MIT License which can be found in the file LICENSE.

See www.yabasic.de for details.

*/

/*----------- includes -------------*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <shlobj.h>
#include <shellapi.h>
#include <commctrl.h>
#include <ole2.h>
#include "resource.h"


/*------------ defines -------------------*/

/* names and symbols for basic */
#define BASIC_NAME "Yabasic"
#define BASIC_DOKU "Yabasic"
#define BASIC_EXE "yabasic.exe"
#define BASIC_EXTENSION ".yab"
#define BASIC_VERFILE "yabver.txt"
#define BASIC_ICON "yabico.ico"
#define BASIC_DEMOPROG "demo"
#define BASIC_README "readme.txt"
#define BASIC_SETUP "setup.exe"
#define BASIC_LOG "yabasic.log"

/* headings for messageboxes */
#define INSTALL_HEADING " Install yabasic !"
#define REMOVE_HEADING " Remove yabasic !"

/* basic-defaults */
#define DEFAULTPATH "c:\\yabasic\\"
#define DEFAULTFONT "swiss13"
#define DEFAULTBACKGROUND "255,255,255"
#define DEFAULTFOREGROUND "0,0,0"
#define DEFAULTGEOMETRY "+10+10"

/* shortcuts for end-message */
#define INSTALL_CANCELLED 1
#define INSTALL_IMPOSSIBLE 2
#define INSTALL_ABORTED 3
#define INSTALL_SUCCESS 4
#define INSTALL_FAILURE 5
#define REMOVE_SUCCESS 6
#define REMOVE_FAILURE 7
#define REMOVE_CANCELLED 8
#define SILENT 9

/* shortcuts for registry */
#define ROOT HKEY_CLASSES_ROOT
#define LOCAL HKEY_LOCAL_MACHINE
#define SOFT "SOFTWARE\\"
#define UNINSTALL "SOFTWARE\\MICROSOFT\\WINDOWS\\CURRENTVERSION\\UNINSTALL\\"

/* operationmodes for My...() functions */
#define INSTALL 1
#define REMOVE 2

/* defines for files() */
#define RESET 1
#define NEXT 2

/* shortcut for standard Message Box Style */
#define MB_STYLE MB_OK|MB_SYSTEMMODAL|MB_ICONINFORMATION

/* standard string length */
#define SSLEN 2000

#if !defined(TRUE)
#define TRUE (1==1)
#endif

#ifndef FALSE
#define FALSE (1!=1)
#endif

/* avoid warning */
#define strdup _strdup

/*------------ global types -----------------------*/

typedef struct linkinfo {
	int folder; /* registry key */
	char *link; /* name of link */
	char *file; /* name of file */
	char *desc; /* description of link */
	char *icon; /* name of icon for link */
	int removeonly; /* true, if icon should be removed but not installed */
} LINKINFO;

typedef struct semver {
	int major;
	int minor;
	int patch;
} SEMVER;

/*------------ global variables -------------------*/

char *currentpath;       /* current path */
char *installpath;       /* path, where to install */
char *librarypath;       /* path, where libraries should be installed */
char *temppath;          /* path to store temporary files */
char logs[10000];        /* string to compose log-message */
char logpath[1000] = "undefined";      /* string containing pathname of logfile */
int here;                /* install in current path ? */
int install;             /* install or remove ? */
int copied;              /* true if copy in temp-directory */

int total_progress;      /* number of steps to advance progress counter */

HINSTANCE this_instance; /* instance */

SEMVER newversion;        /* version to be installed */

/*------------ prototypes -------------------*/

/* My...() functions */
int MyLinks(int); /* add or remove shell links */
int MyFiles(int); /* copy or delete files */
int MyRegs(int); /* add or delete entries to or from registry */

/* dialog callbacks */
BOOL CALLBACK pathdialog(HWND, UINT, WPARAM, LPARAM);/* choose installpath */
BOOL CALLBACK progressdialog(HWND, UINT, WPARAM, LPARAM);/* show progress */
UINT CALLBACK HookProc(HWND, UINT, WPARAM, LPARAM); /* hook for save as */

/* registry manipulation */
int delreg(HKEY, char *, char *); /* delete keys from Registry */
char *getreg(char *); /* get keys from Registry */
int putreg(HKEY, char *, char *, char *); /* put keys into Registry */

/* shell link functions */
/* Create link: */
HRESULT CreateShellLink(LINKINFO *, char *);
/* delete a shell link */
HRESULT DeleteShellLink(LINKINFO *);

/* functions dealing with progress bar */
void progress(char *); /* show progress */

/* for handling semantic versions */
int parsesemver(char *, SEMVER *); /* parse semantiv version contained in string */
int comparesemver(SEMVER *, SEMVER *); /* compare two semantic version numbers */
char *formatsemver(SEMVER *,char *); /* return string with formatted version number */

/* miscellanous functions */
void end(int); /* display message and terminate */
char *app(char *trail); /* append trail to installpath */
int Copy(char *, char *, int); /* copy files */
char *brushup(char *); /* change to upper case, add slash */
char *enumfiles(int); /* give filenames, one after another */
LINKINFO *enumlinks(int); /* give back links, one after the other */
void logit(char *); /* write text to logfile */
int MyMessage(HWND, LPCSTR, LPCSTR, UINT); /* wrapper for MessageBox() */
char *reportdir(char *); /* generate a string containing filenames in directory */

/*------------ main program --------------*/

int WINAPI WinMain(HINSTANCE _this_instance,
	HINSTANCE prev_instance,
	LPSTR commandline,
	int win_state)
{
	SEMVER oldversion;    /* version already installed */
	FILE *verfile;       /* file with version */
	int cancel;          /* return value of dialog */
	int success;         /* return value of My..() functions */
	char string[SSLEN];  /* multi-purpose string */
	char string2[SSLEN]; /* multi-purpose string */
	char string3[SSLEN]; /* multi-purpose string */
	char errmsg[SSLEN];  /* for error messages */
	char *full;
	int i;


	/* copy intance information to global variable */
	this_instance = _this_instance;

	/* get path for temporary files */
	GetTempPath(SSLEN, string);
	GetLongPathName(string, string, SSLEN);
	temppath = brushup(string);

	/* write to log */
	sprintf(logs, "--Temppath: '%s'\n", temppath);
	logit(logs);

	sprintf(logs, "--Commandline='%s'\n", commandline);
	logit(logs);

	/* 'parse' commandline */
	install = TRUE;
	copied = FALSE;
	if (!strcmp(commandline, "remove")) {
		install = FALSE;
	}
	else if (!strncmp(commandline, "copied", 6)) {
		install = FALSE;
		copied = TRUE;
	}
	full = GetCommandLine();
	if (*full == '\"') full++;
	for (i = strlen(full); i >= 0; i--) if (full[i] == '/' || full[i] == '\\') break;
	strncpy(string, full, i);
	string[i] = '\0';
	currentpath = brushup(string);

	/* write to log */
	sprintf(logs, "--Currentpath: '%s'\n", currentpath);
	logit(logs);

	if (install) {   /* install yabasic */
		char *ver;     /* string containing installed version */
		HANDLE dir;    /* handle for current working direcotry */
		WIN32_FIND_DATA  fileinfo; /* information about a single file */
		char dirglob[SSLEN];

		/* set advance for progresscount */
		total_progress = 28;

		/* write contents of current directory to logfile */
		sprintf(dirglob, "%s*.*", currentpath);
		dir = FindFirstFile(dirglob, &fileinfo);
		if (dir == INVALID_HANDLE_VALUE) {
			sprintf(logs, "--Could not read content of '%s': %s\n", currentpath, strerror(errno));
			logit(logs);
		}
		else {
			sprintf(logs, "--Content of directory '%s':\n", currentpath);
			logit(logs);
			sprintf(logs, "   %s\n", fileinfo.cFileName);
			logit(logs);
			while (FindNextFile(dir, &fileinfo)) {
				sprintf(logs, "   %s\n", fileinfo.cFileName);
				logit(logs);
			}
			logit("--end of list\n");
			FindClose(dir);
		}

		/* get and check versions ... */

		/* get new version from file */
		sprintf(string, "%s%s", currentpath, BASIC_VERFILE);
		verfile = fopen(string, "r");
		if (!verfile) {
			sprintf(errmsg, "Could not open version number file\n\n   %s\n\nReason: %s", string, strerror(errno));
			MyMessage(NULL, errmsg, INSTALL_HEADING, MB_STYLE);
			end(INSTALL_IMPOSSIBLE);
		}
		else if (!fscanf(verfile, "%s", string2)) {
			sprintf(errmsg, "Could not read version number from file '%s': %s", string, strerror(errno));
			MyMessage(NULL, errmsg, INSTALL_HEADING, MB_STYLE);
			end(INSTALL_IMPOSSIBLE);
		}
		else if (!parsesemver(string2, &newversion)) {
			sprintf(errmsg, "Could not parse version number '%s' as read from file '%s': %s", string2, string, strerror(errno));
			MyMessage(NULL, errmsg, INSTALL_HEADING, MB_STYLE);
			end(INSTALL_IMPOSSIBLE);
		}
		else {
			sprintf(logs, "--New version: %s\n", formatsemver(&newversion,string));
			logit(logs);
		}
		if (verfile) fclose(verfile);

		/* get old version */
		ver = getreg("version");
		oldversion.major = 0;
		oldversion.minor = 0;
		oldversion.patch = 0;
		if (ver) parsesemver(ver, &oldversion);

		/* get confirmation */
		sprintf(string, "This will install\n\n       Yabasic, Version %s\n\nDo you want to proceed ?", formatsemver(&newversion,string2));
		if (MyMessage(NULL, string, INSTALL_HEADING,
			MB_YESNO | MB_ICONQUESTION | MB_SYSTEMMODAL) == IDNO)
			end(INSTALL_CANCELLED);

		/* check versions */
		if (comparesemver(&oldversion, &newversion)>0) {
			sprintf(string, "A newer Version of "BASIC_NAME
				" has already been installed:\n"
				"  \talready installed: \t%s\n"
				"  \tto be installed: \t%s\n"
				"Shall the installation proceed, superseeding the\n"
				"existing version ?", formatsemver(&oldversion,string2), formatsemver(&newversion,string3));
			if (MyMessage(NULL, string, INSTALL_HEADING,
				MB_YESNO | MB_ICONQUESTION | MB_SYSTEMMODAL) == IDNO)
				end(INSTALL_CANCELLED);
		}

		/* get path */
		installpath = getreg("path");
		if (!installpath) installpath = DEFAULTPATH;
		cancel = !DialogBox((HANDLE)this_instance,
			MAKEINTRESOURCE(IDD_PATHDIALOG),
			(HWND)NULL, (DLGPROC)pathdialog);
		if (cancel) end(INSTALL_CANCELLED);
		installpath = brushup(installpath);
		here = !strcmp(currentpath, installpath);

		/* get library path */
		librarypath = malloc(strlen(installpath) + 10);
		strcpy(librarypath, installpath);
		brushup(librarypath);
		strcat(librarypath, "lib\\");

		/* write to log */
		sprintf(logs, "--Installpath: '%s'\n", installpath);
		logit(logs);

		/* check for disk-space */
		{
			DWORD spc, bps, frcl, tncl;
			float total;
			int answer;

			sprintf(string, "%c:\\", *installpath);
			GetDiskFreeSpace(string, &spc, &bps, &frcl, &tncl);
			total = (float)frcl*spc*bps / (1024 * 1024);
			if (total < 1024) {
				sprintf(string, "Free disk space is only %g MB!\n"
					"Proceed anyway ?", total);
				answer = MyMessage(NULL, string, INSTALL_HEADING,
					MB_YESNO | MB_SYSTEMMODAL | MB_ICONINFORMATION);
				if (answer == IDNO) end(INSTALL_CANCELLED);
			}
		}
		/* make entry in the registry */
		success = MyRegs(INSTALL);
		if (!success) {
			MyMessage(NULL, "Failed to make entries in the Registry !",
				INSTALL_HEADING, MB_STYLE);
			end(INSTALL_FAILURE);
		}

		/* create shell links */
		success = MyLinks(INSTALL);
		if (!success) {
			MyMessage(NULL, "Failed to add entry to the start-Menu !",
				INSTALL_HEADING, MB_STYLE);
			end(INSTALL_FAILURE);
		}

		/* create directories */
		progress("Creating directories.");
		CreateDirectory(installpath, NULL);
		CreateDirectory(librarypath, NULL);

		/* copy files */
		progress("Copying files.");
		success = MyFiles(INSTALL);
		if (!success) {
			MyMessage(NULL, "Couldn't copy files !",
				INSTALL_HEADING, MB_STYLE);
			end(INSTALL_FAILURE);
		}

		/* installation successfull ! */
		end(INSTALL_SUCCESS);
	}
	else {  /* remove yabasic */
		HANDLE from;
		DWORD pid;
		STARTUPINFO start;
		PROCESS_INFORMATION proc;

		if (!copied)
			if (MyMessage(NULL, "Really remove yabasic ?", REMOVE_HEADING,
				MB_YESNO | MB_ICONQUESTION | MB_SYSTEMMODAL) == IDNO)
				end(REMOVE_CANCELLED);

		/* get installpath */
		installpath = getreg("path");
		installpath = brushup(installpath);
		librarypath = malloc(strlen(installpath) + 10);
		strcpy(librarypath, installpath);
		brushup(librarypath);
		strcat(librarypath, "lib\\");
		if (installpath == NULL) {
			MyMessage(NULL, "Could not find installation path !",
				REMOVE_HEADING, MB_STYLE);
			end(REMOVE_FAILURE);
		}

		/* write to log */
		sprintf(logs, "--Installpath: '%s'\n", installpath);
		logit(logs);

		/* set advance for progresscount */
		total_progress = 9;

		here = !strcmp(currentpath, installpath);

		/* remove files */
		if (!copied) {
			char to[SSLEN];
			char *from;
			char string[SSLEN]; /* multi purpose string */

			GetTempPath(SSLEN, to);
			strcat(to, BASIC_SETUP);
			from = app(BASIC_SETUP);
			CopyFile(from, to, FALSE);

			/* change registry, to point to new location */
			sprintf(string, "%s %s", to, "remove");
			putreg(LOCAL, UNINSTALL BASIC_NAME, "UninstallString", string);

			/* remove library directory */
			success = RemoveDirectory(librarypath);
			if (!success) {
				char *contents;

				contents = reportdir(librarypath);
				if (!contents) {
					sprintf(string, "Could not remove library directory '%s' !\n"
						"You may check its contents, remove it by hand and try again.", librarypath);
					MyMessage(NULL, string, REMOVE_HEADING, MB_STYLE);
					end(REMOVE_FAILURE);
				}
				else {
					sprintf(string, "Could not remove library directory '%s'.\n"
						"These libraries have been found:\n\n%s\n"
						"You may remove these files by hand and try again !\n"
						, librarypath, contents);
					MyMessage(NULL, string, REMOVE_HEADING, MB_STYLE);
					end(REMOVE_FAILURE);
				}
			}

			/* remove other files */
			MyFiles(REMOVE);

			GetStartupInfo(&start);

			pid = GetCurrentProcessId();
			sprintf(string, "%s copied %d", to, pid);
			if (!CreateProcess(NULL, string, NULL, NULL, TRUE, NORMAL_PRIORITY_CLASS,
				NULL, NULL, &start, &proc)) {
				MyMessage(NULL, "Couldn't hand over", REMOVE_HEADING, MB_STYLE);
				end(REMOVE_FAILURE);
			}
			end(SILENT);
		}

		/* from now on: copied */

		/* get process id */
		sscanf(commandline, "copied %d", &pid);
		from = OpenProcess(PROCESS_QUERY_INFORMATION | SYNCHRONIZE, FALSE, pid);
		if (from && WaitForSingleObject(from, 10000) == WAIT_TIMEOUT) {
			MyMessage(NULL, "Couldn't take over", REMOVE_HEADING, MB_STYLE);
			end(REMOVE_FAILURE);
		}

		DeleteFile(app(BASIC_SETUP));
		success = RemoveDirectory(installpath);
		if (!success) {
			char *contents;

			contents = reportdir(librarypath);
			if (!contents) {
				sprintf(string, "Could not remove yabasic directory '%s' !\n"
					"You should remove it by hand and try again.\n", installpath);
				MyMessage(NULL, string, REMOVE_HEADING, MB_STYLE);
				end(REMOVE_FAILURE);
			}
			else {
				sprintf(string, "Could not remove yabasic directory '%s'.\n"
					"These files of suspect origin have been found:\n\n%s\n"
					"You should remove it by hand and try again.\n", librarypath, contents);
				MyMessage(NULL, string, REMOVE_HEADING, MB_STYLE);
				end(REMOVE_FAILURE);
			}
		}

		/* delete shell links */
		MyLinks(REMOVE);

		/* remove entries from the registry */
		MyRegs(REMOVE);

		end(REMOVE_SUCCESS);
	}
	return TRUE;
}


/*------------ subroutines --------------*/

BOOL CALLBACK pathdialog(HWND handle, UINT message,
	WPARAM wparam, LPARAM lparam)
	/* callback for choice of installation path */
{
	int cmdid;           /* id of command */
	char buf[SSLEN];       /* buffer for installation-path */
	int offset = 0;
	char name[SSLEN];       /* buffer for filename */
	OPENFILENAME fname; /* for common dialog */
	int ret;

	switch (message) {
	case WM_INITDIALOG:
	{ /* center dialog box */
		RECT rc;

		GetWindowRect(handle, &rc);
		SetWindowPos(handle, HWND_TOP,
			((GetSystemMetrics(SM_CXSCREEN) - (rc.right - rc.left)) / 2),
			((GetSystemMetrics(SM_CYSCREEN) - (rc.bottom - rc.top)) / 2),
			0, 0, SWP_NOSIZE | SWP_NOACTIVATE | SWP_SHOWWINDOW);
	}
	SetDlgItemText(handle, IDINSTPATH, installpath);
	return TRUE;

	case WM_COMMAND:
		cmdid = LOWORD(wparam);
		switch (cmdid) {
		case IDOK:
			logit("--Pathdialog: OK\n");
			EndDialog(handle, TRUE);
			GetDlgItemText(handle, IDINSTPATH, buf, SSLEN);
			installpath = strdup(buf);
			return TRUE;
		case IDCANCEL:
			logit("--Pathdialog: CANCEL\n");
			EndDialog(handle, FALSE);
			return TRUE;
		case IDC_BROWSE:
			fname.lStructSize = sizeof(fname);
			fname.hwndOwner = handle;
			fname.hInstance = this_instance;
			fname.lpstrFilter = "None\0+.+++\0\0";
			fname.lpstrCustomFilter = NULL;
			fname.nMaxCustFilter = 0;
			fname.nFilterIndex = 0;
			fname.nMaxFile = SSLEN;
			fname.lpstrFileTitle = NULL;
			fname.nMaxFileTitle = 0;
			offset = 0;
			GetDlgItemText(handle, IDINSTPATH, buf, SSLEN);
			ret = GetFileAttributes(buf);
			if (ret == 0xFFFFFFFF || !(ret & FILE_ATTRIBUTE_DIRECTORY)) {
				GetLogicalDriveStrings(SSLEN, buf);
				offset = strlen(buf) + 1;
			}
			fname.lpstrInitialDir = buf + offset;
			strcpy(name, "dummy");
			fname.lpstrFile = name;
			fname.lpstrTitle = "Select yabasic's directory";
			fname.Flags = OFN_HIDEREADONLY | OFN_EXPLORER |
				OFN_ENABLEHOOK | OFN_ENABLETEMPLATE | OFN_NOVALIDATE;
			fname.lpstrDefExt = NULL;
			fname.lCustData = 0;
			fname.lpfnHook = HookProc;
			fname.lpTemplateName = MAKEINTRESOURCE(IDD_EXPLANATION);
			if (GetOpenFileName(&fname)) {
				name[fname.nFileOffset] = '\0';
				SetDlgItemText(handle, IDINSTPATH, name);
			}
			return TRUE;
		default:
			break;
		}
	default:
		break;
	}
	return FALSE;
}


UINT CALLBACK HookProc(HWND hdl, UINT msg, WPARAM wparam, LPARAM lparam) /* hook for save as */
{
	if (msg == WM_INITDIALOG) {
		RECT rc;
		/* center dialog box */
		GetWindowRect(GetParent(hdl), &rc);
		SetWindowPos(GetParent(hdl), HWND_TOP,
			((GetSystemMetrics(SM_CXSCREEN) - (rc.right - rc.left)) / 2),
			((GetSystemMetrics(SM_CYSCREEN) - (rc.bottom - rc.top)) / 2),
			0, 0, SWP_NOSIZE | SWP_NOACTIVATE | SWP_SHOWWINDOW);
		CommDlg_OpenSave_HideControl(GetParent(hdl), cmb1);
		CommDlg_OpenSave_HideControl(GetParent(hdl), edt1);
		CommDlg_OpenSave_SetControlText(GetParent(hdl), IDOK, "Okay");
		CommDlg_OpenSave_SetControlText(GetParent(hdl), IDCANCEL, "Cancel");
		CommDlg_OpenSave_SetControlText(GetParent(hdl), stc4, "Install in: ");
		CommDlg_OpenSave_HideControl(GetParent(hdl), stc3);
		CommDlg_OpenSave_HideControl(GetParent(hdl), stc2);
		return FALSE;
	}
	return FALSE;
}


int delreg(HKEY start, char *keyname, char *subkey)
/*
delete keys from Registry
start   : one of the predefined key (e.g. HKEY_CLASSES_ROOT)
keyname : path to the key to delete
subkey  : subkey to delete
*/
{
	HKEY key;

	if (RegOpenKeyEx(start, keyname, 0, KEY_ALL_ACCESS, &key) != ERROR_SUCCESS)
		return FALSE;

	if (RegDeleteKey(key, subkey) != ERROR_SUCCESS) return FALSE;

	return TRUE;
}


char *getreg(char *name) /* get keys from Registry */
{
	char *keyname = "SOFTWARE\\"BASIC_NAME;
	HKEY key;
	char value[SSLEN];
	DWORD n;

	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, keyname, 0,
		KEY_ALL_ACCESS, &key) != ERROR_SUCCESS) return NULL;
	n = SSLEN;
	value[0] = '\0';
	if (RegQueryValueEx(key, name, NULL,
		NULL, value, &n) != ERROR_SUCCESS) return NULL;
	value[n] = '\0';

	return strdup(value);
}


int putreg(HKEY start, char *keyname, char *name, char *content)
/*
put keys into Registry
start   : one of the predefined key (e.g. HKEY_CLASSES_ROOT)
keyname : path to the key to create
name    : subkey to create
content : it's content
*/

{
	HKEY key;
	DWORD status;
	DWORD istype;
	char *iscon;
	DWORD islen;
	char buf[SSLEN];
	char buf2[SSLEN];
	char details[SSLEN];	
	DWORD ret;

	sprintf(details, "keyname='%s', name='%s', content='%s'", keyname, name, content);
	islen = strlen(content) + 1;
	iscon = malloc(islen);
	if (RegOpenKeyEx(start, keyname, 0, KEY_QUERY_VALUE, &key) == ERROR_SUCCESS) {
		if (RegQueryValueEx(key, name, NULL, &istype, iscon, &islen) == ERROR_SUCCESS)
			if (!strcmp(iscon, content)) {
				free(iscon);
				return TRUE;
			}
			else {
				RegCloseKey(key);
				if (ret = RegOpenKeyEx(start, keyname, 0, KEY_QUERY_VALUE | KEY_SET_VALUE, &key) == ERROR_SUCCESS) {
					ret = RegSetValueEx(key, name, 0, REG_SZ, content, strlen(content) + 1);
					if (ret == ERROR_SUCCESS) {
						return TRUE;
					}
					else {
						FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, ret, 0, buf, SSLEN, 0);
						sprintf(buf2, "Could not set value for existing Registry key RegSetValueEx(%s), %s", details, buf);
						logit(buf2);
						return FALSE;
					}
				}
				else {
					FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, ret, 0, buf, SSLEN, 0);
					sprintf(buf2, "Could not open existing Registry key for writing RegOpenKeyEx(%s), %s", details, buf);
					logit(buf2);
					return FALSE;
				}
			}
	}
	else {
		RegCloseKey(key);
	}
	sprintf(buf2, "Registry key could not be opend for reading, trying to create it RegOpenKeyEx(%s), %s", details, buf);
	logit(buf2);
	ret = RegCreateKeyEx(start, keyname, 0, "", 0, KEY_QUERY_VALUE | KEY_SET_VALUE, NULL, &key, &status);
	if (ret != ERROR_SUCCESS) {
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, ret, 0, buf, SSLEN, 0);
		sprintf(buf2, "Could not create Registry key RegCreateKeyEx(%s), %s", details, buf);
		logit(buf2);
		return FALSE;
	}
	free(iscon);
	ret = RegSetValueEx(key, name, 0, REG_SZ, content, strlen(content) + 1);
	if (ret == ERROR_SUCCESS) {
		return TRUE;
	}
	else {
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, ret, 0, buf, SSLEN, 0);
		sprintf(buf2, "Could not set value of newly created Registry key RegSetValueEx(%s), %s", details, buf);
		logit(buf2);
		return FALSE;
	}
}


void end(int m) { /* display message and terminate */
	char *msg;
	int ret;
	int ret2;
	char string[SSLEN];          /* multi-purpose string */
	char string2[SSLEN];
	int run_demo = FALSE;
	int show_log = TRUE;
	char *heading = INSTALL_HEADING;

	switch (m) {
	case INSTALL_CANCELLED:
		msg = "Installation cancelled.\n\n"
			"No garbage has been left.";
		ret = FALSE;
		show_log = FALSE;
		break;
	case INSTALL_IMPOSSIBLE:
		msg = "Installation failed !\n\n"
			"No garbage has been left.";
		ret = FALSE;
		break;
	case INSTALL_FAILURE:
		msg = "Installation failed !\n"
			"Some garbage has been left in the system.\n\n"
			"To clear up, you better remove "BASIC_NAME" through its entry in control-panel, section software.";
		ret = FALSE;
		break;
	case INSTALL_ABORTED:
		msg = "Installation aborted.\n"
			"Some garbage has been left in the system !\n\n"
			"To clean up, you better remove "BASIC_NAME" through its entry in control-panel, section software.";
		ret = FALSE;
		break;
	case INSTALL_SUCCESS:
		msg = "Installation completed successfully !\n\n"
			"You may now start writing Yabasic-programs.";
		ret = TRUE;
		run_demo = TRUE;
		show_log = FALSE;
		break;
	case REMOVE_SUCCESS:
		msg = BASIC_NAME" has been removed properly !";
		ret = TRUE;
		show_log = FALSE;
		heading = REMOVE_HEADING;
		break;
	case REMOVE_CANCELLED:
		msg = "Cancelled. "BASIC_NAME" has been left intact.";
		ret = FALSE;
		show_log = FALSE;
		heading = REMOVE_HEADING;
		break;
	case REMOVE_FAILURE:
		msg = "Couldn't remove "BASIC_NAME" properly !";
		ret = FALSE;
		heading = REMOVE_HEADING;
		break;
	case SILENT:
		ret = TRUE;
		show_log = FALSE;
		goto silent;
	default:
		break;
	}

	string2[0] = '\0';
	if (show_log) sprintf(string2, "\n\n\nDo you want to view the logfile ?\n(%s)\n\nYou may send it to mail@yabasic.de and I will try to help.", logpath);
	if (run_demo) sprintf(string2, "\n\n\nDo you want to run the demo of yabasic ?");
	sprintf(string, "\n\n\n%s%s", msg, string2);
	if (MyMessage(NULL, string, heading, (show_log || run_demo) ? (MB_YESNO | MB_ICONQUESTION | MB_SYSTEMMODAL) : MB_STYLE) == IDYES) {
		if (show_log) sprintf(string, "%s", logpath);
		if (run_demo) sprintf(string, "%s/demo.yab", installpath);
		ret2 = ShellExecute(NULL, "open", string, NULL, NULL, SW_SHOWNORMAL);
		if (ret2 <= 32) {
			FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(),
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), string, SSLEN, NULL);
			if (show_log) {
				sprintf(string2, "Could show setup log (%s): %d, %s", logpath, ret2, string);
				heading = " Could not show Logfile ! ";
			}
			if (run_demo) {
				sprintf(string2, "Could start demo of yabasic: %d, %s", ret2, string);
				heading = " Could not show Logfile ! ";
			}
			MessageBoxEx(NULL, string2, heading,
				MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));
		}
	}

silent:

	/* close log-file */
	logit(NULL);

	exit(ret);

	return;
}


char *app(char *trail) /* append trail to installpath */
{
	char *result;
	int i, t;

	i = strlen(installpath);
	t = strlen(trail);

	result = malloc(i + t + 1);
	memcpy(result, installpath, i);
	memcpy(result + i, trail, t);
	result[t + i] = '\0';

	return result;
}


HRESULT CreateShellLink(LINKINFO *li, char *path)
/*
stolen from win32 SDK Help: Create a shell-link
li    : points to LINKINFO structure containing all infos about link
path  : Full pathname for objects
*/
{
	HRESULT hres;                /* return value */
	IShellLink* psl;             /* pointer to new shell-link */
	LPITEMIDLIST pidl;           /* path id */
	char PathLink[MAX_PATH];     /* path name */
	char string[SSLEN];          /* multi-purpose string */
	static int first = TRUE;

	/* make filename from registry folder constant */
	hres = SHGetSpecialFolderLocation(NULL, li->folder, &pidl);
	if (!SUCCEEDED(hres)) return hres;
	SHGetPathFromIDList(pidl, PathLink);
	strcat(PathLink, "\\");
	strcat(PathLink, li->link);

	/* initialize COM-library */
	if (first) {
		CoInitialize(NULL);
		first = FALSE;
	}

	/* Get a pointer to the IShellLink interface. */
	hres = CoCreateInstance(&CLSID_ShellLink, NULL,
		CLSCTX_INPROC_SERVER, &IID_IShellLink, &psl);
	if (SUCCEEDED(hres)) {
		IPersistFile* ppf;

		/* Set the path to the shortcut target */
		sprintf(string, "%s%s", path, li->file);
		psl->lpVtbl->SetPath(psl, string);

		/* add description */
		psl->lpVtbl->SetDescription(psl, li->desc);

		/* set working directory */
		psl->lpVtbl->SetWorkingDirectory(psl, path);

		/* set icon */
		if (li->icon[1]) {
			sprintf(string, "%s%s", path, li->icon);
			psl->lpVtbl->SetIconLocation(psl, string, 0);
		}
		else {
			GetSystemDirectory(string, SSLEN);
			strcat(string, "\\shell32.dll");
			psl->lpVtbl->SetIconLocation(psl, string, li->icon[0]);
		}

		/* Query IShellLink for the IPersistFile interface for saving the
		shortcut in persistent storage. */
		hres = psl->lpVtbl->QueryInterface(psl, &IID_IPersistFile, &ppf);

		if (SUCCEEDED(hres)) {
			WORD wsz[MAX_PATH];

			/* Ensure that the string is ANSI. */
			MultiByteToWideChar(CP_ACP, 0, PathLink, -1, wsz, MAX_PATH);

			/* Save the link by calling IPersistFile::Save. */
			hres = ppf->lpVtbl->Save(ppf, wsz, TRUE);
			ppf->lpVtbl->Release(ppf);
		}
		psl->lpVtbl->Release(psl);
	}
	return hres;
}


HRESULT DeleteShellLink(LINKINFO *li)
/*
Delete a shell-link
li    : points to LINKINFO structure containing all infos about link
*/
{
	HRESULT hres;                /* return value */
	LPITEMIDLIST pidl;           /* path id */
	char PathLink[MAX_PATH];     /* path name */

	/* make filename from folder constant */
	hres = SHGetSpecialFolderLocation(NULL, li->folder, &pidl);
	if (!SUCCEEDED(hres)) return hres;
	SHGetPathFromIDList(pidl, PathLink);
	strcat(PathLink, "\\");
	strcat(PathLink, li->link);

	sprintf(logs, "--Deleting '%s'\n", PathLink);
	logit(logs);
	return DeleteFile(PathLink);
}


int MyLinks(int mode) /* add or remove shell links */
{
	int success = TRUE;
	LINKINFO *li; /* contains info about links */
	char string[SSLEN];
	LPITEMIDLIST pidl;           /* path id */
	char PathLink[MAX_PATH];     /* path name */
	int res;

	enumlinks(RESET);

	if (mode == INSTALL) {
		/* make filename from registry folder constant */
		SHGetSpecialFolderLocation(NULL, CSIDL_PROGRAMS, &pidl);
		SHGetPathFromIDList(pidl, PathLink);
		strcat(PathLink, "\\"BASIC_NAME);
		res = CreateDirectory(PathLink, NULL);
	}
	while (li = enumlinks(NEXT)) {
		if (mode == INSTALL && !li->removeonly) {
			sprintf(string, "Adding %s", li->desc);
			progress(string);
			success = SUCCEEDED(CreateShellLink(li, installpath)) && success;
		}
		else {
			sprintf(string, "removing %s", li->desc);
			progress(string);
			success = SUCCEEDED(DeleteShellLink(li)) && success;
		}
	}
	if (mode != INSTALL) {
		/* make filename from registry folder constant */
		SHGetSpecialFolderLocation(NULL, CSIDL_PROGRAMS, &pidl);
		SHGetPathFromIDList(pidl, PathLink);
		strcat(PathLink, "\\"BASIC_NAME);
		res = RemoveDirectory(PathLink);
	}
	return success;
}


int MyFiles(int mode) /* copy or delete files */
{
	int success = TRUE;
	char *name;
	int failures = 0;
	char string[SSLEN];   /* multi-purpose-string */

	switch (mode) {

	case INSTALL:
		enumfiles(RESET);

		while (success && (name = enumfiles(NEXT))) {
			sprintf(string, "%s%s", currentpath, name);
			success = Copy(string, app(name), here) && success;
			sprintf(string, "Copying '%s'", name);
			progress(string);
		}
		break;
	case REMOVE:
		enumfiles(RESET);

		while (name = enumfiles(NEXT)) {
			if (!DeleteFile(app(name))) failures++;
			sprintf(string, "Deleting '%s'", name);
			progress(string);
		}
		if (failures > 1) success = FALSE;

		break;
	default:
		break;
	}
	return success;
}


int MyRegs(int mode) /* add or delete entries to or from registry */
{
	int success = TRUE;
	char string[SSLEN];   /* multi-purpose-string */
	char windir[SSLEN];   /* windows-directory */
	char buf[SSLEN];

	switch (mode) {
	case INSTALL:
		/* registering uninstall program */
		progress("Registering uninstall-program");
		success = putreg(LOCAL, UNINSTALL BASIC_NAME, "DisplayName", BASIC_NAME);
		sprintf(string, "%s%s %s", installpath, BASIC_SETUP, "remove");
		success = putreg(LOCAL, UNINSTALL BASIC_NAME, "UninstallString", string) && success;
		progress(NULL);
		progress("Adding defaults to registry.");
		/* make changes in registry, put in defaults */
		success = putreg(LOCAL, SOFT BASIC_NAME, "path", installpath) && success;
		progress(NULL);
		success = putreg(LOCAL, SOFT BASIC_NAME, "librarypath", librarypath) && success;
		progress(NULL);
		success = putreg(LOCAL, SOFT BASIC_NAME, "font", DEFAULTFONT) && success;
		progress(NULL);
		success = putreg(LOCAL, SOFT BASIC_NAME, "foreground", DEFAULTFOREGROUND) && success;
		progress(NULL);
		success = putreg(LOCAL, SOFT BASIC_NAME, "background", DEFAULTBACKGROUND) && success;
		progress(NULL);
		success = putreg(LOCAL, SOFT BASIC_NAME, "geometry", DEFAULTGEOMETRY) && success;
		sprintf(string, "%s", formatsemver(&newversion,buf));
		progress(NULL);
		success = putreg(LOCAL, SOFT BASIC_NAME, "version", string) && success;

		progress("Registering file extension.");
		/* change context-menue */
		success = putreg(ROOT, BASIC_EXTENSION, "", BASIC_NAME) && success;
		progress(NULL);
		success = putreg(ROOT, BASIC_NAME, "", "Yabasic Program") && success;
		progress(NULL);
		success = putreg(ROOT, BASIC_NAME"\\DefaultIcon", "", app(BASIC_ICON)) && success;
		progress(NULL);
		success = putreg(ROOT, BASIC_EXTENSION"\\ShellNew", "NullFile", "") && success;
		success = putreg(ROOT, BASIC_NAME"\\shell\\open", "", "&Execute") && success;
		success = putreg(ROOT, BASIC_NAME"\\shell\\open\\command", "",
			app(BASIC_EXE" \"%1\" \"%2\" \"%3\" \"%4\" \"%5\" \"%6\" \"%7\" \"%8\" \"%9\"")) && success;

		progress("Linking to root-Menu");
		success = putreg(ROOT, BASIC_NAME"\\shell\\New", "", "&Edit") && success;
		GetWindowsDirectory(string, SSLEN);
		sprintf(windir, "%s%s", brushup(string), "Notepad.exe \"%1\"");
		success = putreg(ROOT, BASIC_NAME"\\shell\\New\\command", "", windir)
			&& success;
		/* printing of embedded docu */
		success = putreg(ROOT, BASIC_NAME"\\shell\\ViewDocu", "", "&View docu") && success;
		success = putreg(ROOT, BASIC_NAME"\\shell\\ViewDocu\\command", "",
			app(BASIC_EXE" \"-doc_%1\"")) && success;

		return success;
	case REMOVE:
		delreg(ROOT, BASIC_EXTENSION, "");
		progress(NULL);
		delreg(ROOT, BASIC_NAME, "");
		progress(NULL);
		delreg(LOCAL, SOFT BASIC_NAME, "");
		progress(NULL);
		delreg(LOCAL, UNINSTALL BASIC_NAME, "");
	}
	return success;
}


BOOL CALLBACK progressdialog(HWND handle, UINT message,
	WPARAM wparam, LPARAM lparam)
	/* callback for cprogress dialog */
{

	switch (message) {
	case WM_INITDIALOG:
	{ /* center dialog box */
		RECT rc;

		GetWindowRect(handle, &rc);
		SetWindowPos(handle, HWND_TOP,
			((GetSystemMetrics(SM_CXSCREEN) - (rc.right - rc.left)) / 2),
			((GetSystemMetrics(SM_CYSCREEN) - (rc.bottom - rc.top)) / 2),
			0, 0, SWP_NOSIZE | SWP_NOACTIVATE | SWP_SHOWWINDOW);
	}
	return TRUE;
	default:
		break;
	}
	return FALSE;
}


void progress(char *msg) /* show progress */
{
	int timerid;
	MSG timermsg;
	RECT rc;
	static int count = 0;
	static HWND progressbox = NULL;   /* handle of progress dialog */
	static HWND hwndPB = NULL; /* handle of progress bar */
	char string[SSLEN];             /* multi-purpose string */
	int thumb;  // height of scroll bar arrow 

	count++;

	/* create progress dialog */
	if (progressbox == NULL) {
		InitCommonControls();
		progressbox = CreateDialog((HANDLE)this_instance,
			MAKEINTRESOURCE(IDD_PROGRESSDIALOG),
			(HANDLE)NULL,
			(DLGPROC)progressdialog);
		GetClientRect(progressbox, &rc);
		thumb = GetSystemMetrics(SM_CYVSCROLL);
		hwndPB = CreateWindowEx(0, PROGRESS_CLASS, (LPSTR)NULL,
			WS_CHILD | WS_VISIBLE, rc.left + thumb,
			rc.bottom - 3 * thumb, rc.right - 2 * thumb, 2 * thumb,
			progressbox, (HMENU)0, this_instance, NULL);
		SendMessage(hwndPB, PBM_SETRANGE, 0, MAKELPARAM(0, total_progress));
		SendMessage(hwndPB, PBM_SETSTEP, (WPARAM)1, 0);
		/* actually display the window */
		ShowWindow(progressbox, SW_SHOW);
	}

	/* change text */
	if (msg) SetDlgItemText(progressbox, IDC_PROGRESSTEXT, msg);

	/* advance progress count */
	SendMessage(hwndPB, PBM_STEPIT, 0, 0);

	/* write to logfile */
	if (msg) {
		sprintf(logs, "--Progress: %d, '%s'\n", count, msg);
		logit(logs);
	}

	/* set heading of progress window */
	sprintf(string, "Work in progress ... step %d", count);
	SendMessage((HWND)progressbox, (UINT)WM_SETTEXT, 0, (LPARAM)(LPCTSTR)string);

	/* wait a bit ... */
	timerid = SetTimer(NULL, 0, 200, (TIMERPROC)NULL);
	GetMessage((LPMSG)&timermsg, NULL, WM_TIMER, WM_TIMER);
	KillTimer(NULL, timerid);
}


int Copy(char *name, char *dest, int here) /* copy files */
{
	int ret;
	char string[SSLEN];
	WIN32_FIND_DATA file;

	if (here) {
		ret = (FindFirstFile(dest, &file) != INVALID_HANDLE_VALUE);
	}
	else
		ret = CopyFile(name, dest, FALSE);
	if (!ret) {
		sprintf(string, "Failed to copy '%s' !", name);
		MyMessage(NULL, string, INSTALL_HEADING, MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);
	}
	return ret;
}


char *enumfiles(int mode) /* give filenames, one after another */
{
	static int num = 0;

	if (mode == RESET) {
		num = 0;
		return NULL;
	}

	num++;

	if (num == 1) return strdup(BASIC_SETUP);
	if (num == 2) return strdup(BASIC_ICON);
	if (num == 3) return strdup(BASIC_EXE);
	if (num == 4) return strdup(BASIC_DEMOPROG".yab");
	if (num == 5) return strdup(BASIC_README);
	if (num == 6) return strdup(BASIC_NAME".htm");

	return NULL;
}


LINKINFO *enumlinks(int mode) /* give back linkinfos, one after another */
{
	static int num = 0;
	static LINKINFO li[] = {
	  {CSIDL_PROGRAMS,BASIC_NAME"\\"BASIC_NAME".LNK",BASIC_EXE,
		"Link to "BASIC_NAME,BASIC_ICON,FALSE},
	  {CSIDL_PROGRAMS,BASIC_NAME".LNK",BASIC_EXE,
	  "Link to "BASIC_NAME,BASIC_ICON,TRUE},
	  {CSIDL_PROGRAMS,BASIC_NAME"\\DEMO.LNK",BASIC_DEMOPROG".yab",
	  "Link to "BASIC_DEMOPROG".yab","\025",FALSE},
	  {CSIDL_DESKTOPDIRECTORY,"DEMO.LNK",BASIC_DEMOPROG".yab",
	  "Link to "BASIC_DEMOPROG".yab",BASIC_ICON,FALSE},
	  {CSIDL_PROGRAMS,BASIC_NAME"\\DOCU.LNK",BASIC_NAME".htm",
	  "Link to "BASIC_NAME".htm","\026",FALSE},
	  {CSIDL_DESKTOPDIRECTORY,"DOCU.LNK",BASIC_NAME".htm",
	  "Link to "BASIC_NAME".htm",BASIC_ICON,FALSE}
	};

	if (mode == RESET) {
		num = -1;
		return NULL;
	}

	num++;

	if (num > 5)
		return NULL;
	else
		return &li[num];
}


char *brushup(char *path) /* change to lower case, add slash */
{
	int i;
	char buf[SSLEN];

	if (path == NULL) return NULL;

	i = 0;
	do {
		buf[i] = tolower(path[i]);
		if (buf[i] == '/') buf[i] = '\\';
		i++;
	} while (path[i] != '\0' && isprint(path[i]));

	buf[i] = '\0';

	if (buf[i - 1] != '\\') {
		buf[i] = '\\';
		buf[i + 1] = '\0';
	}

	return strdup(buf);
}


void logit(char *text)
/* write text to log-file */
{
	static FILE *log = NULL;   /* file for logging */
	SYSTEMTIME time;         /* time */
	char string[SSLEN];
	static int oldtime;

	/* open log-file */
	if (!log) {
		sprintf(logpath, "%s%s", temppath, BASIC_LOG);
		log = fopen(logpath, "a");
		if (!log) {
			sprintf(string, "Could not open log file '%s': %s", logpath, strerror(errno));
			MyMessage(NULL, string, INSTALL_HEADING, MB_STYLE);
			end(INSTALL_IMPOSSIBLE);
		}
		GetSystemTime(&time);
		if (log) {
			fprintf(log, "\n\n\n---------------------------------------------------\n"
				"Starting installation-log, "
				"hr=%d, min=%d, sec=%d, msec=%d.\n",
				time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
			oldtime = GetCurrentTime();
		}
	}

	if (log) {
		GetSystemTime(&time);
		if (GetCurrentTime() - oldtime > 10000) {
			fprintf(log, "Timestamp: hr=%d, min=%d, sec=%d, msec=%d\n",
				time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
			oldtime = GetCurrentTime();
		}
		if (text) {
			if (strncmp(text, "--", 2)) fprintf(log, "  ");
			while (*text != '\0') {
				fputc(*text, log);
				if (*text == '\n' && *(text + 1) != '\0') fprintf(log, "  ");
				text++;
			}
		}
		else {  /* not text ... */
			fprintf(log, "Closing installation-log.");
			fflush(log);
			fclose(log);
		}
	}
	if (log) fflush(log);
}


int MyMessage(HWND handle, LPCSTR text, LPCSTR title, UINT style)
/* wrapper for MessageBox() */
{

	sprintf(logs, "--Message box: '%s'\n", text);
	logit(logs);

	return MessageBoxEx(handle, text, title, style,
		MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));
}


char *reportdir(char *path)
/* generate a string containing filenames in directory */
{
	static char list[1000];
	char file[SSLEN];
	WIN32_FIND_DATA found;
	HANDLE search;

	sprintf(file, "%s\\*.*", path);
	search = FindFirstFile(file, &found);
	FindNextFile(search, &found);
	if (!FindNextFile(search, &found)) {
		return NULL;
	}
	else {
		list[0] = '\0';
		do {
			strcat(list, "        ");
			strcat(list, found.cFileName);
			strcat(list, "\n");
		} while (FindNextFile(search, &found));
		return list;
	}
}


int parsesemver(char *text, SEMVER *parsed)
/* parse semantiv version contained in string */
{
	switch (sscanf(text, "%d.%d.%d", &(parsed->major), &(parsed->minor), &(parsed->patch))) {
	case 3:
		return TRUE;
	case 2:
		if (parsed->minor > 100) {
			parsed->patch = parsed->minor % 10;
			parsed->minor = (parsed->minor - parsed->patch) / 10;
		}
		else {
			parsed->patch = 0;
		}
		return TRUE;
	}
	return FALSE;
}

int comparesemver(SEMVER *this, SEMVER *other)
/* compare two semantic version numbers */
{
	if (this->major == other->major) {
		if (this->minor == other->minor) {
			if (this->patch == other->patch) {
				return 0;
			}
			else if (this->patch < other->patch) {
				return -1;
			}
			else {
				return 1;
			}
		}
		else if (this->minor < other->minor) {
			return -1;
		}
		else {
			return 1;
		}
	}
	else if (this->major < other->major) {
		return -1;
	}
	else {
		return 1;
	}
}


char *formatsemver(SEMVER *ver, char *buf)
/* return string with formatted version number */
{
	sprintf(buf, "%d.%d.%d", ver->major, ver->minor, ver->patch);
	return buf;
}
