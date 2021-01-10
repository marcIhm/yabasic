/*

    YABASIC ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2021
    more info at www.yabasic.de

    yabasic.h --- function prototypes and global variables

    This file is part of yabasic and may be copied under the terms of
    MIT License which can be found in the file LICENSE.

*/

#define YABASIC_INCLUDED

/* ------------- defines ---------------- */

/*
  Define one and only one of the following symbols, depending on your
  System:
  - UNIX: uses some UNIX-features and X11
  - WINDOWS: uses WIN32-features
*/

#if defined(UNIX) && defined(WINDOWS)
#error UNIX and WINDOWS are defined together; check your compiler settings
#endif
/* ------------- includes ---------------- */
#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <errno.h>
#ifdef WINDOWS
#include <string.h>
#include <windows.h>
#include <io.h>
#include <Winspool.h>
#define ARCHITECTURE "windows"
#define YY_NO_UNISTD_H
#ifdef __LCC__			/* fix for lccwin32 */
#include <winspool.h>
#endif
#endif
#ifdef UNIX
#define ARCHITECTURE UNIX_ARCHITECTURE
#ifdef HAS_STRING_HEADER
#include <string.h>
#elif HAS_STRINGS_HEADER
#include <strings.h>
#endif
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Intrinsic.h>
#define XK_LATIN1
#define XK_MISCELLANY
#include <X11/keysymdef.h>
#include <unistd.h>
#include <fcntl.h>
#include <term.h>
#ifdef HAVE_NCURSES_H
#include <ncurses.h>
#else
#ifdef HAVE_CURSES_H
#include <curses.h>
#endif
#endif
#ifndef KEY_MAX
#define KEY_MAX 0777
#endif
#endif
#ifndef FOPEN_MAX
#define FOPEN_MAX 9
#endif
#include <signal.h>
#include <ctype.h>
#ifdef UNIX
#ifndef LIBRARY_PATH
#define LIBRARY_PATH "/usr/lib"
#endif
#endif
#define OPEN_HAS_STREAM 1
#define OPEN_HAS_MODE 2
#define OPEN_PRINTER 8
#define STDIO_STREAM 1234

/* -------- variables needed in all files and defined in ... -------- */

/* main.c */
extern struct command *currcmd;	        /* currently executed command */
extern struct command *cmd_root;	/* first command */
extern struct command *cmd_head;	/* next command */
extern struct command *last_cmd;	/* last command */
extern int severity_threshold;  /* minimum severity the user wants to see */
extern int severity_so_far;     /* maximum severity that has been printed until now */
extern int interactive;		/* true, if commands come from stdin */
extern char *progname;		/* name of yabasic-program */
extern char *cexplanation[];	/* explanations of commands */
extern char *fexplanation[];	/* explanations of functions */
extern char **yabargv;		/* arguments for yabasic */
extern int yabargc;		/* number of arguments in yabargv */
extern long long int compilation_start, compilation_end, execution_end;
extern char *string;		/* for trash-strings */
extern char *estring;	/* for error-strings */
extern int errorcode;		/* error-codes */
extern char library_path[];	/* full path to search libraries */
extern int program_state;	/* state of program */
extern int check_compat;	/* true, if compatibility should be checked */
extern int is_bound;		/* true, if this executable is bound */
extern char *progname;		/* name of yabasic-program */
extern char *main_file_name;	/* name of program to be executed */
extern char *inter_path;	/* name of interpreter executing; i.e. ARGV[0] */

/* io.c */
extern FILE *streams[];		/* file streams */
extern int read_controls;	/* TRUE, if input should read control characters */
extern int stream_modes[];	/* modes for streams */
extern int curinized;		/* true, if curses has been initialized */
extern int badstream (int, int);	/* test for valid stream id */
void myseek (struct command *);	/* reposition file pointer */
void mystream (int);		/* switch to specified stream */
#ifdef WINDOWS
extern HANDLE gotwinkey;		/* mutex to signal key reception */
extern char conkeybuff[]; /* Key received from console */
extern char winkeybuff[]; /* Key received from window */
extern HANDLE wthandle;		/* handle of win thread */
extern HANDLE kthandle;		/* handle of inkey thread */
extern DWORD ktid;		/* id of inkey thread */
extern int LINES;		/* number of lines on screen */
extern int COLS;		/* number of columns on screen */
extern HANDLE ConsoleInput;	/* handle for console input */
extern HANDLE ConsoleOutput;	/* handle for console output */
#else
extern int winpid;		/* pid of process waiting for window keys */
extern int termpid;		/* pid of process waiting for terminal keys */
#endif

