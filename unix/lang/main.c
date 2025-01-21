/*

    YABASIC  ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2025
    more info at www.yabasic.de

    main.c -- main() and auxilliary functions

    This file is part of yabasic and may be copied under the terms of
    MIT License which can be found in the file LICENSE.

*/

/* ------------- includes ---------------- */

#ifndef YABASIC_INCLUDED
#include "yabasic.h" /* all prototypes and structures */
#endif
#include "bison.h"
#include "whereami.h"

/* ------------- defines ---------------- */

#define DONE                                                                   \
  {                                                                            \
    currcmd = currcmd->next;                                                   \
    break;                                                                     \
  } /* reduces type-work */
#define COPYRIGHT                                                              \
  "Copyright 1995-2025 by Marc Ihm, according to the MIT License"
/* NOTE: Including whatever timestamp into the banner would break the
 * reproducible build */
#define BANNER                                                                 \
  "\nThis is yabasic version " VERSION ",\nconfigured for " ARCHITECTURE       \
  " at " BUILD_TIME "\n\n   " COPYRIGHT "\n\n"
#define BANNER_VERSION "yabasic " VERSION ", built on " ARCHITECTURE
#define YABFORHELP "(type 'yabasic --help' for help)"
#define YABMAGIC "__YaBaSiC_MaGiC_CoOkIe__"

/* ------------- external references ---------------- */

extern int yylineno;      /* line number */
extern int yycolumn;      /* column number */
extern int yydoublenl;    /* column number */
extern YYLTYPE yylloc;    /* line numbers and columns */
extern int yyparse();     /* call bison parser */
extern int yydebug;       /* for bison debugging */
extern int yy_flex_debug; /* for flex debugging */

/* ------------- local functions ---------------- */

static void parse_arguments(int, char *argv[]);
static void set_program_state(int);
static void initialize(void);
static void run_it(void);
static void end_it(void);
#ifdef WINDOWS
static void chop_command(char *, int *, char ***);
#endif
void create_docu_array(void);
int equal(char *, char *, int);
static int mybind(char *);
void put_and_count(char *, FILE *, int *);
char *find_interpreter(char *);
static int seekback(FILE *, int, int);
int effective_lineno(void);

/* ------------- global variables ---------------- */

struct command *cmd_root; /* first command */
struct command *cmd_head; /* next command */
struct command *last_cmd; /* last command, that has been added */
struct command *currcmd;  /* currently executed command */
int severity_threshold;   /* minimum severity the user wants to see */
int severity_so_far;      /* maximum severity that has been printed until now */
static int debug_count;   /* number of debug messages */
static int note_count;    /* number of notes */
static int warning_count; /* number of warning messages */
static int error_count;   /* number of error messages */
int x11_note_on_receive_expose = FALSE;  /* print a note when receiving this event */
int con_fore_inten = cciLEGACY; /* console foreground intensity */
int con_fore_col = -1; /* console foreground color */
int con_back_col = -1; /* console background color */
int interactive;          /* true, if commands come from stdin */
int is_bound;             /* true, if this executable is bound */
static char *to_bind = NULL; /* name bound program to be written */
FILE *bound_program = NULL;  /* points to embedded yabasic program (if any) */
char *string;                /* for trash-strings */
char *estring;               /* for error-strings */
int errorcode;               /* error-codes */
static int commandcount;     /* total number of commands */
int program_state;           /* state of program */
char *progname = NULL;       /* name of yabasic-program */
int print_docu = FALSE;      /* TRUE, if only docu should be printed */
int hold_docu = FALSE;       /* TRUE, if docu should be printed in portions */
#ifdef WINDOWS
DWORD InitialConsole; /* initial state of console window */
#endif
char *cexplanation[cLAST_COMMAND - cFIRST_COMMAND +
                   1]; /* explanations of commands */
char *fexplanation[fLAST_FUNCTION - fFIRST_FUNCTION +
                   1];        /* explanations of functions */
char *explicit = NULL;        /* yabasic commands given on the command line */
char **yabargv;               /* arguments for yabasic */
int yabargc;                  /* number of arguments in yabargv */
static int endreason = rNONE; /* reason for termination */
static int exitcode = 0;
static int signal_arrived = 0;
/* timing */
long long int compilation_start, compilation_end, execution_end;
char library_path[NAMEBUFFLEN];    /* full path to search libraries */
char library_default[NAMEBUFFLEN]; /* default full path to search libraries */
static struct command *docuhead = NULL; /* first docu in main */
static int docucount = 0;               /* number of docu-lines in array */
int check_compat = 0;        /* true, if compatibility should be checked */
char *inter_path = NULL;     /* name of interpreter executing; i.e. ARGV[0] */
char *main_file_name = NULL; /* name of program to be executed */

/* ------------- main program ---------------- */

int main(int argc, char **argv) {
#ifdef WINDOWS
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  char *lp;
  int fromlibpath;
  DWORD consoleflags;
#endif
  int len;
  char lpath_def_from;

  string = (char *)my_malloc(sizeof(char) * INBUFFLEN);
  estring = (char *)my_malloc(sizeof(char) * INBUFFLEN);
  *estring = '\0';
  errorcode = 0;

  program_state = spHATCHED;
  severity_threshold = sWARNING; /* set the default severity threshold */
  yy_flex_debug = 0;             /* can be switched on again via -i b */

#ifdef WINDOWS

  /* enable %n for printf */
  _set_printf_count_output(1);

  /* get handle for current thread */
  DuplicateHandle(GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(),
                  &mainthread, THREAD_ALL_ACCESS, FALSE, 0);

  /* get handle of instance */
  this_instance = GetModuleHandle(NULL);

  /* define my window class */
  myclass.style = 0;
  myclass.lpfnWndProc = (LPVOID)mywindowproc;
  myclass.cbClsExtra = 0; /* no extra bytes */
  myclass.cbWndExtra = 0;
  myclass.hInstance = this_instance;
  myclass.hIcon = LoadIcon(this_instance, "yabasicIcon");
  myclass.hCursor = LoadCursor(NULL, IDC_ARROW); /*  standard cursor */
  myclass.hbrBackground = (HBRUSH)COLOR_WINDOW;  /* default-background */
  myclass.lpszMenuName = NULL;
  myclass.lpszClassName = my_class;

  RegisterClass(&myclass);

  /* get console handles */
  ConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
  ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  GetConsoleMode(ConsoleInput, &InitialConsole);
  /* In theory, the system-call below does the same as the api-calls above. However, this
     seems to make color-handling more robust, and brings windows console into a sane state,
     that cannot (?) be reached with ordinary api-calls. This is needed especially for
     study/default_console_colors.yab if it is started several times in the same window of
     windows console-host (windows-terminal is okay); in that case traces of the yellow
     color appear even before "clear screen" has been called; maybe those traces have
     survived between yabasic-runs in the console-host and can only erased with "color" ...
     See also
     https://stackoverflow.com/questions/6460932/change-entire-console-background-color-win32-c.
     And also system("cls") in io.c */
  system("color");
  
  /* request processing of excape sequences */
  GetConsoleMode(ConsoleOutput, &consoleflags);
  SetConsoleMode(ConsoleOutput, consoleflags | ENABLE_PROCESSED_OUTPUT |
                                    ENABLE_WRAP_AT_EOL_OUTPUT);

  /* find out, if launched from commandline */
  GetConsoleScreenBufferInfo(ConsoleOutput, &csbi);
  Commandline =
      !((csbi.dwCursorPosition.X == 0) && (csbi.dwCursorPosition.Y == 0));
  if ((csbi.dwSize.X <= 0) || (csbi.dwSize.Y <= 0)) {
    Commandline = TRUE;
  }

#endif

  /* compute default for library path before parsing arguments, because we want
   * to report it within the usage message */
  /* remark: no debuglevel known yet, so we defer debug-messages until after
   * parsing of command line args */
  library_path[0] = '\0';
  library_default[0] = '\0';
#ifdef UNIX
  strcpy(library_default, LIBRARY_PATH);
  lpath_def_from = 'b';
#else
  fromlibpath = TRUE;
  if (lp = getreg("librarypath")) {
    strcpy(library_default, lp);
    fromlibpath = TRUE;
    lpath_def_from = 'l';
  } else if (lp = getreg("path")) {
    strcpy(library_default, lp);
    fromlibpath = FALSE;
    lpath_def_from = 'p';
  } else {
    library_default[0] = '\0';
    fromlibpath = FALSE;
    lpath_def_from = 'n';
    if (severity_threshold <= sDEBUG)
      error(sDEBUG, "No default for library_path ");
  }
#endif

  /* find out, if this executable is bound to a yabasic program */
  inter_path = find_interpreter(argv[0]);
  is_bound = isbound();

  /* parse arguments */
  parse_arguments(argc, argv);

  /* now, that we have the debuglevel, we may report, where we got the library
   * path from */
  if (severity_threshold <= sDEBUG) {
    switch (lpath_def_from) {
    case 'b':
      sprintf(string, "Using builtin default for library_path: %s",
              library_default);
      break;
    case 'l':
      sprintf(
          string,
          "Using default for library_path from registry key 'librarypath': %s",
          library_default);
      break;
    case 'p':
      sprintf(string,
              "Using default for library_path from registry key 'path': %s",
              library_default);
      break;
    case 'n':
      sprintf(string, "No default for library_path ");
      break;
    }
    error(sDEBUG, string);
  }
  /* brush up library path */
  if (!library_path[0]) {
    strcpy(library_path, library_default);
    if (severity_threshold <= sDEBUG)
      error(sDEBUG, "No library_path specified on commandline");
  } else if (severity_threshold <= sDEBUG) {
    sprintf(string, "library_path from commandline is: %s", library_path);
    error(sDEBUG, string);
  }

  len = strlen(library_path);
#ifdef UNIX
  if (library_path[len - 1] == '/' || library_path[len - 1] == '\\') {
    library_path[len - 1] = '\0';
  }
#else
  if (library_path[0]) {
    if (library_path[len - 1] != '/' && library_path[len - 1] != '\\') {
      strcat(library_path, "\\");
    }
    if (!fromlibpath) {
      strcat(library_path, "lib\\");
    }
  }
#endif
  if (severity_threshold <= sDEBUG) {
    sprintf(string, "Final value for library_path is: %s", library_path);
    error(sDEBUG, string);
  }

  compilation_start = compilation_end = current_millis();

  /* initialize error handling: no errors seen 'til now */
  severity_so_far = sDEBUG;
  debug_count = 0;
  note_count = 0;
  warning_count = 0;
  error_count = 0;

  error(sDEBUG, "This is yabasic " VERSION ", compiled on " ARCHITECTURE
                ", configured at " BUILD_TIME);

  initialize();

  if (severity_so_far < sERROR) {

    set_program_state(spINITIALIZED);

    error(sNOTE, "calling parser/compiler");

    if (interactive) {
      printf("%s", BANNER);
      printf("Enter your program and type RETURN twice when done.\n\n");
      printf("Your program will execute immediately and cannot be saved;\n");
      printf("create your program with an external editor, to avoid this.\n");
#ifdef UNIX
      printf("Type 'man yabasic' or see the file yabasic.htm for more "
             "information,\n");
#else
      printf("See the documentation within the start-menu for more "
             "information,\n");
#endif
      printf("or go to www.yabasic.de for online resources.\n\n");
    }

    set_program_state(spCOMPILING);
    start_token = tSTART_PROGRAM;
    error(sDEBUG, "parsing complete program");
    if (yyparse() && severity_so_far >= sERROR) {
      error_without_position(sERROR, "Couldn't parse program");
    }

    if (severity_so_far < sERROR) {
      create_docu_array();
      add_command(cEND);
    }

    sprintf(string, "read %d line(s) and generated %d command(s)", yylineno,
            commandcount);
    error(sNOTE, string);

    compilation_end = current_millis();

    if (to_bind) {
      if (mybind(to_bind)) {
        sprintf(string, "Successfully bound '%s' and '%s' into '%s'",
                inter_path, main_file_name, to_bind);
        error(sINFO, string);
        end_it();
      } else {
        sprintf(string, "Could not bind '%s' and '%s' into '%s'", inter_path,
                main_file_name, to_bind);
        error(sERROR, string);
        end_it();
      }
    }
  }

  if (severity_so_far < sERROR && !check_compat) {
    set_program_state(spRUNNING);
    run_it();
  } else {
    if (check_compat)
      printf("Check for possible compatibility problems done\nProgram will not "
             "be executed, %d possible problem(s) reported\n",
             warning_count);
    else {
      error_without_position(sERROR, "Program not executed");
    }
  }

  set_program_state(spFINISHED);
  sprintf(string, "%d debug(s), %d note(s), %d warning(s), %d error(s)",
          debug_count, note_count, warning_count, error_count);
  error(sNOTE, string);
  execution_end = current_millis();
  sprintf(string, "compilation time %.3g second(s), execution %.3g",
          (double)(compilation_end - compilation_start) / 1000,
          (double)(execution_end - compilation_end) / 1000);
  error(sNOTE, string);

  end_it();
  return !(severity_so_far >= sERROR);
}

