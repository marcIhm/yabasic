/*

    YABASIC ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2019
    more info at www.yabasic.de

    graphic.c --- code for windowed graphics, printing and plotting

    This file is part of yabasic and may be copied under the terms of
    MIT License which can be found in the file LICENSE.

*/



/* ------------- includes ---------------- */

#ifndef YABASIC_INCLUDED
#include "yabasic.h"		/* all prototypes and structures */
#endif
#ifdef UNIX
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#ifdef HAVE_PRCTL_H
#include <sys/prctl.h>
#endif
#ifndef KEY_MAX
#define KEY_MAX 0777
#endif
#endif


/* ------------- local functions ---------------- */

static void transform (double *, double *);	/* do transformation */
static void itransform (int *, int *);	/* integer variant of transform() */
static int grafinit (void);	/* initialize grafics (either X or Windows) */
static char *newrgb (int, int);	/* create a new bitmap string */
static void addrgb (char *, unsigned short, unsigned short, unsigned short);	/* add one rgb pixel to bitstring */
static int readrgb (char *, unsigned short *, unsigned short *, unsigned short *);	/* read rgb pixel from string one after another */
static int change_font (char *);	/* change font */
static int rgb_to_pixel (int, int, int); /* create a pixel value from rgb values */

#ifdef WINDOWS
static DWORD winthread (LPWORD);	/* window thread */
static void startdraw (int);	/* prepare for drawing */
static void enddraw ();		/* end of drawing */

#endif
/* ------------- global variables ---------------- */
/* printing and plotting */
static char *printerfilename = NULL;	/* filename to print on */
static int deleteprinterfile = FALSE;	/* true, if we created the filename ourself an can delete it on close */
int print_to_file = FALSE;	/* print to file ? */
#ifdef WINDOWS
static LOGFONT logfont;		/* structure for font-characteristics */
HFONT printerfont;		/* handle of printer-font */
static HPEN printerpen;		/* handle of printer-pen */
static HPEN revprinterpen;	/* handle of reverse printer-pen */
HDC printer = NULL;		/* handle of printer */
static float prnscale;		/* scaling factor for printer */
static float prnoffx;		/* offset for printer */
static float prnoffy;		/* offset for printer */
#else
FILE *printerfile = NULL;	/* file to print on */
static double psscale;		/* factor from window-pixels to ps-points */
static int firsttext = TRUE;	/* true until text has been printed */
#endif
int drawmode = 0;		/* flag for drawing */
#ifdef UNIX
static XFontStruct *myfont = NULL;	/* properties of default font */
#else
HFONT myfont;			/* handle of font for screen */
#endif

/* window coordinates */
int winopened = FALSE;		/* flag if window is open already */
char *winorigin;		/* e.g. "lt","rc"; defines origin of grafic window */
int winwidth, winheight;	/* size of window */
static int winx, winy;		/* position of window */

/* mouse and keyboard */
int mousex = 0, mousey = 0, mouseb = 0, mousemod = 0;	/* last known mouse coordinates */
char *ykey[kLASTKEY + 1];	/* keys returned by inkey */
#ifdef UNIX
#else
static DWORD wtid;		/* id of win thread */
static HANDLE wtevent = INVALID_HANDLE_VALUE;	/* handle for win thread event */
static HANDLE drawmutex = INVALID_HANDLE_VALUE;	/* handle for drawing mutex */

#endif
/* text and font */
char *text_align;		/* specifies alignement of text */
int fontheight;			/* height of font in pixel */

/* general window stuff */
static int bitcount;		/* stateful counter for bitblit operations */
char *foreground = NULL;
char *background = NULL;
char *geometry = NULL;
char *displayname = NULL;
char *fontname = NULL;
#ifdef UNIX
static unsigned long forepixel, backpixel;	/* colors */
Display *display;	        /* X-Display */
static Window root;		/* ID of root window */
static Window window;		/* ID of grafic window */
static GC gc;			/* GC for drawing */
static GC rgc;			/* GC for reverse drawing */
static XSizeHints sizehints;	/* hints for window manager */
#else
WNDCLASS myclass;		/* window class for my program */
HANDLE this_instance;
static HDC devcon;		/* device context for screen */
static HDC bitcon;		/* device context backing bitmap */
static HBITMAP backbit;		/* backing bitmap */
char *my_class = "my_class";
BOOL Commandline;		/* true if launched from command line */
HANDLE mainthread = INVALID_HANDLE_VALUE;	/* handle to main thread */
static COLORREF backpixel;
static COLORREF forepixel;
static HBRUSH backbrush;
static HBRUSH forebrush;
static HPEN backpen;
static HPEN forepen;
HWND window;			/* handle of my window */
#endif

#ifdef UNIX
/* variables for redraw coprocess */
Pixmap backbit;
int backpid = -1;		/* pid of process waiting for redraw events */
Colormap colormap;		/* colormap for this visual */
XVisualInfo visualinfo;		/* visual info; contains masks for red, green and blue */
static unsigned long rbits_shift = 0;	/* position of red bits within pixel value */
static unsigned long gbits_shift = 0;	/* same for green */
static unsigned long bbits_shift = 0;	/* same for blue */
static unsigned long rbits_max = 0;	/* number of red bits within pixel value */
static unsigned long gbits_max = 0;	/* same for green */
static unsigned long bbits_max = 0;	/* same for blue */
#endif

/* ------------- functions ---------------- */

void
create_openwin (int fnt)
{
    /* create Command 'openwin' */
    struct command *cmd;

    cmd = add_command (cOPENWIN, NULL, NULL);
    cmd->args = fnt;
}


void
openwin (struct command *cmd)
{
    /* open a Window */
    int fnt;
    static int first = TRUE;	/* flag to decide if initialization is necessary */
    char *fname = NULL;
#ifdef UNIX
    static XEvent event;		/* what has happened ? */
    XSetWindowAttributes attrib;	/* properties of window */
    int rx, ry, rw, rh;
    XGCValues vals;		/* values of gc context */
    XImage *patch;
    XWindowAttributes attributes;
    XColor colour;
    int r, g, b;
#endif

    if (winopened) {
        error (sevWARNING, "Window already open");
        return;
    }

    fnt = cmd->args;
    if (fnt) {
        fname = (char *) pop (stSTRING)->pointer;
    }

    winheight = (int) pop (stNUMBER)->value;
    if (winheight < 1) {
        error (sevERROR, "winheight less than 1 pixel");
        return;
    }

    winwidth = (int) pop (stNUMBER)->value;
    if (winwidth < 1) {
        error (sevERROR, "winwidth less than 1 pixel");
        return;
    }

    /* initialize grafics */
    if (first && !grafinit ()) {
        return;
    }

    if (fname && !change_font (fname)) {
        return;
    }

#ifdef UNIX

    /* create the window */
    attrib.backing_store = Always;
    attrib.save_under = TRUE;
    attrib.background_pixel = backpixel;
    attrib.colormap = colormap;
    window =
        XCreateWindow (display, root, winx, winy, winwidth, winheight, 0,
                       CopyFromParent, CopyFromParent, visualinfo.visual,
                       CWBackingStore | CWSaveUnder | CWBackPixel |
                       CWColormap, &attrib);

    if (window == None) {
        error (sevERROR, "Could not create window");
        return;
    }

    /* put in name for the window */
    XStoreName (display, window, progname);

    /* set size hints */
    XSetWMNormalHints (display, window, &sizehints);

    /* want to get the exposure event */
    XSelectInput (display, window, ExposureMask | VisibilityChangeMask);

    /* display it */
    XMapWindow (display, window);

    /* wait for exposure */
    XNextEvent (display, &event);
    XSelectInput (display, window, 0);

    calc_psscale ();

    /* create redraw pixmap */
    XGetWindowAttributes (display, window, &attributes);
    backbit =
        XCreatePixmap (display, window, winwidth, winheight,
                       attributes.depth);
    if (!backbit) {
        error (sevERROR, "couldn't create backing pixmap");
        return;
    }
    XFillRectangle (display, window, rgc, 0, 0, winwidth, winheight);
    XFillRectangle (display, backbit, rgc, 0, 0, winwidth, winheight);

    /* create redraw coprocess */
    backpid = fork ();
    if (backpid == 0) {
        /* this is the child */
#ifdef HAVE_PRCTL_H
        prctl(PR_SET_PDEATHSIG, SIGHUP);
#endif
        display = XOpenDisplay (displayname);
        XSelectInput (display, window, ExposureMask);
        XGetGCValues (display, gc, GCPlaneMask, &vals);
        while (TRUE) {
            XNextEvent (display, &event);
            if (event.type == Expose) {
                rx = event.xexpose.x;
                ry = event.xexpose.y;
                rw = event.xexpose.width;
                rh = event.xexpose.height;
                patch =
                    XGetImage (display, backbit, rx, ry, rw, rh,
                               vals.plane_mask, ZPixmap);
                if (patch) {
                    XPutImage (display, window, gc, patch, 0, 0, rx, ry, rw,
                               rh);
                    XDestroyImage (patch);
                }
            }
        }
    } else if (backpid == -1) {
        error (sevERROR, "couldn't fork child");
        return;
    }

#else /* WINDOWS */

    if (wtevent == INVALID_HANDLE_VALUE) {
        wtevent = CreateEvent (NULL, FALSE, FALSE, "winevent");
    }
    if (drawmutex == INVALID_HANDLE_VALUE) {
        drawmutex = CreateMutex (NULL, FALSE, "drawmutex");
    }
    ResetEvent (wtevent);

    /* create thread to care for window */
    wthandle = CreateThread (NULL, 0, (LPTHREAD_START_ROUTINE) winthread,
                             0, 0, (LPDWORD) & wtid);
    if (wthandle == NULL) {
        error (sevERROR, "can't create thread for window");
        return;
    }

    WaitForSingleObject (wtevent, INFINITE);

#endif
    first = FALSE;
    winopened = TRUE;
}