/* foreign.c */
extern char last_frnfn_call_error_text[]; /* last error message produced by foreign call */
extern int last_frnfn_call_okay;         /* true, if last foreign call has been okay */

/* graphic.c */
/* printing and plotting */
extern int print_to_file;	/* print to file ? */
#ifdef WINDOWS
extern HFONT printerfont;	/* handle of printer-font */
extern HDC printer;		/* handle of printer */
#endif
extern FILE *printerfile;	/* file to print on */
extern double xoff;		/* offset for x-mapping */
extern double xinc;		/* inclination of x-mapping */
extern double yoff;		/* offset for y-mapping */
extern double yinc;		/* inclination for y-mapping */
/* window coordinates */
extern int winopened;		/* flag if window is open already */
extern char *winorigin;		/* e.g. "lt","rc"; defines origin of grafic window */
extern int winwidth, winheight;	/* size of window */
/* mouse, console and keyboard */
extern int mousex, mousey, mouseb, mousemod;	/* last know mouse coordinates */
extern char *ykey[];		/* keys returned by inkey */
/* text and font */
extern char *getreg (char *);	/* get defaults from Registry */
extern char *text_align;	/* specifies alignement of text */
extern int fontheight;		/* height of font in pixel */
extern int check_alignment (char *);	/* checks, if text-alignement is valid */

#ifdef WINDOWS
extern HFONT myfont;		/* handle of font for screen */
#endif
/* general window stuff */
extern char *foreground;
extern char *background;
extern char *geometry;
extern char *displayname;
extern char *fontname;
extern int drawmode;
#ifdef UNIX
extern Display *display;
#endif
#ifdef WINDOWS
extern HWND window;		/* handle of my window */
extern HANDLE mainthread;	/* handle to main thread */
extern HANDLE this_instance;
extern WNDCLASS myclass;	/* window class for my program */
extern char *my_class;
extern BOOL Commandline;	/* true if launched from command line */
#else
extern int backpid;		/* pid of process waiting for redraw events */
#endif

/* function.c */
extern struct command *datapointer;	/* current location for read-command */
extern char *last_inkey; /* last result of inkey */
void switch_compare (void);	/* compare topmost values for switch statement */

/* symbol.c */
extern struct stackentry *stackroot;	/* first element of stack */
extern struct stackentry *stackhead;	/* last element of stack; actually stackhead->prev is the last element, that has contents */
extern void query_array (struct command *cmd);	/* query array */
extern struct command *last_symref;
extern struct command *first_symref;
extern int labelcount;		/* count self-generated labels */

/* flex.c */
extern struct library *library_stack[];	/* stack for library file names */
extern struct library *currlib;	/* current libfile as relevant to bison */
extern int inlib;		/* true, while in library */
extern int in_short_if;		/* true, if within a short if */
extern int library_chain_length;	/* length of library_chain */
extern struct library *library_chain[];	/* list of all library file names */
extern int include_depth; /* current position in libfile_stack */
extern int start_token; /* pseudo token used to switch start state */

/* bison.c */
extern char *current_function;	/* name of currently parsed function */
extern int yydebug;
extern int missing_endif;
extern int missing_endif_line;
void report_if_missing(char *,int);
void report_conflicting_close(char *,int);
void collect_missing_clauses(char *, char);
    
/*-------------------------- defs and undefs ------------------------*/

/* undef symbols */
#undef FATAL
#undef ERROR
#undef WARNING
#undef NOTE
#undef DEBUG
#undef DUMP

#if !defined(TRUE)
#define TRUE (1==1)
#endif

#ifndef FALSE
#define FALSE (1!=1)
#endif

/* I've been told, that some symbols are missing under SunOs ... */
#ifndef RAND_MAX
#define RAND_MAX 32767
#endif

/* length of buffers for system() and input */
#define PIPEBUFFLEN 1000   /* writing into pipes, e.g. for system$ */
#define INBUFFLEN 10000 /* user input */
#define NAMEBUFFLEN 200 /* names chosen by user */


/* ---------------------- enum types ------------------------------- */

enum severity {
    /* error levels  */
    sBISON, sDEBUG, sNOTE, sWARNING, sDUMP, sINFO, sERROR, sFATAL
};

enum end_reasons {
    /* ways to end the program */
    rNONE, rERROR, rREQUEST, rEOF
};

