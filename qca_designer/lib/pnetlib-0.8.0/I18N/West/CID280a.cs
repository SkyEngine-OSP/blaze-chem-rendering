/*
 * CID280a.cs - es-PE culture handler.
 *
 * Copyright (c) 2003  Southern Storm Software, Pty Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

// Generated from "es_PE.txt".

namespace I18N.West
{

using System;
using System.Globalization;
using I18N.Common;

public class CID280a : CID000a
{
	public CID280a() : base(0x280A) {}

	public override String Name
	{
		get
		{
			return "es-PE";
		}
	}
	public override String ThreeLetterWindowsLanguageName
	{
		get
		{
			return "ESR";
		}
	}
	public override String Country
	{
		get
		{
			return "PE";
		}
	}

	public override DateTimeFormatInfo DateTimeFormat
	{
		get
		{
			DateTimeFormatInfo dfi = base.DateTimeFormat;
			dfi.DateSeparator = "/";
			dfi.TimeSeparator = ":";
			dfi.LongDatePattern = "d' de 'MMMM' de 'yyyy";
			dfi.LongTimePattern = "hh:mm:ss tt z";
			dfi.ShortDatePattern = "dd/MM/yy";
			dfi.ShortTimePattern = "hh:mm tt";
			dfi.FullDateTimePattern = "dddd d' de 'MMMM' de 'yyyy hh:mm:ss tt z";
			dfi.I18NSetDateTimePatterns(new String[] {
				"d:dd/MM/yy",
				"D:dddd d' de 'MMMM' de 'yyyy",
				"f:dddd d' de 'MMMM' de 'yyyy hh:mm:ss tt z",
				"f:dddd d' de 'MMMM' de 'yyyy hh:mm:ss tt z",
				"f:dddd d' de 'MMMM' de 'yyyy hh:mm:ss tt",
				"f:dddd d' de 'MMMM' de 'yyyy hh:mm tt",
				"F:dddd d' de 'MMMM' de 'yyyy HH:mm:ss",
				"g:dd/MM/yy hh:mm:ss tt z",
				"g:dd/MM/yy hh:mm:ss tt z",
				"g:dd/MM/yy hh:mm:ss tt",
				"g:dd/MM/yy hh:mm tt",
				"G:dd/MM/yy HH:mm:ss",
				"m:MMMM dd",
				"M:MMMM dd",
				"r:ddd, dd MMM yyyy HH':'mm':'ss 'GMT'",
				"R:ddd, dd MMM yyyy HH':'mm':'ss 'GMT'",
				"s:yyyy'-'MM'-'dd'T'HH':'mm':'ss",
				"t:hh:mm:ss tt z",
				"t:hh:mm:ss tt z",
				"t:hh:mm:ss tt",
				"t:hh:mm tt",
				"T:HH:mm:ss",
				"u:yyyy'-'MM'-'dd HH':'mm':'ss'Z'",
				"U:dddd, dd MMMM yyyy HH:mm:ss",
				"y:yyyy MMMM",
				"Y:yyyy MMMM",
			});
			return dfi;
		}
		set
		{
			base.DateTimeFormat = value; // not used
		}
	}

	private class PrivateTextInfo : _I18NTextInfo
	{
		public PrivateTextInfo(int culture) : base(culture) {}

		public override int EBCDICCodePage
		{
			get
			{
				return 20284;
			}
		}
		public override int OEMCodePage
		{
			get
			{
				return 850;
			}
		}

	}; // class PrivateTextInfo

	public override TextInfo TextInfo
	{
		get
		{
			return new PrivateTextInfo(LCID);
		}
	}

}; // class CID280a

public class CNes_pe : CID280a
{
	public CNes_pe() : base() {}

}; // class CNes_pe

}; // namespace I18N.West
