#
# Pack and check a new distribution of yabasic
#

use IPC::Open3;
use File::Copy;

# Variables, that can be configured
$homepagedir="C:\\Users\\Marc-Oliver\\Eigene Websites\\yabasic";
$downloaddir=$homepagedir."\\download";
$workspacedir="C:\\Users\\Marc-Oliver\\Documents\\yabasic\\Windows\\Yabasic (Arbeitsbereich)";
$sourcedir=$workspacedir."\\Yabasic (Projekt)";
$yabexedir=$sourcedir."\\Release";
$setupsrcdir=$workspacedir."\\Yabasic Setup (Projekt)";
$setupexedir=$setupsrcdir."\\Release";
$zipexe="C:\\Program Files (x86)\\7-Zip\\7z.exe";
$sfxexe="C:\\Program Files (x86)\\7-Zip SFX Maker\\7-ZIP SFX Maker.exe";
$sfxresult="yabbin.sfx.exe";
$tempdir="C:\\Users\\Marc-Oliver\\AppData\\Local\\Temp";
$yabpackdir="C:\\Users\\Marc-Oliver\\Documents\\yabasic\\Windows\\YabPack";
$sharedldir="C:\\VMWare\\shared\\yabasic-exchange\\from_linux";
$sharedwdir="C:\\VMWare\\shared\\yabasic-exchange\\from_windows";

# files to copy from shared directory
%fromlist=("yabasic.*\\.tar\\.gz"=>$downloaddir,
	   "yabasic.*\\.rpm"=>$downloaddir,
	   "main\\.c"=>$sourcedir,
	   "io\\.c"=>$sourcedir,
	   "graphic\\.c"=>$sourcedir,
	   "function\\.c"=>$sourcedir,
	   "symbol\\.c"=>$sourcedir,
	   "yabasic\\.h"=>$sourcedir,
	   "bison\\.c"=>$sourcedir,
	   "bison\\.h"=>$sourcedir,
	   "config\\.h"=>$sourcedir,
	   "flex\\.c"=>$sourcedir,
	   "bison\\.txt"=>$sourcedir,
	   "yabasic\\.htm"=>$homepagedir,
	   "news\\.txt"=>$homepagedir,
	   "flex\\.txt"=>$sourcedir);

# files to copy to shared directory
%tolist=("main.c"=>$sourcedir,
	 "io.c"=>$sourcedir,
	 "graphic.c"=>$sourcedir,
	 "function.c"=>$sourcedir,
	 "symbol.c"=>$sourcedir,
	 "yabasic.h"=>$sourcedir);

# source or html files with version information
%verdir=("yabasic.htm"=>$homepagedir,
	 "head.html"=>$homepagedir,
	 "config.h"=>$sourcedir,
	 "yabasic.exe"=>$yabexedir);
%vermatch=("yabasic.htm"=>"(2)\\.(\\d+)",
	   "head.htm"=>"(2)\\.(\\d+)",
	   "config.h"=>"\\s*#define\\s+VERSION\\s+\"(\\d)\\.(\\d+)\"",
	   "yabasic.exe"=>"yabasic\\s+(\\d)\\.(\\d+)");

# files of binary distribution
@binfiles=("$yabexedir\\yabasic.exe",
	   "$setupexedir\\setup.exe",
   	   "$yabpackdir\\Dist\\Readme.txt",
	   "$yabpackdir\\Yabver.txt",
	   "$yabpackdir\\source\\yabico.ico",
	   "$homepagedir\\yabasic.htm",
	   "$yabpackdir\\Dist\\demo.yab");

# files of source distribution
@srcfiles=("$setupsrcdir\\yabinst.rc",
	   "$setupsrcdir\\yabinst.c",
	   "$setupsrcdir\\setup.dsp",
	   "$setupsrcdir\\resource.h",
	   "$yabpackdir\\source\\yabico.ico",
	   "$sourcedir\\yabasic.dsp",
	   "$sourcedir\\config.h",
	   "$yabpackdir\\source\\readme.txt",
	   "$yabpackdir\\pack.pl");

# positions within download, which must be changed
@download=('(<a\s*href="download/yabasic-)(\d\.\d+)(-1\.i586\.rpm">)',
	   '(>\s*yabasic-)(\d\.\d+)(-1\.i586\.rpm\s*</a>)',
	   '(<a\s*href="download/yabasic-)(\d\.\d+)(\.tar\.gz">)',
	   '(>\s*yabasic-)(\d\.\d+)(\.tar\.gz\s*</a>)',
	   '(<a\s*href="download/yabasic-)(\d\.\d+)(-setup\.exe">)',
	   '(>\s*yabasic-)(\d\.\d+)(-setup\.exe\s*</a>)',
	   '(<a\s*href="download/yabasic-)(\d\.\d+)(-src\.zip">)',
	   '(>\s*yabasic-)(\d\.\d+)(-src\.zip\s*</a>)'
	   );


# Autoflush stdout
$|=1;

