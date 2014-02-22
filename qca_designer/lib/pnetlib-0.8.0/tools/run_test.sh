#!/bin/sh
#
# run_test.sh - Run a C# test using "ilrun".
#
# Copyright (C) 2001, 2002  Southern Storm Software, Pty Ltd.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

# Get the incoming configuration variables.
ILRUN="/usr/local/bin/ilrun"

# Get the top-most build directory, so that we can add the right
# paths to the "ilrun" command-line.
TOP_BUILDDIR="$1"
shift

# Make sure that we are in the default locale so that locale-sensitive
# tests don't get confused on non-English systems.
LANG=en_US
LC_ALL=en_US
export LANG LC_ALL

# Run the test.
exec "$ILRUN" -L"$TOP_BUILDDIR"/runtime \
	-L"$TOP_BUILDDIR"/I18N \
	-L"$TOP_BUILDDIR"/System \
	-L"$TOP_BUILDDIR"/DotGNU.SSL \
	-L"$TOP_BUILDDIR"/DotGNU.Images \
	-L"$TOP_BUILDDIR"/System.Xml \
	-L"$TOP_BUILDDIR"/csunit \
	-L"$TOP_BUILDDIR"/compat \
	-L"$TOP_BUILDDIR"/JScript \
	-L"$TOP_BUILDDIR"/Basic \
	-L"$TOP_BUILDDIR"/System.Drawing \
	-L"$TOP_BUILDDIR"/System.Drawing.Xsharp \
	-L"$TOP_BUILDDIR"/Xsharp \
	-L"$TOP_BUILDDIR"/System.Windows.Forms \
	-L"$TOP_BUILDDIR"/SharpZipLib \
	-L"$TOP_BUILDDIR"/OpenSystem.Platform \
	-L"$TOP_BUILDDIR"/compat \
	"$TOP_BUILDDIR/csunit/csunit.exe" $*
