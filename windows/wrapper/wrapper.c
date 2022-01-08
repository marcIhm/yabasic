/*

  Simple wrapper for setup.exe of yabasic, invoked from iexpress.
  This wrapper is needed because setup.exe requires admin privileges
  but iexpress refuses to start such a program.
  Copyright by Marc Ihm 1996-2022
  
  This file is part of yabasic and may be copied under the terms of
  MIT License which can be found in the file LICENSE.
  
  See www.yabasic.de for details.

*/

/*----------- includes -------------*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

/*------------ main program --------------*/

int WINAPI WinMain(HINSTANCE _this_instance,
	HINSTANCE prev_instance,
	LPSTR commandline,
	int win_state)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	char path[MAX_PATH];
	int ret;
	char *slash;
	SHELLEXECUTEINFO ShExecInfo = { 0 };

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	GetModuleFileName(NULL, path, MAX_PATH);
	for (slash = path + strlen(path); *slash != '\\' && *slash != '/' && slash >= path; slash--) {}
	strcpy(slash + 1, "setup.exe");

	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = "runas";
	ShExecInfo.lpFile = path;
	ShExecInfo.lpParameters = "";
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_SHOWNORMAL;
	ShExecInfo.hInstApp = NULL;

	if (ShellExecuteEx(&ShExecInfo)) {
		WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
	}
	else {
		char string[512];
		char string2[512];

		ret = GetLastError();
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, ret,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), string, 512, NULL);
		sprintf(string2, "Could not start setup.exe for yabasic: %d, %s", ret, string);
		MessageBoxEx(NULL, string2, "Install yabasic !",
			MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));
	}
}

