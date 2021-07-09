#
# This script runs itself as admin (if it does not already have those privs)
#
# See: https://stackoverflow.com/questions/7690994/running-a-command-as-administrator-using-powershell
# 
if (!([Security.Principal.WindowsPrincipal][Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)) {
    Start-Process PowerShell -Verb RunAs "-NoProfile -ExecutionPolicy Bypass -Command `"cd '$pwd'; & '$PSCommandPath';`"";
    exit;
}
iexpress.exe /N yabasic-setup.SED