# Check date of files
print "\nCopying Files:\n";
# generate directory of disk ...
@dir=split(/\n/,qx(dir /b $sharedldir));
for $ff (keys(%fromlist)) {
    $file=lc($ff);
    for $f (@dir) {
	$file=lc($f) if ($f=~/^$ff$/i);
    }
    $fromfile="$sharedldir\\$file";
    $fromtime=(stat($fromfile))[9];
    $tofile="$fromlist{$ff}\\$file";
    $totime=(stat($tofile))[9];
    if ($fromtime>$totime+120) {
	if ($totime) {
	    print "  $tofile (",$fromtime-$totime," sec newer)\n";
	} else {
	    print "  $tofile (nonexistent)\n";
	}
	$copied++;
	if (!copy($fromfile,$tofile)) {
	    print " error !\n";
	    print "Couldn't copy $fromfile to $tofile\n";
	    <STDIN>;
	    exit;
	}
    }
}
if (!$copied) {
    print "done.\nAll files are up to date.\n";
}
else {
    print "done.\n";
    print "\nCopied some files, better recompile.\n";
    <STDIN>;exit;
}

# check versions
print "\nChecking versions:\n";
for $file (keys(%verdir)) {
    $fullname="$verdir{$file}\\$file";
    if (!open(YAB,$fullname)) {print "\nCouldn't open $fullname\n";<STDIN>;exit;}
    $found=0;
    binmode(YAB);
    while(<YAB>) {
	if (/$vermatch{$file}/im) {
	    $ver="$1.$2";
	    $ver=$ver*1;
	    if ($file =~ /^yabasic.html?$/) {
		$htmlver=$ver;
		$html.="0" if $htmlver=~/\.\d\d$/;
	    } else {
	    	$version{$ver}=$file;
		$otherver=$ver;
		$otherver.="0" if $otherver=~/\.\d\d$/;
	    }
	    $found=1;
	    print "  $ver ($file)\n";
	    $file2ver{$file}=$ver;
	    last;
	}
    }
    if (!$found) {
	print "\nCouldn't get Version from $fullname\n";<STDIN>;exit;
    }
    close(YAB);
}
if (scalar(keys(%version))>2 || abs($htmlver-$otherver)>=0.01) {
    print "They don't match, better bring them in line ($htmlver<>$otherver) !\n";
    <STDIN>;
    exit;
}
if (!$file2ver{"yabasic.exe"}) {
    print "Did not find version of yabasic.exe (%file2ver)!\n";
    <STDIN>;
    exit;
}
if ($file2ver{"config.h"}!=$file2ver{"yabasic.exe"}) {
    print "config.h and yabasic.exe do not have the same version !\n";
    <STDIN>;
    exit;
}
print "They match.\n";
open(YAB,"> Yabver.txt") || die "Couldn't open Yabver.txt\n";
print YAB $ver,"\n";
close(YAB);
print "Press <RETURN> to proceed ...";<STDIN>;

# adjust download page
print "\nBringing download page up to date ";
$d="$homepagedir\\download.html";
open DOWN,"$d" or die "Could not open $d for reading !\n";
while(<DOWN>) {$dd.=$_;};
for $down (@download) {
    if ($dd=~s/$down/$1$otherver$3/m) {
	print ".";
	$count++;
    } else {
	push @failed,$down;
    }
}
if ($count==$#download+1) {
    print " done.\n";
} else {
    print "... FAILURE !\n\nThese patterns did not match:\n",join("\n",@failed),"\n";
    <STDIN>;exit;
}
open DOWN,">$d" or die "Could not open $d for writing !\n";
print DOWN $dd;
close DOWN;

print "\nCopying files to shared directory $sharedwdir\n";
for $file (keys(%tolist)) {
    $fromdir=$tolist{$file};
    if (!copy("$fromdir\\$file","$sharedwdir\\$file")) {
	print "\n\nERROR !\n\n";
	print "Couldn't copy $fromdir\\$file to $sharedwdir: $!\n";
	<STDIN>;
	exit;
    } else {
	print "  $file\n";
    }
}
print "done.\n";
print "Press <RETURN> to proceed ...";<STDIN>;

print "\nPacking binaries:\n";
system("del $tempdir\\yabbin.zip");
system("\"$zipexe\" a \"$tempdir\\yabbin.7z\" \"".join("\" \"",@binfiles)."\"");
print "Creating selfextracting archive.\n";
print "Press <RETURN> to launch sfx-maker, please remember to load settings ...";<STDIN>;
system("\"$sfxexe\" \"$tempdir\\yabbin.7z\"");
system("dir \"$tempdir\\$sfxresult\"");
print "Press <RETURN> to proceed ...";<STDIN>;
sleep 2;
system("move /Y \"$tempdir\\$sfxresult\" \"$downloaddir\\yabasic-$otherver-setup\.exe\"");
print "done.\n";

print "\nPacking sources:\n";
system("del $tempdir\\yabsrc.zip");
system("\"$zipexe\" a $tempdir\\yabsrc.zip \"".join("\" \"",@srcfiles)."\"");
system("move /Y \"$tempdir\\yabsrc.zip\" \"$downloaddir\\yabasic-$otherver-src.zip\"");
print "done.\n";

print "\nProgram done, press <RETURN>.\n";
<STDIN>;
exit;