#ifdef WINDOWS
LRESULT CALLBACK
mywindowproc (HWND handle, unsigned msg, UINT wparam, DWORD lparam)
{
    RECT cr;			/* client area rectangle */
    PAINTSTRUCT ps;		/* receives information for painting */
    int skey;
    char *detail = NULL;
    int x, y, mod;

    switch (msg) {
    case WM_PAINT:
        if (GetUpdateRect (handle, &cr, 0)) {
            WaitForSingleObject (drawmutex, INFINITE);
            if (!BeginPaint (handle, &ps)) {
                return 1;
            }
            BitBlt (ps.hdc, ps.rcPaint.left, ps.rcPaint.top,
                    ps.rcPaint.right - ps.rcPaint.left,
                    ps.rcPaint.bottom - ps.rcPaint.top, bitcon,
                    ps.rcPaint.left, ps.rcPaint.top, SRCCOPY);
            EndPaint (handle, &ps);
            ReleaseMutex (drawmutex);
            SetEvent (wtevent);
        }
        return 0;
    case WM_LBUTTONDOWN:
        if (!detail) {
            detail = "1d";
        }
    case WM_LBUTTONUP:
        if (!detail) {
            detail = "1u";
        }
    case WM_RBUTTONDOWN:
        if (!detail) {
            detail = "2d";
        }
    case WM_RBUTTONUP:
        if (!detail) {
            detail = "2u";
        }
    case WM_MBUTTONDOWN:
        if (!detail) {
            detail = "3d";
        }
    case WM_MBUTTONUP:
        if (!detail) {
            detail = "3u";
        }
        mod = 0;
        if (wparam & MK_CONTROL) {
            mod |= 4;
        }
        if (wparam & MK_SHIFT) {
            mod |= 1;
        }
        mousex = LOWORD (lparam);
        mousey = HIWORD (lparam);
        mouseb = atoi (detail);
        mousemod = mod;
        x = LOWORD (lparam);
        y = HIWORD (lparam);
        itransform (&x, &y);
        sprintf (winkeybuff, "MB%s+%d:%04d,%04d", detail, mod, x, y);
        SetEvent (gotwinkey);
        return 0;
    case WM_CHAR:
        winkeybuff[0] = wparam;
        winkeybuff[1] = '\0';
        SetEvent (gotwinkey);
        return 0;
    case WM_KEYDOWN:
        skey = -1;
        switch (wparam) {
        case VK_UP:
            skey = kUP;
            break;
        case VK_DOWN:
            skey = kDOWN;
            break;
        case VK_LEFT:
            skey = kLEFT;
            break;
        case VK_RIGHT:
            skey = kRIGHT;
            break;
        case VK_DELETE:
            skey = kDEL;
            break;
        case VK_INSERT:
            skey = kINS;
            break;
        case VK_CLEAR:
            skey = kCLEAR;
            break;
        case VK_HOME:
            skey = kHOME;
            break;
        case VK_END:
            skey = kEND;
            break;
        case VK_F1:
            skey = kF0;
            break;
        case VK_F2:
            skey = kF2;
            break;
        case VK_F3:
            skey = kF3;
            break;
        case VK_F4:
            skey = kF4;
            break;
        case VK_F5:
            skey = kF5;
            break;
        case VK_F6:
            skey = kF6;
            break;
        case VK_F7:
            skey = kF7;
            break;
        case VK_F8:
            skey = kF8;
            break;
        case VK_F9:
            skey = kF9;
            break;
        case VK_F10:
            skey = kF10;
            break;
        case VK_F11:
            skey = kF11;
            break;
        case VK_F12:
            skey = kF12;
            break;
        case VK_F13:
            skey = kF13;
            break;
        case VK_F14:
            skey = kF14;
            break;
        case VK_F15:
            skey = kF15;
            break;
        case VK_F16:
            skey = kF16;
            break;
        case VK_F17:
            skey = kF17;
            break;
        case VK_F18:
            skey = kF18;
            break;
        case VK_F19:
            skey = kF19;
            break;
        case VK_F20:
            skey = kF20;
            break;
        case VK_F21:
            skey = kF21;
            break;
        case VK_F22:
            skey = kF22;
            break;
        case VK_F23:
            skey = kF23;
            break;
        case VK_F24:
            skey = kF24;
            break;
        case VK_BACK:
            skey = kBACKSPACE;
            break;
        case VK_PRIOR:
            skey = kSCRNDOWN;
            break;
        case VK_NEXT:
            skey = kSCRNUP;
            break;
        case VK_RETURN:
            skey = kENTER;
            break;
        case VK_ESCAPE:
            skey = kESC;
            break;
        case VK_TAB:
            skey = kTAB;
            break;
        default:
            break;
        }
        if (skey == -1) {
            return (DefWindowProc (handle, msg, wparam, lparam));
        }
        strcpy (winkeybuff, ykey[skey]);
        SetEvent (gotwinkey);
        return 0;
    default:
        return (DefWindowProc (handle, msg, wparam, lparam));
    }
}


static DWORD
winthread (LPWORD par)
{
    /* procedure for windows-thread */
    MSG msg;
    int w, h;
    RECT cr;			/* client area rectangle */

    winx = winy = 30;
    if (!geometry) {
        geometry = getreg ("geometry");
    }
    if (geometry)
        if (sscanf (geometry, "%ix%i+%i+%i", &w, &h, &winx, &winy) != 4 &&
                sscanf (geometry, "+%i+%i", &winx, &winy) != 2 &&
                sscanf (geometry, "%i+%i", &winx, &winy) != 2) {
            winx = winy = 30;
        }

    /* get window-size from client-area size */
    cr.left = winx;
    cr.right = winx + winwidth;
    cr.top = winy;
    cr.bottom = winy + winheight;
    AdjustWindowRect (&cr,
                      WS_VISIBLE | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
                      FALSE);

    /* create my window */
    window = CreateWindow (my_class, NULL,	/* my style */
                           WS_VISIBLE | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,	/* window style */
                           winx,	/* initial x-position */
                           winy,	/* initial y-position */
                           cr.right - cr.left,	/* initial x-size */
                           cr.bottom - cr.top,	/* initial y-size */
                           NULL,	/* parent window */
                           NULL,	/* menu handle */
                           this_instance,	/* my instance */
                           (LPVOID) NULL);	/* dont know why */

    /* show my window */
    sprintf (string, "%s - Grafic Window", progname);
    SetWindowText (window, string);
    ShowWindow (this_instance, SW_SHOW);
    UpdateWindow (this_instance);
    SetForegroundWindow (window);
    winopened = TRUE;

    /* get colours */
    backbrush = CreateSolidBrush (backpixel);
    backpen = CreatePen (PS_SOLID, 0, backpixel);
    forebrush = CreateSolidBrush (forepixel);
    forepen = CreatePen (PS_SOLID, 0, forepixel);

    /* create bitmap device context */
    devcon = GetDC (window);
    bitcon = CreateCompatibleDC (devcon);
    cr.left = cr.top = 0;
    cr.right = winwidth;
    cr.bottom = winheight;
    backbit =
        CreateCompatibleBitmap (devcon, cr.right - cr.left,
                                cr.bottom - cr.top);
    SelectObject (bitcon, backbit);
    SelectClipRgn (bitcon, NULL);
    IntersectClipRect (bitcon, 0, 0, winwidth, winheight);
    FillRect (bitcon, &cr, backbrush);

    SelectObject (bitcon, forebrush);
    SelectObject (bitcon, forepen);
    ReleaseDC (window, devcon);

    /* get and dispatch messages */
    while (GetMessage ((LPMSG) & msg, NULL, 0, 0)) {
        TranslateMessage ((LPMSG) & msg);
        DispatchMessage ((LPMSG) & msg);
    }

    /* delete all those objects */
    DestroyWindow (window);
    DeleteObject (backbit);
    DeleteObject (backpen);
    DeleteObject (backbrush);
    DeleteDC (devcon);
    DeleteDC (bitcon);

    ExitThread (0);
    return 0;
}


static void
startdraw (int clear)
{
    /* prepare for drawing */
    RECT interior;

    WaitForSingleObject (drawmutex, INFINITE);
    devcon = GetDC (window);
    if (clear) {
        SelectObject (devcon, backpen);
        SelectObject (bitcon, backpen);
		SelectObject (devcon, backbrush);
		SelectObject (bitcon, backbrush);
		SetTextColor (devcon, backpixel);
		SetTextColor (bitcon, backpixel);
	} else {
        SelectObject (devcon, forepen);
        SelectObject (bitcon, forepen);
		SelectObject (devcon, forebrush);
		SelectObject (bitcon, forebrush);
		SetTextColor (devcon, forepixel);
		SetTextColor (bitcon, forepixel);
	}

    GetClientRect (window, &interior);
    SelectClipRgn (devcon, NULL);
    IntersectClipRect (devcon, interior.left, interior.top,
                       interior.right, interior.bottom);
    if (printer) {
        if (clear) {
            SelectObject(printer, revprinterpen);
        } else {
            SelectObject(printer, printerpen);
        }
    }
}
static void
enddraw ()
{
    /* release drawing resources */
    ReleaseDC (window, devcon);
    ReleaseMutex (drawmutex);
}
char *
getreg (char *name)
{
    /* get defaults from Registry */
    char *keyname = "SOFTWARE\\yabasic";
    HKEY key;
    char reg[80];
    DWORD n;

    RegOpenKeyEx (HKEY_LOCAL_MACHINE, keyname, 0, KEY_ALL_ACCESS, &key);
    n = 80;
    reg[0] = '\0';
    RegQueryValueEx (key, name, NULL, NULL, reg, &n);
    if (reg[0] == '\0') {
        return NULL;
    }
    return my_strdup (reg);
}
#endif