/* ------------- subroutines ---------------- */

void std_diag(char *head, int type, char *symname,
              char *diag) /* produce standard diagnostic */
{
  int n, i;
  char *dest = string;
  struct stackentry *sp;

  if (type > cLAST_COMMAND || type < cFIRST_COMMAND) {
    sprintf(dest, "%s Illegal %d %n", head, type, &n);
  } else {
    if (symname)
      sprintf(dest, "%s %s (%s) %n", head, cexplanation[type], symname, &n);
    else {
      sprintf(dest, "%s %s %n", head, cexplanation[type], &n);
    }
    if (diag && *diag) {
      dest += n;
      sprintf(dest, "'%s' %n", diag, &n);
    }
  }
  dest += n;
  if (stackhead->prev != stackroot && stackhead != stackroot) {
    sprintf(dest, "t[");
    dest += 2;
    sp = stackhead;
    for (i = 0; TRUE; i++) {
      sp = sp->prev;
      if (sp == stackroot) {
        break;
      }
      if (i >= 5) {
        continue;
      }
      if (i > 0) {
        sprintf(dest, ",");
        dest++;
      }
      switch (sp->type) {
      case stGOTO:
        sprintf(dest, "goto%n", &n);
        break;
      case stSTRINGARRAYREF:
      case stNUMBERARRAYREF:
        if (sp->pointer) {
          sprintf(dest, "%s()%n", (char *)sp->pointer, &n);
        } else {
          sprintf(dest, "ARRAY()%n", &n);
        }
        break;
      case stSTRING:
        sprintf(dest, "'%s'%n", (char *)sp->pointer, &n);
        break;
      case stNUMBER:
        sprintf(dest, "%g%n", sp->value, &n);
        break;
      case stLABEL:
        sprintf(dest, "label%n", &n);
        break;
      case stRET_ADDR:
        sprintf(dest, "retadd%n", &n);
        break;
      case stRET_ADDR_CALL:
        sprintf(dest, "retaddcall%n", &n);
        break;
      case stFREE:
        sprintf(dest, "free%n", &n);
        break;
      case stROOT:
        sprintf(dest, "root%n", &n);
        break;
      case stSWITCH_STRING:
        sprintf(dest, "switch_string%n", &n);
        break;
      case stSWITCH_NUMBER:
        sprintf(dest, "switch_number%n", &n);
        break;
      default:
        sprintf(dest, "unknown%n", &n);
        break;
      }
      dest += n;
    }
    if (i > 7) {
      sprintf(dest, ";+%d%n", i - 5, &n);
      dest += n;
    }
    strcpy(dest, "]b");
  } else {
    strcpy(dest, "t[]b");
  }
  error(sDEBUG, string);
}

int effective_lineno()
/* compute effective lineno for error messages; see the remark in yabasic.flex
   for some background */
{
  static int last_yy = -1;
  static struct library *lastlib = NULL;
  int this_yy;

  if (lastlib != currlib) {
    last_yy = -1;
    lastlib = currlib;
  }
  this_yy = yylineno - currlib->yylineno_at_start + 1 -
            (yycolumn == 1 ? (yydoublenl ? 2 : 1) : 0);
  if (this_yy < last_yy) {
    return last_yy;
  } else {
    last_yy = this_yy;
    return this_yy;
  }
}

struct command *add_command(int type)
/* common case without a sym */
{
  return add_command_with_sym_and_diag(type, NULL, NULL);
}

struct command *add_command_with_sym_and_diag(int type, char *symname,
                                              char *diag)
/* get room for new command, and make a link from old one */
{
  struct command *new;

  if (severity_threshold <= sDEBUG) {
    std_diag("creating", type, symname, diag);
  }
  cmd_head->type = type; /* store command */
  cmd_head->line = effective_lineno();
  cmd_head->first_column = yylloc.first_column;
  cmd_head->last_column = yylloc.last_column;
  cmd_head->lib = currlib;
  cmd_head->cnt = commandcount;
  cmd_head->diag = my_strdup(diag);
  if (!symname || !*symname) {
    cmd_head->symname = NULL;
  } else {
    cmd_head->symname = my_strdup(symname);
  }
  commandcount++;
  cmd_head->pointer = NULL;
  cmd_head->tag = 0;
  cmd_head->jump = NULL;
  cmd_head->next_assoc = NULL;
  if (!currlib->datapointer && cmd_head->type == cDATA) {
    currlib->firstdata = currlib->datapointer = cmd_head;
  }

  /* link into chain of commands referencing a symbol */
  if (symname) {
    if (last_symref) {
      last_symref->next_symref = cmd_head;
    }
    last_symref = cmd_head;
  }

  /* create new command */
  new = (struct command *)my_malloc(sizeof(struct command));
  /* and initialize */
  new->next = NULL;
  new->prev = cmd_head;
  new->pointer = NULL;
  new->symbol = NULL;
  new->next_symref = NULL;
  new->next_assoc = NULL;
  new->symname = NULL;
  new->switch_state = NULL;

  cmd_head->next = new;
  last_cmd = cmd_head;
  cmd_head = cmd_head->next;
  return last_cmd;
}

struct command *add_command_with_switch_state(
    int type) /* same as add_command, but add switch_state too */
{
  struct command *cmd;

  cmd = add_command(type);
  return add_switch_state(cmd);
}

void dump_commands(char *dumpfilename)
/* dump commands into given file */
{
  FILE *dump = NULL;
  struct command *cmd;
  int max_explanation_length = 0;

  dump = fopen(dumpfilename, "w");
  if (dump == NULL) {
    sprintf(string, "could not open '%s' for writing: %s", dumpfilename,
            my_strerror(errno));
    error(sERROR, string);
    return;
  }

  for (cmd = cmd_root; cmd; cmd = cmd->next) {
    int len;
    len = strlen(cexplanation[cmd->type]);
    if (len > max_explanation_length) {
      max_explanation_length = len;
    }
    if (cmd->type > cLAST_COMMAND || cmd->type < cFIRST_COMMAND) {
      sprintf(string, "Illegal command type %d", cmd->type);
      error(sERROR, string);
      return;
    }
    if (cmd->type == cEND) {
      break;
    }
  }

  for (cmd = cmd_root; cmd; cmd = cmd->next) {
    fprintf(dump, "Line %4d, Address %p:   %-*s   (lib %s, ptr %p, tag 0x%x)\n",
            cmd->line, cmd, max_explanation_length, cexplanation[cmd->type],
            cmd->lib->short_name, cmd->pointer, cmd->tag);
    if (cmd->type == cEND) {
      break;
    }
  }
  fclose(dump);
  sprintf(string, "Dumped to '%s'", dumpfilename);
  error(sINFO, string);
}

