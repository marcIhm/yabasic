
dnl  Process this file with 'autoconf' to get a configure-script

AC_INIT([yabasic], [2.84.0])
AC_CONFIG_SRCDIR([main.c])
AM_INIT_AUTOMAKE
LT_INIT

dnl  get canonical system name
AC_CANONICAL_HOST

dnl  find out, which c-compiler is available
AC_PROG_CC

dnl  set compiler options
AC_CHECK_PROG(CCOPTIONS,gcc,-Wall,)

dnl  check for required headers
AC_CHECK_HEADERS([malloc.h alloc.h prctl.h])
dnl  check for <alloca.h>; needed for bison
AC_FUNC_ALLOCA

dnl  check for types
AC_TYPE_SIZE_T

dnl  if strtod is not present, create replacement
AC_FUNC_STRTOD
dnl  crete define, if functions not available
AC_CHECK_FUNCS([strerror mkstemp])

dnl  allow users to disable use of ffi
AC_ARG_ENABLE([use-ffi],[  --disable-use-ffi       disable use of ffi],[use_ffi=${enableval}],[use_ffi=yes])

dnl  check for libffi, not required
have_ffi=no
AC_SEARCH_LIBS([ffi_call],[ffi],[have_ffi=yes])
AC_CHECK_HEADERS([ffi.h],[],[have_ffi=no])
if test "x${have_ffi}" = xno; then
    AC_MSG_WARN([Did not find libffi library and/or header, calling foreign libraries will not be possible])
fi

dnl  check for dlopen, not required
have_dlopen=no
AC_SEARCH_LIBS([dlopen],[dl dld],[have_dl=yes])
AC_CHECK_HEADERS([dlfcn.h],[],[have_dl=no])
if test "x${have_dl}" = xno; then
    AC_MSG_WARN([Did not find dlopen library and/or header, calling foreign libraries will not be possible])
fi

dnl  calling foreign libraries requires both dlopen and libffi
if test "x${have_dl}" = xyes -a "x${have_ffi}" = xyes -a "x${use_ffi}" = xyes; then
    AC_MSG_NOTICE([support for calling foreign libraries will be available])
    AC_MSG_NOTICE([support for calling foreign libraries will be built into])
    AC_DEFINE([USE_DL_FFI],1,[libffi and dlopen available])
fi

dnl  check for curses
have_curses=no
have_ncurses=no
AC_SEARCH_LIBS([initscr],[curses],[have_curses=yes])
AC_SEARCH_LIBS([initscr],[ncurses],[have_ncurses=yes])
if test "x${have_curses}" = xyes; then
    AC_CHECK_HEADERS([curses.h],[],[have_curses=no])
fi
if test "x${have_ncurses}" = xyes; then
    AC_CHECK_HEADERS([ncurses.h],[],[have_ncurses=no])
fi
if test "x${have_curses}" = xno && "x${have_ncurses}" = xno ; then
    AC_MSG_ERROR([Did not find curses/ncurses library and header])
fi
AC_CHECK_FUNCS(getnstr)

dnl  check for dladdr() function
AC_SEARCH_LIBS([dladdr], [dl dld])

dnl  check for X-Window system
AC_PATH_XTRA
if test "x${no_x}" = xyes ; then
    AC_MSG_ERROR([Did not find X11 library and header])
fi

dnl  architecture of build machine
AC_DEFINE_UNQUOTED(UNIX_ARCHITECTURE,"$host",[architecture of build machine])

dnl  build-time, that will be displayed in banner
AC_DEFINE_UNQUOTED(BUILD_TIME,"`date -u -d @$SOURCE_DATE_EPOCH 2>/dev/null || date -u -r $SOURCE_DATE_EPOCH 2>/dev/null || date -u`",[build-time, that will be displayed in banner])

dnl  produce results
AC_CONFIG_HEADERS([config.h:config.h.in])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