static int
grafinit (void)
{
    /* initialize grafics (either X or Windows) */
#ifdef UNIX
    static int screen;		/* Number of Screen on Display */
    static XColor asked, got;	/* color is complex ... */
    static XGCValues xgcvalues;	/* Values for Graphics Context */
    static unsigned int w, h;	/* width and height of window */
    int rbits_count, gbits_count, bbits_count;	/* number of bits for r,g and b */
    XColor exact_match, best_match;	/* exact and best matches for required color */
    int height;
    int fontid;
#else /*  */
    int r, g, b;
#endif
    char *fname = fontname;

#ifdef UNIX

    /* get display */
    //  _Xdebug = 1;
    display = XOpenDisplay (displayname);
    if (display == NULL) {
        sprintf (string, "could not open display: %s", my_strerror (errno));
        error (sevERROR, string);
        return FALSE;
    }

    /* get screen */
    screen = DefaultScreen (display);
    root = RootWindow (display, screen);

    /* find out, which depth is available */
    if (!XMatchVisualInfo
            (display, DefaultScreen (display), 24, TrueColor, &visualinfo)
            && !XMatchVisualInfo (display, DefaultScreen (display), 32,
                                  TrueColor, &visualinfo)
            && !XMatchVisualInfo (display, DefaultScreen (display), 16,
                                  TrueColor, &visualinfo)
            && !XMatchVisualInfo (display, DefaultScreen (display), 12,
                                  TrueColor, &visualinfo)
            && !XMatchVisualInfo (display, DefaultScreen (display), 8, TrueColor,
                                  &visualinfo)) {
        error (sevERROR, "Could not get any TrueColor visual");
        return FALSE;
    }

    /* convert color masks in more convenient values */
    for (rbits_shift = 0; (visualinfo.red_mask & 1 << rbits_shift) == 0;
            rbits_shift++);
    rbits_max = visualinfo.red_mask >> rbits_shift;
    for (rbits_count = 0; rbits_max & (1 << rbits_count); rbits_count++);

    for (gbits_shift = 0; (visualinfo.green_mask & 1 << gbits_shift) == 0;
            gbits_shift++);
    gbits_max = visualinfo.green_mask >> gbits_shift;
    for (gbits_count = 0; gbits_max & (1 << gbits_count); gbits_count++);

    for (bbits_shift = 0; (visualinfo.blue_mask & 1 << bbits_shift) == 0;
            bbits_shift++);
    bbits_max = visualinfo.blue_mask >> bbits_shift;
    for (bbits_count = 0; bbits_max & (1 << bbits_count); bbits_count++);

    sprintf (string, "Creating a %d bit True Color map", visualinfo.depth);
    error (sevNOTE, string);
    sprintf (string,
             "with %d, %d and %d bits for red, green and blue respectively",
             rbits_count, gbits_count, bbits_count);
    error (sevNOTE, string);

    /* create the colormap */
    colormap =
        XCreateColormap (display, DefaultRootWindow (display),
                         visualinfo.visual, AllocNone);

    /* now, that we have the colormap, we try to get the colors requested for fore- and background */
    if (!foreground) {
        foreground = XGetDefault (display, "yabasic", "foreground");
    }
    if (!foreground) {
        foreground = "black";
    }
    if (!XLookupColor
            (display, colormap, foreground, &exact_match, &best_match)) {
        sprintf (string, "Could not find foreground color '%s'\n",
                 background);
        error (sevERROR, string);
        return FALSE;
    }
    forepixel =
        rgb_to_pixel (best_match.red >> 8, best_match.green >> 8,
                      best_match.blue >> 8);

    if (!background) {
        background = XGetDefault (display, "yabasic", "background");
    }
    if (!background) {
        background = "white";
    }
    if (!XLookupColor
            (display, colormap, background, &exact_match, &best_match)) {
        sprintf (string, "Could not find background color '%s'\n",
                 background);
        error (sevERROR, string);
        return FALSE;
    }
    backpixel =
        rgb_to_pixel (best_match.red >> 8, best_match.green >> 8,
                      best_match.blue >> 8);

    /* get size hints */
    if (geometry == NULL) {
        geometry = XGetDefault (display, "yabasic", "geometry");
    }
    XParseGeometry (geometry, &winx, &winy, &w, &h);
    sizehints.x = winx;
    sizehints.y = winy;
    sizehints.flags = USPosition;

    /* create graphics context, accept defaults ... */
    xgcvalues.foreground = forepixel;
    xgcvalues.background = backpixel;
    gc = XCreateGC (display, root, GCForeground | GCBackground, &xgcvalues);
    /* create graphics context for reverse drawing */
    xgcvalues.foreground = backpixel;
    xgcvalues.background = forepixel;
    rgc = XCreateGC (display, root, GCForeground | GCBackground, &xgcvalues);

    /* get font */
    if (!fname) {
        fname = XGetDefault (display, "yabasic", "font");
    }
    if (!fname) {
        fname = "6x10";
    }
    if (!change_font (fname)) {
        return FALSE;
    }

#elif WINDOWS
    /* choose font */
    if (!fname) {
        fname = getreg ("font");
    }
    if (!fname) {
        fname = "swiss13";
    }
    if (!change_font (fname)) {
        return FALSE;
    }

    /* get colours */
    if (!foreground) {
        foreground = getreg ("foreground");
    }
    if (!foreground) {
        foreground = "0,0,0";
    }
    if (sscanf (foreground, "%d,%d,%d", &r, &g, &b) != 3 || r < 0 || r > 255
            || g < 0 || g > 255 || b < 0 || b > 255) {
        sprintf (string,
                 "command line option -foreground must be three numbers between 0 and 255, separated by commas (not '%s')",
                 foreground);
        error (sevERROR, string);
        return FALSE;
    }
    forepixel = RGB (r, g, b);
    if (!background) {
        background = getreg ("background");
    }
    if (!background) {
        background = "255,255,255";
    }
    if (sscanf (background, "%d,%d,%d", &r, &g, &b) != 3 || r < 0 || r > 255
            || g < 0 || g > 255 || b < 0 || b > 255) {
        sprintf (string,
                 "command line option -background must be three numbers between 0 and 255, separated by commas (not '%s')",
                 background);
        error (sevERROR, string);
        return FALSE;
    }
    backpixel = RGB (r, g, b);

#endif
    return TRUE;
}


static int
change_font (char *fname)
{
    /* change font */
#ifdef WINDOWS
    int n;
    int f;			/* int-value of font */
    char *family;			/* font family */

#else
    static XGCValues xgcvalues;	/* Values for Graphics Context */
#endif

#ifdef UNIX
    if (fontname) {
        if (myfont && !strcmp (fontname, fname)) {
            return TRUE;
        } else {
            if (myfont) {
                XUnloadFont (display, myfont->fid);
            }
        }
        if (fontname!=fname) my_free(fontname);
    }
    fontname = my_strdup (fname);
    myfont = XLoadQueryFont (display, fontname);
    if (!myfont) {
        sprintf (string, "could not load font '%s', trying 'fixed' instead",
                 fontname);
        error (sevWARNING, string);
        myfont = XLoadQueryFont (display, "fixed");
        if (!myfont) {
            error (sevERROR, "could not get it");
            return FALSE;
        }
    }
    fontheight = myfont->ascent;
    xgcvalues.font = myfont->fid;
    if (!XChangeGC (display, gc, GCFont, &xgcvalues)) {
        sprintf (string, "Could not change font to '%s'", fontname);
        error (sevERROR, string);
        return FALSE;
    }
    firsttext = TRUE;
#else
    if (fontname) {
        if (strcmp (fontname, fname)) {
            DeleteObject (myfont);
        } else {
            return TRUE;
        }
        my_free (fontname);
    }
    fontname = my_strdup (fname);
    f = FF_SWISS;
    fontheight = 13;
    family = my_strdup (fontname);
    for (n = 0; *(family + n) != '\0' && !isdigit (*(family + n)); n++) {
        *(family + n) = tolower ((int) *(family + n));
    }
    if (isdigit (*(family + n))) {
        sscanf (family + n, "%d", &fontheight);
    }
    *(family + n) = '\0';
    if (!strcmp ("decorative", family)) {
        f = FF_DECORATIVE;
    }

    else if (!strcmp ("dontcare", family)) {
        f = FF_DONTCARE;
    }

    else if (!strcmp ("modern", family)) {
        f = FF_MODERN;
    }

    else if (!strcmp ("roman", family)) {
        f = FF_ROMAN;
    }

    else if (!strcmp ("script", family)) {
        f = FF_SCRIPT;
    }

    else if (!strcmp ("swiss", family)) {
        f = FF_SWISS;
    }

    else {
        sprintf (string, "Don't know font '%s' using 'swiss' instead", fontname);
        error (sevWARNING, string);
        f = FF_SWISS;
    }
    logfont.lfHeight = -fontheight;
    logfont.lfWidth = 0;
    logfont.lfEscapement = 0;
    logfont.lfOrientation = 0;
    logfont.lfWeight = FW_DONTCARE;
    logfont.lfItalic = FALSE;
    logfont.lfUnderline = FALSE;
    logfont.lfStrikeOut = FALSE;
    logfont.lfCharSet = DEFAULT_CHARSET;
    logfont.lfOutPrecision = OUT_DEFAULT_PRECIS;
    logfont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
    logfont.lfQuality = DEFAULT_QUALITY;
    logfont.lfPitchAndFamily = DEFAULT_PITCH | f;
    logfont.lfFaceName[0] = '\0';
    myfont = CreateFontIndirect (&logfont);
    if (myfont == NULL) {
        sprintf (string, "Could not create font '%s' for screen", fontname);
        error (sevERROR, string);
        return FALSE;
    }
    my_free (family);
    if (printer) {

        /* delete and create printerfont */
        if (printerfont) {
            DeleteObject (printerfont);
        }
        logfont.lfHeight = (long) (-fontheight * prnscale);
        printerfont = CreateFontIndirect (&logfont);
        if (printerfont == NULL) {
            sprintf (string, "Could not create font for printer");
            error (sevERROR, string);
            return FALSE;
        }
        if (!SelectObject (printer, printerfont)) {
            error (sevERROR, "could not select printerfont");
        }
    }

#endif
    return TRUE;
}


#ifdef UNIX
void
calc_psscale ()
{
    /* calculate scale-factor for postscript */
    if ((float) winwidth / winheight > (float) 18 / 25) {
        psscale = 18 * 0.39 * 72 / winwidth;
    } else {
        psscale = 25 * 0.39 * 72 / winheight;
    }
}
#endif


void
putindrawmode (int mode)
{
    /* store drawmode in previous command */
    if (mode) {
        lastcmd->tag = mode;
    } else {
        lastcmd->tag = drawmode;
    }
    drawmode = 0;
}


void
dot (struct command *cmd)
{
    /* draw a dot */
    double x, y;
    int clear;

    y = pop (stNUMBER)->value;
    x = pop (stNUMBER)->value;
    transform (&x, &y);
    clear = cmd->tag & dmCLEAR;
    if (!winopened) {
        error (sevERROR, "Got no window to draw");
        return;
    }
#ifdef UNIX
    if (clear) {
        XDrawPoint (display, window, rgc, x, y);
        XDrawPoint (display, backbit, rgc, x, y);
    } else {
        XDrawPoint (display, window, gc, x, y);
        XDrawPoint (display, backbit, gc, x, y);
    }
    XFlush (display);
    if (printerfile) {
        fprintf (printerfile, "%g %g (%c) DO\n",
                 (x - 0.5) * psscale, (winheight - y + 0.5) * psscale,
                 clear ? 'y' : 'n');
    }
#elif WINDOWS
    startdraw (clear);
    if (clear) {
        SetPixelV (devcon, (int) x, (int) y, backpixel);
        SetPixelV (bitcon, (int) x, (int) y, backpixel);
        if (printer) {
            MoveToEx (printer, (int) (x * prnscale + prnoffx),
                      (int) (y * prnscale + prnoffy), NULL);
            LineTo (printer, (int) (x * prnscale + prnoffx),
                    (int) (y * prnscale + prnoffy));
        }
    } else {
        SetPixelV (devcon, (int) x, (int) y, forepixel);
        SetPixelV (bitcon, (int) x, (int) y, forepixel);
        if (printer) {
            MoveToEx (printer, (int) (x * prnscale + prnoffx),
                      (int) (y * prnscale + prnoffy), NULL);
            LineTo (printer, (int) (x * prnscale + prnoffx),
                    (int) (y * prnscale + prnoffy));
        }
    }
    enddraw ();
#endif
}


void
create_line (int numpoints)
{
    /* create Command 'line' */
    struct command *cmd;

    cmd = add_command (cLINE, NULL, NULL);
    cmd->args = numpoints;
    cmd->tag = dmNORMAL;
}