enum stream_modes {
    /* ways to access a stream */
    mCLOSED = 0, mREAD = 1, mWRITE = 2, mPRINT = 4
};

enum functions {
    /* functions in yabasic (sorted by number of arguments) */
    fFIRST_FUNCTION,		/* no function, just marks start of list */
    fRAN2, fDATE, fTIME,
    fFRNFN_CALL, fFRNFN_CALL2, fFRNBF_ALLOC, fFRNBF_DUMP, fFRNBF_DUMP2,
    fFRNBF_GET_NUMBER, fFRNBF_GET_STRING, fFRNBF_GET_BUFFER, fFRNFN_SIZE, fFRNBF_SIZE,
    fZEROARGS,
    fINKEY, fMOUSEX, fMOUSEY, fMOUSEB, fMOUSEMOD,
    fSIN, fASIN, fCOS, fACOS, fTAN,
    fATAN, fSYSTEM, fSYSTEM2, fPEEK, fPEEK2, fPEEK4, fTELL, fEXP, fLOG, fLEN,
    fSTR,
    fSQRT, fSQR, fFRAC, fROUND, fABS, fSIG, fRAN, fINT, fCEIL, fFLOOR, fVAL, fASC, fHEX, fBIN, fDEC,
    fUPPER, fLOWER, fCHOMP, 
    fLTRIM, fRTRIM, fTRIM, fCHR, fBITNOT,
    fONEARGS, fDEC2, fATAN2, fLEFT, fAND, fOR,
    fEOR, fSHL, fSHR, fLOG2,
    fRIGHT, fINSTR, fRINSTR, fSTR2, fMOD, fMIN, fMAX, fPEEK3, fMID2,
    fTWOARGS,
    fMID, fINSTR2, fRINSTR2, fSTR3,
    fTHREEARGS,
    fGETBIT, fGETCHAR,
    fLAST_FUNCTION,		/* no function, just marks end of list */
};

enum arraymode {
    /* type of array access */
    CALLARRAY, ASSIGNARRAY, CALLSTRINGARRAY, ASSIGNSTRINGARRAY,
    GETSTRINGPOINTER
};

enum drawing_modes {
    /* various ways to draw */
    dmNORMAL = 0, dmCLEAR = 1, dmFILL = 2
};

enum eval_types {
    /* different types of eval */
    evNONE = 0, evNUMBER = 1, evSTRING = 2, evASSIGNMENT = 3
};

enum cmd_type {
    /* type of command */
    cFIRST_COMMAND,		/* no command, just marks start of list */

    cLABEL, cLINK_SUBR, cGOTO, cQGOTO, cGOSUB, cQGOSUB, cRETURN_FROM_GOSUB,	/* flow control */
    cEND, cEXIT, cBIND, cDECIDE, cSKIPPER, cNOP, cFINDNOP, cEXCEPTION,
    cANDSHORT,
    cORSHORT, cSKIPONCE, cRESETSKIPONCE, cRESETSKIPONCE2, cCOMPILE, cEXECUTE, cEXECUTE2, cEVAL, cEVAL_CODE,

    cDIM, cFUNCTION, cDOARRAY, cARRAYLINK, cPUSHARRAYREF, cCLEARSYMREFS,	/* everything with "()" */
    cARDIM, cARSIZE, cTOKEN, cTOKEN2, cTOKENALT, cTOKENALT2,
    cSPLIT, cSPLIT2, cSPLITALT, cSPLITALT2,
    cSTARTFOR, cFORCHECK, cFORINCREMENT,	/* for for-loops */

    cSWITCH_COMPARE, cNEXT_CASE, cNEXT_CASE_HERE, cBREAK_MULTI, 	/* break-continue-switch */
    cCONTINUE, cBREAK_HERE, cCONTINUE_HERE, cPOP_MULTI,
    cBEGIN_LOOP_MARK, cEND_LOOP_MARK, cBEGIN_SWITCH_MARK, cEND_SWITCH_MARK,

    cDBLADD, cDBLMIN, cDBLMUL, cDBLDIV, cDBLPOW,	/* double operations */
    cNEGATE, cPUSHDBLSYM, cPOP, cPOPDBLSYM, cPUSHDBL,

    cREQUIRE, cPUSHFREE, cMAKELOCAL, cMAKESTATIC, cCOUNT_PARAMS,	/* functions and procedures */
    cCALL, cQCALL, cPUSHSYMLIST, cPOPSYMLIST, cRETURN_FROM_CALL,
    cUSER_FUNCTION, cCHECK_RETURN_VALUE, cEND_FUNCTION,
    cFUNCTION_OR_ARRAY, cSTRINGFUNCTION_OR_ARRAY,