static void parse_arguments(int cargc, char *cargv[])
/* parse arguments from the command line */
{
  char **argv;
  int argc, larg;
#ifdef UNIX
  char *parg;
  int i;
#endif
  int ar;
  FILE *inputfile = NULL;
  char *option;
  char *info;
  int options_done = FALSE;

  if (cargc > 1) {
    larg = strlen(cargv[1]);
  } else {
    larg = 0;
  }
#ifdef UNIX
  if (cargc > 0) {
    /* get room for arguments */
    argv = (char **)my_malloc((larg + cargc + 1) * sizeof(char *));
    /* copy zero argument */
    argv[0] = cargv[0];
    argc = 0;
    /* chop first argument into pieces */
    if (cargc >= 2) {
      parg = strtok(my_strdup(cargv[1]), " \t");
      for (argc = 1; parg; argc++) {
        argv[argc] = parg;
        parg = strtok(NULL, " \t");
      }
    }
    /* copy other arguments */
    for (i = 2; i < cargc; i++) {
      argv[argc] = cargv[i];
      argc++;
    }
  } else {
    argv = cargv;
    argc = cargc;
  }
#else
  argv = cargv;
  argc = cargc;
#endif
  yabargv = (char **)my_malloc((larg + cargc + 1) * sizeof(char *));
  yabargc = 0;

  if (is_bound) {
    options_done = 1;
  }
  /* process options */
  for (ar = 1; ar < argc; ar++) {
    option = argv[ar];
    if (!options_done) {
      if (equal("-version", option, 2)) {
        fprintf(stderr, "%s\n", BANNER_VERSION);
        end_it();
      } else if (equal("-help", option, -2) || equal("-?", option, 2)) {
        fprintf(stderr,
                "\nUsage:        yabasic [OPTIONS] [FILENAME [ARGUMENTS]]\n\n");
        fprintf(stderr, "FILENAME  : file, which contains the yabasic program; "
                        "omit it to type\n");
        fprintf(stderr, "            in your program on the fly (terminated by "
                        "a double newline)\n");
        fprintf(stderr, "ARGUMENTS : strings, that are available from within "
                        "the yabasic program\n\n");
        fprintf(stderr, "Available OPTIONS:\n");
        fprintf(stderr, "   --help                  : print this message\n");
        fprintf(stderr,
                "   --version               : show version of yabasic\n");
        fprintf(stderr, "   -i,--infolevel [dnwefb] : set infolevel to "
                        "debug,note,warning,error,fatal or bison+flex\n");
        fprintf(stderr, "   -e,--execute COMMANDS   : execute yabasic COMMANDS "
                        "right away\n");
        fprintf(stderr, "   --bind BOUND            : bind interpreter with "
                        "FILENAME into BOUND\n");
        fprintf(
            stderr,
            "   --geometry x+y          : position graphic window at x,y\n");
#ifdef UNIX
        fprintf(stderr, "   -fg,--foreground COL    : specify foreground color "
                        "of graphic window\n");
        fprintf(stderr, "   -bg,--background COL    : specify background color "
                        "of graphic window\n");
        fprintf(stderr, "   --display DISP          : display, where window "
                        "will show up\n");
        fprintf(stderr,
                "   --font FONT             : font for graphic window\n");
#else
        fprintf(stderr, "   --font FONT             : font for graphic, supply "
                        "style (decorative,dontcare,\n");
        fprintf(stderr, "                             modern,roman,script or "
                        "swiss) and size, e.g. swiss10\n");
#endif
        fprintf(stderr, "   --docu NAME             : print embedded docu of "
                        "program or library\n");
        fprintf(stderr, "   --check                 : check for possible "
                        "compatibility problems\n");
        fprintf(stderr, "   --librarypath PATH      : directory to search "
                        "libraries not found in\n");
        fprintf(stderr,
                "                             current dir (default %s)\n",
                library_default);
        fprintf(stderr, "   --                      : pass any subsequent "
                        "words as arguments to yabasic\n");
        fprintf(stderr, "\n");
        end_it();
      } else if (equal("-check", option, 2)) {
        check_compat = 1;
      } else if (!strcmp("--", option)) {
        options_done = TRUE;
        continue;
      } else if (equal("-infolevel", option, 2)) {
        ar++;
        if (ar >= argc) {
          error(sERROR, "no infolevel specified " YABFORHELP);
          end_it();
        }
        info = argv[ar];
        if (!strncmp(info, "debug", strlen(info))) {
          severity_threshold = sDEBUG;
        } else if (!strncmp(info, "note", strlen(info))) {
          severity_threshold = sNOTE;
        } else if (!strncmp(info, "warning", strlen(info))) {
          severity_threshold = sWARNING;
        } else if (!strncmp(info, "error", strlen(info))) {
          severity_threshold = sERROR;
        } else if (!strncmp(info, "fatal", strlen(info))) {
          severity_threshold = sFATAL;
        } else if (!strncmp(info, "bison", strlen(info))) {
          yydebug = 1;
          yy_flex_debug = 1;
          severity_threshold = sDEBUG;
        } else {
          sprintf(string, "there's no infolevel '%s' " YABFORHELP, argv[ar]);
          error(sERROR, string);
          end_it();
        }
      } else if (equal("-fg", option, 3) || equal("-foreground", option, 4)) {
        ar++;
        if (ar >= argc) {
          error(sERROR, "no foreground colour specified " YABFORHELP);
          end_it();
        }
        foreground = my_strdup(argv[ar]);
      } else if (equal("-bg", option, 2) || equal("-background", option, 2)) {
        ar++;
        if (ar >= argc) {
          error(sERROR, "no background colour specified (-h for help)");
          end_it();
        }
        background = my_strdup(argv[ar]);
      } else if (equal("-geometry", option, 2)) {
        ar++;
        if (ar >= argc) {
          error(sERROR, "no geometry string specified (-h for help)");
          end_it();
        }
        geometry = my_strdup(argv[ar]);
      } else if (equal("-bind", option, 3)) {
        ar++;
        if (ar >= argc) {
          error(sERROR, "name of bound program to be written is missing");
          end_it();
        }
        to_bind = my_strdup(argv[ar]);
      } else if (equal("-execute", option, 2)) {
        ar++;
        if (ar >= argc) {
          error(sERROR, "no commands specified (-h for help)");
          end_it();
        }
        explicit = my_strdup(argv[ar]);
      } else if (equal("-librarypath", option, 4)) {
        ar++;
        if (ar >= argc) {
          error(sERROR, "no library path specified (-h for help)");
          end_it();
        }
        strcpy(library_path, argv[ar]);
      } else if (equal("-display", option, 3)) {
        ar++;
        if (ar >= argc) {
          error(sERROR, "no display name specified (-h for help)");
          end_it();
        }
        displayname = my_strdup(argv[ar]);
      } else if (equal("-font", option, 4)) {
        ar++;
        if (ar >= argc) {
          error(sERROR, "no font specified (-h for help)");
          end_it();
        }
        fontname = my_strdup(argv[ar]);
      } else if (!print_docu &&
                 (!strcmp("-doc", option) || !strncmp("-doc_", option, 5) ||
                  !strcmp("-docu", option) || !strncmp("-docu_", option, 6))) {
        print_docu = TRUE;
        if (!strncmp("-doc_", option, 5)) {
          ar--;
          hold_docu = TRUE;
          main_file_name = my_strdup(option + 5);
        } else if (!strncmp("-docu_", option, 6)) {
          ar--;
          hold_docu = TRUE;
          main_file_name = my_strdup(option + 6);
        } else {
          if (ar >= argc - 1) {
            error(sERROR, "no filename specified (-h for help)");
            end_it();
          }
          hold_docu = FALSE;
          main_file_name = my_strdup(argv[ar + 1]);
        }
      } else if (!print_docu && *option == '-') {
        sprintf(string, "unknown or ambiguous option '%s' " YABFORHELP, option);
        error(sERROR, string);
        end_it();
      } else if (!is_bound && !inputfile && !explicit) {
        /* not an option */
        if (!main_file_name) {
          main_file_name = my_strdup(argv[ar]);
        }
        inputfile = fopen(main_file_name, "r");
        if (inputfile == NULL) {
          sprintf(string, "could not open '%s': %s", main_file_name,
                  my_strerror(errno));
          error(sERROR, string);
          endreason = rERROR;
          exitcode = 1;
          end_it();
        } else {
          progname = strrchr(main_file_name, '\\');
          if (!progname) {
            progname = strrchr(main_file_name, '/');
          }
          if (progname) {
            progname++;
          } else {
            progname = main_file_name;
          }
          if (!progname) {
            progname = "Yabasic";
          }
        }
      } else {
        /* option for yabasic program */
        yabargv[yabargc] = my_strdup(argv[ar]);
        yabargc++;
      }
    } else {
      yabargv[yabargc] = my_strdup(argv[ar]);
      yabargc++;
    }
  }

  interactive = FALSE;

#ifdef WINDOWS
  if (is_bound || !progname) {
    SetConsoleTitle("");
  } else {
    SetConsoleTitle(progname);
  }
#endif

  if (is_bound) {
    inputfile = bound_program;
    main_file_name = my_strdup(inter_path);
  } else if (!inputfile && !explicit) {
    interactive = TRUE;
    inputfile = stdin;
    main_file_name = "standard input";
  }
  if (explicit) {
    main_file_name = "command line";
  }

  /* open a flex buffer for the initial file */
  open_main(inputfile, explicit, main_file_name);
  return;
}

int equal(char *a, char *b, int min) /* helper for processing options */
{
  int len;
  if (b[0] == '-' && b[1] == '-' && b[2]) {
    b++;
  }
  if (min < 0) {
    min = -min;
    len = min;
  } else {
    len = strlen(b);
  }

  return (!strncmp(a, b, len) && len >= min);
}

#ifdef WINDOWS
static void chop_command(char *command, int *argc, char ***argv)
/* chop the WIN95-commandline into seperate strings */
{
  int i, j, count;
  int quote;
  char c, last;
  char *curr;
  char **list;

  /* count, how many arguments */
  count = i = 0;
  last = ' ';
  quote = FALSE;
  while ((c = *(command + i)) != '\0') {
    if (!quote && c != ' ' && last == ' ') {
      count++;
    }
    if (c == '\"') {
      quote = !quote;
    }
    last = c;
    i++;
  }

  /* fill yabasic into argv[0] */
  *argv = my_malloc((count + 1) * sizeof(char *));
  list = *argv;
  *argc = count + 1;
  *list = my_strdup("yabasic");

  /* fill in other strings */
  i = 0;
  count = 1;
  last = ' ';
  quote = FALSE;
  do {
    c = *(command + i);
    if (!quote && c != ' ' && last == ' ') {
      j = i;
    }
    if (c == '\"') {
      quote = !quote;
      if (quote) {
        j++;
      }
    }
    if (((c == ' ' && !quote) || c == '\0') && last != ' ') {
      *(list + count) = my_malloc((i - j + 1) * sizeof(char));
      strncpy(*(list + count), command + j, i - j);
      curr = *(list + count) + i - j;
      *curr = '\0';
      if (*(curr - 1) == '\"') {
        *(curr - 1) = '\0';
      }
      count++;
    }
    last = c;
    i++;
  } while (c != '\0');
}
#endif