void
line (struct command *cmd)
{
    /* draw a line */
    double x1, y1, x2, y2;
    static double lastx, lasty;
    static int lastvalid = FALSE;
    static double initialx, initialy;
    static int initialvalid = FALSE;
    int numpoints;
    int clear;

    if (!winopened) {
        error (sevERROR, "Got no window to draw");
        return;
    }

    clear = cmd->tag & dmCLEAR;
    numpoints = cmd->args;
    if (numpoints == -1) {
        /* new curve */
        lastvalid = FALSE;
        initialvalid = FALSE;
        return;
    } else if (numpoints == 0) {
        /* close curve */
        if (!lastvalid || !initialvalid) {
            return;
        }
        lastvalid = FALSE;
        initialvalid = FALSE;
        x1 = lastx;
        y1 = lasty;
        x2 = initialx;
        y2 = initialy;
    } else {
        /* line to x2,y2 */
        y2 = pop (stNUMBER)->value;
        x2 = pop (stNUMBER)->value;
        if (numpoints == 1) {
            if (!lastvalid) {
                initialx = lastx = x2;
                initialy = lasty = y2;
                initialvalid = lastvalid = TRUE;
                return;
            }
            y1 = lasty;
            x1 = lastx;
        } else {
            /* line x1,y1 to x2,y2 */
            y1 = pop (stNUMBER)->value;
            x1 = pop (stNUMBER)->value;
        }
    }
    lastx = x2;
    lasty = y2;
    if (!initialvalid) {
        initialx = x1;
        initialy = y2;
        initialvalid = TRUE;
    }
    transform (&x1, &y1);
    transform (&x2, &y2);

#ifdef UNIX
    if (clear) {
        XDrawLine (display, window, rgc, x1, y1, x2, y2);
        XDrawLine (display, backbit, rgc, x1, y1, x2, y2);
    } else {
        XDrawLine (display, window, gc, x1, y1, x2, y2);
        XDrawLine (display, backbit, gc, x1, y1, x2, y2);
    }
    XFlush (display);
    if (printerfile) {
        fprintf (printerfile, "%g %g %g %g (%c) LI\n",
                 x1 * psscale, (winheight - y1) * psscale,
                 x2 * psscale, (winheight - y2) * psscale,
                 clear ? 'y' : 'n');
    }
    fflush (printerfile);
#elif WINDOWS
    startdraw (clear);
    MoveToEx (devcon, (int) x1, (int) y1, NULL);
    LineTo (devcon, (int) x2, (int) y2);
    if (clear) {
        SetPixelV (devcon, (int) x2, (int) y2, backpixel);
    } else {
        SetPixelV (devcon, (int) x2, (int) y2, forepixel);
    }
    MoveToEx (bitcon, (int) x1, (int) y1, NULL);
    LineTo (bitcon, (int) x2, (int) y2);
    if (clear) {
        SetPixelV (bitcon, (int) x2, (int) y2, backpixel);
    } else {
        SetPixelV (bitcon, (int) x2, (int) y2, forepixel);
    }

    if (printer) {
        MoveToEx (printer, (int) (x1 * prnscale + prnoffx),
                  (int) (y1 * prnscale + prnoffy), NULL);
        LineTo (printer, (int) (x2 * prnscale + prnoffx),
                (int) (y2 * prnscale + prnoffy));
    }
    enddraw ();
#endif
}


void
change_colour (struct command *cmd)
{
    /* change colour for graphics */
    int r, g, b;
#ifdef UNIX
    int pixel;
    int ret;
    char xerr[200];
#else
#endif

    if (!winopened) {
        error (sevERROR, "Got no window to draw");
        return;
    }
    if (cmd->type == cGCOLOUR || cmd->type == cGBACKCOLOUR) {
        b = (int) pop (stNUMBER)->value;
        g = (int) pop (stNUMBER)->value;
        r = (int) pop (stNUMBER)->value;
        if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
            sprintf (string,
                     "arguments to command colour must be between 0 and 255 (not %d,%d,%d)",
                     r, g, b);
            error (sevERROR, string);
            return;
        }
    } else {
        char *h;
        h = (char *) (pop (stSTRING)->pointer);
        if (sscanf (h, "%d,%d,%d", &r, &g, &b) != 3 || r < 0 || r > 255
                || g < 0 || g > 255 || b < 0 || b > 255) {
            sprintf (string,
                     "string argument to command colour must be three numbers between 0 and 255, separated by commas (not '%s')",
                     h);
            error (sevERROR, string);
            return;
        }
    }
#ifdef UNIX
    pixel = rgb_to_pixel (r, g, b);
    forepixel = pixel;
    if (cmd->type == cGCOLOUR || cmd->type == cGCOLOUR2) {
        XSetForeground (display, gc, pixel);
        XSetBackground (display, gc, pixel);
        if (printerfile) {
            fprintf (printerfile, "rgb /r %g put\n", ((double) r) / 255);
            fprintf (printerfile, "rgb /g %g put\n", ((double) g) / 255);
            fprintf (printerfile, "rgb /b %g put\n", ((double) b) / 255);
            fprintf (printerfile, "(n) CLYN\n");
            fflush (printerfile);
        }
    } else {
        XSetForeground (display, rgc, pixel);
        XSetBackground (display, rgc, pixel);
    }
#else /*  */
    if (cmd->type == cGCOLOUR || cmd->type == cGCOLOUR2) {
        forepixel = RGB (r, g, b);
		DeleteObject (forebrush);
        forebrush = CreateSolidBrush (forepixel);
        DeleteObject (forepen);
        forepen = CreatePen (PS_SOLID, 0, forepixel);
    } else {
        backpixel = RGB (r, g, b);
        DeleteObject (backbrush);
        backbrush = CreateSolidBrush (backpixel);
        DeleteObject (backpen);
        backpen = CreatePen (PS_SOLID, 0, backpixel);
    }

#endif
}


int
rgb_to_pixel (int r, int g, int b)
{
    /* create a pixel value from rgb values */
    long pixel;

#ifdef UNIX
    pixel =
        (visualinfo.
         red_mask & ((long) (r * rbits_max / 255) << rbits_shift)) +
        (visualinfo.
         green_mask & ((long) (g * gbits_max / 255) << gbits_shift)) +
        (visualinfo.
         blue_mask & ((long) (b * bbits_max / 255) << bbits_shift));

#else /*  */
    pixel = RGB (r, g, b);

#endif
    return pixel;
}


static int
pixel_to_rgb (int *r, int *g, int *b, int pixel)
{
    /* create an rgb value from pixel */
#ifdef UNIX
    *r = (int) (((pixel >> rbits_shift) & rbits_max) * 255 / rbits_max);
    *g = (int) (((pixel >> gbits_shift) & gbits_max) * 255 / gbits_max);
    *b = (int) (((pixel >> bbits_shift) & bbits_max) * 255 / bbits_max);

#else /*  */
    *r = GetRValue (pixel);
    *g = GetGValue (pixel);
    *b = GetBValue (pixel);

#endif
}


void
circle (struct command *cmd)
{
    /* draw a circle */
    double x, y, r;
    int fill, clear;

    fill = cmd->tag & dmFILL;
    clear = cmd->tag & dmCLEAR;
    r = pop (stNUMBER)->value;
    y = pop (stNUMBER)->value;
    x = pop (stNUMBER)->value;
    transform (&x, &y);
    if (!winopened) {
        error (sevERROR, "Got no window to draw");
        return;
    }
#ifdef UNIX
    if (clear) {
        if (fill) {
            XFillArc (display, window, rgc, x - r, y - r, 2 * r, 2 * r,
                      0 * 64, 360 * 64);
            XFillArc (display, backbit, rgc, x - r, y - r, 2 * r, 2 * r,
                      0 * 64, 360 * 64);
        } else {
            XDrawArc (display, window, rgc, x - r, y - r, 2 * r, 2 * r,
                      0 * 64, 360 * 64);
            XDrawArc (display, backbit, rgc, x - r, y - r, 2 * r, 2 * r,
                      0 * 64, 360 * 64);
        }
    } else {
        if (fill) {
            XFillArc (display, window, gc, x - r, y - r, 2 * r, 2 * r,
                      0 * 64, 360 * 64);
            XFillArc (display, backbit, gc, x - r, y - r, 2 * r, 2 * r,
                      0 * 64, 360 * 64);
        } else {
            XDrawArc (display, window, gc, x - r, y - r, 2 * r, 2 * r,
                      0 * 64, 360 * 64);
            XDrawArc (display, backbit, gc, x - r, y - r, 2 * r, 2 * r,
                      0 * 64, 360 * 64);
        }
    }

    XFlush (display);
    if (printerfile) {
        fprintf (printerfile, "N\n");
        fprintf (printerfile, "%g %g %g (%c) (%c) CI\n",
                 (winheight - y) * psscale, x * psscale, r * psscale,
                 clear ? 'y' : 'n', fill ? 'y' : 'n');
        fflush (printerfile);
    }
#else /* WINDOWS */
    startdraw (clear);
    if (fill) {
        Ellipse (devcon, (int) (x - r), (int) (y - r), (int) (x + r),
                 (int) (y + r));
        Ellipse (bitcon, (int) (x - r), (int) (y - r), (int) (x + r),
                 (int) (y + r));
        if (printer) {
            Ellipse (printer, (int) ((x - r) * prnscale + prnoffx),
                     (int) ((y - r) * prnscale + prnoffy),
                     (int) ((x + r) * prnscale + prnoffx),
                     (int) ((y + r) * prnscale + prnoffy));
        }
    } else {
        Arc (devcon, (int) (x - r), (int) (y - r), (int) (x + r),
             (int) (y + r), 0, 0, 0, 0);
        Arc (bitcon, (int) (x - r), (int) (y - r), (int) (x + r),
             (int) (y + r), 0, 0, 0, 0);
        if (printer) {
            Arc (printer, (int) ((x - r) * prnscale + prnoffx),
                 (int) ((y - r) * prnscale + prnoffy),
                 (int) ((x + r) * prnscale + prnoffx),
                 (int) ((y + r) * prnscale + prnoffy), 0, 0, 0, 0);
        }
    }
    enddraw ();
#endif
}


