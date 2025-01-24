
dnl  Process this file with 'autoconf' to get a configure-script
dnl  Maybe run these two lines before:
dnl    autoreconf --install
dnl    automake --add-missing --copy

AC_INIT([yabasic], [2.91.1])
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
dnl  create define, if functions not available
AC_CHECK_FUNCS([strerror mkstemp])

dnl  use our own pkg.m4 from m4 dir
AC_CONFIG_MACRO_DIRS([m4])

dnl  option to control building with ffi
AC_ARG_WITH([ffi],
  [AS_HELP_STRING([--with-ffi], [Build with ffi-support for calling foreign libraries @<:@default=yes@:>@])],
  [],
  [with_ffi=yes])

dnl  check for libffi
if test "x${with_ffi}" = xyes; then

   dnl  pkg-config may help to locate ffi
   dnl  if this cannot be found, I probably need to fix ACLOCAL_PATH to locate pkg.m4
   dnl  see also:   aclocal --print-ac-dir
   PKG_PROG_PKG_CONFIG
   if test -n "$PKG_CONFIG"; then
      PKG_CHECK_MODULES([FFI], [libffi], [CFLAGS="$CFLAGS $FFI_CFLAGS";LIBS="$LIBS $FFI_LIBS"]) 
   fi

    have_ffi=no
    AC_SEARCH_LIBS([ffi_call],[ffi],[have_ffi=yes])
    AC_CHECK_HEADERS([ffi.h],[],[have_ffi=no])
    if test "x${have_ffi}" = xno ; then
        AC_MSG_ERROR([Did not find libffi library and/or header; please install them or supply '--without-ffi' to built without ffi. If you have both installed and still get this error, you may manually locate the directories with header files and libraries and add them to the environment variables CFLAGS (as -Idir) and LDFLAGS (as -Ldir); see also 'configure --help' for details about supported environment variables.])
    fi
fi

dnl  check for dlopen
if test "x${with_ffi}" = xyes; then
    have_dlopen=no
    AC_SEARCH_LIBS([dlopen],[dl dld],[have_dlopen=yes])
    AC_CHECK_HEADERS([dlfcn.h],[],[have_dlopen=no])
    if test "x${have_dlopen}" = xno ; then
        AC_MSG_ERROR([Did not find dl library and/or header; please install them or supply '--without-ffi' to built without ffi and dlopen])
    fi
fi

dnl  calling foreign libraries requires both dlopen and libffi
if test "x${have_ffi}" = xyes && test "x${have_dlopen}" = xyes; then
    AC_DEFINE([USE_DL_FFI],1,[libffi and dlopen available])
else
    AC_MSG_NOTICE([support for calling foreign libraries will NOT be available])
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