    cPOKE, cPOKEFILE, cSWAP, cDUPLICATE, cDOCU,	/* internals */

    cAND, cOR, cNOT, cLT, cGT, cLE, cGE, cEQ, cNE,	/* comparisons */
    cSTREQ, cSTRNE, cSTRLT, cSTRLE, cSTRGT, cSTRGE,

    cPUSHSTRSYM, cPOPSTRSYM, cPUSHSTR, cCONCAT,	/* string operations */
    cPUSHSTRPTR, cCHANGESTRING, cGLOB,

    cPRINT, cREAD, cRESTORE, cQRESTORE, cONESTRING,	/* i/o operations */
    cREADDATA, cDATA, cOPEN, cCHECKOPEN, cCHECKSEEK, cCLOSE, cPUSHSTREAM,
    cPOPSTREAM,
    cSEEK, cSEEK2, cTESTEOF, cWAIT, cBELL, cMOVE,
    cCLEARSCR, cCOLOUR, cCHKPROMPT, cERROR,

    cOPENWIN, cDOT, cLINE, cCIRCLE, cTRIANGLE, cTEXT1, cTEXT2, cTEXT3, cCLOSEWIN, cCLEARWIN,	/* grafics */
    cOPENPRN, cCLOSEPRN, cMOVEORIGIN, cRECT, cGCOLOUR, cGCOLOUR2,
    cGBACKCOLOUR, cGBACKCOLOUR2, cPUTBIT, cPUTCHAR,

    cFRNBF_SET_NUMBER, cFRNBF_SET_STRING, cFRNBF_FREE,    /* foreign libraries */
    cFRNBF_SET_BUFFER,
    
    cLAST_COMMAND			/* no command, just marks end of list */
};

enum stackentries {
    /* different types of stackentries */
    stGOTO, stSTRING, stSTRINGARRAYREF, stNUMBER, stNUMBERARRAYREF, stLABEL,
    stRET_ADDR, stRET_ADDR_CALL, stFREE, stROOT,
    stANY, stSTRING_OR_NUMBER, stSTRING_OR_NUMBER_ARRAYREF,	/* these will never appear on stack but are used to check with pop */
    stSWITCH_STRING, stSWITCH_NUMBER	/* only used in switch statement, compares true to every string or number */
};

enum symbols {
    /* different types of symbols */
    sySTRING, syNUMBER, syFREE, syARRAY
};

enum function_type {
    /* different types of functions */
    ftNONE, ftNUMBER, ftSTRING
};

enum addmodes {
    /* different modes for adding symbols */
    amSEARCH, amSEARCH_PRE, amADD_LOCAL, amADD_GLOBAL, amSEARCH_VERY_LOCAL
};

enum states {
    /* current state of program (variable program_state) */
    spHATCHED, spINITIALIZED, spCOMPILING, spRUNNING, spFINISHED
};

enum yabkeys {
    /* recognized special keys */
    kERR, kUP, kDOWN, kLEFT, kRIGHT, kDEL, kINS, kCLEAR, kHOME, kEND,
    kF0, kF1, kF2, kF3, kF4, kF5, kF6, kF7, kF8, kF9, kF10, kF11, kF12,
    kF13, kF14, kF15, kF16, kF17, kF18, kF19, kF20, kF21, kF22, kF23, kF24,
    kBACKSPACE, kSCRNDOWN, kSCRNUP, kENTER, kESC, kTAB, kLASTKEY
};

enum search_modes {
    /* modes for searching labels */
    srmSUBR = 1, srmLINK = 2, srmLABEL = 4, srmGLOBAL = 8
};

/* ------------- global types ---------------- */

struct stackentry {
    /* one element on stack */
    int type;			/* type of entry */
    struct stackentry *next;
    struct stackentry *prev;
    void *pointer;		/* multi-use pointer, e.g. for strings */
    double value;		/* double value, only one of pointer or value is used */
};

struct symstack {
    /* stack of symbol lists */
    struct symbol *next_in_list;
    struct symstack *next_in_stack;
    struct symstack *prev_in_stack;
};

struct symbol {
    /* general symbol; either variable, string */
    int type;
    struct symbol *link;		/* points to linked symbol, if any */
    struct symbol *next_in_list;	/* next symbol in symbollist */
    char *name;			/* name of symbol */
    void *pointer;		/* pointer to string contents (if any) */
    char *args;			/* used to store number of arguments for functions/array */
    double value;
};

