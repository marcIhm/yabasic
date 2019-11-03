
dnl  Process this file with 'autoconf' to get a configure-script

AC_INIT([yabasic], [2.84.3])
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

dnl  check for libffi
if test "x${use_ffi}" = xyes; then
    have_ffi=no
    AC_SEARCH_LIBS([ffi_call],[ffi],[have_ffi=yes])
    AC_CHECK_HEADERS([ffi.h],[],[have_ffi=no])
    if test "x${have_ffi}" = xno; then
        AC_MSG_ERROR([Did not find libffi library and/or header; install them or supply '--disable-use-ffi' to built anyway and without ffi. If you are sure to have both installed and still get this error, you may search for the location of ffi.h (e.g. /usr/local/lib64/libffi-3.2.1/include/ffi.h) and make it visible in /usr/include])
    fi
fi

dnl  check for dlopen
if test "x${use_ffi}" = xyes; then
    have_dlopen=no
    AC_SEARCH_LIBS([dlopen],[dl dld],[have_dl=yes])
    AC_CHECK_HEADERS([dlfcn.h],[],[have_dl=no])
    if test "x${have_dl}" = xno; then
        AC_MSG_ERROR([Did not find dl library and/or header; install them or supply '--disable-use-ffi' to built anyway and without ffi])
    fi
fi

dnl  calling foreign libraries requires both dlopen and libffi
if test "x${use_ffi}" = xyes; then
    AC_DEFINE([USE_DL_FFI],1,[libffi and dlopen available])
else
    AC_MSG_NOTICE([support for calling foreign libraries will not be available])
fi

dnl  check for curses
have_curses_lib=no
AC_SEARCH_LIBS([initscr],[curses ncurses],[have_curses_lib=yes])
if test "x${have_curses_lib}" = xno ; then
    AC_MSG_ERROR([Did not find curses/ncurses library])
fi
have_curses_head=no
AC_CHECK_HEADERS([curses.h ncurses.h],[have_curses_head=yes])
if test "x${have_curses_head}" = xno ; then
    AC_MSG_ERROR([Did not find curses/ncurses header])
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