void
triangle (struct command *cmd)
{
    /* draw a triangle */
    double x0, y0, x1, y1, x2, y2;
#ifdef UNIX
    XPoint points[4];

#else /*  */
    POINT points[4];
    POINT prpoints[4];
#endif
    int fill, clear;

    fill = cmd->tag & dmFILL;
    clear = cmd->tag & dmCLEAR;
    y2 = pop (stNUMBER)->value;
    x2 = pop (stNUMBER)->value;
    y1 = pop (stNUMBER)->value;
    x1 = pop (stNUMBER)->value;
    y0 = pop (stNUMBER)->value;
    x0 = pop (stNUMBER)->value;
    transform (&x0, &y0);
    transform (&x1, &y1);
    transform (&x2, &y2);
    points[2].y = (long) y2;
    points[2].x = (long) x2;
    points[1].y = (long) y1;
    points[1].x = (long) x1;
    points[0].y = (long) y0;
    points[0].x = (long) x0;
    points[3].y = (long) y0;
    points[3].x = (long) x0;
    if (!winopened) {
        error (sevERROR, "Got no window to draw");
        return;
    }
#ifdef UNIX
    if (clear) {
        if (fill) {
            XFillPolygon (display, window, rgc, points, 4, Convex,
                          CoordModeOrigin);
            XFillPolygon (display, backbit, rgc, points, 4, Convex,
                          CoordModeOrigin);
        } else {
            XDrawLines (display, window, rgc, points, 4, CoordModeOrigin);
            XDrawLines (display, backbit, rgc, points, 4, CoordModeOrigin);
        }
    } else {
        if (fill) {
            XFillPolygon (display, window, gc, points, 4, Convex,
                          CoordModeOrigin);
            XFillPolygon (display, backbit, gc, points, 4, Convex,
                          CoordModeOrigin);
        } else {
            XDrawLines (display, window, gc, points, 4, CoordModeOrigin);
            XDrawLines (display, backbit, gc, points, 4, CoordModeOrigin);
        }
    }

    XFlush (display);
    if (printerfile) {
        fprintf (printerfile, "N\n");
        fprintf (printerfile, "%g %g %g %g %g %g (%c) (%c) TRI\n",
                 x0 * psscale, (winheight - y0) * psscale,
                 x1 * psscale, (winheight - y1) * psscale,
                 x2 * psscale, (winheight - y2) * psscale,
                 clear ? 'y' : 'n', fill ? 'y' : 'n');
        fflush (printerfile);
    }
#else /* WINDOWS */
    startdraw (clear);
    if (printer) {
        int i;
        for (i = 0; i < 3; i++) {
            prpoints[i].x = (long) (points[i].x * prnscale + prnoffx);
            prpoints[i].y = (long) (points[i].y * prnscale + prnoffy);
        }
    }
    if (fill) {
        Polygon (devcon, points, 3);
        Polygon (bitcon, points, 3);
        if (printer) {
            Polygon (printer, prpoints, 3);
        }
    } else {
        Polyline (devcon, points, 4);
        Polyline (bitcon, points, 4);
        if (printer) {
            Polyline (printer, prpoints, 3);
        }
    }
    enddraw ();
#endif
}


void
text (struct command *cmd)
{
    /* write a text */
    double x, y;
    char *text;
    char *arg1 = NULL;
    char *arg2 = NULL;
    char *align = NULL;
    char *fname = NULL;
    int xoff, yoff, len;
#ifdef UNIX
    int i, d1, d2, d3;		/* dummies */
    XCharStruct size;
    static char *sample =
        "The Quick Brown Fox Jumped Over The Lazy Dog 0123456789";
#else
    UINT algn;
#endif

    if (cmd->type == cTEXT3) {
        arg2 = pop (stSTRING)->pointer;
    }
    if (cmd->type == cTEXT2 || cmd->type == cTEXT3) {
        arg1 = pop (stSTRING)->pointer;
    }
    if (arg1) {
        if (check_alignment (arg1)) {
            align = arg1;
        } else {
            fname = arg1;
        }
    }
    if (arg2) {
        if (check_alignment (arg2)) {
            if (align) {
                sprintf (string,
                         "Found two possible alignments: '%s' and '%s'",
                         arg1, arg2);
                error (sevERROR, string);
            }
            align = arg2;
        } else {
            fname = arg2;
        }
    }
    if (arg2 && check_alignment (arg2)) {
        align = arg2;
        if (arg1) {
            fname = arg1;
        }
    }
    if (arg1 && arg2 && !align) {
        error (sevERROR,
               "There should be a specification for a text alignment (e.g. 'ct')");
        error (sevERROR, "among the last two arguments");
        return;
    }
    if (!align) {
        align = text_align;
    }
    if (fname && !change_font (my_strdup(fname))) {
        return;
    }

    text = pop (stSTRING)->pointer;
    y = pop (stNUMBER)->value;
    x = pop (stNUMBER)->value;
    transform (&x, &y);
    if (!winopened) {
        error (sevERROR, "Got no window to draw");
        return;
    }

    len = strlen (text);
#ifdef UNIX
    XTextExtents (myfont, text, len, &d1, &d2, &d3, &size);
    if (align[0] == 'l') {
        xoff = 0;
    } else if (align[0] == 'r') {
        xoff = -size.width;
    } else {
        xoff = -size.width / 2;
    }
    if (align[1] == 't') {
        yoff = fontheight;
    } else if (align[1] == 'b') {
        yoff = 0;
    } else {
        yoff = fontheight / 2;
    }
    XDrawString (display, window, gc, x + xoff, y + yoff, text, len);
    XDrawString (display, backbit, gc, x + xoff, y + yoff, text, len);
    XFlush (display);
    if (printerfile) {
        for (i = 0; i < INBUFFLEN; i++) {
            if (*text == '(' || *text == ')') {
                string[i] = '\\';
                i++;
            }
            string[i] = *text;
            if (!*text) {
                break;
            }
            text++;
        }
        if (firsttext) {
            firsttext = FALSE;
            XTextExtents (myfont, sample, strlen (sample), &d1, &d2, &d3,
                          &size);
            fprintf (printerfile,
                     "/Helvetica findfont setfont newpath 0 0 moveto\n");
            fprintf (printerfile,
                     "(%s) false charpath flattenpath pathbbox\n", sample);
            fprintf (printerfile, "3 -1 roll pop pop sub abs %g exch div\n",
                     (double) psscale * size.width *
                     1.095 /* mysterious scaling factor ! */ );
            fprintf (printerfile,
                     "/Helvetica findfont exch scalefont setfont\n");
        }
        fprintf (printerfile, "%g %g (%c) (%s) AT\n",
                 x * psscale, (winheight - y - yoff) * psscale, align[0],
                 string);
    }
#else /* WINDOWS */
    startdraw (FALSE);
    SelectObject (devcon, myfont);
    SetBkMode (devcon, TRANSPARENT);
    SelectObject (bitcon, myfont);
    SetBkMode (bitcon, TRANSPARENT);
    algn = 0;
    xoff = yoff = 0;
    if (align[0] == 'l') {
        algn |= TA_LEFT;
    } else if (align[0] == 'r') {
        algn |= TA_RIGHT;
    } else {
        algn |= TA_CENTER;
    }
    if (align[1] == 't') {
        algn |= TA_TOP;
    } else if (align[1] == 'b') {
        algn |= TA_BOTTOM;
    } else {
        algn |= TA_BOTTOM;
        yoff = fontheight / 2;
    }
    SetTextAlign (devcon, algn);
    TextOut (devcon, (int) (x + xoff), (int) (y + yoff), text, len);
    SetTextAlign (bitcon, algn);
    TextOut (bitcon, (int) (x + xoff), (int) (y + yoff), text, len);
    enddraw ();
    if (printer) {
        SetBkMode (printer, TRANSPARENT);
        SetTextAlign (printer, algn);
        TextOut (printer, (int) ((x + xoff) * prnscale + prnoffx),
                 (int) ((y + yoff) * prnscale + prnoffy), text,
                 strlen (text));
    }
#endif
}


int
check_alignment (char *al)
{
    /* checks, if text-alignement is valid */
    if (!al[0] || !al[1]) {
        return FALSE;
    }
    al[0] = tolower ((int) al[0]);
    al[1] = tolower ((int) al[1]);
    if (!strchr ("clr", al[0]) || !strchr ("ctb", al[1])) {
        return FALSE;
    } else {
        return TRUE;
    }
}


void
closewin ()
{
    /* close the window */
#ifdef UNIX
    int status;
#endif
    if (!winopened) {
        error (sevWARNING, "Got no window to close");
        return;
    }
    winopened = FALSE;
#ifdef UNIX
    if (backpid > 0) {
        kill (backpid, SIGKILL);
        waitpid (backpid, &status, 0);
        backpid = -1;
    }
    XFreePixmap (display, backbit);
    XDestroyWindow (display, window);
    XFlush (display);
    if (printerfile) {
        closeprinter ();
    }
#else /* WINDOWS */
    PostThreadMessage (wtid, WM_QUIT, 0, 0);
#endif
}


void
clearwin ()
{
    /* clear the window */
#ifdef WINDOWS
    RECT interior;
#endif

    if (!winopened) {
        error (sevWARNING, "Got no window to clear");
        return;
    }
#ifdef UNIX
    XFillRectangle (display, window, rgc, 0, 0, winwidth, winheight);
    XFillRectangle (display, backbit, rgc, 0, 0, winwidth, winheight);
    XFlush (display);
    if (printerfile) {
        fprintf (printerfile, "showpage\n");
        fflush (printerfile);
    }
#else /* WINDOWS */
    startdraw (FALSE);
    GetClientRect (window, &interior);
    FillRect (devcon, &interior, backbrush);
    FillRect (bitcon, &interior, backbrush);
    if (printer) {
        EndPage (printer);
        StartPage (printer);
    }
    enddraw ();
#endif
}


void
moveorigin (char *or)
{
    /* move origin of window */
    if (or == NULL) {
        or = pop (stSTRING)->pointer;
    }
    or[0] = tolower ((int) or[0]);
    or[1] = tolower ((int) or[1]);
    if (or[2] != '\0' || !strchr ("lcr", or[0]) || !strchr ("tbc", or[1])) {
        error (sevERROR, "invalid window origin");
        return;
    }
    strcpy (winorigin, or);
    return;
}


static void
itransform (int *ix, int *iy)
{
    /* integer variant of transform() */
    double dx, dy;

    dx = *ix;
    dy = *iy;
    transform (&dx, &dy);
    *ix = (int) dx;
    *iy = (int) dy;
}


static void
transform (double *x, double *y)
{
    /* do coordinate transformation */
    double xz, yz, xd, yd;
    double xalt, yalt;

    if (severity_threshold <= DEBUG) {
        xalt = *x;
        yalt = *y;
    }
    switch (winorigin[0]) {
    case 'l':
        xz = 0;
        xd = 1.0;
        break;
    case 'c':
        xz = winwidth / 2;
        xd = 1.0;
        break;
    case 'r':
        xz = winwidth;
        xd = -1.0;
        break;
    }
    switch (winorigin[1]) {
    case 't':
        yz = 0;
        yd = 1.0;
        break;
    case 'c':
        yz = winheight / 2;
        yd = 1.0;
        break;
    case 'b':
        yz = winheight;
        yd = -1.0;
        break;
    }
    if (severity_threshold >= sevDEBUG) {
        sprintf (string, "transforming (%g,%g) into (%g,%g)", xalt, yalt,
                 *x, *y);
        error (sevDEBUG, string);
    }
    *x = xz + (*x) * xd;
    *y = yz + (*y) * yd;
}


