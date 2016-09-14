echo off
rem
rem  Pack the binary distribution of Yabasic
rem

rem Create the archive
C:\Kits\Zip-Unzip\Zip\zip YabBin.zip -j -D -@ <YabBin.txt

rem Glue self extractor and zip archive together
copy /b /Y C:\Kits\Zip-Unzip\Unzip\unzipsfx.exe+YabBin.zip yabbin.exe

rem Adjust archive
C:\Kits\Zip-Unzip\Zip\zip -A yabbin.exe

rem move zip
move /Y yabbin.exe E:\html\homepage\download

echo Done.


