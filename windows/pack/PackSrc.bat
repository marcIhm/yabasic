echo off
rem
rem  Pack the source distribution of Yabasic
rem

rem Create the archive
C:\Kits\Zip-Unzip\Zip\zip YabSrc.zip -j -D -@ <YabSrc.txt

rem Glue self extractor and zip archive together
copy /b /Y C:\Kits\Zip-Unzip\Unzip\unzipsfx.exe+YabSrc.zip yabsrc.exe

rem Adjust archive
C:\Kits\Zip-Unzip\Zip\zip -A yabsrc.exe

rem move zip
move /Y yabsrc.exe E:\html\homepage\download

echo Done.