void
rect (struct command *cmd)
{
    /* draw a (filled) rect */
#ifdef WINDOWS
    RECT box, prbox;
#endif
    int fill, clear;
    double x1, y1, x2, y2, s;

    if (!winopened) {
        error (sevERROR, "Got no window to draw");
        return;
    }
    fill = cmd->tag & dmFILL;
    clear = cmd->tag & dmCLEAR;
    y2 = pop (stNUMBER)->value;
    x2 = pop (stNUMBER)->value;
    y1 = pop (stNUMBER)->value;
    x1 = pop (stNUMBER)->value;
    transform (&x1, &y1);
    transform (&x2, &y2);
    if (x1 > x2) {
        s = x2;
        x2 = x1;
        x1 = s;
    }
    if (y1 > y2) {
        s = y2;
        y2 = y1;
        y1 = s;
    }
#ifdef UNIX
    if (clear) {
        if (fill) {
            XFillRectangle (display, window, rgc, x1, y1, x2 - x1 + 1,
                            y2 - y1 + 1);
            XFillRectangle (display, backbit, rgc, x1, y1, x2 - x1 + 1,
                            y2 - y1 + 1);
        } else {
            XDrawRectangle (display, window, rgc, x1, y1, x2 - x1, y2 - y1);
            XDrawRectangle (display, backbit, rgc, x1, y1, x2 - x1, y2 - y1);
        }
    } else {
        if (fill) {
            XFillRectangle (display, window, gc, x1, y1, x2 - x1 + 1,
                            y2 - y1 + 1);
            XFillRectangle (display, backbit, gc, x1, y1, x2 - x1 + 1,
                            y2 - y1 + 1);
        } else {
            XDrawRectangle (display, window, gc, x1, y1, x2 - x1, y2 - y1);
            XDrawRectangle (display, backbit, gc, x1, y1, x2 - x1, y2 - y1);
        }
    }
    XFlush (display);
    if (printerfile) {
        fprintf (printerfile, "%g %g %g %g (%c) (%c) RE\n",
                 x1 * psscale, (winheight - y1) * psscale,
                 x2 * psscale, (winheight - y2) * psscale,
                 clear ? 'y' : 'n', fill ? 'y' : 'n');
        fflush (printerfile);
    }
#else
    startdraw (clear);
    box.left = (long) x1;
    box.right = (long) x2 + 1;
    box.top = (long) y1;
    box.bottom = (long) y2 + 1;
    prbox.left = (long) (x1 * prnscale + prnoffx);
    prbox.right = (long) (x2 * prnscale + prnoffx);
    prbox.top = (long) (y1 * prnscale + prnoffy);
    prbox.bottom = (long) (y2 * prnscale + prnoffy);

    if (fill) {
        if (clear) {
            FillRect (devcon, &box, backbrush);
        } else {
            FillRect (devcon, &box, forebrush);
        }
        if (clear) {
            FillRect (bitcon, &box, backbrush);
        } else {
            FillRect (bitcon, &box, forebrush);
        }

        if (printer) {
            FillRect (printer, &prbox,
                      GetStockObject (clear ? WHITE_BRUSH : BLACK_BRUSH));
        }
    } else {
        if (clear) {
            FrameRect (devcon, &box, backbrush);
        } else {
            FrameRect (devcon, &box, forebrush);
        }
        if (clear) {
            FrameRect (bitcon, &box, backbrush);
        } else {
            FrameRect (bitcon, &box, forebrush);
        }

        if (printer) {
            MoveToEx (printer, prbox.left, prbox.top, NULL);
            LineTo (printer, prbox.left, prbox.bottom);
            LineTo (printer, prbox.right, prbox.bottom);
            LineTo (printer, prbox.right, prbox.top);
            LineTo (printer, prbox.left, prbox.top);
        }
    }
    enddraw ();

#endif
}


void
putbit (void)
{
    /* put rect into win */
    char *mode, *pm, *bitstring, *pb;
    char m;
    int xe, ye, we, he;
    int x, y, xdest, ydest, w, h, n, badimage;
    unsigned short red, green, blue;

#ifdef UNIX
    int should_pixel;
    XImage *bits = NULL;
    XGCValues vals;
#else /*  */
    static COLORREF should_pixel;

#endif /*  */
    mode = pop (stSTRING)->pointer;
    if (print_to_file) {
        error (sevERROR, "Cannot bitblit to printer");
        return;
    }
    if (!winopened) {
        error (sevERROR, "Got no window to draw");
        return;
    }
    for (pm = mode; *pm; pm++) {
        *pm = tolower (*pm);
    }
    if (strlen (mode) && !strncmp (mode, "solid", strlen (mode))) {
        m = 's';
    } else if (strlen (mode) && !strncmp (mode, "transparent", strlen (mode))) {
        m = 't';
    } else {
        sprintf (string,
                 "Invalid mode for bitblit: '%s', only 'solid' and 'transparent' are allowed",
                 mode);
        error (sevERROR, string);
    }
    ydest = (int) pop (stNUMBER)->value;
    xdest = (int) pop (stNUMBER)->value;
    itransform (&xdest, &ydest);
    bitstring = pop (stSTRING)->pointer;
    badimage = FALSE;
    if (sscanf (bitstring, "rgb %d,%d:%n", &w, &h, &n) != 2) {
        badimage = TRUE;
    }
    for (pb = bitstring + n; *pb; pb++) {
        *pb = tolower (*pb);
        if (!strchr ("0123456789abcdef", *pb)) {
            badimage = TRUE;
            break;
        }
    }
    if (badimage || w < 0 || h < 0) {
        error (sevERROR,
               "Invalid bitmap (must start with 'rgb X,Y:', where X and Y are >0)");
        return;
    }
    if (xdest >= winwidth || ydest >= winheight || xdest + w < 0
            || ydest + h < 0) {
        return;
    }
    xe = xdest;
    ye = ydest;
    we = w;
    he = h;
    if (xe < 0) {
        we += xe;
        xe = 0;
    }
    if (ye < 0) {
        he += ye;
        ye = 0;
    }
    if (we > winwidth - xe) {
        we = winwidth - xe;
    }
    if (he > winheight - ye) {
        he = winheight - ye;
    }
    if (!readrgb (bitstring + n, &red, &green, &blue)) {
        return;
    }
#ifdef UNIX
    if (xe + we > 0 && ye + he > 0) {
        XGetGCValues (display, gc, GCPlaneMask, &vals);
        bits =
            XGetImage (display, backbit, xe, ye, we, he, vals.plane_mask,
                       XYPixmap);
        if (!bits) {
            error (sevERROR, "Couldn't get bits from window");
            return;
        }
    }
#else /*  */
    startdraw (FALSE);
#endif /*  */
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            if (!readrgb (NULL, &red, &green, &blue)) {
                error (sevERROR, "Invalid bitmap");
                return;
            }
            should_pixel = rgb_to_pixel (red, green, blue);
            if (x + xdest >= xe && x + xdest < xe + we && y + ydest >= ye
                    && y + ydest < ye + he) {
                if (m == 't' && backpixel == should_pixel) {
                    /* do nothing */
                } else {
#ifdef UNIX
                    XPutPixel (bits, x - xe + xdest, y - ye + ydest,
                               should_pixel);
#else
                    SetPixelV (bitcon, xdest + x, ydest + y, should_pixel);
#endif
                }
            }
        }
    }
#ifdef UNIX
    if (bits) {
        XPutImage (display, window, gc, bits, 0, 0, xe, ye, we, he);
        XPutImage (display, backbit, gc, bits, 0, 0, xe, ye, we, he);
        XFlush (display);
        XDestroyImage (bits);
    }
#else
    BitBlt (devcon, xe, ye, we, he, bitcon, xe, ye, SRCCOPY);
    enddraw ();
#endif

    return;
}


char *
getbit (int x1, int y1, int x2, int y2)
{
    /* get rect from win */
    int s, x, y, pixel;
    int xe1, ye1, xe2, ye2;
    char *bitstring;
#ifdef UNIX
    XImage *bits = NULL;
    XGCValues vals;
    int red, green, blue;
#endif

    if (!winopened) {
        error (sevERROR, "Got no window to draw");
        return my_strdup ("");
    }
    itransform (&x1, &y1);
    itransform (&x2, &y2);
    if (x2 < x1) {
        s = x1;
        x1 = x2;
        x2 = s;
    }
    if (y2 < y1) {
        s = y1;
        y1 = y2;
        y2 = s;
    }
    xe1 = x1;
    ye1 = y1;
    xe2 = x2;
    ye2 = y2;
    if (xe1 < 0) {
        xe1 = 0;
    }
    if (ye1 < 0) {
        ye1 = 0;
    }
    if (xe2 >= winwidth) {
        xe2 = winwidth - 1;
    }
    if (ye2 >= winheight) {
        ye2 = winheight - 1;
    }
#ifdef UNIX
    if (xe1 <= xe2 && ye1 <= ye2) {
        XGetGCValues (display, gc, GCPlaneMask, &vals);
        bits =
            XGetImage (display, backbit, xe1, ye1, xe2 - xe1 + 1,
                       ye2 - ye1 + 1, vals.plane_mask, XYPixmap);
        if (!bits) {
            error (sevERROR, "Couldn't get bits from window");
            return my_strdup ("");
        }
    }
    bitstring = newrgb (x2 - x1 + 1, y2 - y1 + 1);
    for (y = y1; y <= y2; y++) {
        for (x = x1; x <= x2; x++) {
            if (x >= xe1 && x <= xe2 && y >= ye1 && y <= ye2) {
                pixel = XGetPixel (bits, x - xe1, y - ye1);
            } else {
                pixel = backpixel;
            }
            pixel_to_rgb (&red, &green, &blue, pixel);
            addrgb (bitstring, red, green, blue);
        }
    }
    if (bits) {
        XDestroyImage (bits);
    }
#else /*  */
    startdraw (FALSE);
    bitstring = newrgb (x2 - x1 + 1, y2 - y1 + 1);
    for (y = y1; y <= y2; y++) {
        for (x = x1; x <= x2; x++) {
            if (x >= xe1 && x <= xe2 && y >= ye1 && y <= ye2) {
                pixel = GetPixel (bitcon, x, y);
            } else {
                pixel = backpixel;
            }
            addrgb (bitstring, GetRValue (pixel), GetGValue (pixel),
                    GetBValue (pixel));
        }
    }
    enddraw ();
#endif
    return bitstring;
}


static char *
newrgb (int w, int h)
{
    /* create a new bitmap string */
    char *bits;

    sprintf (string, "rgb %d,%d:", w, h);
    bits = my_malloc (strlen (string) + ((w * h) * 6) + 2);
    strcpy (bits, string);
    bitcount = 0;

    return bits;
}