static void end_it(void) /* perform shutdown-operations */
{
  char l[INBUFFLEN];
#ifdef UNIX
  int status;

  if (backpid == 0) {
    /* this is the background process */
    exit(1);
  }
  if (backpid > 0) {
    kill(backpid, SIGTERM);
    waitpid(backpid, &status, 0);
    backpid = -1;
  }
  if ((con_xcap_inized || winopened) && endreason != rREQUEST) {
#else
  if (!Commandline && endreason != rREQUEST) {
#endif
    /* we assume that user want to study grafical window or curses-output before we close
       all this */
    mystream(STDIO_STREAM);
    onestring("---Program done, press RETURN---\n");
#ifdef UNIX
    if (con_xcap_inized) {
      int ch = 0;
      raw();
      cbreak();
      noecho();
      /* Consume chars until we see ctrl-c or return. On ctrl-c this behaves better than
	 getnstr, because with this loop we get a chance to reset terminal quickly. */
      while(ch != 3 && ch != 10 && ch != 13) {
	ch=getch();
      }
    } else {
      /* avoid a compiler warning */
      (void)!fgets(l, INBUFFLEN, stdin);
    }
#else
    SetConsoleMode(ConsoleInput, InitialConsole & (~ENABLE_ECHO_INPUT));
    FlushConsoleInputBuffer(ConsoleInput);
    fgets(l, INBUFFLEN, stdin);
    if (wthandle != INVALID_HANDLE_VALUE) {
      TerminateThread(wthandle, 0);
    }
#endif
  }

  con_xcap_deinit();  
#ifdef WINDOWS
  if (printerfont) {
    DeleteObject(printerfont);
  }
  if (myfont) {
    DeleteObject(myfont);
  }
  if (printer) {
    DeleteDC(printer);
  }
#endif
  exit(exitcode);
}

static void set_program_state(int state) {
  char *txt;

  if (severity_threshold <= sDEBUG && program_state != state) {

    switch (state) {
    case spHATCHED:
      txt = "HATCHED";
      break;
    case spINITIALIZED:
      txt = "INITIALIZED";
      break;
    case spCOMPILING:
      txt = "COMPILING";
      break;
    case spRUNNING:
      txt = "RUNNING";
      break;
    case spFINISHED:
      txt = "FINISHED";
      break;
    default:
      sprintf(estring, "unknown program state: %d", state);
      error(sERROR, estring);
      return;
    }
    sprintf(estring, "Switching to program state %s", txt);
    error(sDEBUG, estring);
  }

  program_state = state;
}

static void initialize(void)
/* give correct values to pointers etc ... */
{
  struct symbol *s;
  struct stackentry *base;
#ifdef UNIX
  struct timeval time;
#endif
  int i;

  /* install exception handler */
  signal(SIGFPE, signal_handler);
  signal(SIGSEGV, signal_handler);
  signal(SIGINT, signal_handler);
#ifdef SIGHUP
  signal(SIGHUP, signal_handler);
#endif
#ifdef SIGQUIT
  signal(SIGQUIT, signal_handler);
#endif
#ifdef SIGABRT
  signal(SIGABRT, signal_handler);
#endif

  last_inkey = my_malloc(INBUFFLEN);
  last_inkey[0] = '\0';

  /* initialize stack of symbol lists */
  pushsymlist();

  /* initialize numeric stack */
  /* create first : */
  stackroot = (struct stackentry *)my_malloc(sizeof(struct stackentry));
  stackroot->next = NULL;
  stackroot->prev = NULL;
  stackhead = stackroot; /* central processing stack */

  /* initialize command stack */
  /* create first: */
  cmd_root = (struct command *)my_malloc(sizeof(struct command));
  cmd_root->next = cmd_root->prev = NULL;

  /* initialize random number generator */
#ifdef UNIX
  gettimeofday(&time, NULL);
  srand((time.tv_sec * 1000) + (time.tv_usec / 1000));
#else
  srand(GetTickCount());
#endif

  /* specify default text-alignement and window origin */
  text_align = my_strdup("lb");
  winorigin = my_strdup("lt");

  /* initialize stack */
  base = push();
  base->type = stROOT; /* push nil, so that pop will not crash */
  cmd_head = cmd_root; /* list of commands */
  ;
  commandcount = 0;

  /* initialize switch_id stack */
  initialize_switch_id_stack();

  /* add internal string variables */
  s = get_sym("yabos$", sySTRING, amADD_GLOBAL);
  if (s->pointer) {
    my_free(s->pointer);
  }
#ifdef UNIX
  s->pointer = my_strdup("unix");
#else
  s->pointer = my_strdup("windows");
#endif

  /* set default-scales for grafics */
  fontheight = 10;
  winheight = 100;
  winwidth = 100;
#ifdef UNIX
  calc_psscale();
#endif

  /* file stuff */
  for (i = 1; i <= 9; i++) {
    streams[i] = NULL;
    stream_modes[i] = mCLOSED;
  }
  streams[0] = stdin;
  stream_modes[0] = mREAD | mWRITE;
#ifdef UNIX
  printerfile = NULL; /* no ps-file yet */
#endif

  /* array with explanation of commands */
  for (i = cFIRST_COMMAND; i <= cLAST_COMMAND; i++) {
    cexplanation[i] = NULL;
  }
  cexplanation[cFIRST_COMMAND] = "FIRST_COMMAND";
  cexplanation[cFINDNOP] = "FINDNOP";
  cexplanation[cEXCEPTION] = "EXCEPTION";
  cexplanation[cLABEL] = "LABEL";
  cexplanation[cLINK_SUBR] = "cLINK_SUBR";
  cexplanation[cTOKEN] = "TOKEN";
  cexplanation[cTOKEN2] = "TOKEN2";
  cexplanation[cTOKENALT] = "TOKENALT";
  cexplanation[cTOKENALT2] = "TOKENALT2";
  cexplanation[cSPLIT] = "SPLIT";
  cexplanation[cSPLIT2] = "SPLIT2";
  cexplanation[cSPLITALT] = "SPLITALT";
  cexplanation[cSPLITALT2] = "SPLITALT2";
  cexplanation[cGOTO] = "GOTO";
  cexplanation[cQGOTO] = "QGOTO";
  cexplanation[cGOSUB] = "GOSUB";
  cexplanation[cQGOSUB] = "QGOSUB";
  cexplanation[cCALL] = "CALL";
  cexplanation[cQCALL] = "QCALL";
  cexplanation[cRETURN_FROM_GOSUB] = "RETURN_FROM_GOSUB";
  cexplanation[cRETURN_FROM_CALL] = "RETURN_FROM_CALL";
  cexplanation[cCHECK_RETURN_VALUE] = "CHECK_RETURN_VALUE";
  cexplanation[cSWAP] = "SWAP";
  cexplanation[cDECIDE] = "DECIDE";
  cexplanation[cANDSHORT] = "ANDSHORT";
  cexplanation[cORSHORT] = "ORSHORT";
  cexplanation[cSKIPPER] = "SKIPPER";
  cexplanation[cSKIPONCE] = "SKIPONCE";
  cexplanation[cRESETSKIPONCE] = "RESETSKIPONCE";
  cexplanation[cRESETSKIPONCE2] = "RESETSKIPONCE2";
  cexplanation[cNOP] = "NOP";
  cexplanation[cEND_FUNCTION] = "END_FUNCTION";
  cexplanation[cDIM] = "DIM";
  cexplanation[cFUNCTION] = "FUNCTION";
  cexplanation[cDOARRAY] = "DOARRAY";
  cexplanation[cDBLADD] = "DBLADD";
  cexplanation[cDBLMIN] = "DBLMIN";
  cexplanation[cDBLMUL] = "DBLMUL";
  cexplanation[cDBLDIV] = "DBLDIV";
  cexplanation[cDBLPOW] = "DBLPOW";
  cexplanation[cNEGATE] = "NEGATE";
  cexplanation[cPUSHDBLSYM] = "PUSHDBLSYM";
  cexplanation[cREQUIRE] = "REQUIRE";
  cexplanation[cCLEARSYMREFS] = "CLEARSYMREFS";
  cexplanation[cPUSHSYMLIST] = "PUSHSYMLIST";
  cexplanation[cPOPSYMLIST] = "POPSYMLIST";
  cexplanation[cMAKELOCAL] = "MAKELOCAL";
  cexplanation[cCOUNT_PARAMS] = "COUNT_PARAMS";
  cexplanation[cMAKESTATIC] = "MAKESTATIC";
  cexplanation[cARRAYLINK] = "ARRAYLINK";
  cexplanation[cPUSHARRAYREF] = "PUSHARRAYREF";
  cexplanation[cARDIM] = "ARRAYDIMENSION";
  cexplanation[cARSIZE] = "ARRAYSIZE";
  cexplanation[cUSER_FUNCTION] = "USER_FUNCTION";
  cexplanation[cFUNCTION_OR_ARRAY] = "FUNCTION_OR_ARRAY";
  cexplanation[cSTRINGFUNCTION_OR_ARRAY] = "STRINGFUNCTION_OR_ARRAY";
  cexplanation[cPUSHFREE] = "PUSHFREE";
  cexplanation[cPOPDBLSYM] = "POPDBLSYM";
  cexplanation[cPOP] = "POP";
  cexplanation[cPUSHDBL] = "PUSHDBL";
  cexplanation[cPOKE] = "POKE";
  cexplanation[cPOKEFILE] = "POKEFILE";
  cexplanation[cAND] = "AND";
  cexplanation[cOR] = "OR";
  cexplanation[cNOT] = "NOT";
  cexplanation[cLT] = "LT";
  cexplanation[cGT] = "GT";
  cexplanation[cLE] = "LE";
  cexplanation[cGE] = "GE";
  cexplanation[cEQ] = "EQ";
  cexplanation[cNE] = "NE";
  cexplanation[cSTREQ] = "STREQ";
  cexplanation[cSTRNE] = "STRNE";
  cexplanation[cSTRLT] = "STRLT";
  cexplanation[cSTRLE] = "STRLE";
  cexplanation[cSTRGT] = "STRGT";
  cexplanation[cSTRGE] = "STRGE";
  cexplanation[cPUSHSTRSYM] = "PUSHSTRSYM";
  cexplanation[cPOPSTRSYM] = "POPSTRSYM";
  cexplanation[cPUSHSTR] = "PUSHSTR";
  cexplanation[cCONCAT] = "CONCAT";
  cexplanation[cPUSHSTRPTR] = "PUSHSTRPTR";
  cexplanation[cCHANGESTRING] = "CHANGESTRING";
  cexplanation[cGLOB] = "GLOB";
  cexplanation[cPRINT] = "PRINT";
  cexplanation[cREAD] = "READ";
  cexplanation[cRESTORE] = "RESTORE";
  cexplanation[cQRESTORE] = "QRESTORE";
  cexplanation[cREADDATA] = "READDATA";
  cexplanation[cONESTRING] = "ONESTRING";
  cexplanation[cDATA] = "DATA";
  cexplanation[cOPEN] = "OPEN";
  cexplanation[cCHECKOPEN] = "CHECKOPEN";
  cexplanation[cCHECKSEEK] = "CHECKSEEK";
  cexplanation[cCOMPILE] = "COMPILE";
  cexplanation[cEXECUTE] = "EXECUTE";
  cexplanation[cEXECUTE2] = "EXECUTE$";
  cexplanation[cEVAL] = "EVAL";
  cexplanation[cEVAL_CODE] = "EVAL_CODE";
  cexplanation[cCLOSE] = "CLOSE";
  cexplanation[cSEEK] = "SEEK";
  cexplanation[cSEEK2] = "SEEK2";
  cexplanation[cPUSHSTREAM] = "cPUSHSTREAM";
  cexplanation[cPOPSTREAM] = "cPOPSTREAM";
  cexplanation[cWAIT] = "WAIT";
  cexplanation[cBELL] = "BELL";
  cexplanation[cMOVE] = "MOVE";
  cexplanation[cMOVEORIGIN] = "MOVEORIGIN";
  cexplanation[cRECT] = "RECT";
  cexplanation[cCLEARSCR] = "CLEARSCR";
  cexplanation[cOPENWIN] = "OPENWIN";
  cexplanation[cDOT] = "DOT";
  cexplanation[cPUTBIT] = "PUTBIT";
  cexplanation[cPUTCHAR] = "PUTCHAR";
  cexplanation[cFRNBF_SET_NUMBER] = "FRNBF_SET_NUMBER";
  cexplanation[cFRNBF_SET_STRING] = "FRNBF_SET_STRING";
  cexplanation[cFRNBF_SET_BUFFER] = "FRNBF_SET_BUFFER";
  cexplanation[cFRNBF_FREE] = "FRNBF_FREE";
  cexplanation[cLINE] = "LINE";
  cexplanation[cGCOLOUR] = "GCOLOUR";
  cexplanation[cGCOLOUR2] = "GCOLOUR2";
  cexplanation[cGBACKCOLOUR] = "GBACKCOLOUR";
  cexplanation[cGBACKCOLOUR2] = "GBACKCOLOUR2";
  cexplanation[cCIRCLE] = "CIRCLE";
  cexplanation[cTRIANGLE] = "TRIANGLE";
  cexplanation[cTEXT1] = "TEXT1";
  cexplanation[cTEXT2] = "TEXT2";
  cexplanation[cTEXT3] = "TEXT3";
  cexplanation[cCLOSEWIN] = "CLOSEWIN";
  cexplanation[cCLEARWIN] = "CLEARWIN";
  cexplanation[cOPENPRN] = "OPENPRN";
  cexplanation[cCLOSEPRN] = "CLOSEPRN";
  cexplanation[cTESTEOF] = "TESTEOF";
  cexplanation[cCOLOUR] = "COLOUR";
  cexplanation[cDUPLICATE] = "DUPLICATE";
  cexplanation[cDOCU] = "DOCU";
  cexplanation[cEND] = "END";
  cexplanation[cEXIT] = "EXIT";
  cexplanation[cBIND] = "BIND";
  cexplanation[cERROR] = "ERROR";
  cexplanation[cSTARTFOR] = "STARTFOR";
  cexplanation[cFORCHECK] = "FORCHECK";
  cexplanation[cFORINCREMENT] = "FORINCREMENT";
  cexplanation[cBEGIN_SWITCH_MARK] = "BEGIN_SWITCH_MARK";
  cexplanation[cEND_SWITCH_MARK] = "END_SWITCH_MARK";
  cexplanation[cBEGIN_LOOP_MARK] = "BEGIN_LOOP_MARK";
  cexplanation[cEND_LOOP_MARK] = "END_LOOP_MARK";
  cexplanation[cSWITCH_COMPARE] = "SWITCH_COMPARE";
  cexplanation[cNEXT_CASE] = "NEXT_CASE";
  cexplanation[cNEXT_CASE_HERE] = "NEXT_CASE_HERE";
  cexplanation[cBREAK_MULTI] = "BREAK_MULTI";
  cexplanation[cCONTINUE] = "CONTINUE";
  cexplanation[cBREAK_HERE] = "BREAK_HERE";
  cexplanation[cCONTINUE_HERE] = "CONTINUE_HERE";
  cexplanation[cPOP_MULTI] = "POP_MULTI";
  cexplanation[cCHKPROMPT] = "CHKPROMPT";
  cexplanation[cLAST_COMMAND] = "LAST_COMMAND";
  for (i = cFIRST_COMMAND; i <= cLAST_COMMAND; i++) {
    if (!cexplanation[i]) {
      sprintf(string, "command %d has no description (command after %s)", i,
              cexplanation[i - 1]);
      error(sERROR, string);
    }
  }

  /* array with explanation of functions */
  for (i = fFIRST_FUNCTION; i <= fLAST_FUNCTION; i++) {
    fexplanation[i] = NULL;
  }
  fexplanation[fFIRST_FUNCTION] = "FIRST_FUNCTION";
  fexplanation[fRAN2] = "RAN2";
  fexplanation[fDATE] = "DATE";
  fexplanation[fTIME] = "TIME";
  fexplanation[fZEROARGS] = "ZEROARGS";
  fexplanation[fINKEY] = "INKEY";
  fexplanation[fMOUSEX] = "MOUSEX";
  fexplanation[fMOUSEY] = "MOUSEY";
  fexplanation[fMOUSEB] = "MOUSEB";
  fexplanation[fMOUSEMOD] = "MOUSEMOD";
  fexplanation[fSIN] = "SIN";
  fexplanation[fASIN] = "ASIN";
  fexplanation[fCOS] = "COS";
  fexplanation[fACOS] = "ACOS";
  fexplanation[fTAN] = "TAN";
  fexplanation[fATAN] = "ATAN";
  fexplanation[fSYSTEM] = "SYSTEM";
  fexplanation[fSYSTEM2] = "SYSTEM2";
  fexplanation[fPEEK] = "PEEK";
  fexplanation[fPEEK2] = "PEEK2";
  fexplanation[fPEEK4] = "PEEK4";
  fexplanation[fFRNFN_CALL] = "FRNFN_CALL";
  fexplanation[fFRNFN_CALL2] = "FRNFN_CALL2";
  fexplanation[fFRNBF_SIZE] = "FRNBF_SIZE";
  fexplanation[fFRNBF_ALLOC] = "FRNBF_ALLOC";
  fexplanation[fFRNBF_DUMP] = "FRNBF_DUMP";
  fexplanation[fFRNBF_DUMP2] = "FRNBF_DUMP2";
  fexplanation[fFRNFN_SIZE] = "FRNFN_SIZE";
  fexplanation[fFRNBF_GET_NUMBER] = "FRNBF_GET_NUMBER";
  fexplanation[fFRNBF_GET_STRING] = "FRNBF_GET_STRING";
  fexplanation[fFRNBF_GET_BUFFER] = "FRNBF_GET_BUFFER";
  fexplanation[fTELL] = "TELL";
  fexplanation[fEXP] = "EXP";
  fexplanation[fLOG] = "LOG";
  fexplanation[fLEN] = "LEN";
  fexplanation[fSTR] = "STR";
  fexplanation[fSTR4] = "STR4";
  fexplanation[fSQRT] = "SQRT";
  fexplanation[fSQR] = "SQR";
  fexplanation[fFRAC] = "FRAC";
  fexplanation[fROUND] = "ROUND";
  fexplanation[fABS] = "ABS";
  fexplanation[fSIG] = "SIG";
  fexplanation[fRAN] = "RAN";
  fexplanation[fINT] = "INT";
  fexplanation[fCEIL] = "CEIL";
  fexplanation[fFLOOR] = "FLOOR";
  fexplanation[fVAL] = "VAL";
  fexplanation[fASC] = "ASC";
  fexplanation[fHEX] = "HEX";
  fexplanation[fBIN] = "BIN";
  fexplanation[fDEC] = "DEC";
  fexplanation[fUPPER] = "UPPER";
  fexplanation[fLOWER] = "LOWER";
  fexplanation[fCHOMP] = "CHOMP";
  fexplanation[fLTRIM] = "LTRIM";
  fexplanation[fRTRIM] = "RTRIM";
  fexplanation[fTRIM] = "TRIM";
  fexplanation[fSTRING] = "STRING";
  fexplanation[fCHR] = "CHR";
  fexplanation[fBITNOT] = "BITNOT";
  fexplanation[fONEARGS] = "ONEARGS";
  fexplanation[fDEC2] = "DEC2";
  fexplanation[fATAN2] = "ATAN2";
  fexplanation[fLEFT] = "LEFT";
  fexplanation[fAND] = "AND";
  fexplanation[fOR] = "OR";
  fexplanation[fEOR] = "EOR";
  fexplanation[fSHL] = "SHL";
  fexplanation[fSHR] = "SHR";
  fexplanation[fLOG2] = "LOG2";
  fexplanation[fRIGHT] = "RIGHT";
  fexplanation[fINSTR] = "INSTR";
  fexplanation[fRINSTR] = "RINSTR";
  fexplanation[fSTR2] = "STR2";
  fexplanation[fMOD] = "MOD";
  fexplanation[fMIN] = "MIN";
  fexplanation[fMAX] = "MAX";
  fexplanation[fPEEK3] = "PEEK3";
  fexplanation[fMID2] = "MID2";
  fexplanation[fTWOARGS] = "TWOARGS";
  fexplanation[fMID] = "MID";
  fexplanation[fINSTR2] = "INSTR2";
  fexplanation[fRINSTR2] = "RINSTR2";
  fexplanation[fSTR3] = "STR3";
  fexplanation[fTHREEARGS] = "THREEARGS";
  fexplanation[fGETBIT] = "GETBIT";
  fexplanation[fGETCHAR] = "GETCHAR";
  fexplanation[fLAST_FUNCTION] = "LAST_FUNCTION";
  for (i = fFIRST_FUNCTION; i <= fLAST_FUNCTION; i++) {
    if (!fexplanation[i]) {
      sprintf(string, "function %d has no description (command after %s)", i,
              fexplanation[i - 1]);
      error(sERROR, string);
    }
  }

  ykey[kERR] = "error";
  ykey[kUP] = "up";
  ykey[kDOWN] = "down";
  ykey[kLEFT] = "left";
  ykey[kRIGHT] = "right";
  ykey[kDEL] = "del";
  ykey[kINS] = "ins";
  ykey[kCLEAR] = "clear";
  ykey[kHOME] = "home";
  ykey[kEND] = "end";
  ykey[kF0] = "f0";
  ykey[kF1] = "f1";
  ykey[kF2] = "f2";
  ykey[kF3] = "f3";
  ykey[kF4] = "f4";
  ykey[kF5] = "f5";
  ykey[kF6] = "f6";
  ykey[kF7] = "f7";
  ykey[kF8] = "f8";
  ykey[kF9] = "f9";
  ykey[kF10] = "f10";
  ykey[kF11] = "f11";
  ykey[kF12] = "f12";
  ykey[kF13] = "f13";
  ykey[kF14] = "f14";
  ykey[kF15] = "f15";
  ykey[kF16] = "f16";
  ykey[kF17] = "f17";
  ykey[kF18] = "f18";
  ykey[kF19] = "f19";
  ykey[kF20] = "f20";
  ykey[kF21] = "f21";
  ykey[kF22] = "f22";
  ykey[kF23] = "f23";
  ykey[kF24] = "f24";
  ykey[kBACKSPACE] = "backspace";
  ykey[kSCRNDOWN] = "scrndown";
  ykey[kSCRNUP] = "scrnup";
  ykey[kENTER] = "enter";
  ykey[kESC] = "esc";
  ykey[kTAB] = "tab";
  ykey[kLASTKEY] = "";
}

void signal_handler(int sig) /* handle signals */
/* Will not be called under unix when curses is active,
   because curses has its own signal handler.
   So curses can not be cleaned up here */
{
  signal(sig, SIG_DFL);
  if (program_state == spFINISHED) {
    exit(1);
  }
  signal_arrived = sig;

#ifdef WINDOWS
  if (signal_arrived) {
    SuspendThread(mainthread);
    if (wthandle != INVALID_HANDLE_VALUE) {
      SuspendThread(wthandle);
    }
  }
#endif

  switch (sig) {
  case SIGFPE:
    error(sFATAL, "floating point exception, cannot proceed.");
  case SIGSEGV:
    error(sFATAL, "segmentation fault, cannot proceed.");
  case SIGINT:
#ifdef UNIX
    if (backpid == 0) {
      exit(1);
    }
#endif
    error(sFATAL, "keyboard interrupt, cannot proceed.");
#ifdef SIGHUP
  case SIGHUP:
    error(sFATAL, "received signal HANGUP, cannot proceed.");
#endif
#ifdef SIGQUIT
  case SIGQUIT:
    error(sFATAL, "received signal QUIT, cannot proceed.");
#endif
#ifdef SIGABRT
  case SIGABRT:
    error(sFATAL, "received signal ABORT, cannot proceed.");
#endif
  default:
    break;
  }
}

static void run_it()
/* execute the compiled code */
{
  int l = 0;

  currcmd = cmd_root; /* start with first comand */
  if (print_docu) {
    /* don't execute program, just print docu */
    while (currcmd != cmd_head) {
      if (currcmd->type == cDOCU) {
        if (severity_threshold <= sDEBUG) {
          std_diag("executing", currcmd->type, currcmd->symname, currcmd->diag);
        }
        printf("%s\n", (char *)currcmd->pointer);
        l++;
        if (hold_docu && !(l % 24)) {
          printf("---Press RETURN to continue ");
          (void)!fgets(string, INBUFFLEN, stdin);
        }
      } else {
        if (severity_threshold <= sDEBUG) {
          std_diag("skipping", currcmd->type, currcmd->symname, currcmd->diag);
        }
      }
      currcmd = currcmd->next;
    }
    if (!l) {
      printf("---No embbeded documentation\n");
    }
    if (hold_docu) {
      printf("---End of embbedded documentation, press RETURN ");
      (void)!fgets(string, INBUFFLEN, stdin);
    }
  } else {
    while (currcmd != cmd_head && endreason == rNONE) {
      if (severity_threshold <= sDEBUG) {
        std_diag("executing", currcmd->type, currcmd->symname, currcmd->diag);
      }
      switch (currcmd->type) {
      case cGOTO:
      case cQGOTO:
      case cGOSUB:
      case cQGOSUB:
      case cCALL:
      case cQCALL:
        jump(currcmd);
        DONE;
      case cEXCEPTION:
        exception(currcmd);
        DONE;
      case cSKIPPER:
        skipper();
        break;
      case cSKIPONCE:
        skiponce(currcmd);
        DONE;
      case cRESETSKIPONCE:
        resetskiponce(currcmd, 1);
        DONE;
      case cRESETSKIPONCE2:
        resetskiponce(currcmd, 2);
        DONE;
      case cBREAK_MULTI:
        mybreak(currcmd);
        DONE;
      case cNEXT_CASE:
        next_case(currcmd);
        DONE;
      case cSWITCH_COMPARE:
        switch_compare();
        DONE;
      case cCONTINUE:
        mycontinue(currcmd);
        DONE;
      case cFINDNOP:
        findnop();
        DONE;
      case cFUNCTION_OR_ARRAY:
      case cSTRINGFUNCTION_OR_ARRAY:
        function_or_array(currcmd);
        break; /* NOT 'DONE' ! */
      case cLABEL:
      case cDATA:
      case cNOP:
      case cUSER_FUNCTION:
      case cLINK_SUBR:
      case cEND_FUNCTION:
      case cDOCU:
      case cBREAK_HERE:
      case cCONTINUE_HERE:
      case cNEXT_CASE_HERE:
      case cBEGIN_LOOP_MARK:
      case cEND_LOOP_MARK:
      case cBEGIN_SWITCH_MARK:
      case cEND_SWITCH_MARK:
        DONE;
      case cERROR:
        error_without_position(sERROR, pop(stSTRING)->pointer);
        DONE;
      case cCOMPILE:
        compile();
        DONE;
      case cEXECUTE:
      case cEXECUTE2:
        execute(currcmd);
        DONE;
      case cEVAL:
        eval(currcmd);
        DONE;
      case cRETURN_FROM_GOSUB:
      case cRETURN_FROM_CALL:
        myreturn(currcmd);
        DONE;
      case cCHECK_RETURN_VALUE:
        check_return_value(currcmd);
        DONE;
      case cPUSHDBLSYM:
        pushdblsym(currcmd);
        DONE;
      case cPUSHDBL:
        pushdbl(currcmd);
        DONE;
      case cPOPDBLSYM:
        popdblsym(currcmd);
        DONE;
      case cPOP:
        pop(stANY);
        DONE;
      case cPOP_MULTI:
        pop_multi(currcmd);
        DONE;
      case cPOPSTRSYM:
        popstrsym(currcmd);
        DONE;
      case cPUSHSTRSYM:
        pushstrsym(currcmd);
        DONE;
      case cPUSHSTR:
        pushstr(currcmd);
        DONE;
      case cCLEARSYMREFS:
        clear_symrefs(currcmd);
        DONE;
      case cPUSHSYMLIST:
        pushsymlist();
        DONE;
      case cPOPSYMLIST:
        popsymlist();
        DONE;
      case cREQUIRE:
        require(currcmd);
        DONE;
      case cMAKELOCAL:
        makelocal(currcmd);
        DONE;
      case cCOUNT_PARAMS:
        count_params(currcmd);
        DONE;
      case cMAKESTATIC:
        makestatic(currcmd);
        DONE;
      case cARRAYLINK:
        arraylink(currcmd);
        DONE;
      case cPUSHARRAYREF:
        pusharrayref(currcmd);
        DONE;
      case cTOKEN:
      case cTOKEN2:
      case cSPLIT:
      case cSPLIT2:
        token(currcmd);
        DONE;
      case cTOKENALT:
      case cTOKENALT2:
      case cSPLITALT:
      case cSPLITALT2:
        tokenalt(currcmd);
        DONE;
      case cARDIM:
      case cARSIZE:
        query_array(currcmd);
        DONE;
      case cPUSHFREE:
        push()->type = stFREE;
        DONE;
      case cCONCAT:
        concat();
        DONE;
      case cPRINT:
        print(currcmd);
        DONE;
      case cMOVE:
        mymove();
        DONE;
      case cCOLOUR:
        colour(currcmd);
        DONE;
      case cCLEARSCR:
        clearscreen();
        DONE;
      case cONESTRING:
        onestring(currcmd->pointer);
        DONE;
      case cTESTEOF:
        testeof(currcmd);
        DONE;
      case cOPEN:
        myopen(currcmd);
        DONE;
      case cCHECKOPEN:
      case cCHECKSEEK:
        checkopen();
        DONE;
      case cCLOSE:
        myclose();
        DONE;
      case cSEEK:
      case cSEEK2:
        myseek(currcmd);
        DONE;
      case cPUSHSTREAM:
        push_stream(currcmd);
        DONE;
      case cPOPSTREAM:
        pop_stream();
        DONE;
      case cCHKPROMPT:
        chkprompt();
        DONE;
      case cREAD:
        myread(currcmd);
        DONE;
      case cRESTORE:
      case cQRESTORE:
        restore(currcmd);
        DONE;
      case cREADDATA:
        readdata(currcmd);
        DONE;
      case cDBLADD:
      case cDBLMIN:
      case cDBLMUL:
      case cDBLDIV:
      case cDBLPOW:
        dblbin(currcmd);
        DONE;
      case cNEGATE:
        negate();
        DONE;
      case cEQ:
      case cNE:
      case cGT:
      case cGE:
      case cLT:
      case cLE:
        dblrelop(currcmd);
        DONE;
      case cSTREQ:
      case cSTRNE:
      case cSTRLT:
      case cSTRLE:
      case cSTRGT:
      case cSTRGE:
        strrelop(currcmd);
        DONE;
      case cAND:
      case cOR:
      case cNOT:
        boole(currcmd);
        DONE;
      case cFUNCTION:
        function(currcmd);
        DONE;
      case cGLOB:
        glob();
        DONE;
      case cDOARRAY:
        doarray(currcmd);
        DONE;
      case cCHANGESTRING:
        changestring(currcmd);
        DONE;
      case cPUSHSTRPTR:
        pushstrptr(currcmd);
        DONE;
      case cDIM:
        dim(currcmd);
        DONE;
      case cDECIDE:
        decide();
        DONE;
      case cANDSHORT:
      case cORSHORT:
        logical_shortcut(currcmd);
        DONE;
      case cOPENWIN:
        openwin(currcmd);
        DONE;
      case cMOVEORIGIN:
        moveorigin(NULL);
        DONE;
      case cOPENPRN:
        openprinter(currcmd);
        DONE;
      case cCLOSEPRN:
        closeprinter();
        DONE;
      case cDOT:
        dot(currcmd);
        DONE;
      case cPUTBIT:
        putbit();
        DONE;
      case cPUTCHAR:
        putchars();
        DONE;
      case cLINE:
        line(currcmd);
        DONE;
      case cGCOLOUR:
      case cGCOLOUR2:
      case cGBACKCOLOUR:
      case cGBACKCOLOUR2:
        change_colour(currcmd);
        DONE;
      case cCIRCLE:
        circle(currcmd);
        DONE;
      case cTRIANGLE:
        triangle(currcmd);
        DONE;
      case cTEXT1:
      case cTEXT2:
      case cTEXT3:
        text(currcmd);
        DONE;
      case cCLOSEWIN:
        closewin();
        DONE;
      case cCLEARWIN:
        clearwin();
        DONE;
      case cRECT:
        rect(currcmd);
        DONE;
      case cWAIT:
        mywait();
        DONE;
      case cBELL:
        mybell();
        DONE;
      case cPOKE:
        poke(currcmd);
        DONE;
      case cPOKEFILE:
        pokefile(currcmd);
        DONE;
      case cSWAP:
        swap();
        DONE;
      case cDUPLICATE:
        duplicate();
        DONE;
      case cFORCHECK:
        forcheck();
        DONE;
      case cFORINCREMENT:
        forincrement();
        DONE;
      case cSTARTFOR:
        startfor();
        DONE;
      case cBIND:
        mybind(pop(stSTRING)->pointer);
        DONE;
      case cFRNBF_SET_NUMBER:
        frnbf_set();
        DONE;
      case cFRNBF_SET_STRING:
        frnbf_set2();
        DONE;
      case cFRNBF_SET_BUFFER:
        frnbf_set_buffer();
        DONE;
      case cFRNBF_FREE:
        frnbf_free();
        DONE;
      case cEND:
        endreason = rEOF;
        break;
      case cEXIT:
        exitcode = (int)pop(stNUMBER)->value;
        endreason = rREQUEST;
        break;
      default:
        sprintf(string, "Command %s (%d, right before '%s') not implemented",
                cexplanation[currcmd->type], currcmd->type,
                cexplanation[currcmd->type + 1]);
        error(sERROR, string);
      }
    }
  }
  set_program_state(spFINISHED);
  switch (severity_so_far) {
  case sNOTE:
  case sDEBUG:
    error(sNOTE, "Program ended normally.");
    break;
  case sWARNING:
    error(sWARNING, "Program ended with a warning");
    break;
  case sERROR:
    error(sERROR, "Program stopped due to an error");
    break;
  case sFATAL: /* should not come here ... */
    error(sFATAL, "Program terminated due to FATAL error");
    break;
  }
}

void error(int severity, char *message)
/* reports an error to the user and possibly exits */
{
  if (program_state == spCOMPILING) {
    error_with_position(severity, message, currlib->long_name,
                        effective_lineno(), yylloc.first_column,
                        yylloc.last_column);
  } else if (program_state == spRUNNING && currcmd->line > 0) {
    error_with_position(severity, message, currcmd->lib->long_name,
                        currcmd->line, currcmd->first_column,
                        currcmd->last_column);
  } else {
    error_without_position(severity, message);
  }
}

void error_with_position(int severity, char *message, char *filename,
                         int lineno, int first_column, int last_column)
/* reports a yabasic-error to the user and possibly exits */
{
  char *severity_text;
  static int printed_lineno = -1;
  static char *printed_filename = NULL;
  static int sub_dumped = FALSE;

  if (severity >= severity_threshold) {
#ifdef UNIX
    if (severity >= sERROR) {
      con_xcap_deinit();
    }
#endif
    switch (severity) {
    case sINFO:
      severity_text = "---Info";
      break;
    case sDUMP:
      severity_text = "---Dump";
      break;
    case sDEBUG:
      severity_text = "---Debug";
      debug_count++;
      break;
    case sNOTE:
      severity_text = "---Note";
      note_count++;
      break;
    case sWARNING:
      severity_text = "---Warning";
      warning_count++;
      break;
    case sERROR:
      severity_text = "---Error";
      error_count++;
      break;
    case sFATAL:
      severity_text = "---Fatal";
      break;
    }
    if (filename &&
        (printed_filename != filename || printed_lineno != lineno)) {
      fprintf(stderr, "%s in %s, line %d:\n", severity_text, filename, lineno);
      printed_filename = filename;
      printed_lineno = lineno;
    }
    fprintf(stderr, "%s: %s\n", severity_text, message);
    if (filename && severity == sERROR) {
      show_and_mark_line(filename, lineno, first_column, last_column);
    }
    if (severity >= sERROR && !sub_dumped && program_state > spINITIALIZED) {
      dump_sub(1);
      sub_dumped = TRUE;
    }
  }
  if (severity > severity_so_far)
    severity_so_far = severity;
  if (severity >= sERROR) {
    endreason = rERROR;
    exitcode = 1;
  }
  if (severity >= sFATAL) {
    set_program_state(spFINISHED);
    fprintf(stderr, "---Immediate exit to system, due to a fatal error.\n");
    end_it();
  }
}

void show_and_mark_line(
    char *filename, int lineno, int first_column,
    int last_column) /* try to find and show offending line */
{
  FILE *file;
  char linebuffer[INBUFFLEN];
  int i;

  if (is_bound) {
    return;
  }

  file = fopen(filename, "r");
  if (!file) {
    return;
  }

  linebuffer[0] = '\0';
  while (lineno && fgets(linebuffer, INBUFFLEN, file)) {
    lineno--;
  }
  fclose(file);

  if (linebuffer[0] && lineno == 0) {
    linebuffer[strcspn(linebuffer, "\n")] = '\0';
    fprintf(stderr, "   ");
    fprintf(stderr, "%s", linebuffer);
    fprintf(stderr, "\n   ");
    for (i = 1; i <= last_column; i++) {
      fputc((i < first_column) ? ' ' : ((i == first_column) ? '^' : '~'),
            stderr);
    }
    fprintf(stderr, "\n");
  }
}

void error_without_position(int severity, char *message)
/* like error_with_position but without position */
{
  error_with_position(severity, message, NULL, 0, 0, 0);
}

char *my_strndup(char *arg, int len) /* own version of strndup */
{
  char *copy;

  copy = my_malloc(len + 1);

  strncpy(copy, arg, len);
  copy[len] = '\0';

  return copy;
}

char *my_strdup(char *arg) /* my own version of strdup, checks for failure */
{
  int l;

  if (!arg) {
    return my_strndup("", 0);
  }
  l = strlen(arg);
  return my_strndup(arg, l);
}

void *my_malloc(unsigned num) /* Alloc memory and issue warning on failure */
{
  void *room;

  if (num > INT_MAX - sizeof(int)) {
    error(sFATAL, "memory allocation too large (overflow)");
  }

  room = malloc(num + sizeof(int));
  if (room == NULL) {
    sprintf(string, "Can't malloc %d bytes of memory (no memory available)",
            num);
    error(sFATAL, string);
  }
  return room;
}

void my_free(void *mem) /* free memory */
{
  free(mem);
}

struct library *
new_library(char *long_name,
            char *short_name) /* create a new structure for library */
{
  struct library *new;
  struct library *curr;
  static struct library *last = NULL;
  int start, end;

  /* check, if library has already been imported */
  for (curr = library_chain[0]; curr; curr = curr->next_lib) {
    if (!strcmp(curr->long_name, long_name) &&
        currlib->imported_from != curr->imported_from) {
      if (is_bound) {
        return curr;
      } else {
        return NULL;
      }
    }
  }

  new = my_malloc(sizeof(struct library));
  new->next_lib = NULL;
  if (last) {
    last->next_lib = new;
  }
  last = new;

  new->long_name = my_strdup(long_name);
  new->long_len = strlen(new->long_name);
  new->yylineno_at_start = yylineno;

  if (short_name) {
    new->short_name = my_strdup(short_name);
  } else {
    /* no short name supplied; get piece from long_name */
    end = strlen(long_name);
    for (start = end; start > 0; start--) {
      if (long_name[start - 1] == '\\' || long_name[start - 1] == '/') {
        break;
      }
      if (long_name[start] == '.') {
        end = start;
      }
    }
    end--;
    new->short_name = my_malloc(end - start + 2);
    strncpy(new->short_name, new->long_name + start, end - start + 1);
    new->short_name[end - start + 1] = '\0';
  }
  new->short_len = strlen(new->short_name);
  new->datapointer = new->firstdata = NULL;

  return new;
}

char *dotify(char *name,
             int addfun) /* add library name, if not already present */
{
  static char buff[NAMEBUFFLEN];
  if (!strchr(name, '.')) {
    strncpy(buff, currlib->short_name, NAMEBUFFLEN);
    strncat(buff, ".", NAMEBUFFLEN - 1 - strlen(buff));
    strncat(buff, name, NAMEBUFFLEN - 1 - strlen(buff));
  } else {
    strncpy(buff, name, NAMEBUFFLEN);
  }
  if (addfun && !strchr(name, '@')) {
    strncat(buff, "@", NAMEBUFFLEN - 1 - strlen(buff));
    strncat(buff, current_function, NAMEBUFFLEN - 1 - strlen(buff));
  }
  return buff;
}

char *strip(char *name) /* strip down to minimal name */
{
  static char buff[NAMEBUFFLEN];
  char *at, *dot;

  if (severity_threshold <= sDEBUG) {
    return name;
  }
  dot = strchr(name, '.');
  if (dot) {
    strncpy(buff, dot + 1, NAMEBUFFLEN);
  } else {
    strncpy(buff, name, NAMEBUFFLEN);
  }
  at = strchr(buff, '@');
  if (at) {
    *at = '\0';
  }

  return buff;
}

void compile() /* create subroutine at runtime */
{
  char *compile_text = my_strdup(pop(stSTRING)->pointer);
  struct library *currlib_saved;

  currlib_saved = currlib;
  currlib = currcmd->lib;
  start_flex_from_string(compile_text);

  if (severity_threshold <= sDEBUG) {
    sprintf(string, "Compiling string as subroutine definition: '%s'",
            compile_text);
    error(sDEBUG, string);
  }
  start_token = tSTART_FUNCTION_DEFINITION;
  if (yyparse() && severity_so_far >= sERROR) {
    sprintf(string, "Couldn't parse string as definition of subroutine: '%s'",
            compile_text);
    error_without_position(sERROR, string);
  }
  end_flex_from_string();
  free(compile_text);
  currlib = currlib_saved;
}

void create_execute(int string) /* create command 'cEXECUTESUB' */
{
  struct command *cmd;

  cmd = add_command(string ? cEXECUTE2 : cEXECUTE);
  cmd->pointer = my_strdup(dotify("", FALSE));
}

void execute(struct command *cmd) /* execute a subroutine */
{
  struct stackentry *st, *ret;
  char *fullname, *shortname;
  struct command *newcurr;

  st = stackhead;
  do {
    st = st->prev;
  } while (st->type != stFREE);
  st = st->next;
  if (st->type != stSTRING) {
    error(sERROR, "need a string as a function name");
    return;
  }
  shortname = st->pointer;
  if ((shortname[strlen(shortname) - 1] == '$') != (cmd->type == cEXECUTE2)) {
    if (cmd->type == cEXECUTE2)
      sprintf(string, "expecting the name of a string function (not '%s')",
              shortname);
    else
      sprintf(string, "expecting the name of a numeric function (not '%s')",
              shortname);
    error(sERROR, string);
    return;
  }
  fullname = my_malloc(strlen(cmd->pointer) + strlen(shortname) + 2);
  strcpy(fullname, cmd->pointer);
  strcat(fullname, shortname);
  free(st->pointer);
  st->type = stFREE;
  newcurr = search_label(fullname, srmSUBR);
  if (!newcurr) {
    sprintf(string, "subroutine '%s' not defined", fullname);
    error(sERROR, string);
    return;
  }
  ret = push();
  ret->pointer = currcmd;
  ret->type = stRET_ADDR_CALL;
  reorder_stack_before_call(ret);
  currcmd = newcurr;
  free(fullname);
}

void create_eval(int type) /* create command 'eval' */
/* type can be 0 (number), 1 (string) or 2 (assignment) */
{
  struct command *cmd;

  cmd = add_command(cEVAL);
  cmd->args = type;
}

void eval(
    struct command *cmd) /* do the work for eval functions and command eval */
{
  struct command *eval_seek = cmd->jump;
  struct command *eval_seek_before = cmd;
  struct command *eval_exec;
  struct library *currlib_saved;
  char *eval_text = my_strdup(pop(stSTRING)->pointer);
  struct stackentry *ret_val;
  struct stackentry *ret_addr;
  const int start_tokens[] = {0, tSTART_EXPRESSION, tSTART_STRING_EXPRESSION};
  const char *description[] = {"", "numeric expression", "string expression"};
  int eval_type = cmd->args;

  /* remember return address */
  ret_addr = push();
  ret_addr->pointer = cmd;
  ret_addr->type = stRET_ADDR;

  /* try to find text of current eval in associated list of previous evals */
  while (eval_seek && strcmp(eval_text, (char *)eval_seek->pointer)) {
    if (severity_threshold <= sDEBUG) {
      sprintf(string,
              "Seeking current eval; this prior eval does not match: %s",
              (char *)eval_seek->pointer);
      error(sDEBUG, string);
    }
    eval_seek_before = eval_seek;
    eval_seek = eval_seek->jump;
  }
  if (eval_seek) {
    /* eval text has been found and need not be compiled again */
    eval_exec = eval_seek;
    if (severity_threshold <= sDEBUG) {
      sprintf(string, "String for %s has already been compiled before",
              description[eval_type]);
      error(sDEBUG, string);
    }
  } else {
    /* eval text has not been found and needs to be compiled before execution */
    eval_exec = add_command_with_sym_and_diag(cEVAL_CODE, NULL, eval_text);
    eval_seek_before->jump = eval_exec;
    eval_exec->pointer = my_strdup(eval_text);
    start_flex_from_string(eval_text);
    start_token = start_tokens[eval_type];
    if (severity_threshold <= sDEBUG) {
      sprintf(string, "Compiling string as %s", description[eval_type]);
      error(sDEBUG, string);
    }

    add_command(cCLEARSYMREFS);
    start_symref_chain();
    currlib_saved = currlib;
    currlib = currcmd->lib;
    if (yyparse() && severity_so_far >= sERROR) {
      sprintf(string, "Couldn't parse string as %s: '%s'",
              description[eval_type], eval_text);
      error_without_position(sERROR, string);
      ret_val = push();
      if (eval_type == evSTRING) {
        ret_val->type = stSTRING;
        ret_val->pointer = my_strdup("");
      } else {
        ret_val->type = stNUMBER;
        ret_val->value = 0.0;
      }
      return;
    }
    end_flex_from_string();
    free(eval_text);
    currlib = currlib_saved;
    add_command(cSWAP);
    add_command(cCLEARSYMREFS);
    end_symref_chain();
    add_command(cRETURN_FROM_GOSUB);
  }
  /* jump to eval */
  currcmd = eval_exec;
}

void create_docu(char *doc) /* create command 'docu' */
{
  struct command *cmd;
  static struct command *previous = NULL;

  if (inlib) {
    return;
  }
  cmd = add_command(cDOCU);
  cmd->pointer = doc;
  if (previous) {
    previous->next_assoc = cmd;
  } else {
    docuhead = cmd;
  }
  previous = cmd;
  docucount++;
}

void create_docu_array(void) /* create array with documentation */
{
  struct array *ar;
  struct command *doc;
  int i;

  /* create and prepare docu-array */
  ar = create_array('s', 1);
  ar->bounds[0] = docucount + 1;
  ar->pointer = my_malloc((docucount + 1) * sizeof(char *));
  ((char **)ar->pointer)[0] = my_strdup("");
  doc = docuhead;
  i = 1;
  while (doc) {
    ((char **)ar->pointer)[i] = doc->pointer;
    doc = doc->next_assoc;
    i++;
  }
  get_sym("main.docu$", syARRAY, amADD_GLOBAL)->pointer = ar;
}

int isbound(void) /* check if this interpreter is bound to a program */
{
  FILE *inter;
  int i;
  int c;
  int proglen = 0;
  int namelen = 0;
  int bound = 1;
  char *infolevel_text;
  int remlen = strlen("\nrem "); /* different under windows and unix */
  int offset = 0;

  if (!inter_path || !inter_path[0]) {
    error(sINFO, "inter_path is not set !");
    return 0;
  }
  if (!(inter = fopen(inter_path, "r"))) {
    sprintf(string, "Couldn't open '%s' to check, if it is bound: %s",
            inter_path, my_strerror(errno));
    error(sINFO, string);
    return 0;
  }

  /* Read fields from end of program as written in mybind() */

  /* check magic cookie */
  offset -= 1 + strlen(YABMAGIC);
  if (!seekback(inter, offset, FALSE))
    return 0;
  for (i = 0; i < (int)strlen(YABMAGIC); i++) {
    c = fgetc(inter);
    if (c == EOF || c != (YABMAGIC)[i]) {
      bound = 0;
    }
  }
  if (!bound) {
    fclose(inter);
    return bound;
  }

  /* infolevel */
  offset -= remlen + 2;
  if (!seekback(inter, offset, TRUE))
    return 0;
  if (!fscanf(inter, "%d", &severity_threshold)) {
    error(sWARNING, "Could not read infolevel");
    return 0;
  }
  /* repeat just for its output side-effect */
  if (!seekback(inter, offset, TRUE))
    return 0;
  switch (severity_threshold) {
  case sFATAL:
    infolevel_text = "FATAL";
    break;
  case sERROR:
    infolevel_text = "ERROR";
    break;
  case sINFO:
    infolevel_text = "INFO";
    break;
  case sDUMP:
    infolevel_text = "DUMP";
    break;
  case sWARNING:
    infolevel_text = "WARNING";
    break;
  case sNOTE:
    infolevel_text = "NOTE";
    break;
  case sDEBUG:
    infolevel_text = "DEBUG";
    break;
  case sDEBUG - 1:
    infolevel_text = "DEBUG+BISON";
    yydebug = 1;
    severity_threshold = sDEBUG;
    break;
  };
  sprintf(estring, "Set infolevel to %s", infolevel_text);
  error(sDEBUG, estring);

  /* length of name of embedded program */
  offset -= remlen + 8;
  if (!seekback(inter, offset, TRUE))
    return 0;
  if (!fscanf(inter, "%d", &namelen)) {
    error(sWARNING, "Could not read length of name of embedded program");
    return 0;
  }
  sprintf(estring, "Length of name of embedded program is %d", namelen);
  error(sDEBUG, estring);

  /* name of embedded program */
  offset -= remlen + namelen;
  if (!seekback(inter, offset, TRUE))
    return 0;
  progname = (char *)my_malloc(sizeof(char) * (namelen + 1));
  if (!fgets(progname, namelen + 1, inter)) {
    error(sWARNING, "Could not read name of embedded program");
    return 0;
  }
  sprintf(estring, "Name of embedded program is '%s'", progname);
  error(sDEBUG, estring);

  /* length of program */
  offset -= remlen + 8;
  if (!seekback(inter, offset, TRUE))
    return 0;
  if (!fscanf(inter, "%d", &proglen)) {
    error(sWARNING, "Could not read length of embedded program");
    return 0;
  }
  sprintf(estring, "Length of embedded program is %d", proglen);
  error(sDEBUG, estring);

  /* seek back to start of embedded program */
  offset -= 4 + proglen; /* only the text 'rem ' without preceding linefeed */
  if (!seekback(inter, offset, TRUE))
    return 0;

  if (severity_threshold <= sNOTE) {
    error(sNOTE, "Dumping the embedded program, that will be executed:");
    fprintf(stderr, "     ");
    for (i = 0; i < proglen; i++) {
      c = fgetc(inter);
      if (isprint(c) || c == '\r' || c == '\n')
        fprintf(stderr, "%c", c);
      if (c == '\n' && i < proglen - 1) {
        fprintf(stderr, "     ");
      }
    }
    fprintf(stderr, "\n");
    error(sNOTE, "End of program, that will be executed");
    if (!seekback(inter, offset, TRUE))
      return 0;
  }
  bound_program = inter;
  return 1;
}

static int seekback(FILE *file, int offset,
                    int cookie_found) /* seek back bytes */
{
  if (fseek(file, offset, SEEK_END)) {
    sprintf(estring, "Couldn't seek within '%s': %s", inter_path,
            my_strerror(errno));
    error(sWARNING, estring);
    return FALSE;
  }
  if (!fgets(string, INBUFFLEN, file)) {
    error(cookie_found ? sWARNING : sDEBUG,
          "Could not read from end of embedded program");
    return FALSE;
  }
  string[(strlen(string) || 1) - 1] = '\0';
  if (cookie_found && severity_threshold <= sDEBUG) {
    sprintf(estring,
            "Next line from end of embbeded program to be processed is: '%s'",
            string);
    error(sDEBUG, estring);
  }
  if (fseek(file, offset, SEEK_END)) {
    sprintf(estring, "Couldn't seek within '%s': %s", inter_path,
            my_strerror(errno));
    error(sWARNING, estring);
    return FALSE;
  }

  return TRUE;
}

static int
mybind(char *bound) /* bind a program to the interpreter and save it */
{
  FILE *fyab;
  FILE *fprog;
  FILE *fbound;
  FILE *flib;
  int c;
  int i;
  int proglen = 0;

  if (interactive) {
    error(sERROR, "cannot bind a program when called interactively");
    return 0;
  }

  if (!strcmp(inter_path, bound)) {
    sprintf(string, "will not overwrite '%s' with '%s'", bound, inter_path);
    error(sERROR, string);
    return 0;
  }
  if (!strcmp(main_file_name, bound)) {
    sprintf(string, "will not overwrite '%s' with '%s'", bound, main_file_name);
    error(sERROR, string);
    return 0;
  }

  if (!(fyab = fopen(inter_path, "rb"))) {
    sprintf(string, "could not open '%s' for reading: %s", inter_path,
            my_strerror(errno));
    error(sERROR, string);
    return 0;
  }
  if (!(fprog = fopen(main_file_name, "rb"))) {
    sprintf(string, "could not open '%s' for reading: %s", main_file_name,
            my_strerror(errno));
    error(sERROR, string);
    fclose(fyab);
    return 0;
  }
  if (!(fbound = fopen(bound, "wb"))) {
    sprintf(string, "could not open '%s' for writing: %s", bound,
            my_strerror(errno));
    error(sERROR, string);
    fclose(fyab);
    fclose(fprog);
    return 0;
  }

  if (severity_threshold <= sDEBUG) {
    sprintf(string, "binding %s and %s into %s", inter_path, main_file_name,
            bound);
    error(sNOTE, string);
  }

  while ((c = fgetc(fyab)) != EOF) {
    fputc(c, fbound);
  }
  for (i = 1; i < library_chain_length; i++) {
    if (!(flib = fopen(library_chain[i]->long_name, "rb"))) {
      sprintf(string, "could not open '%s' for reading: %s",
              library_chain[i]->long_name, my_strerror(errno));
      error(sERROR, string);
      return 0;
    }
    sprintf(string, "\nimport %s\n", library_chain[i]->short_name);
    put_and_count(string, fbound, &proglen);

    put_and_count("\nimport __IGNORE_NESTED_IMPORTS\n", fbound, &proglen);
    while ((c = fgetc(flib)) != EOF) {
      fputc(c, fbound);
      proglen++;
    }

    put_and_count("\nimport __END_OF_CURRENT_IMPORT\n", fbound, &proglen);
  }

  put_and_count("\nimport __END_OF_ALL_IMPORTS\n", fbound, &proglen);
  put_and_count("\nimport main\n", fbound, &proglen);
  while ((c = fgetc(fprog)) != EOF) {
    fputc(c, fbound);
    proglen++;
  }
  fprintf(fbound, "\nend\n");
  proglen += 5;
  fprintf(fbound, "rem %08d\n", proglen);
  fprintf(fbound, "rem %s\n", progname);
  fprintf(fbound, "rem %08lu\n", strlen(progname));
  fprintf(fbound, "rem %02d\n", severity_threshold + yydebug);
  fprintf(fbound, "rem %s\n", YABMAGIC);
  fclose(fyab);
  fclose(fprog);
  fclose(fbound);

  return 1;
}

void put_and_count(char *text, FILE *file,
                   int *len) /* write text to file and increment len */
{
  for (; *text; text++) {
    fputc(*text, file);
    (*len)++;
  }
}

char *find_interpreter(char *name) /* find interpreter with full path, use code
                                      from Gregory Pakosz */
{
  char *path = NULL;
  int length, dirname_length;

  length = wai_getExecutablePath(NULL, 0, NULL);
  if (length <= 0)
    return my_strdup(name);
  path = (char *)malloc(length + 1);
  wai_getExecutablePath(path, length, &dirname_length);
  path[length] = '\0';

  return path;
}

char *my_strerror(int err) {
  /* return description of error */
#ifdef WINDOWS
  return strerror(err);
#else
#ifdef HAVE_STRERROR
  return strerror(err);
#else
  char buff[100];
  sprintf(buff, "errno=%d", err);
  return buff;
#endif
#endif
}
