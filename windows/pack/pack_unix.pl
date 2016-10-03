#
# Pack and check a new distribution of yabasic
#

use IPC::Open3;
use Time::Local;

# Variables, that can be configured
$homepagedir="E:\\Html\\Homepage\\download";
$projectdir="E:\\Projekte\\Yabasic";

# files to copy from floppy
@fromlist=("yabasic.htm",
	   "yabasic.c",
	   "yabasic.h");

# files to copy to floppy
@tolist=("yab.tar.Z",
	 "yablinux.tar.Z",
	 "$sourcedir/yabasic.c",
	 "$sourcedir/yabasic.h",
	 "$sourcedir/bison.c",
	 "$sourcedir/bison.h",
	 "$sourcedir/flex.c",
	 "$sourcedir/yabasic.htm",
	 "$sourcedir/yabasic.bison",
	 "$sourcedir/yabasic.flex",
);
# list of files, that need to be renamed 
%torename=("yabasic.flex"=>"flex.txt",
	   "yabasic.bison"=>"bison.txt");
# list of files, that need non default options for mcopy
%tooptions=("yab.tar.Z"=>"",
	    "yablinux.tar.Z"=>"");

# content of sourcepack
@sourcepack=("COPYING",
	     "Makefile.in",
	     "README",
	     "pack",
	     "animals.yab",
	     "bison.c",
	     "bison.h",
	     "configure",
	     "configure.in",
	     "flex.c",
	     "prime.yab",
	     "rotate.yab",
	     "runme",
	     "test.yab",
	     "yabasic.bison",
	     "yabasic.c",
	     "yabasic.flex",
	     "yabasic.h",
	     "yabasic.htm");

# name of sourcepack
$spackfile="yab.tar";

# contents of linuxpack
@linuxpack=("COPYING",
	    "README",
	    "yabasic",
	    "animals.yab",
	    "prime.yab",
	    "rotate.yab",
	    "test.yab",
	    "yabasic.htm");

# name of linuxpack
$lpackfile="yablinux.tar";

# Autoflush stdout
$|=1;

# Check date of files
print "\nChecking Files:\n";
# read content of floppy
open(MDIR,"mdir |") || die "Need a floppy !\n";
while(<MDIR>) {
    if (/\s*\S+\s+\S+\s*(\d+)\s+(\d+)-(\d+)-(\d+)\s+(\d+):(\d+)(\S)?\s+(\S+)/) {
	($size,$mon,$day,$year,$hr,$min,$pm,$name)=($1,$2,$3,$4,$5,$6,$7,$8);
	$hr+=12 if ($pm eq "p" and $hr!=12);
	$year-=1900;
	$mon--;
	$fromtime{$name}=timelocal(0,$min,$hr,$day,$mon,$year);
    }
}
# compare with local files
for $name (@fromlist) {
    $totime=(stat($name))[9];
    if (!exists($fromtime{$name})) {
	print "WARNING: Can't find $name on floppy !\n";
	next;
    }
    if ($fromtime{$name}>$totime+120) {
	$diff=$fromtime{$name}-$totime;
	$difft=$diff." sec";
	$difft=sprintf("%g",($diff/60))." min" if ($diff>60*2);
	$difft=sprintf("%g",($diff/3600))." hours" if ($diff>3600*2);
	$difft=sprintf("%g",($diff/86400))." days" if ($diff>86400*2);
	print "$name is $difft newer on floppy, need to copy ... ";
	$command="mcopy -tn a:$name $name 2>/dev/null";
	if (system($command)) {
	    print "error !\n";
	    exit;
	}
	else {
	    print "done.\n";
	    $copied++;
	}
    }
}

if ($copied) {
    print "\nCopied $copied file(s), you better recompile ...\n\n";
    exit;
}
print "All files are up to date.\n";