static void
addrgb (char *bits, unsigned short red, unsigned short green,
        unsigned short blue)
{
    /* add one rgb pixel to bitstring */
    static char *pbits;

    if (bitcount == 0) {
        pbits = bits + strlen (bits);
    }
    bitcount++;
    sprintf (pbits, "%02x%02x%02x", red, green, blue);
    pbits += 6;
}


static int
readrgb (char *bits, unsigned short *red, unsigned short *green,
         unsigned short *blue)
{
    /* read rgb bit from string one after another */
    static char *bitpt;
    int r, g, b;

    if (bits) {
        bitpt = bits;
        return 1;
    }
    if (sscanf (bitpt, "%02x%02x%02x", &r, &g, &b) == 3) {
        *red = r;
        *green = g;
        *blue = b;
        bitpt += 6;
        return 1;
    }
    return 0;
}


void
create_openprinter (int num)
{
    /* create command 'openprinter' */
    struct command *cmd;

    cmd = add_command (cOPENPRN, NULL, NULL);
    cmd->args = num;
}


void
openprinter (struct command *cmd)
{
    /* opens a printer */
#ifdef WINDOWS
    char PrinterName[200];	/* Name of default Printer */
    char *p;			/* points into PrinterName */
    static int first = TRUE;
    DOCINFO di;
    float width, height, prnscalex, prnscaley;
    LOGBRUSH mybrush;
    RECT interior;
#endif

    /* close file, if already open */
#ifdef UNIX
    if (printerfile) {
        closeprinter ();
    }
#endif

    if (cmd->args == 1) {
        printerfilename = my_strdup ((char *) (pop (stSTRING)->pointer));
        print_to_file = TRUE;
    } else {
        printerfilename = my_strdup ("\0");
        print_to_file = FALSE;
    }

#ifdef UNIX

    if (*printerfilename == '\0') {
#ifdef HAVE_MKSTEMP
        int fd;
        my_free (printerfilename);
        printerfilename =
            my_strdup ("/tmp/yabasic-postscript-output-XXXXXX");
        fd = mkstemp (printerfilename);
        if (fd > 0) {
            printerfile = fdopen (fd, "w");
        } else {
            printerfile = NULL;
        }
#else
        struct stat s;
        my_free (printerfilename);
        printerfilename = my_strdup ("/tmp/yabasic.ps");
        if (stat (printerfilename, &s) && errno != ENOENT) {
            sprintf (string, "could not check printerfile '%s': %s",
                     printerfilename, my_strerror (errno));
            error (sevERROR, string);
            return;
        }
        if (s.st_mode & S_IFLNK) {
            sprintf (string,
                     "could not print to file '%s'; it is a symbolic link");
            error (sevERROR, string);
            return;
        }
        printerfile = fopen (printerfilename, "w");
#endif
        deleteprinterfile = TRUE;
    } else {
        printerfile = fopen (printerfilename, "w");
        deleteprinterfile = FALSE;
    }
    if (!printerfile) {
        sprintf (string, "could not open file '%s' for printing: %s",
                 printerfilename, my_strerror (errno));
        error (sERROR, string);
    }
#endif

#ifdef WINDOWS

    if (first) {

        /* query win.ini for default printer */
        GetProfileString ("windows", "device", ",,,", PrinterName, 200);

        /* truncate printer name */
        p = PrinterName;
        while (*p && *p != ',') {
            p++;
        }
        *p = '\0';

        printer = CreateDC (NULL, PrinterName, NULL, NULL);
        if (!printer) {
            printer = CreateDC (NULL, "winspool", NULL, NULL);
        }

        if (!printer) {
            error (sERROR, "Couldn't get handle for printer");
            return;
        }

        /* calculate scaling-factors */
        width = (float) GetDeviceCaps (printer, PHYSICALWIDTH);
        prnoffx = (float) GetDeviceCaps (printer, PHYSICALOFFSETX);
        prnscalex = (float) (width - 4 * prnoffx) / winwidth;
        height = (float) GetDeviceCaps (printer, PHYSICALHEIGHT);
        prnoffy = (float) GetDeviceCaps (printer, PHYSICALOFFSETY);
        prnscaley = (float) (height - 4 * prnoffy) / winheight;
        prnscale = (prnscalex < prnscaley) ? prnscalex : prnscaley;

        /* create printerpens */
        mybrush.lbStyle = BS_SOLID;
        mybrush.lbColor = RGB (255, 255, 255);
        mybrush.lbHatch = HS_DIAGCROSS;
        revprinterpen =
            ExtCreatePen (PS_GEOMETRIC, (long) prnscale, &mybrush, 0, NULL);
        mybrush.lbStyle = BS_SOLID;
        mybrush.lbColor = RGB (0, 0, 0);
        mybrush.lbHatch = HS_DIAGCROSS;
        printerpen =
            ExtCreatePen (PS_GEOMETRIC, (long) prnscale, &mybrush, 0, NULL);

        /* set clipping region */
        GetClientRect (window, &interior);
        SelectClipRgn (printer, NULL);
        IntersectClipRect (printer,
                           (int) (interior.left * prnscalex + prnoffx),
                           (int) (interior.top * prnscaley + prnoffy),
                           (int) (interior.right * prnscalex + prnoffx),
                           (int) (interior.bottom * prnscaley + prnoffy));

        /* create printerfont */
        logfont.lfHeight = (long) (-fontheight * prnscale);
        printerfont = CreateFontIndirect (&logfont);
        if (printerfont == NULL) {
            sprintf (string, "Could not create font for printer");
            error (ERROR, string);
            return;
        }
        if (!SelectObject (printer, printerfont)) {
            error (ERROR, "could not select printerfont");
        }
    }
    di.cbSize = sizeof (DOCINFO);
    di.lpszDocName = "yabasic grafics";
    di.lpszOutput = (print_to_file) ? printerfilename : (LPTSTR) NULL;
    di.lpszDatatype = (LPTSTR) NULL;
    di.fwType = 0;

    if (StartDoc (printer, &di) == SP_ERROR) {
        error (ERROR, "Couldn't start printing");
        return;
    }
    StartPage (printer);
    first = FALSE;

#else /* UNIX */

    fprintf (printerfile, "%%!PS-Adobe-1.0\n");
    fprintf (printerfile, "%%%%Title: %s grafic\n", progname);
    fprintf (printerfile, "%%%%BoundingBox: 0 0 %i %i\n",
             (int) (winwidth * psscale), (int) (winheight * psscale));
    fprintf (printerfile, "%%%%DocumentFonts: Helvetica\n");
    fprintf (printerfile, "%%%%Creator: yabasic\n");
    fprintf (printerfile, "%%%%Pages: (atend)\n");
    fprintf (printerfile, "%%%%EndComments\n");
    fprintf (printerfile, "gsave\n");
    fprintf (printerfile, "/txt 4 dict def\n");
    fprintf (printerfile, "/rec 6 dict def\n");
    fprintf (printerfile, "/tri 8 dict def\n");
    fprintf (printerfile, "/cir 5 dict def\n");
    fprintf (printerfile, "/rgb 3 dict def\n");
    fprintf (printerfile, "rgb /r 0 put\n");
    fprintf (printerfile, "rgb /g 0 put\n");
    fprintf (printerfile, "rgb /b 0 put\n");
    fprintf (printerfile, "0 setgray\n");
    fprintf (printerfile, "/M {moveto} def\n");
    fprintf (printerfile, "/RL {rlineto} def\n");
    fprintf (printerfile, "/L {lineto} def\n");
    fprintf (printerfile, "/N {newpath} def\n");
    fprintf (printerfile, "/S {stroke} def\n");
    fprintf (printerfile,
             "/CLYN {(y) eq {1 setgray} {rgb /r get rgb /g get rgb /b get setrgbcolor} ifelse} def\n");
    fprintf (printerfile,
             "/DO {CLYN N M 0 %g RL %g 0 RL 0 %g RL"
             " closepath fill (n) CLYN} def\n", psscale, psscale, -psscale);
    fprintf (printerfile, "/LI {CLYN N M L stroke (n) CLYN} def\n");
    fprintf (printerfile, "/CI {mark 6 1 roll cir /fi 3 -1 roll put\n");
    fprintf (printerfile, "     cir /cl 3 -1 roll put\n");
    fprintf (printerfile, "     cir /r 3 -1 roll put\n");
    fprintf (printerfile, "     cir /x 3 -1 roll put\n");
    fprintf (printerfile, "     cir /y 3 -1 roll put\n");
    fprintf (printerfile, "     cir /cl get (y) CLYN\n");
    fprintf (printerfile,
             "     N cir /x get cir /y get cir /r get 0 360 arc\n");
    fprintf (printerfile,
             "     closepath cir /fi get (y) eq {fill} {stroke} ifelse\n");
    fprintf (printerfile, "     (n) CLYN cleartomark} def\n");
    fprintf (printerfile, "/AT {mark 5 1 roll txt /txt 3 -1 roll put\n");
    fprintf (printerfile, "     txt /xa 3 -1 roll put\n");
    fprintf (printerfile, "     txt /y 3 -1 roll put\n");
    fprintf (printerfile, "     txt /x 3 -1 roll put\n");
    fprintf (printerfile, "     N txt /x get txt /y get M\n");
    fprintf (printerfile,
             "     txt /txt get false charpath flattenpath pathbbox\n");
    fprintf (printerfile, "     pop exch pop exch sub\n");
    fprintf (printerfile, "     txt /x get exch\n");
    fprintf (printerfile, "     txt /xa get (c) eq {2 div sub} if\n");
    fprintf (printerfile, "     txt /xa get (l) eq {pop} if\n");
    fprintf (printerfile, "     txt /xa get (r) eq {sub} if\n");
    fprintf (printerfile, "     txt /y get M\n");
    fprintf (printerfile, "     txt /txt get show cleartomark\n");
    fprintf (printerfile, "     } def\n");
    fprintf (printerfile, "/RE {mark 7 1 roll rec /fi 3 -1 roll put\n");
    fprintf (printerfile, "     rec /cl 3 -1 roll put\n");
    fprintf (printerfile, "     rec /y2 3 -1 roll put\n");
    fprintf (printerfile, "     rec /x2 3 -1 roll put\n");
    fprintf (printerfile, "     rec /y1 3 -1 roll put\n");
    fprintf (printerfile, "     rec /x1 3 -1 roll put\n");
    fprintf (printerfile, "     rec /cl get CLYN\n");
    fprintf (printerfile, "     N rec /x1 get rec /y1 get M\n");
    fprintf (printerfile, "     rec /x1 get rec /y2 get L\n");
    fprintf (printerfile, "     rec /x2 get rec /y2 get L\n");
    fprintf (printerfile, "     rec /x2 get rec /y1 get L\n");
    fprintf (printerfile, "     rec /x1 get rec /y1 get L\n");
    fprintf (printerfile,
             "     closepath rec /fi get (y) eq {fill} {stroke} ifelse\n");
    fprintf (printerfile, "     (n) CLYN cleartomark} def\n");
    fprintf (printerfile, "/TRI {mark 9 1 roll tri /fi 3 -1 roll put\n");
    fprintf (printerfile, "     tri /cl 3 -1 roll put\n");
    fprintf (printerfile, "     tri /y3 3 -1 roll put\n");
    fprintf (printerfile, "     tri /x3 3 -1 roll put\n");
    fprintf (printerfile, "     tri /y2 3 -1 roll put\n");
    fprintf (printerfile, "     tri /x2 3 -1 roll put\n");
    fprintf (printerfile, "     tri /y1 3 -1 roll put\n");
    fprintf (printerfile, "     tri /x1 3 -1 roll put\n");
    fprintf (printerfile, "     tri /cl get CLYN\n");
    fprintf (printerfile, "     N tri /x1 get tri /y1 get M\n");
    fprintf (printerfile, "     tri /x2 get tri /y2 get L\n");
    fprintf (printerfile, "     tri /x3 get tri /y3 get L\n");
    fprintf (printerfile,
             "     closepath tri /fi get (y) eq {fill} {stroke} ifelse\n");
    fprintf (printerfile, "     (n) CLYN cleartomark} def\n");
    fprintf (printerfile, "30 30 translate\n");
    fprintf (printerfile, "%g setlinewidth\n", psscale);
    firsttext = TRUE;		/* font will be set in text-command */
    fflush (printerfile);
#endif
}


