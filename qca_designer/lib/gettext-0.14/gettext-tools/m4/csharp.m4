# csharp.m4 serial 1 (gettext-0.14)
dnl Copyright (C) 2004 Free Software Foundation, Inc.
dnl This file is free software, distributed under the terms of the GNU
dnl General Public License.  As a special exception to the GNU General
dnl Public License, this file may be distributed as part of a program
dnl that contains a configuration script generated by Autoconf, under
dnl the same distribution terms as the rest of that program.

# Sets CSHARP_CHOICE to the preferred C# implementation:
# 'pnet' or 'mono' or 'any' or 'no'.
AC_DEFUN([gt_CSHARP_CHOICE],
[
  AC_MSG_CHECKING([for preferred C[#] implementation])
  AC_ARG_ENABLE(csharp,
    [  --enable-csharp[[=IMPL]]  choose preferred C[#] implementation (pnet or mono)],
    [CSHARP_CHOICE="$enableval"],
    CSHARP_CHOICE=any)
  AC_SUBST(CSHARP_CHOICE)
  AC_MSG_RESULT([$CSHARP_CHOICE])
  case "$CSHARP_CHOICE" in
    pnet)
      AC_DEFINE([CSHARP_CHOICE_PNET], 1,
        [Define if pnet is the preferred C[#] implementation.])
      ;;
    mono)
      AC_DEFINE([CSHARP_CHOICE_MONO], 1,
        [Define if mono is the preferred C[#] implementation.])
      ;;
  esac
])
