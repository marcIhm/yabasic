
dnl  Process this file with 'autoconf' to get a configure-script

AC_INIT([yabasic], [2.79.1])
AC_CONFIG_SRCDIR([main.c])
#AC_CONFIG_LINKS
AM_INIT_AUTOMAKE
LT_INIT

dnl --- get canonical system name ---
AC_CANONICAL_HOST

dnl --- find out, which c-compiler is available ---
AC_PROG_CC

dnl --- set options appropriate for compiler ---
AC_CHECK_PROG(CCOPTIONS,gcc,-Wall,)

dnl --- check for X-Window system ---
AC_PATH_XTRA
AS_IF([test "X$no_x" = "Xyes"],[AC_MSG_WARN([Could not find X11 header files; please install libx11-devel or similar.])])

dnl --- check for required headers ---
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([fcntl.h limits.h stddef.h stdlib.h stdio.h float.h\
                  math.h time.h sys/time.h string.h strings.h Intrinsic.h\
                  unistd.h signal.h ctype.h malloc.h sys/prctl.h],,\
		  AC_MSG_WARN([Header file is missing (see above)]))
AC_CHECK_HEADERS([string.h strings.h])

dnl --- check for typedefs, structures, and compiler characteristics ---
AC_C_CONST
AC_TYPE_SIZE_T
AC_HEADER_TIME

dnl --- check for library functions ---
AC_FUNC_ERROR_AT_LINE
AC_FUNC_FORK
AC_FUNC_SELECT_ARGTYPES
AC_TYPE_SIGNAL
AC_FUNC_STRFTIME
AC_FUNC_STRTOD
AC_FUNC_SETPGRP
AC_FUNC_STAT
AC_CHECK_FUNCS([floor pow select sqrt strchr strerror strpbrk strrchr strstr mkstemp])

dnl --- check for header files ---
AC_CHECK_HEADER(string.h,AC_DEFINE(HAVE_STRING_HEADER,1,[defined, if string.h is present]))
AC_CHECK_HEADER(strings.h,AC_DEFINE(HAVE_STRINGS_HEADER,1,[defined, if strings.h is present]))

dnl --- check for curses.h
AC_CHECK_HEADER(ncurses.h,AC_DEFINE(HAVE_NCURSES_HEADER,1,[defined, if ncurses.h is present]))
AC_CHECK_HEADER(curses.h,AC_DEFINE(HAVE_CURSES_HEADER,1,[defined, if ncurses.h is present]))
AS_IF([test "X$ac_cv_header_curses_h" = "Xno" && test "X$ac_cv_header_curses_h" = "Xno"],[AC_MSG_WARN([Could not find curses or ncurses header files; please install ncurses-devel.])])

dnl --- check if curses library is available ---
AC_CHECK_LIB(ncurses,initscr)
AC_CHECK_LIB(curses,initscr)

dnl --- check for specific functions within ncurses
AC_CHECK_FUNCS(getnstr)

dnl --- check for specific functions ---
AC_CHECK_FUNCS(setitimer)
AC_CHECK_FUNCS(difftime)

dnl --- check for <alloca.h>
AC_FUNC_ALLOCA

dnl --- architecture of build machine ---
AC_DEFINE_UNQUOTED(UNIX_ARCHITECTURE,"$host",[architecture of build machine])

dnl --- build-time, that will be displayed in banner ---
AC_DEFINE_UNQUOTED(BUILD_TIME,"`date -u -d @$SOURCE_DATE_EPOCH 2>/dev/null || date -u -r $SOURCE_DATE_EPOCH 2>/dev/null || date -u`",[build-time, that will be displayed in banner])

dnl --- write out results ---
AC_CONFIG_HEADERS([config.h:config.h.in])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
