//
// System.Web.UI.BaseParser.cs
//
// Authors:
// 	Duncan Mak  (duncan@ximian.com)
//	Gonzalo Paniagua Javier (gonzalo@ximian.com)
//
// (C) 2002 Ximian, Inc. (http://www.ximian.com)
//

//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

using System;
using System.Collections;
using System.IO;
using System.Web;
using System.Web.Compilation;
using System.Web.Configuration;
using System.Web.Util;

namespace System.Web.UI
{
	public class BaseParser
	{
		HttpContext context;
		string baseDir;
		string baseVDir;
		ILocation location;
		CompilationConfiguration compilationConfig;

		internal string MapPath (string path)
		{
			return MapPath (path, true);
		}

		internal string MapPath (string path, bool allowCrossAppMapping)
		{
			if (context == null)
				throw new HttpException ("context is null!!");

			return context.Request.MapPath (path, BaseVirtualDir, allowCrossAppMapping);
		}

		internal string PhysicalPath (string path)
		{
			if (Path.DirectorySeparatorChar != '/')
				path = path.Replace ('/', '\\');
				
			return Path.Combine (BaseDir, path);
		}

		internal bool GetBool (Hashtable hash, string key, bool deflt)
		{
			string val = hash [key] as string;
			if (val == null)
				return deflt;

			hash.Remove (key);

			bool result = false;
			if (String.Compare (val, "true", true) == 0)
				result = true;
			else if (String.Compare (val, "false", true) != 0)
				ThrowParseException ("Invalid value for " + key);

			return result;
		}

		internal static string GetString (Hashtable hash, string key, string deflt)
		{
			string val = hash [key] as string;
			if (val == null)
				return deflt;

			hash.Remove (key);
			return val;
		}
		
		internal void ThrowParseException (string message)
		{
			throw new ParseException (location, message);
		}
		
		internal void ThrowParseException (string message, Exception inner)
		{
			throw new ParseException (location, message, inner);
		}
		
		internal ILocation Location {
			get { return location; }
			set { location = value; }
		}

		internal HttpContext Context {
			get { return context; }
			set { context = value; }
		}

		internal string BaseDir {
			get {
				if (baseDir == null)
					baseDir = MapPath (BaseVirtualDir, false);

				return baseDir;
			}
		}

		internal virtual string BaseVirtualDir {
			get {
				if (baseVDir == null)
					baseVDir = UrlUtils.GetDirectory (context.Request.FilePath);

				return baseVDir;
			}

			set { baseVDir = value; }
		}

		internal CompilationConfiguration CompilationConfig {
			get {
				if (compilationConfig == null)
					compilationConfig = CompilationConfiguration.GetInstance (context);

				return compilationConfig;
			}
		}
	}
}

