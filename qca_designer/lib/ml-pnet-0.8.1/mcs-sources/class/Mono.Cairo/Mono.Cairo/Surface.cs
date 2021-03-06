//
// Mono.Cairo.CairoSurfaceObject.cs
//
// Authors:
//    Duncan Mak
//    Miguel de Icaza.
//
// (C) Ximian Inc, 2003.
// (C) Novell, Inc. 2003.
//
// This is an OO wrapper API for the Cairo API
//
// Copyright (C) 2004 Novell, Inc (http://www.novell.com)
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
using System.Drawing;
using System.Runtime.InteropServices;
using System.Collections;
using Cairo;

namespace Cairo {

	public class Surface : IDisposable 
        {
		static Hashtable surfaces = new Hashtable ();
                internal IntPtr surface = IntPtr.Zero;

                private Surface (IntPtr ptr, bool owns)
                {
                        surface = ptr;
			lock (surfaces.SyncRoot){
				surfaces [ptr] = this;
			}
			if (!owns)
				CairoAPI.cairo_surface_reference (ptr);
                }

		static internal Surface LookupExternalSurface (IntPtr p)
		{
			lock (surfaces.SyncRoot){
				object o = surfaces [p];
				if (o == null){
					return new Surface (p, false);
				}
				return (Surface) o;
			}
		}

                public static Cairo.Surface CreateForImage (
                        string data, Cairo.Format format, int width, int height, int stride)
                {
                        IntPtr p = CairoAPI.cairo_surface_create_for_image (
                                data, format, width, height, stride);
                        
                        return new Cairo.Surface (p, true);
                }

                public static Cairo.Surface CreateForImage (
                        Cairo.Format format, int width, int height)
                {
                        IntPtr p = CairoAPI.cairo_image_surface_create (
                                format, width, height);

                        return new Cairo.Surface (p, true);
                }


                public static Cairo.Surface CreateSimilar (
                        Cairo.Surface surface, Cairo.Format format, int width, int height)
                {
                        IntPtr p = CairoAPI.cairo_surface_create_similar (
                                surface.Handle, format, width, height);

                        return new Cairo.Surface (p, true);
                }

                public static Cairo.Surface CreateSimilarSolid (
                        Cairo.Surface surface, Cairo.Format format,
                        int width, int height, double red, double green, double blue, double alpha)
                {
                        IntPtr p = CairoAPI.cairo_surface_create_similar_solid (
                                surface.Handle, format, width, height, red, green, blue, alpha);

                        return new Cairo.Surface (p, true);
                }

		~Surface ()
		{
			Dispose (false);
		}

		public void Show (Graphics gr, int width, int height) 
		{
			CairoAPI.cairo_show_surface (gr.Handle, surface, width,  height);
		}

		void IDisposable.Dispose ()
		{
			Dispose (true);
			GC.SuppressFinalize (this);
		}

		protected virtual void Dispose (bool disposing)
		{
			if (surface == (IntPtr) 0)
				return;
			lock (surfaces.SyncRoot){
				surfaces.Remove (surface);
			}
			CairoAPI.cairo_surface_destroy (surface);
			surface = (IntPtr) 0;
		}
		
                public IntPtr Handle {
                        get { return surface; }
                }

                public int Repeat {
                        set {
                                CairoAPI.cairo_surface_set_repeat (surface, value);
                        } 
                }

                public Cairo.Matrix Matrix {
                        set {
                                CairoAPI.cairo_surface_set_matrix (surface, value.Pointer);
                        }

                        get {
                                IntPtr p = IntPtr.Zero;
                                CairoAPI.cairo_surface_get_matrix (surface, out p);
                                return new Cairo.Matrix (p);
                        }
                }

                public Cairo.Filter Filter {
                        set {
                                CairoAPI.cairo_surface_set_filter (surface, value);
                        }
                }

                public IntPtr Pointer {
                        get { return surface; }
                }



        }
}
