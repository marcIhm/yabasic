/*

  Installer for yabasic
  Copyright by Marc Ihm 1996-2019
  
  This file is part of yabasic and may be copied under the terms of
  MIT License which can be found in the file LICENSE.
  
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
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")

/*------------ defines -------------------*/

/* headings for messageboxes */
#define INSTALL_HEADING " Installing yabasic ..."
#define REMOVE_HEADING " Removing yabasic ..."

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

/* end-dialog return values */
#define SHOW_LOG 1
#define RUN_DEMO 2
#define READ_DOCU 3
#define JUST_EXIT 4

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
char logs[10*SSLEN];        /* string to compose log-message */
char logfile[SSLEN] = "undefined";      /* string containing pathname of logfile */
int here;                /* install in current path ? */
int install;             /* install or remove ? */
int copied;              /* true if copy in temp-directory */
int control_pressed;     /* true, if shift key has been down at program start or during progress dialog */

int total_progress;      /* number of steps to advance progress counter */

HINSTANCE this_instance; /* instance */
HICON this_icon;         /* yabasic icon */
SEMVER newversion;       /* version to be installed */

/*------------ prototypes -------------------*/

/* My...() functions */
int MyLinks(int); /* add or remove shell links */
int MyFiles(int); /* copy or delete files */
int MyRegs(int); /* add or delete entries to or from registry */

/* dialog callbacks */
BOOL CALLBACK pathdialog(HWND, UINT, WPARAM, LPARAM);/* choose installpath */
BOOL CALLBACK progressdialog(HWND, UINT, WPARAM, LPARAM);/* show progress */
int CALLBACK BrowseCallbackProc(HWND, UINT, LPARAM, LPARAM); /* set initial path for browse */

/* registry manipulation */
int delreg(HKEY, char *, char *);
char *getreg_yab(char *);
char *getreg_full(char *,char *,HKEY);
int putreg(HKEY, char *, char *, char *);

int create_shell_link(LINKINFO *, char *); /* create a shell link */
int delete_shell_link(LINKINFO *); /* delete a shell link */

/* functions dealing with progress bar */
void progress(char *); /* show progress */

/* for handling semantic versions */
int parsesemver(char *, SEMVER *); /* parse semantiv version contained in string */
int comparesemver(SEMVER *, SEMVER *); /* compare two semantic version numbers */
char *formatsemver(SEMVER *,char *); /* return string with formatted version number */

/* miscellanous functions */
void end(int); /* display message and terminate */
char *append(char *); /* append tail to installpath */
int copy_file(char *, char *, int); /* copy files */
char *brushup(char *); /* change to upper case, add slash */
char *enumfiles(int); /* give filenames, one after another */
LINKINFO *enumlinks(int); /* give back links, one after the other */
void logit(char *); /* write text to logfile */
char *current_time(void); /* get current time as string */
int MyMessage(HWND, LPCSTR, LPCSTR, UINT); /* wrapper for MessageBox() */
char *reportdir(char *); /* generate a string containing filenames in directory */
char *last_error(void); /* get last error as string */
void center_dialog(HWND); /* center dialog on screen */
BOOL is_elevated(); /* Check, if program is running with elevated privs */
void log_os_info(); /* Write Windows Version to logfile */
int makedir(char *); /* Create Directory */

/*------------ main program --------------*/