struct command {
    /* one interpreter command */
    int type;			/* type of command */
    int cnt;			/* count of this command */
    struct command *prev;		/* link to previous command */
    struct command *next;		/* link to next command */
    void *pointer;		/* pointer to data */
    void *symbol;			/* pointer to symbol (or data within symbol) associated with command */
    struct command *jump;		/* pointer to jump destination */
    char *symname;			/* name of symbol associated with command */
    struct command *next_symref;	/* next cmd within function referencing a symbol */
    struct command *next_assoc;	/* next cmd within chain of associated commands; used for commands: data, docu, label */
    int args;			/* number of arguments for function/array call 
				   or stream number for open/close */
    int tag;			/* char/int to pass some information */
    int line;			/* line this command has been created for */
    int first_column;           /* column, at which this command started */
    int last_column;            /* column, at which this command ended */
    struct library *lib;	/* associated library */
    char *diag;                 /* optional text for diagnostics */
    struct switch_state *switch_state;  /* state for switch statements */
};

struct switch_state {    /* records surrounding of a statement; used to check gotos into, out-of, within and between switch-statements (i.e. to err on most)  */
    int id;           /* unique id for each switch-statment */
    int nesting;      /* number of nested switch-statements */
    int pop_on_qgoto; /* number of stack entries to pop on quick goto */
};
    
struct array {
    /* data structure for arrays */
    int bounds[10];		/* index boundaries */
    int dimension;		/* dimension of array */
    void *pointer;		/* contents of array */
    char type;			/* decide between string- ('s') and double-Arrays ('d') */
};

struct buff_chain {
    /* buffer chain for system-input */
    char buff[PIPEBUFFLEN + 1];	/* content of buffer */
    int len;			/* used length of buff */
    struct buff_chain *next;	/* next buffer in chain */
};

struct library {
    /* used to store library names and other details */
    char *long_name;		/* long version, including path */
    int long_len;		/* length of l */
    char *short_name;		/* short version */
    int short_len;		/* length of s */
    struct command *datapointer;/* data pointer of this library */
    struct command *firstdata;	/* first data-command in library */
    struct library *next_lib;	/* next in chain */
    struct library *imported_from; /* where has this library been imported from ? */
    int yylineno_at_start;      /* value of yylineno at import of library */
};

/* ------------- function prototypes defined in ... ---------------- */

/* main.c */
void error (int, char *);
void error_with_position (int, char *, char *, int, int, int);
void error_without_position(int, char *);
void show_and_mark_line (char *, int, int, int);
void std_diag (char *, int, char *, char *);
void *my_malloc (unsigned);
void my_free (void *);
char *my_strerror (int);
struct command *add_command (int);
struct command *add_command_with_sym (int, char *);
struct command *add_command_with_diag (int, char *);
struct command *add_command_with_sym_and_diag (int, char *, char *);
struct command *add_command_with_switch_state(int);
void dump_commands (char *);
void signal_handler (int);
char *my_strdup (char *);
char *my_strndup (char *, int);
struct library *new_library (char *, char *);
char *dotify (char *, int);
char *strip (char *);
void create_docu (char *);
extern void add_variables (char *);
void compile (void);
void create_execute (int);
void execute (struct command *);
void create_eval (int);
void eval (struct command *);
int isbound (void);

/* io.c */
void checkopen (void);
void create_colour (int);
void colour (struct command *cmd);
void create_print (char);
void print (struct command *);
void create_myread (char, int);
void myread (struct command *);
void create_onestring (char *);
void onestring (char *);
void chkprompt (void);
void create_myopen (int);
void myopen (struct command *);
void testeof (struct command *);
void myclose ();
void create_pps (int, int);
void push_stream (struct command *);
void pop_stream (void);
void mymove ();
void clearscreen ();
char *inkey (double);
char *replace_escapes (char *);
int count_backslashes(char *);

/* graphic.c */
void create_openwin (int);
void openwin (struct command *);
void create_openprinter (int);
void openprinter (struct command *);
void closeprinter (void);
void putindrawmode (int);
void dot (struct command *);
void create_line (int);
void line (struct command *);
void moveorigin ();
int check_alignement (char *);
void circle (struct command *);
void triangle (struct command *);
void create_text (int);
void text (struct command *);
void closewin (void);
void clearwin (void);
void rect (struct command *);
void putbit (void);
void putchars (void);
void create_marker (int);
void marker (struct command *);
void getwinkey (char *);
void gettermkey (char *);
char *getbit (int, int, int, int);
char *getchars (int, int, int, int);
void change_colour (struct command *);
#ifdef WINDOWS
LRESULT CALLBACK mywindowproc (HWND, unsigned, UINT, DWORD);
#else
void calc_psscale (void);
#endif

