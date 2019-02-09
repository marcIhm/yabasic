
bin_PROGRAMS = yabasic
yabasic_SOURCES = main.c function.c io.c graphic.c symbol.c flow.c flex.c bison.c whereami.c yabasic.h bison.h whereami.h
man_MANS = yabasic.1
LDADD = @X_PRE_LIBS@ -lm @LIBS@ -lX11 @X_LIBS@ @X_EXTRA_LIBS@
AM_CPPFLAGS = -DUNIX $(X_CFLAGS)
EXTRA_DIST = runme yabasic.htm yabasic.flex yabasic.bison tests configure.ac LICENSE demo.yab $(man_MANS)
AUTOMAKE_OPTIONS = check-news subdir-objects
TESTS = tests/break.yab tests/bugs.yab tests/grammar.yab tests/io.yab tests/long_variable_name.yab tests/simple.yab tests/switch_continue_break.yab tests/switch_for.yab tests/switch_gosub.yab tests/switch_goto.yab tests/switch_return.yab tests/switch_simple.yab tests/switch_subr.yab tests/switch.yab tests/numbers.yab tests/system.yab tests/string.yab tests/silent.sh tests/run_in_script.sh tests/inkey.sh tests/print-at.sh tests/nested_import.yab

# flags for flex (-d for debugging)
flexflags = -i -I -L -s

# create scanner and remove include for unistd.h (needed for windows)
flex: yabasic.flex Makefile
	flex $(flexflags) -t yabasic.flex >flex.c
#	perl -i -n -e 'if (!/^\#include\s+<unistd.h>\s+$$/) {print if $$i;$$i++}' flex.c

# flags for bison (-t -v for debugging)
bisonflags = -d -l -t -v

bison: yabasic.bison Makefile
	bison $(bisonflags) --output-file bison.c yabasic.bison
