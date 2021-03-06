
# configure.ac
#
# This file is part of fizmo.
#
# Copyright (c) 2019 Christoph Ender.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. Neither the name of the copyright holder nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
# IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


AC_ARG_ENABLE([tracing],
 [AS_HELP_STRING([--enable-tracing],
                 [enable tracelog for debugging])],
 [],
 [enable_tracing=no])

AC_INIT(
 [libsndifsdl2-test],
 [0.1.0],
 fizmo@spellbreaker.org,
 libsndifsdl2-test)

AC_CONFIG_AUX_DIR([.])

libsndifsdl2_test_reqs="libfizmo >= 0.7.16, libsndifsdl2 >= 0.8.4"

PKG_CHECK_MODULES([libfizmo], [libfizmo >= 0.7.16])
PKG_CHECK_MODULES([libsndifsdl2], [libsndifsdl2 >= 0.8.4])

AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AC_PROG_RANLIB
AM_PROG_AR

AC_SUBST([LIBSNDIFSDL2_TEST_REQS], $libsndifsdl2_test_reqs)
AC_SUBST([LIBSDL2_TEST_NONPKG_CFLAGS], $libsdl2_test_nonpkg_cflags)
AC_SUBST([LIBSDL2_TEST_NONPKG_LIBS], $libsdl2_test_nonpkg_libs)
AC_SUBST([LIBSNDFILE_TEST_NONPKG_CFLAGS], $libsndfile_test_nonpkg_cflags)
AC_SUBST([LIBSNDFILE_TEST_NONPKG_LIBS], $libsndfile_test_nonpkg_libs)

AM_CONDITIONAL([ENABLE_TRACING],
                [test "$enable_tracing" = "yes"])

# Due to autoconf limitations (no variables in include files?) the file
# below has to be manually copied over from the sound interface's
# "config-subst.m4".
m4_include(config-subst-libsndifsdl2.m4)

AC_CONFIG_FILES([Makefile src/sound_sdl2_test/Makefile])
AC_OUTPUT