int WINAPI WinMain(HINSTANCE _this_instance,
	HINSTANCE prev_instance,
	LPSTR commandline,
	int win_state)
{
	SEMVER oldversion;    /* version already installed */
	char *oldpath;  /* old installation path */
	FILE *verfile;       /* file with version */
	int cancel;          /* return value of dialog */
	int success;         /* return value of My..() functions */
	char string[SSLEN];  /* multi-purpose string */
	char string2[SSLEN]; 
	char string3[SSLEN]; 
	char errmsg[SSLEN];
	char *full;
	int answer;
	int i;

	/* copy intance information to global variable */
	this_instance = _this_instance;
	this_icon = LoadIcon(this_instance, "yabico.ico");

	/* get path for temporary files */
	GetTempPath(SSLEN, string);
	GetLongPathName(string, string, SSLEN);
	temppath = brushup(string);
	sprintf(logs, "--Temppath: '%s'\n", temppath);
	logit(logs);

	/* get state of control key */
	control_pressed = (GetAsyncKeyState(VK_CONTROL) < 0);

	/* initialize COM-library for creation of shell links */
	CoInitialize(NULL);

	sprintf(logs, "--Commandline='%s'\n", commandline);
	logit(logs);

	sprintf(logs, "--Process is elevated=%s\n", is_elevated() ? "true" : "false");
	logit(logs);
	log_os_info();
	
	/* parse commandline */
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
		total_progress = 21;

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
		sprintf(string, "%s%s", currentpath, "yabver.txt");
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
		ver = getreg_yab("version");
		oldversion.major = 0;
		oldversion.minor = 0;
		oldversion.patch = 0;
		if (ver) parsesemver(ver, &oldversion);

		/* get confirmation */
		sprintf(string, "This will install\n\n       Yabasic, Version %s\n\nDo you want to proceed ?", formatsemver(&newversion,string2));
		if (MyMessage(NULL, string, INSTALL_HEADING,
			MB_YESNO | MB_ICONQUESTION | MB_SYSTEMMODAL) == IDNO)
			end(INSTALL_CANCELLED);

		control_pressed = control_pressed || (GetAsyncKeyState(VK_CONTROL) < 0);

		/* check versions */
		if (comparesemver(&oldversion, &newversion)>0) {
			sprintf(string, "A newer Version of Yabasic"
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
		oldpath = brushup(getreg_yab("path"));
		installpath = malloc(SSLEN + 1);
		SHGetSpecialFolderPath(0, installpath, CSIDL_PROGRAM_FILES, FALSE);
		strcat(installpath, "\\yabasic");
		cancel = !DialogBox((HANDLE)this_instance,
			MAKEINTRESOURCE(IDD_PATHDIALOG),
			(HWND)NULL, (DLGPROC)pathdialog);
		if (cancel) end(INSTALL_CANCELLED);
		control_pressed = control_pressed || (GetAsyncKeyState(VK_CONTROL) < 0);
		installpath = brushup(installpath);
		here = !strcmp(currentpath, installpath);
		if (oldpath && strcmp(installpath, oldpath)) {
			sprintf(string, "Yabasic will be installed in:\n\n\t%s\n\n"
				"However, an old installation of yabasic has been found in:\n\n\t%s\n\n"
				"After this installation has finished, you can safely\n"
				"remove the old directory by hand !\n\n"
				"Shall the installation continue ?", installpath, oldpath);
			answer = MyMessage(NULL, string, INSTALL_HEADING, MB_YESNO | MB_SYSTEMMODAL | MB_ICONINFORMATION);
			if (answer == IDNO) end(INSTALL_CANCELLED);
		}

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
		sprintf(string, "Creating directory for Installation %s", installpath);
		progress(string);
		if (!makedir(installpath)) {
		  MyMessage(NULL, "Couldn't create directory for installation !",
			    INSTALL_HEADING, MB_STYLE);
		  end(INSTALL_FAILURE);
		};
		sprintf(string, "Creating directory for Libraries %s", librarypath);
		progress(string);
		if (!makedir(librarypath)) {
		  MyMessage(NULL, "Couldn't create directory for libraries !",
			    INSTALL_HEADING, MB_STYLE);
		  end(INSTALL_FAILURE);
		};

		/* copy files */
		progress("Copying files.");
		success = MyFiles(INSTALL);
		if (!success) {
			MyMessage(NULL, "Couldn't copy files !",
				INSTALL_HEADING, MB_STYLE);
			end(INSTALL_FAILURE);
		}

		/* installation successfull ! */
		Sleep(400);
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
		installpath = getreg_yab("path");
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

		sprintf(logs, "--Installpath: '%s'\n", installpath);
		logit(logs);

		/* set advance for progresscount */
		total_progress = 8;

		here = !strcmp(currentpath, installpath);

		/* remove files */
		if (!copied) {
			char to[SSLEN];
			char *from;
			char string[SSLEN]; /* multi purpose string */

			GetTempPath(SSLEN, to);
			strcat(to, "setup.exe");
			from = append("setup.exe");
			CopyFile(from, to, FALSE);

			/* change registry, to point to new location */
			sprintf(string, "%s %s", to, "remove");
			putreg(LOCAL, UNINSTALL "Yabasic", "UninstallString", string);

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

		DeleteFile(append("setup.exe"));
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
	char name[SSLEN];       /* directory name */
	BROWSEINFO bi;
	LPITEMIDLIST pidl;

	switch (message) {
	case WM_INITDIALOG:
		center_dialog(handle);
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
			logit("--Pathdialog: BROWSE\n");
			memset(&bi, 0, sizeof(bi));
			bi.lpszTitle = "Please choose and create the directory, where the files of yabasic should be placed.";
			bi.ulFlags = BIF_NEWDIALOGSTYLE | BIF_RETURNONLYFSDIRS;
			bi.lpfn = BrowseCallbackProc;
			bi.lParam = (LPARAM)installpath;
			pidl=SHBrowseForFolder(&bi);
			if (pidl!=0 && SHGetPathFromIDList(pidl, name)) {
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

static int CALLBACK BrowseCallbackProc(HWND hwnd, UINT message, LPARAM lparam, LPARAM lpdata)
{
	int hpos;
	switch (message) {
	case BFFM_INITIALIZED:
		SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpdata);
		break;
	case BFFM_SELCHANGED:
		/* This does not work yet ... */
		hpos = SendMessage(hwnd, TVM_GETNEXTITEM, TVGN_CARET, 0); /* this always returns 0 */
		SendMessage(hwnd, TVM_ENSUREVISIBLE, hpos, 0); 
		break;
	}
	return 0;
}

BOOL CALLBACK errordialog(HWND handle, UINT message,
	WPARAM wparam, LPARAM lparam)
	/* callback for reporting error in installation */
{
	int cmdid;           /* id of command */

	switch (message) {
	case WM_INITDIALOG:
		center_dialog(handle);
		SetDlgItemText(handle, IDC_ERRORTEXT, (LPCSTR)lparam);
		logit("--Errordialog: Initialized\n");
		return TRUE;
	case WM_COMMAND:
		cmdid = LOWORD(wparam);
		switch (cmdid) {
		case IDC_BUTTON_VIEW_LOG:
			logit("--Errordialog: View log\n");
			EndDialog(handle, SHOW_LOG);
			return TRUE;
		case IDC_BUTTON_JUST_EXIT:
			logit("--Errordialog: Just exit\n");
			EndDialog(handle, JUST_EXIT);
			return TRUE;
		default:
			break;
		}
	default:
		break;
	}
	return FALSE;
}

BOOL CALLBACK successdialog(HWND handle, UINT message,
	WPARAM wparam, LPARAM lparam)
	/* callback for reporting success of installation */
{
	int cmdid;           /* id of command */
	
	switch (message) {
	case WM_INITDIALOG:
		center_dialog(handle);
		SetDlgItemText(handle, IDC_SUCCESSTEXT, (LPCSTR) lparam);
		logit("--Successdialog: Initialized\n");
		return TRUE;
	case WM_COMMAND:
		cmdid = LOWORD(wparam);
		switch (cmdid) {
		case IDC_BUTTON_RUN_DEMO:
			logit("--Successdialog: Run demo\n");
			EndDialog(handle, RUN_DEMO);
			return TRUE;
		case IDC_BUTTON_READ_DOCU:
			logit("--Successdialog: Read docu\n");
			EndDialog(handle, READ_DOCU);
			return TRUE;
		case IDC_BUTTON_VIEW_LOG2:
			logit("--Successdialog: View Logfile\n");
			EndDialog(handle, SHOW_LOG);
			return TRUE;
		case IDC_BUTTON_JUST_EXIT:
			logit("--Successdialog: Just exit\n");
			EndDialog(handle, JUST_EXIT);
			return TRUE;
		default:
			break;
		}
	default:
		break;
	}
	return FALSE;
}

void center_dialog(HWND handle) /* center dialog on screen */
{
	RECT rect;

	GetWindowRect(handle, &rect);
	SetWindowPos(handle, HWND_TOP,
		((GetSystemMetrics(SM_CXSCREEN) - (rect.right - rect.left)) / 2),
		((GetSystemMetrics(SM_CYSCREEN) - (rect.bottom - rect.top)) / 2),
		0, 0, SWP_NOSIZE | SWP_NOACTIVATE | SWP_SHOWWINDOW);
	SendMessage(handle, WM_SETICON, ICON_BIG, (LPARAM)this_icon);
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

int makedir(char *path) /* Create Directory */
{
  DWORD dwAttrib;
  int res;
  char buf[SSLEN];

  dwAttrib = GetFileAttributes(path);
  
  /* check, if directory exists already */
  if (dwAttrib != INVALID_FILE_ATTRIBUTES &&  (dwAttrib & FILE_ATTRIBUTE_DIRECTORY)) {
    sprintf(buf, "Directory to be created already exists '%s'", path);
    logit(buf);
    return TRUE;
  }
  res = CreateDirectory(path, NULL);
  sprintf(buf, "Creating directory '%s': result = %d\n%s", path, res, last_error());
  logit(buf);

  return res;
}

char *getreg_yab(char * name) /* specialized version */
{
  return getreg_full(name, "SOFTWARE\\Yabasic", HKEY_LOCAL_MACHINE);
}

char *getreg_full(char *name,char *keyname,HKEY start) /* get keys from Registry */
{
	HKEY key;
	char value[SSLEN];
	DWORD n;
	char buf[SSLEN];


	if (RegOpenKeyEx(start, keyname, 0,
			 KEY_ALL_ACCESS, &key) != ERROR_SUCCESS) {
	  sprintf(buf, "Could not open registry key %s: %s", keyname, last_error());
	  logit(buf);
	  return NULL;
	}
	n = SSLEN;
	value[0] = '\0';
	if (RegQueryValueEx(key, name, NULL,
			    NULL, value, &n) != ERROR_SUCCESS) {
	  logit("\n");
	  sprintf(buf, "Could not set value %s in registry key %s (open was fine): %s", name, keyname, last_error());
	  logit(buf);
	  return NULL;
	}
	value[n] = '\0';
	
	return strdup(value);
}


int putreg(HKEY start, char *keyname, char *name, char *content) /* put keys into Registry */
{
	HKEY key;
	DWORD status;
	char buf2[SSLEN];
	DWORD ret;
	char *actual;
	char *hname;

	if (start == LOCAL)
	  hname = "HKEY_LOCAL_MACHINE";
	else if (start == ROOT)
	  hname = "HKEY_CLASSES_ROOT";
	else
	  hname = "unknown handle in registry";
	sprintf(buf2, "Going to set registry: handle='%s', keyname='%s', name='%s', content='%s'\n", hname, keyname, name, content);
	logit(buf2);
	/* create key in any case but ignore return value */
	ret = RegCreateKeyEx(start, keyname, 0, "", 0, KEY_QUERY_VALUE | KEY_SET_VALUE, NULL, &key, &status);
	ret = RegOpenKeyEx(start, keyname, 0, KEY_QUERY_VALUE | KEY_SET_VALUE, &key);
	if (ret == ERROR_SUCCESS) {
		ret = RegSetValueEx(key, name, 0, REG_SZ, content, strlen(content) + 1);
		if (ret == ERROR_SUCCESS) {
		  actual = getreg_full(name,keyname,start);
		  if (strcmp(content,actual)) {
		    sprintf(buf2, "Rereading set value for %s gives different result: %s\n", keyname,actual);
			logit(buf2);
			return FALSE;
		  }
		  return TRUE;
		}
		else {
			sprintf(buf2, "Could not set value: %d, %s\n", ret, last_error());
			logit(buf2);
			return FALSE;
		}
	}
	else {
		sprintf(buf2, "Could not open Registry key for writing: %d, %s\n", ret, last_error());
		logit(buf2);
		return FALSE;
	}
}
	

void end(int result) { /* display message and terminate */
	char *msg;
	int success = FALSE;
	int answer;
	char string[SSLEN];          /* multi-purpose string */
	char string2[SSLEN];
	char *se_what = NULL;  /* target for shell execute */
	char se_desc[SSLEN] = "Just exit";  /* description for shell execute */
	int se_ret = 33; /* return value okay for shell-execute*/
	int ask_run_something = FALSE;
	int ask_show_log = TRUE;
	int show_log = control_pressed;
	char *heading = INSTALL_HEADING;

	switch (result) {
	case INSTALL_CANCELLED:
		msg = "Installation cancelled.\n\n"
			"No garbage has been left.";
		ask_show_log = FALSE;
		break;
	case INSTALL_IMPOSSIBLE:
		msg = "\nInstallation failed !\n\n"
			"No garbage has been left.";
		break;
	case INSTALL_FAILURE:
		msg = "\nInstallation failed !\n"
			"Some garbage has been left in the system.\n\n"
			"To clear up, you better remove Yabasic through its entry in control-panel, section software.";
		break;
	case INSTALL_ABORTED:
		msg = "\nInstallation aborted.\n"
			"Some garbage has been left in the system !\n\n"
			"To clean up, you better remove Yabasic through its entry in control-panel, section software.";
		break;
	case INSTALL_SUCCESS:
		msg = "\nInstallation completed successfully !\n\n"
			"You may now start writing Yabasic-programs.";
		success = TRUE;
		ask_run_something = TRUE;
		ask_show_log = FALSE;
		break;
	case REMOVE_SUCCESS:
		msg = "Yabasic has been removed properly !";
		success = TRUE;
		ask_show_log = FALSE;
		heading = REMOVE_HEADING;
		break;
	case REMOVE_CANCELLED:
		msg = "Cancelled. Yabasic has been left intact.";
		ask_show_log = FALSE;
		heading = REMOVE_HEADING;
		break;
	case REMOVE_FAILURE:
		msg = "\nCouldn't remove Yabasic properly !";
		heading = REMOVE_HEADING;
		break;
	case SILENT:
		success = TRUE;
		ask_show_log = FALSE;
	default:
		break;
	}

	sprintf(logs, "--Final Message: %s\n", msg);
	logit(logs);
	
	string2[0] = '\0';
	if (ask_run_something) {
		sprintf(string, "%s\n\n\nDo you want to run the demo of yabasic or read its documentation ?\n\nFor details on the installation you may also read the logfile.\n\n\nNote: These options are also available in the start-menu under 'Yabasic'", msg);
		answer = DialogBoxParam((HANDLE)this_instance,
			MAKEINTRESOURCE(IDD_ON_SUCCESS),
			(HWND)NULL, (DLGPROC)successdialog, (LPARAM) string);
		switch (answer) {
		case RUN_DEMO:
			sprintf(string2, "%s/demo.yab", installpath);
			se_what = string2;
			sprintf(se_desc, "Start the demo of yabasic: %s/%s", installpath, se_what);
			break;
		case READ_DOCU:
			sprintf(string2, "%s/yabasic.htm", installpath);
			se_what = string2;
			sprintf(se_desc, "Show the documentation of yabasic: %s/%s", installpath, se_what);
			break;
		case SHOW_LOG:
			show_log = TRUE;
			break;
		}
	}

	if (!show_log && ask_show_log) {
		sprintf(string, "%s\n\n\nDo you want to view the logfile ?\n\n\t%s\n\nYou may send it to mail@yabasic.de and I will try to help.\n", msg, logfile);
		answer = DialogBoxParam((HANDLE)this_instance,
			MAKEINTRESOURCE(IDD_ON_ERROR),
			(HWND)NULL, (DLGPROC)errordialog, (LPARAM)string);
		if (answer == SHOW_LOG) show_log = TRUE;
	}

	if (show_log) {
		se_what = logfile;
		sprintf(se_desc, "Show the setup-log of yabasic: %s", logfile);
	}

	if (!ask_run_something && !ask_show_log && result!=SILENT) {
		sprintf(string, "%s", msg);
		MyMessage(NULL, string, heading, MB_STYLE);
	}

	if (se_what) {
		se_ret = (int) ShellExecute(NULL, "open", se_what, NULL, NULL, SW_SHOWNORMAL);
		if (se_ret <= 32) {
			sprintf(string, "Could not '%s': %s", se_desc, last_error());
			MyMessage(NULL, string, "Failed to execute !", MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);
			success = FALSE;
		}
		else {
			sprintf(string, "Successfully executed: %s\n", se_desc);
			logit(string);
		}
	}

	/* close log-file */
	logit(NULL);

	exit(success ? 0 : 1);

	return;
}


char *append(char *tail) /* append tail to installpath */
{
	char *result;
	int i, t;

	i = strlen(installpath);
	t = strlen(tail);

	result = malloc(i + t + 1);
	memcpy(result, installpath, i);
	memcpy(result + i, tail, t);
	result[t + i] = '\0';

	return result;
}


int create_shell_link(LINKINFO *li, char *inst_path) /* Create a shell-link */
{
	HRESULT result;              /* return value from various calls */
	LPITEMIDLIST pidl;           /* path id */
	char path[MAX_PATH];         /* path name */
	WORD wpath[MAX_PATH];        /* string with words instead of chars */
	char string[SSLEN];          /* multi-purpose string */
	IPersistFile* ppf;           /* pointer to persist file structure */
	IShellLink* psl;             /* pointer to new shell-link */

	sprintf(logs, "About to create shell link: special_folder=%d, name_of_link=%s, name_of_file=%s,\n  description=%s, ", li->folder, li->link, li->file, li->desc);
	if (li->icon[1]) {
		sprintf(string, "name_of_icon=%s\n", li->icon);
		strcat(logs, string);
	}
	else {
		sprintf(string, "id of icon in system32.dll=%d\n", li->icon[0]);
		strcat(logs, string);
	}
	logit(logs);

	/* make filename from registry folder constant */
	result = SHGetSpecialFolderLocation(NULL, li->folder, &pidl);
	if (!SUCCEEDED(result)) {
		logit("Could not find special folder");
		return FALSE;
	}

	SHGetPathFromIDList(pidl, path);
	strcat(path, "\\");
	strcat(path, li->link);
	sprintf(logs, "Constructed path is: %s\n", path);
	logit(logs);

	/* Get a pointer to the IShellLink interface. */
	result = CoCreateInstance(&CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, &IID_IShellLink, &psl);
	if (!SUCCEEDED(result)) {
		sprintf(logs,"Could not get interface for creating shell link: %s",last_error());
		logit(logs);
		return FALSE;
	}

	/* fill link structure */
	sprintf(string, "%s%s", inst_path, li->file);
	psl->lpVtbl->SetPath(psl, string);
	psl->lpVtbl->SetDescription(psl, li->desc);
	psl->lpVtbl->SetWorkingDirectory(psl, inst_path);
	if (li->icon[1]) {
		sprintf(string, "%s%s", inst_path, li->icon);
		result = psl->lpVtbl->SetIconLocation(psl, string, 0);
	}
	else {
		GetSystemDirectory(string, SSLEN);
		strcat(string, "\\shell32.dll");
		result = psl->lpVtbl->SetIconLocation(psl, string, li->icon[0]);
	}
	
	result = psl->lpVtbl->QueryInterface(psl, &IID_IPersistFile, &ppf);
	if (!SUCCEEDED(result)) {
		sprintf(logs,"Could not get interface for persisting file link: %s", last_error());
		logit(logs);
		return FALSE;
	}

	/* Ensure that the string is ANSI. */
	MultiByteToWideChar(CP_ACP, 0, path, -1, wpath, MAX_PATH);
	
	result = ppf->lpVtbl->Save(ppf, wpath, TRUE);
	ppf->lpVtbl->Release(ppf);

	if (!SUCCEEDED(result)) {
		sprintf(logs,"Could not save shell link: %s", last_error());
		logit(logs);
		return FALSE;
	}
	psl->lpVtbl->Release(psl);

	logit("Done.\n");
	return TRUE;
}


HRESULT delete_shell_link(LINKINFO *li) /* Delete a shell-link */
{
	HRESULT result;              /* return value */
	LPITEMIDLIST pidl;           /* path id */
	char path[MAX_PATH];         /* path name */

	sprintf(logs, "About to delete shell link: special_folder=%d, name_of_link=%s, name_of_file=%s, description=%s\n", li->folder, li->link, li->file, li->desc);
	logit(logs);

	/* make filename from folder constant */
	result = SHGetSpecialFolderLocation(NULL, li->folder, &pidl);
	if (!SUCCEEDED(result)) {
		logit("Could not get special folder location");
		return FALSE;
	}

	SHGetPathFromIDList(pidl, path);
	strcat(path, "\\");
	strcat(path, li->link);

	if (DeleteFile(path)) {
		return TRUE;
	}
	else {
		sprintf(logs, "Could not delete file %s: %s", path, last_error());
		return FALSE;
	}
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
		strcat(PathLink, "\\Yabasic");
		progress("Creating folder in start menu");
		success = makedir(PathLink) && success;
	}
	while (li = enumlinks(NEXT)) {
		if (mode == INSTALL) {
			if (!li->removeonly) {
				sprintf(string, "Adding shell-link %s", li->desc);
				progress(string);
				success = create_shell_link(li, installpath) && success;
			}
		}
		else {
			sprintf(string, "Removing shell-link desc=%s", li->desc);
			progress(string);
			success = delete_shell_link(li) && success;
		}
	}
	if (mode != INSTALL) {
		/* make filename from registry folder constant */
		SHGetSpecialFolderLocation(NULL, CSIDL_PROGRAMS, &pidl);
		SHGetPathFromIDList(pidl, PathLink);
		strcat(PathLink, "\\Yabasic");
		progress("Removing folder in start menu");
		res = RemoveDirectory(PathLink);
		sprintf(string, "Removing directory '%s': result = %d\n%s", PathLink, res, last_error());
		logit(string);
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
			success = copy_file(string, append(name), here) && success;
			sprintf(string, "Copying '%s'", name);
			progress(string);
		}
		break;
	case REMOVE:
		enumfiles(RESET);

		while (name = enumfiles(NEXT)) {
			if (!DeleteFile(append(name))) failures++;
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
	char notepad[SSLEN];  /* full path for notepad */
	char buf[SSLEN];

	switch (mode) {
	case INSTALL:
		/* registering uninstall program */
		progress("Registering uninstall-program");
		success = putreg(LOCAL, UNINSTALL "Yabasic", "DisplayName", "Yabasic");
		sprintf(string, "%s%s %s", installpath, "setup.exe", "remove");
		success = putreg(LOCAL, UNINSTALL "Yabasic", "UninstallString", string) && success;
		sprintf(string,"%d.%d.%d",newversion.major, newversion.minor, newversion.patch);
		success = putreg(LOCAL, UNINSTALL "Yabasic", "DisplayVersion", string) && success;		
		success = putreg(LOCAL, UNINSTALL "Yabasic", "Publisher", "Marc Ihm") && success;		
		/* make changes in registry, put in defaults */
		progress("Setting registry");
		sprintf(string, "%s", formatsemver(&newversion, buf));
		
		success = putreg(LOCAL, SOFT "Yabasic", "path",			installpath) && success;
		success = putreg(LOCAL, SOFT "Yabasic", "librarypath",	librarypath) && success;
		success = putreg(LOCAL, SOFT "Yabasic", "font",			"swiss13") && success;
		success = putreg(LOCAL, SOFT "Yabasic", "foreground",	"0,0,0") && success;
		success = putreg(LOCAL, SOFT "Yabasic", "background",	"255,255,255") && success;
		success = putreg(LOCAL, SOFT "Yabasic", "geometry",		"+10+10") && success;
		success = putreg(LOCAL, SOFT "Yabasic", "version",		string) && success;

		progress("Registering file extension");
		/* change context-menue of root window */
		success = putreg(ROOT, ".yab", "", "Yabasic") && success;
		progress("Setting context menu of root-window");
		success = putreg(ROOT, "yabasic", "", "Yabasic Program") && success;
		success = putreg(ROOT, "Yabasic\\DefaultIcon", "", append("yabico.ico")) && success;
		success = putreg(ROOT, ".yab\\ShellNew", "NullFile", "") && success;
		success = putreg(ROOT, "Yabasic\\shell\\open", "", "&Execute") && success;
		success = putreg(ROOT, "Yabasic\\shell\\open\\command", "",
			append("yabasic.exe \"%1\" \"%2\" \"%3\" \"%4\" \"%5\" \"%6\" \"%7\" \"%8\" \"%9\"")) && success;

		success = putreg(ROOT, "Yabasic\\shell\\Edit", "", "&Edit") && success;
		GetWindowsDirectory(string, SSLEN);
		sprintf(notepad, "%s%s", brushup(string), "Notepad.exe \"%1\"");
		success = putreg(ROOT, "Yabasic\\shell\\Edit\\command", "", notepad)
			&& success;
		/* printing of embedded docu */
		success = putreg(ROOT, "Yabasic\\shell\\ViewDocu", "", "&View docu") && success;
		success = putreg(ROOT, "Yabasic\\shell\\ViewDocu\\command", "",
			append("yabasic.exe \"-doc_%1\"")) && success;

		return success;
	case REMOVE:
		progress("Removing entries in registry");
		delreg(ROOT, ".yab", "");
		delreg(ROOT, "Yabasic", "");
		delreg(LOCAL, SOFT "Yabasic", "");
		delreg(LOCAL, UNINSTALL "Yabasic", "");
	}
	return success;
}


BOOL CALLBACK progressdialog(HWND handle, UINT message,
	WPARAM wparam, LPARAM lparam)
	/* callback for cprogress dialog */
{

	switch (message) {
	case WM_INITDIALOG:
		center_dialog(handle);
		return TRUE;
	default:
		break;
	}
	return FALSE;
}


void progress(char *msg) /* show progress */
{
	RECT rc;
	static int count = 0;
	static HWND progressbox = NULL;   /* handle of progress dialog */
	static HWND hwndPB = NULL; /* handle of progress bar */
	char string[SSLEN];             /* multi-purpose string */
	char *title_clause;
	int thumb;  /* height of scroll bar arrow */

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

	control_pressed = control_pressed || (GetAsyncKeyState(VK_CONTROL) < 0);
	title_clause = control_pressed ? ", logfile pending" : "";

	/* set heading of progress window */
	sprintf(string, "Work in progress%s ... step %d", title_clause, count);
	SendMessage((HWND)progressbox, (UINT)WM_SETTEXT, 0, (LPARAM)(LPCTSTR)string);

	/* wait to let the user notice */
	Sleep(200);
}


int copy_file(char *name, char *dest, int here) /* copy files */
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
	  sprintf(string, "Failed to copy '%s' to '%s': %s", name, dest, last_error());
	  MyMessage(NULL, string, INSTALL_HEADING, MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);
	}
	return ret;
}

char *last_error() /* get last error as string */
{
	static char text[SSLEN];
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), text, SSLEN, NULL);
	return text;
}

char *enumfiles(int mode) /* give filenames, one after another */
{
	static int num = 0;

	if (mode == RESET) {
		num = 0;
		return NULL;
	}

	num++;

	if (num == 1) return strdup("setup.exe");
	if (num == 2) return strdup("yabico.ico");
	if (num == 3) return strdup("yabasic.exe");
	if (num == 4) return strdup("demo.yab");
	if (num == 5) return strdup("readme.txt");
	if (num == 6) return strdup("yabasic.htm");
	if (num == 7) return strdup("LICENSE.txt");

	return NULL;
}


LINKINFO *enumlinks(int mode) /* give back linkinfos, one after another */
{
	static int num = 0;

	/* Fields of structure LINKINFO */
	/* registry key,			name of link;				name of file;		description of link;	name of icon for link;  true, if icon should be removed but not installed */
	static LINKINFO li[] = {
	 {CSIDL_PROGRAMS,			"Yabasic\\Yabasic.lnk",		"yabasic.exe",		"Link to Yabasic",		"yabico.ico",			FALSE},
	 {CSIDL_PROGRAMS,			"Yabasic.lnk",				"yabasic.exe",		"Link to Yabasic",		"yabico.ico",			TRUE},
	 {CSIDL_PROGRAMS,			"Yabasic\\demo.lnk",		"demo.yab",			"Link to demo.yab",		"\025",					FALSE},
	 {CSIDL_DESKTOPDIRECTORY,	"demo.lnk",					"demo.yab",			"Link to demo.yab",		"yabico.ico",			FALSE},
	 {CSIDL_PROGRAMS,			"Yabasic\\docu.lnk",		"Yabasic.htm",		"Link to Yabasic.htm",  "\026",					FALSE},
	 {CSIDL_DESKTOPDIRECTORY,	"docu.lnk",					"Yabasic.htm",		"Link to Yabasic.htm",   "yabico.ico",			FALSE}
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
	char string[SSLEN];
	static int oldtime;

	/* open log-file */
	if (!log) {
		sprintf(logfile, "%s%s", temppath, "yabasic-setup.txt");
		log = fopen(logfile, copied ? "a" : "w");
		if (!log) {
			sprintf(string, "Could not open logfile '%s': %s", logfile, last_error());
			MyMessage(NULL, string, INSTALL_HEADING, MB_STYLE);
			end(INSTALL_IMPOSSIBLE);
		}
		if (log) {
			fprintf(log, "\n\n\n---------------------------------------------------\n"
				"Starting installation-log: %s\n%s\n\n",
				current_time(), logfile);
			oldtime = GetCurrentTime();
		}
	}

	if (log) {
		if (GetCurrentTime() - oldtime > 10000) {
			fprintf(log, "Timestamp: %s\n", current_time());
			oldtime = GetCurrentTime();
		}
		if (text) {
			if (strncmp(text, "--", 2)) fprintf(log, "  ");
			while (*text) {
				fputc(*text, log);
				if (*text == '\n' && *(text + 1)) fprintf(log, "  ");
				text++;
			}
		}
		else {  /* not text ... */
   		        fprintf(log, "Closing installation-log: %s\n%s\n",current_time(), logfile);
			fflush(log);
			fclose(log);
		}
	}
	if (log) fflush(log);
}


char *current_time() /* get current time as string */
{
	SYSTEMTIME time;         /* time */
	static char text[SSLEN];

	GetLocalTime(&time);
	sprintf(text, "%d-%02d-%02d, %02d:%02d:%02d:%03d",
		time.wYear, time.wMonth, time.wDay,
		time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);
	
	return text;
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


BOOL is_elevated()
/* Check, if program is running with elevated privs */
{
  BOOL fRet = FALSE;
    HANDLE hToken = NULL;
    if( OpenProcessToken( GetCurrentProcess( ),TOKEN_QUERY,&hToken ) ) {
        TOKEN_ELEVATION Elevation;
        DWORD cbSize = sizeof( TOKEN_ELEVATION );
        if( GetTokenInformation( hToken, TokenElevation, &Elevation, sizeof( Elevation ), &cbSize ) ) {
            fRet = Elevation.TokenIsElevated;
        }
    }
    if( hToken ) {
        CloseHandle( hToken );
    }
    return fRet;
}


void log_os_info()
/* Write Windows Version to logfile */
{
    OSVERSIONINFOEX info;
    ZeroMemory(&info, sizeof(OSVERSIONINFOEX));
    info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    GetVersionEx(&info);

    sprintf(logs,"--Windows Version: %u.%u\n", info.dwMajorVersion, info.dwMinorVersion);
    logit(logs);
}