/* foreign.c */
void frnfn_call (int,double *,char **);
double frnfn_size (void);
char *frnbf_alloc (void);
void frnbf_free (void);
char *frnbf_dump (int);
int frnbf_size ();
void frnbf_set (void);
void frnbf_set2 (void);
double frnbf_get (void);
char *frnbf_get2 (void);
char *frnbf_get_buffer (void);
void frnbf_set_buffer (void);

/* function.c */
void create_exception (int);
void exception (struct command *);
void create_poke (char);
void poke ();
void pokefile (struct command *);
void create_dblrelop (char);
void dblrelop (struct command *);
void concat (void);
void create_strrelop (char);
void strrelop (struct command *);
void create_changestring (int);
void changestring (struct command *);
void glob (void);
void create_boole (char);
void boole (struct command *);
void create_function (int);
void function (struct command *);
int myformat (char *, int, double, char *, char *);
int myformat2 (char *, int, double, char *, char *);
void create_restore (char *);
void restore (struct command *);
void create_dbldata (double);
void create_strdata (char *);
void create_readdata (char);
void readdata (struct command *);
void mywait ();
void mybell ();
void getmousexybm (char *, int *, int *, int *, int *);
void token (struct command *);
void tokenalt (struct command *);
long long current_millis(void);


/* symbol.c */
struct array *create_array (int, int);
void start_symref_chain (void);
void end_symref_chain (void);
void clear_symrefs (struct command *);
void duplicate (void);
void negate (void);
void create_require (int);
void require (struct command *);
void create_makelocal (char *, int);
void create_makestatic (char *, int);
void create_arraylink (char *, int);
void create_pusharrayref (char *, int);
void pusharrayref (struct command *);
void arraylink (struct command *);
void makestatic (struct command *);
void makelocal (struct command *);
void pushdblsym (struct command *);
void popdblsym (struct command *);
void create_pushdbl (double);
void pushdbl (struct command *);
void create_dblbin (char);
void dblbin (struct command *);
void pushstrsym (struct command *);
void popstrsym (struct command *);
void create_pushstr (char *);
void pushstr (struct command *);
void pushname (char *);
void pushstrptr (struct command *);
void logical_shortcut (struct command *type);
void create_doarray (char *, int);
void doarray (struct command *);
void create_dim (char *, char);
void dim (struct command *);
void swap (void);
struct stackentry *push (void);
struct stackentry *pop (int);
void pop_multi (struct command *);
struct symbol *get_sym (char *, int, int);
void link_symbols (struct symbol *, struct symbol *);
void pushsymlist (void);
void popsymlist (void);
void dump_sym ();
void dump_sub (int);
void function_or_array (struct command *);
int count_args (int);
void stackdesc (int, char *);


/* flow.c */
void link_label (struct command *);
void create_count_params (void);
void count_params (struct command *);
void forcheck (void);
void forincrement (void);
void startfor (void);
void create_goto (char *);
void create_gosub (char *);
void create_call (char *);
void create_label (char *, int);
void create_subr_link (char *);
struct command *add_switch_state(struct command *);
void pushgoto (void);
void popgoto (void);
void jump (struct command *);
void myreturn (struct command *);
void findnop ();
void skipper (void);
void skiponce (struct command *);
void resetskiponce (struct command *, int);
void decide (void);
void pushlabel (void);
void poplabel (void);
void storelabel ();
void matchgoto ();
void create_check_return_value (int, int);
void check_return_value (struct command *);
void create_endfunction (void);
struct command *search_label (char *, int);
void reorder_stack_before_call (struct stackentry *);
void reorder_stack_after_call (int);
void create_mybreak(int);
void mybreak (struct command *);
void mycontinue (struct command *cmd);
void next_case (struct command *);
int check_leave_switch (struct command *, struct command *);
void pop_switch_value (struct command *);
void initialize_switch_id_stack(void);
void push_switch_id (void);
void pop_switch_id (void);


/* flex.c */
void yyerror (char *);
void open_main (FILE *, char *, char *);
FILE *open_library (char *, char **);
void leave_lib (void);
void start_flex_from_string(char *);
void end_flex_from_string(void);
