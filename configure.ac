#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([cffi-callback-test], [0.0.0], [])
AC_CONFIG_AUX_DIR(configure_aux)
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([1.16 -Wall subdir-objects foreign])

AC_CONFIG_MACRO_DIR([m4])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

DEBUG="no"
AC_ARG_ENABLE([debug],
    [AC_HELP_STRING([--enable-debug], [enable debug options]) ],
    [
        if test "x$enableval" = "xyes"; then
            CFLAGS="$CFLAGS -g -O0"
            AC_DEFINE([DEBUG], [1], [build debug version])
            DEBUG="yes"
        fi
    ]
)

SYSROOT=
AC_ARG_WITH(sysroot,
    AC_HELP_STRING([--with-sysroot=DIR],
                   [search for dependencies in DIR]),
    [
        SYSROOT="$withval"
    ]
)
if test -n "$SYSROOT"; then
    CFLAGS="$CFLAGS -I$SYSROOT/include"
    CPPFLAGS="$CPPFLAGS -I$SYSROOT/include"
    LDFLAGS="$LDFLAGS -L$SYSROOT/lib"
    export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:$SYSROOT/lib/pkgconfig
    export PATH=$SYSROOT/bin:$PATH
fi

# Checks for programs.
AC_PROG_CC
AC_PROG_RANLIB
AM_PROG_AR

# Checks for header files.
AC_CHECK_HEADERS([unistd.h])

# Checks for libraries.
AX_PTHREAD([], [ AC_MSG_ERROR([required pthread library not found]) ])

PKG_PROG_PKG_CONFIG

if test -z "$PKG_CONFIG"; then
    AC_MSG_ERROR([pkg-config not found on your system])
fi

# This makes sure AM_PATH_PYTHON which in turn uses AC_PATH_PROGS finds the
# version in our sysroot path first, instead of the default "python" link
# that points to /usr/bin/python3 on most distros
PYTHON="$(which python3)"
AM_PATH_PYTHON([3.8],,[AC_MSG_ERROR([can not generate python bindings, python3 not found])])

AC_MSG_CHECKING([for cffi module presence])
AS_IF([$PYTHON -c 'import cffi'],
    [
        AC_MSG_RESULT([yes])
        AC_SUBST([PYTHON3_BIN], [$PYTHON])
    ],
    [
        AC_MSG_RESULT([no])
        AC_MSG_ERROR([can not generate python bindings, cffi module not found])
    ])

PKG_CHECK_MODULES(PYTHON3, [python3-embed], [],
    [
        AC_MSG_ERROR([required python3/c library not found])
    ])

CFLAGS="$CFLAGS -Wall"

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
