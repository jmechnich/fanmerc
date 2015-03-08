AC_INIT([fanmerc],[0.0.1])
AC_CONFIG_SRCDIR([src/fanmerc/FanmercDefs.hh])
AM_INIT_AUTOMAKE
AC_CONFIG_MACRO_DIR([m4])

AC_ARG_WITH([qt],
	    AC_HELP_STRING([--with-qt],
	                   [build Qt-based gui programs (default=yes)]),
            [], [with_qt=yes])

AM_CONDITIONAL([BUILD_QTLIBS], [test "$with_qt" = yes])

AC_PROG_CC
AC_PROG_CXX
AC_LANG(C++)
AC_PROG_INSTALL
AM_PROG_LIBTOOL

PKG_PROG_PKG_CONFIG([0.17])

if test $with_qt = "yes"; then
        PKG_CHECK_MODULES([QtGui], [QtGui >= 4.8.4])
        AC_CHECK_PROG(MOC, [moc-qt4], [moc-qt4])
fi


AC_OUTPUT([
        Makefile
	src/Makefile
	src/scripts/Makefile
	src/fanmerc/Makefile
	src/console/Makefile
	src/gui/Makefile
        ])