void
closeprinter ()
{
    /* close printer */
#ifdef WINDOWS
    EndPage (printer);
    EndDoc (printer);
#else /* UNIX */
    if (printerfile) {
        fprintf (printerfile, "showpage\ngrestore\n%%%%Trailer\n");
        fclose (printerfile);
        printerfile = NULL;
        if (deleteprinterfile) {
            deleteprinterfile = FALSE;
            sprintf (string, "lpr %s", printerfilename);
            if (system (string)) {
                sprintf (string, "couldn't print '%s'", printerfilename);
                error (ERROR, string);
                return;
            }
            remove (printerfilename);
        }
    }
#endif
    if (printerfilename) {
        my_free (printerfilename);
        printerfilename = NULL;
    }
    print_to_file = FALSE;
}


#ifdef UNIX
void
getwinkey (char *retkey)
{
    /* read a key from grafics window */
    static XEvent event;		/* what has happened ? */
    static KeySym sym;		/* keysmbol */
    KeySym *keysym = NULL;
    int numsym;
    int yk, len, x, y;

    XSelectInput (display, window,
                  KeyPressMask | ButtonPressMask | ButtonReleaseMask);
    do {
        if (keysym) {
            XFree(keysym);
	    keysym = NULL;
        }

        if (!XCheckWindowEvent(display, window, KeyPressMask | ButtonPressMask | ButtonReleaseMask, &event)) {
            return;
        }

        len =
            XLookupString ((XKeyPressedEvent *) & event, retkey, 100, &sym,
                           NULL);
        if (event.type == KeyPress) {
            keysym = XGetKeyboardMapping(display, event.xkey.keycode, 1,&numsym);
	    if (keysym) {
	      sym = keysym[0];
	      XFree(keysym);
	      keysym = NULL;
	    }
        }
    } while (event.type == KeyPress &&
             (sym == XK_Shift_L || sym == XK_Shift_R ||
              sym == XK_Control_L || sym == XK_Control_R ||
              sym == XK_Alt_L || sym == XK_Alt_R ||
              sym == XK_Caps_Lock || sym == XK_Shift_Lock));

    XSelectInput (display, window, 0);
    if (event.type == ButtonPress) {
        x = event.xbutton.x;
        y = event.xbutton.y;
        itransform (&x, &y);
        sprintf (retkey, "MB%dd+%d:%04d,%04d", event.xbutton.button,
                 event.xbutton.state & 15, x, y);
        return;
    }
    if (event.type == ButtonRelease) {
        x = event.xbutton.x;
        y = event.xbutton.y;
        itransform (&x, &y);
        sprintf (retkey, "MB%du+%d:%04d,%04d", event.xbutton.button,
                 event.xbutton.state & 15, x, y);
        return;
    }
    len =
        XLookupString ((XKeyPressedEvent *) & event, retkey, 100, &sym,
                       NULL);
    retkey[len] = '\0';
    if (len != 1 || !isprint (retkey[0])) {
        yk = -1;
        keysym = XGetKeyboardMapping(display, event.xkey.keycode, 1,&numsym);
	if (keysym) {
	  sym = keysym[0];
	  XFree(keysym);
	  keysym = NULL;
	}

        switch (sym) {
        case XK_BackSpace:
            yk = kBACKSPACE;
            break;
        case XK_Tab:
            yk = kTAB;
            break;
        case XK_Insert:
            yk = kINS;
            break;
        case XK_Home:
            yk = kHOME;
            break;
        case XK_End:
            yk = kEND;
            break;
        case XK_Clear:
            yk = kCLEAR;
            break;
        case XK_Return:
            yk = kENTER;
            break;
        case XK_KP_Enter:
            yk = kENTER;
            break;
        case XK_Escape:
            yk = kESC;
            break;
        case XK_Delete:
            yk = kDEL;
            break;
        case XK_Left:
            yk = kLEFT;
            break;
        case XK_Up:
            yk = kUP;
            break;
        case XK_Right:
            yk = kRIGHT;
            break;
        case XK_Down:
            yk = kDOWN;
            break;
        case XK_Page_Up:
            yk = kSCRNUP;
            break;
        case XK_Page_Down:
            yk = kSCRNDOWN;
            break;
        case XK_F1:
            yk = kF1;
            break;
        case XK_F2:
            yk = kF2;
            break;
        case XK_F3:
            yk = kF3;
            break;
        case XK_F4:
            yk = kF4;
            break;
        case XK_F5:
            yk = kF5;
            break;
        case XK_F6:
            yk = kF6;
            break;
        case XK_F7:
            yk = kF7;
            break;
        case XK_F8:
            yk = kF8;
            break;
        case XK_F9:
            yk = kF9;
            break;
        case XK_F10:
            yk = kF10;
            break;
        case XK_F11:
            yk = kF11;
            break;
        case XK_F12:
            yk = kF12;
            break;
        case XK_F13:
            yk = kF13;
            break;
        case XK_F14:
            yk = kF14;
            break;
        case XK_F15:
            yk = kF15;
            break;
        case XK_F16:
            yk = kF16;
            break;
        case XK_F17:
            yk = kF17;
            break;
        case XK_F18:
            yk = kF18;
            break;
        case XK_F19:
            yk = kF19;
            break;
        case XK_F20:
            yk = kF20;
            break;
        case XK_F21:
            yk = kF21;
            break;
        case XK_F22:
            yk = kF22;
            break;
        case XK_F23:
            yk = kF23;
            break;
        case XK_F24:
            yk = kF24;
            break;
        default:
            break;
        }
        if (yk > 0) {
            strcpy (retkey, ykey[yk]);
        } else {
            sprintf (retkey, "key%x", (int) sym);
        }

        if (!strncmp ("MB", retkey, 2)) {
            getmousexybm (retkey, &mousex, &mousey, &mouseb, &mousemod);
        }

    }
}


void
gettermkey (char *keybuff)
{
    /* read a key from terminal */
    char *skey = NULL;
    int key;			/* returned key */

    key = getch ();

    switch (key) {
    case ERR:
        return;
    case KEY_UP:
        skey = ykey[kUP];
        break;
    case KEY_DOWN:
        skey = ykey[kDOWN];
        break;
    case KEY_LEFT:
        skey = ykey[kLEFT];
        break;
    case KEY_RIGHT:
        skey = ykey[kRIGHT];
        break;
    case KEY_DC:
        skey = ykey[kDEL];
        break;
    case KEY_IC:
        skey = ykey[kINS];
        break;
    case KEY_IL:
        skey = ykey[kINS];
        break;
    case KEY_CLEAR:
        skey = ykey[kCLEAR];
        break;
    case KEY_HOME:
        skey = ykey[kHOME];
        break;
#ifdef KEY_END
    case KEY_END:
        skey = ykey[kEND];
        break;
#endif
    case KEY_F0:
        skey = ykey[kF0];
        break;
    case KEY_F (1):
        skey = ykey[kF1];
        break;
    case KEY_F (2):
        skey = ykey[kF2];
        break;
    case KEY_F (3):
        skey = ykey[kF3];
        break;
    case KEY_F (4):
        skey = ykey[kF4];
        break;
    case KEY_F (5):
        skey = ykey[kF5];
        break;
    case KEY_F (6):
        skey = ykey[kF6];
        break;
    case KEY_F (7):
        skey = ykey[kF7];
        break;
    case KEY_F (8):
        skey = ykey[kF8];
        break;
    case KEY_F (9):
        skey = ykey[kF9];
        break;
    case KEY_F (10):
        skey = ykey[kF10];
        break;
    case KEY_F (11):
        skey = ykey[kF11];
        break;
    case KEY_F (12):
        skey = ykey[kF12];
        break;
    case KEY_F (13):
        skey = ykey[kF13];
        break;
    case KEY_F (14):
        skey = ykey[kF14];
        break;
    case KEY_F (15):
        skey = ykey[kF15];
        break;
    case KEY_F (16):
        skey = ykey[kF16];
        break;
    case KEY_F (17):
        skey = ykey[kF17];
        break;
    case KEY_F (18):
        skey = ykey[kF18];
        break;
    case KEY_F (19):
        skey = ykey[kF19];
        break;
    case KEY_F (20):
        skey = ykey[kF20];
        break;
    case KEY_F (21):
        skey = ykey[kF21];
        break;
    case KEY_F (22):
        skey = ykey[kF22];
        break;
    case KEY_F (23):
        skey = ykey[kF23];
        break;
    case KEY_F (24):
        skey = ykey[kF24];
        break;
    case KEY_BACKSPACE:
        skey = ykey[kBACKSPACE];
        break;
    case KEY_NPAGE:
        skey = ykey[kSCRNDOWN];
        break;
    case KEY_PPAGE:
        skey = ykey[kSCRNUP];
        break;
    case KEY_ENTER:
        skey = ykey[kENTER];
        break;
    default:
        if (isprint (key)) {
            keybuff[0] = key;
            keybuff[1] = '\0';
        } else if (key < 0 || key >= KEY_MAX) {
            keybuff[0] = '\0';
        } else {
            switch (key) {
            case 0x1b:
                skey = ykey[kESC];
                break;
            case 0x7f:
                skey = ykey[kDEL];
                break;
            case 0xa:
                skey = ykey[kENTER];
                break;
            case 0x9:
                skey = ykey[kTAB];
                break;
            default:
                sprintf (keybuff, "key%x", key);
            }
        }
        break;
    }
    if (skey) {
        strcpy (keybuff, skey);
    }
}
#endif
