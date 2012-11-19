#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([liblimbo], [1.0], [maxleske@gmail.com])
AM_INIT_AUTOMAKE
LT_PREREQ([2.2])
LT_INIT([shared])
AC_DISABLE_STATIC

AC_CONFIG_SRCDIR([src/limbo.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_PID_T

# Checks for library functions.
AC_FUNC_FORK
AC_CHECK_FUNCS([dup2])

AC_OUTPUT
