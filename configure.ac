
#Ensure that lates version of autoconf avalible
AC_PREREQ([2.63])
#create info about project
AC_INIT([Mide],[0.1])

AM_INIT_AUTOMAKE([foreign dist-bzip2])


# Use it to link library
AC_PROG_LIBTOOL

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX

PKG_CHECK_MODULES([CLUTTER], [clutter-1.0 >= 1.8.0])

#force to less verbose build output
#AM_SILENT_RULES([yes])

AC_CONFIG_FILES([
	Makefile
	Source/Makefile
])

AC_OUTPUT

