/*
 * S.cs - String resources.
 *
 * Copyright (C) 2003  Southern Storm Software, Pty Ltd.
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

namespace Generics
{

using System.Reflection;
using System.Resources;

// This class provides string resource support to the rest
// of the "Generics" library assembly.  It is accessed using
// the "S._(tag)" convention.

internal sealed class S
{
	// Cached copy of the resources for this assembly.
	private static ResourceManager genericsResources = null;

	// Helper for obtaining string resources for this assembly.
	public static String _(String tag)
			{
				lock(typeof(S))
				{
					String value;
					if(genericsResources == null)
					{
						genericsResources = new ResourceManager
							("Generics", (typeof(S)).Assembly);
					}
					return genericsResources.GetString(tag, null);
				}
			}

}; // class S

}; // namespace Generics
