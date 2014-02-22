//
// System.Web.HttpRequestTest.cs - Unit tests for System.Web.HttpRequest
//
// Author:
//	Sebastien Pouliot  <sebastien@ximian.com>
//
// Copyright (C) 2005 Novell, Inc (http://www.novell.com)
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

using System.Text;
using System.Web;

using NUnit.Framework;

namespace MonoTests.System.Web {

	[TestFixture]
	public class HttpRequestTest {

#if NET_1_1
		[Test]
		[ExpectedException (typeof (HttpRequestValidationException))]
		public void ValidateInput_XSS ()
		{
			string problem = "http://server.com/attack2.aspx?test=<script>alert('vulnerability')</script>";
			string decoded = HttpUtility.UrlDecode (problem);
			int n = decoded.IndexOf ('?');
			HttpRequest request = new HttpRequest (null, decoded.Substring (0,n), decoded.Substring (n+1));
			request.ValidateInput ();
			// the next statement throws
			Assert.AreEqual ("<script>alert('vulnerability')</script>", request.QueryString ["test"], "QueryString");
		}

		// Notes:
		// * this is to avoid a regression that would cause Mono to 
		//   fail again on item #2 of the XSS vulnerabilities listed at:
		//   http://it-project.ru/andir/docs/aspxvuln/aspxvuln.en.xml
		// * The author notes that Microsoft has decided not to fix 
		//   this issue (hence the NotDotNet category).

		[Test]
		[Category ("NotDotNet")]
		[ExpectedException (typeof (HttpRequestValidationException))]
		public void ValidateInput_XSS_Unicode ()
		{
			string problem = "http://server.com/attack2.aspx?test=%uff1cscript%uff1ealert('vulnerability')%uff1c/script%uff1e";
			string decoded = HttpUtility.UrlDecode (problem);
			int n = decoded.IndexOf ('?');
			HttpRequest request = new HttpRequest (null, decoded.Substring (0,n), decoded.Substring (n+1));
			request.ValidateInput ();
			// the next statement throws
			Assert.AreEqual ("\xff1cscript\xff1ealert('vulnerability')\xff1c/script\xff1e", request.QueryString ["test"], "QueryString");
		}

		// This has affected ASP.NET 1.1 but it seems fixed now
		// http://secunia.com/advisories/9716/
		// http://weblogs.asp.net/kaevans/archive/2003/11/12/37169.aspx
		[Test]
		[ExpectedException (typeof (HttpRequestValidationException))]
		public void ValidateInput_XSS_Null ()
		{
			string problem = "http://secunia.com/?test=<%00SCRIPT>alert(document.cookie)</SCRIPT>";
			string decoded = HttpUtility.UrlDecode (problem);
			int n = decoded.IndexOf ('?');
			HttpRequest request = new HttpRequest (null, decoded.Substring (0,n), decoded.Substring (n+1));
			request.ValidateInput ();
			// the next statement throws
			Assert.AreEqual ("<SCRIPT>alert(document.cookie)</SCRIPT>", request.QueryString ["test"], "QueryString");
		}
#endif
	}
}
