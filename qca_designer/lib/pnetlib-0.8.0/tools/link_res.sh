#!/bin/sh
#
# link_res.sh - Link a resource file into a satellite assembly.
#
# Copyright (C) 2002  Southern Storm Software, Pty Ltd.
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

# Usage: link_res.sh output.dll input.resources language

# Variables that are inserted by "configure".
CSCC="/usr/local/bin/cscc"
ASSEMBLY_LINKER="pnet"

# Are we using Portable.NET's or Microsoft's tools?
if test "x$ASSEMBLY_LINKER" = "xpnet" ; then
	exec "$CSCC" -nostdlib -o "$1" "-fresources=$2"
else
	exec "$ASSEMBLY_LINKER" /nologo "/out:$1" "/c:$3" "/embed:$2"
fi