# Crosscheck Versions
print "\nChecking versions:\n";
open3(*WRT,*RDR,*ERR,"$yabexe -?") || die "Can't open $yabexe\n";
while(<ERR>) {
    if (/yabasic\s*(\d\.\d{1,2}),/) {
	$exever=$1;
	print "  $exever ($yabexe)\n";
	last;
    }
}
die "Can't get version from $yabexe\n" if (!defined($exever));

open(RDR,$yabsrc) || die "Can't open $yabsrc\n";
while(<RDR>) {
    if (/#define\s*BASIC_VERSION\s*\"(\d\.\d{1,2})\"/) {
	$sourcever=$1;
	print "  $sourcever ($yabsrc)\n";
	last;
    }
}
die "Can't get version from $yabsrc\n" if (!defined($sourcever));

open(RDR,$yabdoku) || die "Can't open $yabdoku\n";
while(<RDR>) {
    if (/Current Version:\s*(\d\.\d{1,2})/) {
	$dokuver=$1;
	print "  $dokuver ($yabdoku)\n";
	last;
    }
}
die "Can't get version from $yabdoku\n" if (!defined($dokuver));

if ($exever eq $dokuver && $dokuver eq $sourcever) {
    print "Okay.\n";
}
else {
    print "Mismatch !\n";
    die "Better go and bring them in line\n";
}

# create and compress sourcepack
$sourcelist="";
for $source (@sourcepack) {
    $sourcelist.="$sourcedir/$source ";
}
$command="cd .. ; rm -f $spackfile; tar cf $spackfile $sourcelist 2>/dev/null";
print "\nCreating tar archive with sources ... ";
if (system($command)) {
    print "error !\n";
    print "Command has been:\n\n$command\n\n";
    exit;
}
else {
    print "done.\n";
}
print "Compressing tar archive ... ";
$command="cd .. ; compress -f $spackfile";
if (system($command)) {
    print "error !\n";
    print "Command has been:\n\n$command\n\n";
    exit;
}
else {
    print "done.\n";
}

# create and compress linuxpack
$linuxlist="";
print "\nCopying files to $linuxdir ... ";
for $linux (@linuxpack) {
# copy file to linuxdir
    if ($linux ne "README") {
	$command="cd ..; cp -f $sourcedir/$linux $linuxdir/$linux";
	if (system($command)) {
	    print "error !\n";
	    print "failed for: $linux\n";
	    exit;
	}
    }
    $linuxlist.="$linuxdir/$linux ";
}
print "done.\n";

$command="cd .. ; rm -f $lpackfile; tar cf $lpackfile $linuxlist 2>/dev/null";
print "Creating tar archive with linux binaries ... ";
if (system($command)) {
    print "error !\n";
    print "Command has been:\n\n$command\n\n";
    exit;
}
else {
    print "done.\n";
}
print "Compressing tar archive ... ";
$command="cd .. ; compress -f $lpackfile";
if (system($command)) {
    print "error !\n";
    print "Command has been:\n\n$command\n\n";
    exit;
}
else {
    print "done.\n";
}

# copy everything to floppy
print "\nFormatting floppy ... ";
$command="mformat a:";
if (system($command)) {
    print "error !\n";
    exit;
}
else {
    print "done.\n";
}
print "Copying files to floppy ";
for $name (@tolist) {
    $rename=0;
    $sopt=0;
    $pos=rindex($name,"/");
    if ($pos>0) {
	$shortname=substr($name,$pos+1);
    }
    else {
	$shortname=$name;
    }
    if (exists($torename{$shortname})) {
	$shortname=$torename{$shortname};
	$rename=2;
    }
    if (exists($tooptions{$shortname})) {
	$opt=$tooptions{$shortname};
	$sopt=1;
    }
    else {
	$opt="-t";
    }
    $command="cd ..; mcopy $opt $name a:$shortname";
    if (system($command)) {
	print "... error !\n";
	print "Command has been:\n\n$command\n\n";
	exit;
    }
    print substr(".orb",$rename+$sopt,1);
}
print " done.\n";
