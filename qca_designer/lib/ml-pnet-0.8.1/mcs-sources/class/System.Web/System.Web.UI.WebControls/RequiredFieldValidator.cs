
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
/**
 * Namespace: System.Web.UI.WebControls
 * Class:     RequiredFieldValidator
 *
 * Author:  Gaurav Vaish
 * Maintainer: gvaish@iitk.ac.in
 * Contact: <my_scripts2001@yahoo.com>, <gvaish@iitk.ac.in>
 * Implementation: yes
 * Status:  100%
 *
 * (C) Gaurav Vaish (2002)
 */

using System.ComponentModel;

namespace System.Web.UI.WebControls
{
	[ToolboxData("<{0}:RequiredFieldValidator runat=\"server\" "
	           + "ErrorMessage=\"RequiredFieldValidator\">"
	           + "</{0}:RequiredFieldValidator>")]
	public class RequiredFieldValidator : BaseValidator
	{
		public RequiredFieldValidator(): base()
		{
		}

#if NET_2_0
	    [ThemeableAttribute (false)]
#else
		[Bindable (true)]
#endif
		[DefaultValue (""), WebCategory ("Behavior")]
		[WebSysDescription ("The initial value for the required field.")]
		public string InitialValue
		{
			get
			{
				object o = ViewState["InitialValue"];
				if(o != null)
					return (String)o;
				return String.Empty;
			}
			set
			{
				ViewState["InitialValue"] = value;
			}
		}

		protected override void AddAttributesToRender(HtmlTextWriter writer)
		{
			base.AddAttributesToRender(writer);
			if(RenderUplevel)
			{
				writer.AddAttribute("evaluationfunction", "RequiredFieldValidatorEvaluateIsValid");
				writer.AddAttribute("initialvalue", InitialValue);
			}
		}

		protected override bool EvaluateIsValid()
		{
			string val = GetControlValidationValue(ControlToValidate);
			if(val != null)
			{
				return (val.Trim() != InitialValue.Trim());
			}
			return true;
		}
	}
}
