/*
 * Xlib.cs - Native method interface for Xlib.
 *
 * Copyright (C) 2002, 2003  Southern Storm Software, Pty Ltd.
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

namespace Xsharp
{

using System;
using System.Runtime.InteropServices;
using Xsharp.Events;
using Xsharp.Types;
using OpenSystem.Platform;
using OpenSystem.Platform.X11;

internal sealed unsafe class Xlib
{
	// Declare Xlib types that may be different sizes on different platforms.
	//
	// Declaring these as enumerated types is a C# trick to get a new
	// integer type of the correct size that is guaranteed to be marshalled
	// to Xlib in the same way as the underlying integer type.

	public enum Xint      : int { Zero }
	public enum Xuint     : uint { Zero }
	public enum Xlong     : int { Zero }
	public enum Xulong    : uint { Zero }

	// Declare display-related external functions.

	[DllImport("X11")]
	extern public static XStatus XInitThreads();

	[DllImport("X11")]
	extern public static IntPtr XOpenDisplay(String display_name);

	[DllImport("X11")]
	extern public static int XCloseDisplay(IntPtr display);

	[DllImport("X11")]
	extern public static String XDisplayName(String str);

	[DllImport("X11")]
	extern public static int XScreenCount(IntPtr display);

	[DllImport("X11")]
	extern public static IntPtr XScreenOfDisplay(IntPtr display, int scr);

	[DllImport("X11")]
	extern public static int XDefaultScreen(IntPtr display);

	[DllImport("X11")]
	extern public static String XDisplayString(IntPtr display);

	[DllImport("X11")]
	extern public static int XFlush(IntPtr display);

	[DllImport("X11")]
	extern public static int XSync(IntPtr display, XBool discard);

	[DllImport("X11")]
	extern public static int XBell(IntPtr display, int percent);

	[DllImport("X11")]
	extern public static int XMaxRequestSize(IntPtr display);

	[DllImport("X11")]
	extern public static IntPtr XSynchronize(IntPtr display, XBool onoff);

	[DllImport("X11")]
	extern public static int XDisplayHeight
			(IntPtr display, int screen_number);

	[DllImport("X11")]
	extern public static int XDisplayHeightMM
			(IntPtr display, int screen_number);

	[DllImport("X11")]
	extern public static int XDisplayWidth
			(IntPtr display, int screen_number);

	[DllImport("X11")]
	extern public static int XDisplayWidthMM
			(IntPtr display, int screen_number);

	// Declare screen-related external functions.

	[DllImport("X11")]
	extern public static XWindow XRootWindowOfScreen(IntPtr screen);

	[DllImport("X11")]
	extern public static XPixel XBlackPixelOfScreen(IntPtr screen);

	[DllImport("X11")]
	extern public static XPixel XWhitePixelOfScreen(IntPtr screen);

	[DllImport("X11")]
	extern public static XColormap XDefaultColormapOfScreen(IntPtr screen);

	[DllImport("X11")]
	extern public static int XDefaultDepthOfScreen(IntPtr screen);

	[DllImport("X11")]
	extern public static int XWidthOfScreen(IntPtr screen);

	[DllImport("X11")]
	extern public static int XHeightOfScreen(IntPtr screen);

	[DllImport("X11")]
	extern public static IntPtr XDefaultVisualOfScreen(IntPtr screen);

	// Declare window-related external functions.

	[DllImport("X11")]
	extern public static XWindow XCreateWindow
			(IntPtr display, XWindow parent, int x, int y,
		     uint width, uint height, uint border_width,
			 int depth, int c_class, IntPtr visual,
			 uint value_mask, ref XSetWindowAttributes values);

	[DllImport("X11")]
	extern public static XWindow XCreateWindow
			(IntPtr display, XWindow parent, int x, int y,
		     uint width, uint height, uint border_width,
			 int depth, int c_class, IntPtr visual,
			 uint value_mask, IntPtr values); // for values == null.

	[DllImport("X11")]
	extern public static int XDestroyWindow(IntPtr display, XWindow w);

	[DllImport("X11")]
	extern public static int XMoveWindow
			(IntPtr display, XWindow w, int x, int y);

	[DllImport("X11")]
	extern public static int XResizeWindow
			(IntPtr display, XWindow w, uint width, uint height);

	[DllImport("X11")]
	extern public static int XMoveResizeWindow
			(IntPtr display, XWindow w, int x, int y,
			 uint width, uint height);

	[DllImport("X11")]
	extern public static int XConfigureWindow
			(IntPtr display, XWindow w, uint value_mask,
			 ref XWindowChanges changes);

	[DllImport("X11")]
	extern public static int XMapWindow(IntPtr display, XWindow w);

	[DllImport("X11")]
	extern public static int XMapRaised(IntPtr display, XWindow w);

	[DllImport("X11")]
	extern public static int XUnmapWindow(IntPtr display, XWindow w);

	[DllImport("X11")]
	extern public static XStatus XWithdrawWindow
			(IntPtr display, XWindow w, int screen_number);

	[DllImport("X11")]
	extern public static XStatus XIconifyWindow
			(IntPtr display, XWindow w, int screen_number);

	[DllImport("X11")]
	extern public static int XReparentWindow
			(IntPtr display, XWindow w, XWindow parent, int x, int y);

	[DllImport("X11")]
	extern public static XCursor XCreateFontCursor
			(IntPtr display, uint shape);

	[DllImport("X11")]
	extern public static int XDefineCursor
			(IntPtr display, XWindow w, XCursor cursor);

	[DllImport("X11")]
	extern public static int XUndefineCursor(IntPtr display, XWindow w);

	[DllImport("X11")]
	extern public static XCursor XCreatePixmapCursor
			(IntPtr display, XPixmap source, XPixmap mask,
			 ref XColor foreground, ref XColor background,
			 uint x, uint y);

	[DllImport("X11")]
	extern public static int XSetWindowBackground
			(IntPtr display, XWindow w, XPixel background_pixel);

	[DllImport("X11")]
	extern public static int XSetWindowBackgroundPixmap
			(IntPtr display, XWindow w, XPixmap background_pixmap);

	[DllImport("X11")]
	extern public static int XClearArea
			(IntPtr display, XWindow w, int x, int y,
			 uint width, uint height, XBool exposures);

	[DllImport("X11")]
	extern public static XStatus XGetGeometry
			(IntPtr display, XDrawable d, out XWindow root_return,
			 out Xint x_return, out Xint y_return,
			 out Xuint width_return, out Xuint height_return,
			 out Xuint border_width_return, out Xuint depth_return);

	[DllImport("X11")]
	extern public static int XGrabKeyboard
			(IntPtr display, XWindow grab_window, XBool owner_events,
			 int pointer_mode, int keyboard_mode, XTime time);

	[DllImport("X11")]
	extern public static int XGrabPointer
			(IntPtr display, XWindow grab_window, XBool owner_events,
			 uint event_mask, int pointer_mode, int keyboard_mode,
			 XWindow confine_to, XCursor cursor, XTime time);

	[DllImport("X11")]
	extern public static int XGrabButton
			(IntPtr display, uint button, uint modifiers,
			 XWindow grab_window, XBool owner_events,
			 uint event_mask, int pointer_mode, int keyboard_mode,
			 XWindow confine_to, XCursor cursor);

	[DllImport("X11")]
	extern public static int XUngrabKeyboard(IntPtr display, XTime time);

	[DllImport("X11")]
	extern public static int XUngrabPointer(IntPtr display, XTime time);

	[DllImport("X11")]
	extern public static int XUngrabButton
			(IntPtr display, uint button, uint modifiers,
			 XWindow grab_window);

	[DllImport("X11")]
	extern public static int XAllowEvents
			(IntPtr display, int event_mode, XTime time);

	// Declare pixmap-related external functions.

	[DllImport("X11")]
	extern public static XPixmap XCreatePixmap
			(IntPtr display, XDrawable d, uint width,
			 uint height, uint depth);

	[DllImport("X11")]
	extern public static int XFreePixmap
			(IntPtr display, XPixmap pixmap);

	[DllImport("X11")]
	extern public static XPixmap XCreateBitmapFromData
			(IntPtr display, XDrawable drawable, byte[] data,
			 uint width, uint height);

	// Declare region-related external functions.

	[DllImport("X11")]
	extern public static IntPtr XCreateRegion();

	[DllImport("X11")]
	extern public static int XDestroyRegion(IntPtr r);

	[DllImport("X11")]
	extern public static int XUnionRegion(IntPtr sra, IntPtr srb,
											  IntPtr dr_return);

	[DllImport("X11")]
	extern public static int XUnionRectWithRegion
			(ref XRectangle rectangle, IntPtr src, IntPtr dest);

	[DllImport("X11")]
	extern public static int XIntersectRegion(IntPtr sra, IntPtr srb,
											      IntPtr dr_return);

	[DllImport("X11")]
	extern public static int XSubtractRegion(IntPtr sra, IntPtr srb,
											     IntPtr dr_return);

	[DllImport("X11")]
	extern public static int XXorRegion(IntPtr sra, IntPtr srb,
										    IntPtr dr_return);

	[DllImport("X11")]
	extern public static int XEmptyRegion(IntPtr r);

	[DllImport("X11")]
	extern public static int XEqualRegion(IntPtr r1, IntPtr r2);

	[DllImport("X11")]
	extern public static int XOffsetRegion
			(IntPtr r, int dx, int dy);

	[DllImport("X11")]
	extern public static int XShrinkRegion
			(IntPtr r, int dx, int dy);

	[DllImport("X11")]
	extern public static int XPointInRegion
			(IntPtr r, int x, int y);

	[DllImport("X11")]
	extern public static IntPtr XPolygonRegion
			(XPoint[] points, int n, int fill_rule);

	[DllImport("X11")]
	extern public static int XClipBox(IntPtr region, out XRectangle rect);

	[DllImport("X11")]
	extern public static int XRectInRegion
			(IntPtr region, int x, int y,
			 uint width, uint height);

	// Declare event-related external functions.

	[DllImport("X11")]
	extern public static int XNextEvent(IntPtr display, out XEvent xevent);

	[DllImport("X11")]
	extern public static int XEventsQueued(IntPtr display, int mode);

	[DllImport("X11")]
	extern public static int XSelectInput(IntPtr display, XWindow w,
											  int mode);

	[DllImport("X11")]
	extern public static XStatus XSendEvent
			(IntPtr display, XWindow w, XBool propagate,
			 int event_mask, ref XEvent event_send);

	// Declare GC-related external functions.

	[DllImport("X11")]
	extern public static IntPtr XCreateGC(IntPtr display,
										  XDrawable drawable,
										  uint values_mask,
										  ref XGCValues values);

	[DllImport("X11")]
	extern public static int XFreeGC(IntPtr display, IntPtr gc);

	[DllImport("X11")]
	extern public static int XChangeGC(IntPtr display, IntPtr gc,
										   uint values_mask,
										   ref XGCValues values);

	[DllImport("X11")]
	extern public static int XGetGCValues(IntPtr display, IntPtr gc,
										      uint values_mask,
										      out XGCValues values);

	[DllImport("X11")]
	extern public static int XSetForeground
			(IntPtr display, IntPtr gc, XPixel foreground);

	[DllImport("X11")]
	extern public static int XSetBackground
			(IntPtr display, IntPtr gc, XPixel background);

	[DllImport("X11")]
	extern public static int XSetFunction
			(IntPtr display, IntPtr gc, int function);

	[DllImport("X11")]
	extern public static int XSetSubwindowMode
			(IntPtr display, IntPtr gc, int subwindow_mode);

	[DllImport("X11")]
	extern public static int XSetFillStyle
			(IntPtr display, IntPtr gc, int fill_style);

	[DllImport("X11")]
	extern public static int XSetTile
			(IntPtr display, IntPtr gc, XPixmap tile);

	[DllImport("X11")]
	extern public static int XSetStipple
			(IntPtr display, IntPtr gc, XPixmap stipple);

	[DllImport("X11")]
	extern public static int XSetTSOrigin
			(IntPtr display, IntPtr gc, int ts_x_origin,
			 int ts_y_origin);

	[DllImport("X11")]
	extern public static int XSetRegion
			(IntPtr display, IntPtr gc, IntPtr r);

	[DllImport("X11")]
	extern public static int XSetClipMask
			(IntPtr display, IntPtr gc, XPixmap pixmap);

	[DllImport("X11")]
	extern public static int XSetClipOrigin
			(IntPtr display, IntPtr gc, int x, int y);

	[DllImport("X11")]
	extern public static int XSetDashes
			(IntPtr display, IntPtr gc, int dash_offset,
			 byte[] dash_list, int n);

	[DllImport("X11")]
	extern public static int XDrawLine
			(IntPtr display, XDrawable drawable, IntPtr gc,
			 int x1, int y1, int x2, int y2);

	[DllImport("X11")]
	extern public static int XDrawLines
			(IntPtr display, XDrawable drawable, IntPtr gc,
			 XPoint[] points, int npoints, int mode);

	[DllImport("X11")]
	extern public static int XDrawPoint
			(IntPtr display, XDrawable drawable, IntPtr gc,
			 int x, int y);

	[DllImport("X11")]
	extern public static int XDrawPoints
			(IntPtr display, XDrawable drawable, IntPtr gc,
			 XPoint[] points, int npoints, int mode);

	[DllImport("X11")]
	extern public static int XDrawRectangle
			(IntPtr display, XDrawable drawable, IntPtr gc,
			 int x, int y, int width, int height);

	[DllImport("X11")]
	extern public static int XDrawRectangles
			(IntPtr display, XDrawable drawable, IntPtr gc,
			 XRectangle[] rectangles, int nrectangles);

	[DllImport("X11")]
	extern public static int XDrawArc
			(IntPtr display, XDrawable drawable, IntPtr gc,
			 int x, int y, int width, int height,
			 int angle1, int angle2);

	[DllImport("X11")]
	extern public static int XFillRectangle
			(IntPtr display, XDrawable drawable, IntPtr gc,
			 int x, int y, int width, int height);

	[DllImport("X11")]
	extern public static int XFillRectangles
			(IntPtr display, XDrawable drawable, IntPtr gc,
			 XRectangle[] rectangles, int nrectangles);

	[DllImport("X11")]
	extern public static int XFillPolygon
			(IntPtr display, XDrawable drawable, IntPtr gc,
			 XPoint[] points, int npoints,
			 int shape, int mode);

	[DllImport("X11")]
	extern public static int XFillArc
			(IntPtr display, XDrawable drawable, IntPtr gc,
			 int x, int y, int width, int height,
			 int angle1, int angle2);

	[DllImport("X11")]
	extern public static int XPutImage
			(IntPtr display, XDrawable drawable, IntPtr gc,
			 IntPtr image, int src_x, int src_y,
			 int dest_x, int dest_y,
			 int width, int height);

	[DllImport("X11")]
	extern public static int XCopyArea
			(IntPtr display, XDrawable src, XDrawable dest,
			 IntPtr gc, int src_x, int src_y,
			 uint width, uint height,
			 int dest_x, int dest_y);

	// Declare window manager related external functions.

	[DllImport("X11")]
	extern public static int XStoreName
			(IntPtr display, XWindow w, String window_name);

	[DllImport("X11")]
	extern public static int XSetIconName
			(IntPtr display, XWindow w, String window_name);

	[DllImport("X11")]
	extern public static XStatus XSetWMProtocols
			(IntPtr display, XWindow w, XAtom[] protocols, int count);

	[DllImport("X11")]
	extern public static int XReconfigureWMWindow
			(IntPtr display, XWindow w, int screen_number,
			 uint value_mask, ref XWindowChanges changes);

	[DllImport("X11")]
	extern public static int XSetTransientForHint
			(IntPtr display, XWindow w, XWindow prop_window);

	[DllImport("X11")]
	extern public static XStatus XGetTransientForHint
			(IntPtr display, XWindow w, out XWindow prop_window);

	[DllImport("X11")]
	extern public static void XSetWMNormalHints
			(IntPtr display, XWindow w, ref XSizeHints hints);

	[DllImport("X11")]
	extern public static void XSetWMHints
			(IntPtr display, XWindow w, ref XWMHints hints);

	[DllImport("X11")]
	extern public static void XSetClassHint
			(IntPtr display, XWindow w, ref XClassHint class_hints);

	[DllImport("X11")]
	extern public static int XKillClient(IntPtr display, XID resource);

	// Declare selection-related external functions.

	[DllImport("X11")]
	extern public static XWindow XGetSelectionOwner
			(IntPtr display, XAtom selection);

	[DllImport("X11")]
	extern public static int XSetSelectionOwner
			(IntPtr display, XAtom selection, XWindow owner, XTime time);

	[DllImport("X11")]
	extern public static int XConvertSelection
			(IntPtr display, XAtom selection, XAtom target,
			 XAtom property, XWindow requestor, XTime time);

	// Declare color-related external functions.

	[DllImport("X11")]
	extern public static int XAllocColor
			(IntPtr display, XColormap colormap, ref XColor xcolor);

	// Declare key-related and pointer-related external functions.

	[DllImport("X11")]
	extern public static int XLookupString
			(ref XKeyEvent xevent, IntPtr buffer, int bytes_buffer,
			 ref XKeySym keysym_return, IntPtr status_in_out);

	[DllImport("X11")]
	extern public static XKeySym XLookupKeysym
			(ref XKeyEvent xevent, int index);

	[DllImport("X11")]
	extern public static int XGetPointerMapping
			(IntPtr display, byte[] map_return, int nmap);

	// Declare atom-related external functions.

	[DllImport("X11")]
	extern public static XAtom XInternAtom
			(IntPtr display, String name, XBool only_if_exists);

	// Declare property-related external functions.

	[DllImport("X11")]
	extern public static int XChangeProperty
			(IntPtr display, XWindow w, XAtom property,
			 XAtom type, int format, int mode,
			 byte[] data, int nelements);

	[DllImport("X11")]
	extern public static int XChangeProperty
			(IntPtr display, XWindow w, XAtom property,
			 XAtom type, int format, int mode,
			 Xlong[] data, int nelements);

	[DllImport("X11")]
	extern public static int XDeleteProperty
			(IntPtr display, XWindow w, XAtom property);

	[DllImport("X11")]
	extern public static XStatus XGetWindowProperty
			(IntPtr display, XWindow w, XAtom property,
			 int long_offset, int long_length,
			 XBool deleteProp, XAtom req_type,
			 out XAtom actual_type_return,
			 out Xlib.Xint actual_format_return,
			 out Xlib.Xulong nitems_return,
			 out Xlib.Xulong bytes_after_return,
			 out IntPtr prop_return);

	// Text property and string functions.

	[DllImport("X11")]
	extern public static int XFree(IntPtr ptr);

	[DllImport("X11")]
	extern public static XStatus XStringListToTextProperty
			(ref IntPtr argv, int argc, ref XTextProperty textprop);

	[DllImport("X11")]
	extern public static XStatus XStringListToTextProperty
			(IntPtr[] argv, int argc, ref XTextProperty textprop);

	[DllImport("X11")]
	extern public static void XSetTextProperty
			(IntPtr display, XWindow w, ref XTextProperty textProp,
			 XAtom property);

	[DllImport("X11")]
	extern public static int _XGetHostname(IntPtr buf, int maxlen);

	// Helper functions from "libXsharpSupport.so".

	[DllImport("XsharpSupport")]
	extern public static int XSharpSupportPresent();

	[DllImport("XsharpSupport")]
	extern public static int XNextEventWithTimeout
			(IntPtr display, out XEvent xevent, int timeout);

	[DllImport("XsharpSupport")]
	extern public static int XSharpUseXft();

	[DllImport("XsharpSupport")]
	extern public static IntPtr XSharpCreateFontXft
			(IntPtr display, String family, String fallbacks,
			 int pointSize, int style);

	[DllImport("XsharpSupport")]
	extern public static void XSharpFreeFontXft
			(IntPtr display, IntPtr fontSet);

	[DllImport("XsharpSupport", CharSet=CharSet.Unicode)]
	extern public static void XSharpDrawStringXft
			(IntPtr display, XDrawable drawable, IntPtr gc,
			 IntPtr fontSet, int x, int y,
			 String str, int style, IntPtr clipRegion,
			 uint colorValue);

	[DllImport("XsharpSupport", CharSet=CharSet.Unicode)]
	extern public static void XSharpTextExtentsXft
			(IntPtr display, IntPtr fontSet, String str,
			 out XRectangle overall_ink_return,
			 out XRectangle overall_logical_return);

	[DllImport("XsharpSupport", CharSet=CharSet.Unicode)]
	extern public static void XSharpFontExtentsXft
			(IntPtr fontSet,
			 out XRectangle max_ink_return,
			 out XRectangle max_logical_return);

	[DllImport("XsharpSupport")]
	extern public static IntPtr XSharpCreateFontSet
			(IntPtr display, String family, int pointSize, int style);

	[DllImport("XsharpSupport")]
	extern public static void XSharpFreeFontSet
			(IntPtr display, IntPtr fontSet);

	[DllImport("XsharpSupport")]
	extern public static void XSharpDrawStringSet
			(IntPtr display, XDrawable drawable, IntPtr gc,
			 IntPtr fontSet, int x, int y,
			 String str, int style);

	[DllImport("XsharpSupport")]
	extern public static void XSharpTextExtentsSet
			(IntPtr display, IntPtr fontSet, String str,
			 out XRectangle overall_ink_return,
			 out XRectangle overall_logical_return);

	[DllImport("XsharpSupport")]
	extern public static void XSharpFontExtentsSet
			(IntPtr fontSet,
			 out XRectangle max_ink_return,
			 out XRectangle max_logical_return);

	[DllImport("XsharpSupport")]
	extern public static IntPtr XSharpCreateFontStruct
			(IntPtr display, String family, int pointSize, int style);

	[DllImport("XsharpSupport")]
	extern public static void XSharpFreeFontStruct
			(IntPtr display, IntPtr fontSet);

	[DllImport("XsharpSupport")]
	extern public static void XSharpDrawStringStruct
			(IntPtr display, XDrawable drawable, IntPtr gc,
			 IntPtr fontSet, int x, int y,
			 [MarshalAs(UnmanagedType.Interface)] String str,
			 int offset, int count, int style);

	[DllImport("XsharpSupport")]
	extern public static void XSharpTextExtentsStruct
			(IntPtr display, IntPtr fontSet,
			 [MarshalAs(UnmanagedType.Interface)] String str,
			 int offset, int count,
			 out XRectangle overall_ink_return,
			 out XRectangle overall_logical_return);

	[DllImport("XsharpSupport")]
	extern public static void XSharpFontExtentsStruct
			(IntPtr fontSet,
			 out XRectangle max_ink_return,
			 out XRectangle max_logical_return);

	[DllImport("XsharpSupport")]
	extern public static IntPtr XSharpPCFCreateImage
			(byte[] data, uint length);

	[DllImport("XsharpSupport")]
	extern public static void XSharpPCFDestroyImage(IntPtr fontImage);

	[DllImport("XsharpSupport")]
	extern public static IntPtr XSharpPCFCreate(IntPtr dpy, IntPtr fontImage);

	[DllImport("XsharpSupport")]
	extern public static void XSharpPCFDestroy(IntPtr dpy, IntPtr renderer);

	[DllImport("XsharpSupport")]
	extern public static void XSharpDrawStringPCF
			(IntPtr display, XDrawable drawable, IntPtr gc,
			 IntPtr fontSet, int x, int y,
			 [MarshalAs(UnmanagedType.Interface)] String str,
			 int offset, int count, int style);

	[DllImport("XsharpSupport")]
	extern public static void XSharpTextExtentsPCF
			(IntPtr display, IntPtr fontSet,
			 [MarshalAs(UnmanagedType.Interface)] String str,
			 int offset, int count,
			 out XRectangle overall_ink_return,
			 out XRectangle overall_logical_return);

	[DllImport("XsharpSupport")]
	extern public static void XSharpFontExtentsPCF
			(IntPtr fontSet,
			 out XRectangle max_ink_return,
			 out XRectangle max_logical_return);

	[DllImport("XsharpSupport")]
	extern public static IntPtr XSharpGetResources(IntPtr dpy, XWindow w);

	[DllImport("XsharpSupport")]
	extern public static void XSharpFreeResources(IntPtr value);

	[DllImport("XsharpSupport")]
	extern public static int XSharpGetRegionSize(IntPtr region);

	[DllImport("XsharpSupport")]
	extern public static void XSharpGetRegionRect
			(IntPtr region, int index, out XRectangle rect);

	[DllImport("XsharpSupport")]
	extern public static IntPtr XSharpCreateImageFromDIB
			(IntPtr screen, int width, int height,
			 int stride, int pixelFormat, byte[] data,
			 int isMask, XPixel[] palette);

	[DllImport("XsharpSupport")]
	extern public static void XSharpDestroyImage(IntPtr image);

	[DllImport("XsharpSupport")]
	extern public static void XSharpGetImageSize
			(IntPtr image, out int width, out int height);

	[DllImport("XsharpSupport")]
	extern public static void XSharpSendClose
			(IntPtr display, XWindow window);

	[DllImport("XsharpSupport")]
	extern public static void XSharpSendWakeup
			(IntPtr display, XWindow window);

	// Helper functions for creating and managing application groups.

	[DllImport("Xext")]
	extern public static XBool XagQueryVersion
			(IntPtr display, out Xint major, out Xint minor);

	[DllImport("Xext")]
	extern public static XStatus XagCreateEmbeddedApplicationGroup
			(IntPtr display, XVisualID root_visual, XColormap default_colormap,
			 XPixel black_pixel, XPixel white_pixel, out XAppGroup app_group);

	[DllImport("Xext")]
	extern public static XStatus XagDestroyApplicationGroup
			(IntPtr display, XAppGroup app_group);

	// Helper functions for managing security tokens.

	public enum XSecurityAuthorization : uint { Zero }

	[DllImport("Xext")]
	extern public static XBool XSecurityQueryExtension
			(IntPtr display, out Xint major, out Xint minor);

	[DllImport("Xext")]
	extern public static Xauth *XSecurityAllocXauth();

	[DllImport("Xext")]
	extern public static void XSecurityFreeXauth(Xauth *auth);

	[DllImport("Xext")]
	extern public static Xauth *XSecurityGenerateAuthorization
			(IntPtr dpy, Xauth *auth_in, uint valuemask,
			 ref XSecurityAuthorizationAttributes attributes,
			 out XSecurityAuthorization auth_id_return);

	// Helper functions for double buffer handling.

	public enum XdbeSwapAction : byte
	{
		Undefined		= 0,
		Background		= 1,
		Untouched		= 2,
		Copied			= 3

	}; // enum XdbeSwapAction

	[StructLayout(LayoutKind.Sequential)]
	public struct XdbeSwapInfo
	{
		public XWindow 			swap_window;
		public XdbeSwapAction	swap_action;

	}; // struct XdbeSwapInfo

	[DllImport("Xext")]
	extern public static XStatus XdbeQueryExtension
			(IntPtr display, out Xint major, out Xint minor);

	[DllImport("Xext")]
	extern public static XDrawable XdbeAllocateBackBufferName
			(IntPtr display, XWindow window, XdbeSwapAction swap_action);

	[DllImport("Xext")]
	extern public static XStatus XdbeDeallocateBackBufferName
			(IntPtr display, XDrawable buffer);

	[DllImport("Xext")]
	extern public static XStatus XdbeSwapBuffers
			(IntPtr display, ref XdbeSwapInfo swap_info, int num_windows);

	// Other functions.

	[DllImport("X11")]
	extern public static IntPtr XListFonts
			(IntPtr display, String pattern, int maxnames,
			 out int actualCountReturn);

	[DllImport("X11")]
	extern public static int XFreeFontNames(IntPtr list);

	// Wrap up the "XListFonts" function and make it friendlier.
	public static String[] XListFonts(IntPtr display, String pattern)
			{
				// Get the full list of fonts.  We may have to use multiple
				// requests if the maximum is reached on the first request.
				int actualCount;
				int maxNames = 1000;
				IntPtr names;
				for(;;)
				{
					names = XListFonts
						(display, pattern, (int)maxNames, out actualCount);
					if(names == IntPtr.Zero)
					{
						return new String [0];
					}
					if(actualCount < maxNames)
					{
						break;
					}
					XFreeFontNames(names);
					maxNames *= 2;
				}

				// Convert the font list into an array of C# strings.
				int posn;	
				int size = IntPtr.Size;
				String[] result;
				try
				{
					result = new String [(int)actualCount];
					for(posn = 0; posn < actualCount; ++posn)
					{
						result[posn] = Marshal.PtrToStringAnsi
							(Marshal.ReadIntPtr(names, posn * size));
					}
				}
				finally
				{
					XFreeFontNames(names);
				}
				return result;
			}

} // class Xlib

} // namespace Xsharp
