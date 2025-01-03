/*

    YABASIC  ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2025
    more info at www.yabasic.de

    io.c -- code for screen and file i/o

    This file is part of yabasic and may be copied under the terms of
    MIT License which can be found in the file LICENSE.

*/

/* ------------- includes ---------------- */

#ifndef YABASIC_INCLUDED
#include "yabasic.h" /* all prototypes and structures */
#endif

/* ------------- local defines ----------------- */

#define YC_BLACK 0
#define YC_WHITE 1
#define YC_RED 2
#define YC_BLUE 3
#define YC_GREEN 4
#define YC_YELLOW 5
#define YC_CYAN 6
#define YC_MAGENTA 7

#ifndef COLOR_BLACK
#define COLOR_BLACK 0
#define COLOR_RED 1
#define COLOR_GREEN 2
#define COLOR_YELLOW 3
#define COLOR_BLUE 4
#define COLOR_MAGENTA 5
#define COLOR_CYAN 6
#define COLOR_WHITE 7
#endif
#ifndef A_COLOR
#define A_COLOR 0xff00
#endif

/* ------------- external references ---------------- */

extern int mylineno;  /* current line number */
extern int yyparse(); /* call bison parser */

/* ------------- local functions ---------------- */

static int onechar(void);   /* read one char from currentinstream */
static void backchar(int);  /* put char back into stream */
static void readline(void); /* read one line from current stream */
static void curinit(void);  /* initialize curses */
static void initcol(void);  /* initialize curses colors */
int checkstream(void);      /* test if currst is still valid */
#ifdef WINDOWS
static DWORD keythread(LPWORD);          /* wait for key input from console */
static int is_valid_key(INPUT_RECORD *); /* check if input rec is valid key */
static void decode_key(int, char *);     /* decode keycode into string */
#endif
int name2yc(char *); /* convert a color name to an integer */
int yc2oc(int, int); /* convert a yabasic color to operating system color */
char *yc2short(int); /* convert yabasic colours to short colour name */
int oc2yc(int);      /* convert an operating system color to yabasic color */

/* ------------- global variables ---------------- */

static int prompted;               /* TRUE, if prompt is fresh */
FILE *streams[FOPEN_MAX];          /* file streams */
int stream_modes[FOPEN_MAX];       /* modes for streams */
int lprstream = -1;                /* stream associated with lineprinter */
static int currstr = STDIO_STREAM; /* currently switched stream */
static FILE *cinstr;               /* current stream for input */
static FILE *coutstr;              /* current stream for output */
static char linebuffer[INBUFFLEN]; /* buffer for one line of input */
int curinized = FALSE;             /* true, if curses has been initialized */
static char *currchar;             /* current char to read */
#ifdef UNIX
FILE *lineprinter = NULL; /* handle for line printer */
#else
static short stdfc; /* standard foreground color of window */
static short stdbc; /* standard background color of window */
HANDLE gotwinkey = INVALID_HANDLE_VALUE;   /* mutex to signal key reception */
char conkeybuff[100];                      /* Key received from console */
char winkeybuff[100];                      /* Key received from window */
HANDLE wthandle = INVALID_HANDLE_VALUE;    /* handle of win thread */
DWORD ktid;                                /* id of inkey thread */
int LINES = 0;                             /* number of lines on screen */
int COLS = 0;                              /* number of columns on screen */
HANDLE ConsoleInput;                       /* handle for console input */
HANDLE ConsoleOutput;                      /* handle for console output */
HANDLE lineprinter = INVALID_HANDLE_VALUE; /* handle for line printer */
#endif

/* ------------- functions ---------------- */

void create_print(char type) /* create command 'print' */
{
  struct command *cmd;

  cmd = add_command(cPRINT);
  cmd->pointer = my_malloc(sizeof(int));
  /* store type of print  */
  cmd->tag = type;
}

void print(struct command *cmd) /* print on screen */
{
  int type;
  struct stackentry *p, *q, *r;
  static int last = 'n';
  char *s;
  long int n;
  double d;
#ifdef UNIX
  int x, y;
#endif

  r = NULL;
  type = cmd->tag;
  if (!checkstream()) {
    return;
  }
  switch (type) {
  case 'n': /* print newline */
    if (curinized && coutstr == stdout) {
#ifdef WINDOWS
      onestring("\r\n");
      break;
#else
      getyx(stdscr, y, x);
      if (y >= LINES - 1) {
        scrl(1);
        y = y - 1;
      }
      move(y + 1, 0);
      refresh();
      break;
#endif
    } else {
      string[0] = '\n';
      if (abs(currstr) == lprstream) {
        string[1] = '\r';
        string[2] = '\0';
      } else {
        string[1] = '\0';
      }
    }
    onestring(string);
    break;
  case 't': /* print tab */
    string[0] = '\t';
    string[1] = '\0';
    onestring(string);
    break;
  case 'd': /* print double value */
    p = pop(stNUMBER);
    d = p->value;
    n = (int)d;
    if (n == d && d <= LONG_MAX && d >= LONG_MIN) {
      sprintf(string, "%s%ld", (last == 'd') ? " " : "", n);
    } else {
      sprintf(string, "%s%g", (last == 'd') ? " " : "", d);
    }
    onestring(string);
    break;
  case 'U':
    r = pop(stSTRING);
  case 'u': /* print using */
    p = pop(stSTRING);
    q = pop(stNUMBER);
    type = 'd';
    s = string;
    if (last == 'd') {
      *s = ' ';
      s++;
    }
    if (!myformat(s, INBUFFLEN, q->value, p->pointer, r ? r->pointer : NULL)) {
      break;
    }
    onestring(string);
    break;
  case 's':
    p = pop(stSTRING);
    onestring((char *)p->pointer);
    break;
  }
  last = type;
}

void mymove() /* move to specific position on screen */
{
  int x, y;
#ifdef WINDOWS
  COORD coord;
#endif

  y = (int)pop(stNUMBER)->value;
  if (y < 0) {
    y = 0;
  }
  if (y > LINES - 1) {
    y = LINES - 1;
  }
  x = (int)pop(stNUMBER)->value;
  if (x < 0) {
    x = 0;
  }
  if (x > COLS - 1) {
    x = COLS - 1;
  }
  if (!curinized) {
    error(sERROR, "need to call 'clear screen' first");
    return;
  }
#ifdef UNIX
  move(y, x);
  refresh();
#else
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(ConsoleOutput, coord);
#endif
}

void clearscreen() /* clear entire screen */
{
#ifdef WINDOWS
  DWORD written; /* number of chars actually written */
  COORD coord;   /* coordinates to start writing */
#endif
  if (!curinized) {
    curinit();
  }
#ifdef UNIX
  clear();
  refresh();
#else
  coord.X = 0;
  coord.Y = 0;
  FillConsoleOutputCharacter(ConsoleOutput, ' ', LINES * COLS, coord, &written);
  FillConsoleOutputAttribute(
      ConsoleOutput, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
      LINES * COLS, coord, &written);
  SetConsoleCursorPosition(ConsoleOutput, coord);
#endif
}

static void curinit(void) /* initialize curses */
{
#ifdef WINDOWS
  CONSOLE_SCREEN_BUFFER_INFO coninfo; /* receives console size */
#endif

#ifdef UNIX
  if (tcsetpgrp(STDIN_FILENO, getpgid(getpid()))) {
    sprintf(string, "could not get control of terminal: %s",
            my_strerror(errno));
    error(sERROR, string);
    return;
  };
  if (!initscr()) {
    error(sERROR, "could not initialize curses");
    return;
  };
  initcol();
  setscrreg(0, LINES);
  scrollok(stdscr, TRUE);
  leaveok(stdscr, TRUE);
  keypad(stdscr, TRUE);
  notimeout(stdscr, FALSE); /* wait after escape for escape-sequence */
  set_escdelay(10);
  curs_set(0);
  intrflush(stdscr, FALSE);
  if (con_fore_inten == cciBRIGHT) {
    attron(A_BOLD);
  }
#else
  GetConsoleScreenBufferInfo(ConsoleOutput, &coninfo);
  COLS = coninfo.srWindow.Right + 1;
  LINES = coninfo.srWindow.Bottom + 1;
  initcol();
#endif
  curinized = TRUE;
}

char *inkey(double maxtime) /* get char from keyboard */
{
  char retkey[100];
  long int max, now, start, left;
#ifdef WINDOWS
  DWORD initial;
  DWORD oflags;      /* saves normal state of console input buffer */
  DWORD flags;       /* new input mode for console input buffer */
  HANDLE evn[2];     /* events to wait for */
  DWORD wait_result; /* return value of wait operation */
  INPUT_RECORD inrec;
  DWORD num;
#else
  fd_set readfds;
  struct timeval tv;
  int maxfd;
  int winfd, termfd;
  int status, ret;
  int pending;
  static int cnt = 0;
#endif

  if (maxtime >= 0.0 && maxtime < 0.01) {
    maxtime = 0.01;
  }
  if (!curinized) {
    error(sERROR, "need to call 'clear screen' first");
    return my_strdup("");
  }

  retkey[0] = '\0';
  left = max = (long int)(maxtime * 1000000);

  /* Initialization */
#ifdef UNIX

  /* events */
  winfd = (winopened && display) ? ConnectionNumber(display) : 0;
  termfd = fileno(stdin);
  maxfd = (termfd > winfd) ? termfd : winfd;

  /* timing */
  gettimeofday(&tv, NULL);
  start = tv.tv_sec * 1000000 + tv.tv_usec;

  /* terminal */
  noecho();
  cbreak();
  refresh();

#elif WINDOWS

  /* events */
  if (gotwinkey == INVALID_HANDLE_VALUE) {
    gotwinkey = CreateEvent(NULL, FALSE, FALSE, NULL);
  }

  /* timing */
  initial = GetTickCount();
  start = 1000 * (GetTickCount() - initial);

  GetConsoleMode(ConsoleInput, &oflags);
  flags = oflags & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
  SetConsoleMode(ConsoleInput, flags);

  /* terminal */
  evn[0] = gotwinkey;
  evn[1] = ConsoleInput;

#endif

  while (((max >= 0 && left > 0) || max < 0) && !retkey[0]) {

    /* already got key ? */
#ifdef UNIX
    if (winopened && display && XPending(display)) {
      getwinkey(retkey);
      if (retkey[0]) {
        break;
      }
    }

    /* prepare to wait for key */
    FD_ZERO(&readfds);
    if (winfd) {
      FD_SET(winfd, &readfds);
    }
    FD_SET(termfd, &readfds);
#elif WINDOWS
    if (*winkeybuff) {
      strcpy(retkey, winkeybuff);
      winkeybuff[0] = '\0';
      return my_strdup(retkey);
    }
    conkeybuff[0] = winkeybuff[0] = '\0';
#endif

    /* wait for key */
    if (max >= 0) {
#ifdef UNIX
      tv.tv_sec = left / 1000000;
      tv.tv_usec = left % 1000000;
      ret = select(maxfd + 1, &readfds, NULL, NULL, &tv);
#elif WINDOWS
      wait_result = WaitForMultipleObjects(2, evn, FALSE, (DWORD)(left / 1000));
#endif
    } else {
#ifdef UNIX
      ret = select(maxfd + 1, &readfds, NULL, NULL, NULL);
#elif WINDOWS
      wait_result = WaitForMultipleObjects(2, evn, FALSE, INFINITE);
#endif
    }

    /* report result */
#ifdef UNIX
    if (ret == -1) {
      error(sERROR, "waiting for input failed");
      break;
    }
#elif WINDOWS
    if (wait_result == WAIT_FAILED) {
      error(sERROR, "waiting for input failed");
      break;
    }

#endif

    /* collect key */
#ifdef UNIX
    if (FD_ISSET(termfd, &readfds)) {
      gettermkey(retkey);
    } else if (FD_ISSET(winfd, &readfds)) {
      getwinkey(retkey);
    }
#elif WINDOWS
    if (wait_result == WAIT_OBJECT_0 + 1) {
      do {
        ReadConsoleInput(ConsoleInput, &inrec, 1, &num);
        GetNumberOfConsoleInputEvents(ConsoleInput, &num);
      } while (!is_valid_key(&inrec) && num > 0);
      conkeybuff[0] = '\0';
      if (is_valid_key(&inrec)) {
        if (isprint(inrec.Event.KeyEvent.uChar.AsciiChar)) {
          conkeybuff[0] = inrec.Event.KeyEvent.uChar.AsciiChar;
          conkeybuff[1] = '\0';
        } else {
          if (inrec.Event.KeyEvent.wVirtualKeyCode) {
            decode_key(inrec.Event.KeyEvent.wVirtualKeyCode, conkeybuff);
          }
        }
      }
    } else if (wait_result == WAIT_OBJECT_0) {
      /* key is already stored in winkeybuff */
    }

    if (*winkeybuff) {
      strcpy(retkey, winkeybuff);
    } else {
      strcpy(retkey, conkeybuff);
    }
    conkeybuff[0] = winkeybuff[0] = '\0';
#endif

    /* adjust timing */
#ifdef UNIX
    gettimeofday(&tv, NULL);
    now = tv.tv_sec * 1000000 + tv.tv_usec;
#elif WINDOWS
    now = 1000 * (GetTickCount() - initial);
#endif
    left = max - now + start;
  }

  /* restore terminal state */
#ifdef UNIX
  echo();
  nocbreak();
  refresh();
#elif WINDOWS
  SetConsoleMode(ConsoleInput, oflags);
#endif

  return my_strdup(retkey);
}

#ifdef WINDOWS
static int
is_valid_key(INPUT_RECORD *rec) /* check if input rec contains valid key */
{
  if (rec->EventType != KEY_EVENT || !rec->Event.KeyEvent.bKeyDown ||
      rec->Event.KeyEvent.wVirtualKeyCode == VK_SHIFT ||
      rec->Event.KeyEvent.wVirtualKeyCode == VK_CONTROL) {
    return FALSE;
  }
  return TRUE;
}

static void decode_key(int key, char *to) /* decode keycode into string */
{
  int skey;

  skey = -1;
  switch (key) {
  case 0x1b:
    skey = kESC;
    break;
  case 0x0d:
    skey = kENTER;
    break;
  case 0x09:
    skey = kTAB;
    break;
  case 0x21:
    skey = kSCRNUP;
    break;
  case 0x22:
    skey = kSCRNDOWN;
    break;
  case 0x70:
    skey = kF1;
    break;
  case 0x71:
    skey = kF2;
    break;
  case 0x72:
    skey = kF3;
    break;
  case 0x73:
    skey = kF4;
    break;
  case 0x74:
    skey = kF5;
    break;
  case 0x75:
    skey = kF6;
    break;
  case 0x76:
    skey = kF7;
    break;
  case 0x77:
    skey = kF8;
    break;
  case 0x78:
    skey = kF9;
    break;
  case 0x79:
    skey = kF10;
    break;
  case 0x7a:
    skey = kF11;
    break;
  case 0x7b:
    skey = kF12;
    break;
  case 0x24:
    skey = kHOME;
    break;
  case 0x23:
    skey = kEND;
    break;
  case 0x2d:
    skey = kINS;
    break;
  case 0x2e:
    skey = kDEL;
    break;
  case 0x08:
    skey = kBACKSPACE;
    break;
  case 0x27:
    skey = kRIGHT;
    break;
  case 0x25:
    skey = kLEFT;
    break;
  case 0x28:
    skey = kDOWN;
    break;
  case 0x26:
    skey = kUP;
    break;
  default:
    sprintf(conkeybuff, "key%x", key);
  }
  if (skey > 0) {
    strcpy(to, ykey[skey]);
  }
}
#endif

char *replace_escapes(char *string) /* replace \n,\a, etc. */
{
  char *from, *to;
  char *p;
  int val;
  static char *hexdigits = "0123456789abcdef";

  from = to = string;
  while (*from) {
    if (*from == '\\') {
      from++;
      switch (*from) {
      case 'n':
        *to = '\n';
        break;
      case 't':
        *to = '\t';
        break;
      case 'v':
        *to = '\v';
        break;
      case 'b':
        *to = '\b';
        break;
      case 'r':
        *to = '\r';
        break;
      case 'f':
        *to = '\f';
        break;
      case 'a':
        *to = '\a';
        break;
      case '\\':
        *to = '\\';
        break;
      case '\?':
        *to = '\?';
        break;
      case '\'':
        *to = '\'';
        break;
      case '\"':
        *to = '\"';
        break;
      case 'x':
        val = 0;
        if ((p = strchr(hexdigits, tolower(*(from + 1)))) &&
            p - hexdigits < 16) {
          from++;
          val = p - hexdigits;
          if ((p = strchr(hexdigits, tolower(*(from + 1)))) &&
              p - hexdigits < 16) {
            from++;
            val *= 16;
            val += p - hexdigits;
          }
        }
        *to = (char)val;
        break;
      default:
        *to = '\\';
        to++;
        *to = *from;
      }
    } else {
      *to = *from;
    }
    from++;
    to++;
  }
  *to = '\0';
  return string;
}

int count_backslashes(
    char *text) /* count number of backslashes up to position in string */
{
  int cnt = 0;
  while (*text == '\\') {
    text--;
    cnt++;
  }
  return cnt;
}

void create_myopen(int num) /* create command 'myopen' */
{
  struct command *cmd;

  cmd = add_command(cOPEN);
  cmd->tag = num;
}

void myopen(struct command *cmd) /* open specified file for given name */
{
#ifdef WINDOWS
  char PrinterName[NAMEBUFFLEN]; /* Name of default Printer */
  char *n;                       /* points into PrinterName */
  DOC_INFO_1 di;
#endif
  FILE *handle = NULL;
  int stream, i;
  char *name = NULL;
  char *mode = NULL;
  char **pmode;
  static char *valid_modes[] = {"r", "w", "a", "rb", "wb", "ab", ""};
  static int smodes[] = {mREAD, mWRITE, mWRITE, mREAD, mWRITE, mWRITE};
  int smode;
  struct stackentry *p;
  int has_mode, has_stream, printer;

  /* decode cmd->tag */
  has_stream = cmd->tag & OPEN_HAS_STREAM;
  has_mode = cmd->tag & OPEN_HAS_MODE;
  printer = cmd->tag & OPEN_PRINTER;

  if (has_mode) {
    mode = my_strdup(pop(stSTRING)->pointer);
  } else {
    mode = printer ? my_strdup("w") : my_strdup("r");
  }
  if (printer) {
    name = my_strdup("/usr/bin/lpr");
  } else {
    name = my_strdup(pop(stSTRING)->pointer);
  }

  if (has_stream) {
    stream = (int)pop(stNUMBER)->value;
  } else {
    stream = 0;
    for (i = 1; i < FOPEN_MAX - 4; i++) {
      if (stream_modes[i] == mCLOSED) {
        stream = i;
        break;
      }
    }
    if (!stream) {
      sprintf(estring, "reached maximum number of open files");
      errorcode = 5;
      goto open_done;
    }
  }

  p = push();
  p->value = 0.;
  p->type = stNUMBER;

  if (printer && print_to_file) {
    sprintf(estring, "cannot open printer: already printing grafics");
    errorcode = 6;
    goto open_done;
  }

  if (badstream(stream, 1)) {
    sprintf(estring, "invalid stream number %d", stream);
    errorcode = 9;
    goto open_done;
  }
  if (stream_modes[stream] != mCLOSED) {
    sprintf(estring, "stream already in use");
    errorcode = 2;
    goto open_done;
  }

  smode = 0;
  for (pmode = valid_modes; **pmode; pmode++) {
    if (!strcmp(*pmode, mode)) {
      break;
    }
    smode++;
  }
  if (!**pmode) {
    sprintf(estring, "\'%s\' is not a valid filemode", mode);
    errorcode = 3;
    goto open_done;
  }

  if (printer) {
#ifdef UNIX
    lineprinter = popen(name, "w");
    if (!lineprinter) {
      sprintf(estring, "could not open line printer");
      errorcode = 7;
      goto open_done;
    }
#else
    /* query win.ini for default printer */
    GetProfileString("windows", "device", ",,,", PrinterName, NAMEBUFFLEN);

    /* truncate printer name */
    n = PrinterName;
    while (*n && *n != ',') {
      n++;
    }
    *n = '\0';

    OpenPrinter(PrinterName, &lineprinter, NULL);
    di.pDocName = "yabasic text";
    di.pOutputFile = (LPTSTR)NULL;
    di.pDatatype = "RAW";
    if (!StartDocPrinter(lineprinter, 1, (LPBYTE)&di)) {
      sprintf(estring, "could not open line printer");
      errorcode = 7;
      goto open_done;
    }
    StartPagePrinter(lineprinter);
#endif
    lprstream = stream;
  } else {
    handle = fopen(name, mode);
    if (handle == NULL) {
      sprintf(estring, "could not open '%s': %s", name, my_strerror(errno));
      errorcode = 4;
      goto open_done;
    }
    streams[stream] = handle;
  }
  stream_modes[stream] = smodes[smode];
  errorcode = 0;
  p->value = stream;
open_done:
  if (name) {
    my_free(name);
  }
  if (mode) {
    my_free(mode);
  }
}

void checkopen(void) /* check, if open has been sucessfully */
{
  double result;

  result = pop(stNUMBER)->value;
  if (result <= 0) {
    error(sERROR, estring);
  }
}

void myclose(void) /* close the specified stream */
{
  int s;
#ifdef WINDOWS
  DWORD written;
#endif

  s = (int)pop(stNUMBER)->value;
  if (badstream(s, 0)) {
    return;
  }
  if (stream_modes[s] == mCLOSED) {
    sprintf(string, "stream %d already closed", s);
    error(sWARNING, string);
    return;
  }
  if (s == lprstream) {
#ifdef UNIX
    pclose(lineprinter);
#else
    WritePrinter(lineprinter, "\f", 2, &written);
    EndPagePrinter(lineprinter);
    EndDocPrinter(lineprinter);
    ClosePrinter(lineprinter);
    lineprinter = INVALID_HANDLE_VALUE;
#endif
    lprstream = -1;
  } else {
    fclose(streams[s]);
  }
  streams[s] = NULL;
  stream_modes[s] = mCLOSED;
}

void myseek(struct command *cmd) /* reposition file pointer */
{
  int s, p, m, i;
  struct stackentry *pp;
  char *mode;

  if (cmd->type == cSEEK2) {
    mode = (char *)my_strdup(pop(stSTRING)->pointer);
  } else {
    mode = my_strdup("begin");
  }
  p = (int)pop(stNUMBER)->value;
  s = (int)pop(stNUMBER)->value;
  pp = push();
  pp->value = 0.;
  pp->type = stNUMBER;
  for (i = 0; mode[i]; i++) {
    mode[i] = tolower(mode[i]);
  }
  if (!strcmp(mode, "begin")) {
    m = SEEK_SET;
  } else if (!strcmp(mode, "end")) {
    m = SEEK_END;
  } else if (!strcmp(mode, "here")) {
    m = SEEK_CUR;
  } else {
    sprintf(estring, "seek mode '%s' is none of begin,end,here", mode);
    errorcode = 12;
    my_free(mode);
    return;
  }
  my_free(mode);
  if (badstream(s, 0)) {
    return;
  }
  if (!(stream_modes[s] & (mREAD | mWRITE))) {
    sprintf(estring, "stream %d not open", s);
    errorcode = 11;
    return;
  }
  if (fseek(streams[s], (long)p, m)) {
    sprintf(estring, "could not position stream %d to byte %d", s, p);
    errorcode = 10;
    return;
  }
  pp->value = 1.0;
}

void create_pps(int type,
                int input) /* create command push_stream or pop_stream */
{
  struct command *cmd;

  cmd = add_command(type);
  cmd->args = input;
}

void push_stream(struct command *cmd) /* push current stream on stack and switch
                                         to new one */
{
  static int oldstream = STDIO_STREAM;
  struct stackentry *s;
  int stream;

  stream = (int)pop(stNUMBER)->value;
  if (badstream(stream, 0)) {
    return;
  }
  if (!cmd->args) {
    stream = -stream;
  }

  s = push();
  s->type = stNUMBER;
  s->value = oldstream;
  if (severity_threshold <= sDEBUG) {
    sprintf(string, "pushing %d on stack, switching to %d", oldstream, stream);
    error(sDEBUG, string);
  }
  oldstream = stream;
  mystream(stream);
}

void pop_stream(void) /* pop stream from stack and switch to it */
{
  int stream;

  stream = (int)pop(stNUMBER)->value;
  if (severity_threshold <= sDEBUG) {
    sprintf(string, "popping %d from stack, switching to it", stream);
    error(sDEBUG, string);
  }
  mystream(stream);
}

void mystream(int stream) /* switch to specified stream */
{
  int stdio, input;

  stdio = (abs(stream) == STDIO_STREAM);
  input = (stream > 0);
  currstr = stream;
  if (stream < 0) {
    stream = -stream;
  }
  if (badstream(stream, 0)) {
    return;
  }

  if (stdio) {
    cinstr = stdin;
    coutstr = stdout;
  } else {
    cinstr = coutstr = NULL;
    if (input) {
      cinstr = streams[stream];
    } else {
      coutstr = streams[stream];
    }
  }
}

int checkstream(void) /* test if currst is still valid */
{
  int stdio, input;

  stdio = (abs(currstr) == STDIO_STREAM);
  input = (currstr > 0);

  if (!stdio) {
    if (input && !(stream_modes[abs(currstr)] & mREAD)) {
      sprintf(string, "stream %d not open for reading", abs(currstr));
      error(sERROR, string);
      return FALSE;
    }
    if (!input && !(stream_modes[abs(currstr)] & (mWRITE | mPRINT))) {
      sprintf(string, "stream %d not open for writing or printing",
              abs(currstr));
      error(sERROR, string);
      return FALSE;
    }
  }
  return TRUE;
}

void testeof(struct command *cmd) /* check if specified stream is at eof */
{
  int s, c;
  struct stackentry *result;
  FILE *str;

  s = (int)pop(stNUMBER)->value;
  if (s && badstream(s, 0)) {
    return;
  }
  result = push();
  result->type = stNUMBER;
  if (s && !(stream_modes[s] & mREAD)) {
    result->value = 1.;
    return;
  }
  str = s ? streams[s] : stdin;
  c = getc(str);
  if (c == EOF) {
    result->value = 1.;
    return;
  }

  result->value = 0.;
  ungetc(c, str);
  return;
}

int badstream(int stream, int errcode) /* test for valid stream id */
{
  if (stream != STDIO_STREAM && (stream > FOPEN_MAX - 4 || stream <= 0)) {
    sprintf(errcode ? estring : string,
            "invalid stream: %d (can handle only streams from 1 to %d)", stream,
            FOPEN_MAX - 4);
    if (errcode) {
      errorcode = errcode;
    } else {
      error(sERROR, string);
    }
    return TRUE;
  }
  return FALSE;
}

void create_myread(char type, int tileol) /* create command 'read' */
{
  struct command *cmd;

  cmd = add_command(cREAD);
  cmd->args = tileol; /* true, if read should go til eol */
  cmd->tag = type;    /* can be 'd' or 's' */
}

void myread(struct command *cmd) /* read string or double */
{
  double d;
  static char buffer[INBUFFLEN]; /* buffer with current input */
  int numread;                   /* number of bytes read */
  int tileol;                    /* true, if read should go til end of line */
  struct stackentry *s;
  int currch; /* current character */

  numread = 0; /* no chars read'til now */
  buffer[0] = '\0';
  tileol = cmd->args;

  /* skip leading whitespace */
  if (!tileol) {
    do {
      currch = onechar();
    } while (currch == ' ' || currch == '\t');
    /* put back last char */
    if (currch != EOF && currch != '\0') {
      backchar(currch);
    }
    if (currch == '\0' || currch == EOF) {
      goto done;
    }
  }

  /* read chars */
  do {
    currch = onechar();
    buffer[numread] = currch;
    numread++;
  } while (((tileol && currch != '\0') ||
            (!tileol && currch != ' ' && currch != '\t' && currch != '\0')) &&
           currch != EOF && numread < INBUFFLEN);

  /* put back last char */
  if (currch != EOF && currch != '\0') {
    backchar(currch);
  }
  /* and remove it from buff */
  if (currch != EOF) {
    numread--;
  }
  buffer[numread] = '\0';
  if (currch == '\0' || currch == EOF) {
    goto done;
  }

  /* skip trailing whitespace */
  if (!tileol) {
    do {
      currch = onechar();
    } while (currch == ' ' || currch == '\t');
    if (currch != EOF && currch != '\0') {
      backchar(currch);
    }
  }

done:
  if (cmd->tag == 's') { /* read string */
    s = push();
    s->type = stSTRING;
    s->pointer = my_strdup(buffer);
  } else { /* read double */
    s = push();
    s->type = stNUMBER;
    s->value = 0.0;
    if (buffer[0] && (sscanf(buffer, "%lf", &d) == 1)) {
      s->value = d;
    }
  }
}

static void readline(void) /* read one line from current stream */
{
#ifdef UNIX
  char *nl; /* position of newline */
  int x, y;
#else
  int read;
#endif

  if (!checkstream()) {
    return;
  }
  linebuffer[0] = '\0';
#ifdef UNIX
  if (curinized && cinstr == stdin) {
    curs_set(1);
    getyx(stdscr, y, x);
#ifdef HAVE_GETNSTR
    getnstr(linebuffer, INBUFFLEN);
#else
    getstr(linebuffer);
#endif
    curs_set(0);
    if ((nl = strchr(linebuffer, '\0'))) {
      *nl = '\n';
      *(nl + 1) = '\0';
    }
    if (y >= LINES - 1) {
      scrl(1);
    }
    refresh();
  }
#else
  if (curinized && cinstr == stdin) {
    FlushConsoleInputBuffer(ConsoleInput);
    ReadConsole(ConsoleInput, linebuffer, INBUFFLEN, &read, NULL);
    if (read >= 2) {
      linebuffer[read - 2] = '\n';
      linebuffer[read - 1] = '\0';
    }
  }
#endif
  else {
    (void)!fgets(linebuffer, INBUFFLEN, cinstr);
  }
  currchar = linebuffer;
  prompted = FALSE;
}

static int onechar() /* read one char from cinstr */
{
  int ch;

  if (!checkstream()) {
    return '\0';
  }
  if (cinstr == stdin) {
    if (!currchar || !*currchar) {
      readline();
    }
    do {
      ch = *currchar;
      currchar++;
    } while (!(!iscntrl(ch) || strchr(" \t\n", ch) || ch == '\0'));
  } else {
    do {
      ch = fgetc(cinstr);
    } while (!(!iscntrl(ch) || strchr(" \t\n", ch) || ch == '\0' || ch == EOF));
  }

  if (ch == '\n' || ch == EOF) {
    return '\0';
  } else {
    return ch;
  }
}

static void backchar(int ch) /* put char back into stream */
{
  if (!checkstream()) {
    return;
  }
  if (cinstr == stdin) {
    if (currchar > linebuffer) {
      currchar--;
    }
  } else {
    ungetc(ch, cinstr);
  }
}

void chkprompt() /* print an intermediate prompt if necessary */
{
  if (cinstr == stdin && (!currchar || !*currchar) && !prompted) {
    onestring("?");
  }
}

void create_onestring(char *str) /* create command 'onestring' */
{
  struct command *cmd;

  cmd = add_command(cONESTRING);
  cmd->pointer = my_strdup(str);
}

void onestring(char *s) /* write string to current file */
{
#ifdef WINDOWS
  DWORD len, written;
  DWORD consoleflags;
#endif

  if (!checkstream()) {
    return;
  }
  if (curinized && abs(currstr) == STDIO_STREAM) {
#ifdef UNIX
    addstr(s);
    refresh();
#else
    len = strlen(s);
    GetConsoleMode(ConsoleOutput, &consoleflags);
    WriteConsole(ConsoleOutput, s, len, &written, NULL);
#endif
  } else if (abs(currstr) == lprstream) {
#ifdef UNIX
    fprintf(lineprinter, "%s", s);
    fflush(lineprinter);
#else
    len = strlen(s);
    WritePrinter(lineprinter, s, len, &written);
#endif
  } else {
    fprintf(coutstr, "%s", s);
    fflush(coutstr);
  }
  prompted = TRUE;
}

void create_colour(int flag) /* create command 'colour' */
{
  struct command *c;

  c = add_command(cCOLOUR);
  c->args = flag;
}

void colour(struct command *cmd) /* switch on colour */
{
  char *fore = NULL, *back = NULL, *p;
  int fc, bc;

  if (cmd->args && !curinized) {
    error(sERROR, "need to call 'clear screen' first");
    return;
  }
  if (cmd->args == 0) {
    if (!curinized) {
      return;
    }
#ifdef UNIX
    attrset(A_NORMAL);
    if (con_fore_inten == cciBRIGHT) {
      attron(A_BOLD);
    }
#else
    SetConsoleTextAttribute(ConsoleOutput, (WORD)(stdfc | stdbc));
    return;
#endif
  } else if (cmd->args == 1) {
#ifdef UNIX
    attrset(A_REVERSE);
    return;
#else
    SetConsoleTextAttribute(
        ConsoleOutput, (WORD)(yc2oc(oc2yc(stdfc), 0) | yc2oc(oc2yc(stdbc), 1)));
    return;
#endif
  } else { /* decode colours */
#ifdef UNIX
    if (!has_colors()) {
      pop(stSTRING);
      if (cmd->args == 3) {
        pop(stSTRING);
      }
      attrset(A_REVERSE);
      return;
    }
#endif
    if (cmd->args == 2) {
      back = NULL;

      fore = pop(stSTRING)->pointer;
      for (p = fore; *p; p++) {
        *p = tolower(*p);
      }
    } else {
      back = pop(stSTRING)->pointer;
      for (p = back; *p; p++) {
        *p = tolower(*p);
      }
      fore = pop(stSTRING)->pointer;
      for (p = fore; *p; p++) {
        *p = tolower(*p);
      }
    }
    fc = name2yc(fore);
    if (fc < 0) {
      sprintf(estring, "unknown foreground colour: '%s'", fore);
      error(sERROR, estring);
    }
    if (back) {
      bc = name2yc(back);
      if (fc < 0) {
        sprintf(estring, "unknown background colour: '%s'", back);
        error(sERROR, estring);
      }
    }
#ifdef UNIX
    if (back) {
      /* Encoding and decoding around init_pair, COLOR_PAIR and PAIR_NUMBER must match */      
      attrset(COLOR_PAIR(fc + bc * 8 + 1));
    } else {
      attrset(COLOR_PAIR(65 + fc));
    }
    if (con_fore_inten == cciBRIGHT) {
      attron(A_BOLD);
    }
#else
    SetConsoleTextAttribute(
        ConsoleOutput, (WORD)(yc2oc(fc, TRUE) | (back ? yc2oc(bc, FALSE) : 0)));
#endif
  }
}

static void initcol(void) /* initialize curses colors */
{
  static int first = TRUE;
#ifdef UNIX
  int i, j;
  short f, b;
#else
  CONSOLE_SCREEN_BUFFER_INFO csbi;
#endif

  if (!first) {
    return;
  }
  first = FALSE;
#ifdef UNIX
  if (!has_colors()) {
    return;
  }
  start_color();
  assume_default_colors(-1, -1);
  /* 73 = 8 * 8 + 8 + 1 = pairs + fore-only + immutable-pair-0 */
  if (COLOR_PAIRS < 73) return;
  
  for (b = 0; b < 8; b++) {
    for (f = 0; f < 8; f++) {
      /* arguments are fore, back. Skip color pair 0 as it cannot be modified */
      /* encoding and decoding around init_pair, COLOR_PAIR and PAIR_NUMBER must match */
      init_pair(f + b * 8 + 1, yc2oc(f, TRUE), yc2oc(b, FALSE));
    }
  }

  for (f = 0; f < 8; f++) {
    init_pair(65 + f, yc2oc(f, TRUE), -1);
  }

  if (con_fore_inten == cciLEGACY) {
    init_color(COLOR_YELLOW, 1000, 1000, 0);
  }

#else
  GetConsoleScreenBufferInfo(ConsoleOutput, &csbi);
  stdfc =
      csbi.wAttributes & (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
  stdbc =
      csbi.wAttributes & (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

#endif
}

int name2yc(char *name) /* convert a color name to an integer */
{
  char *c;

  for (c = name; *c; c++) {
    *c = tolower(*c);
  }
  if (!strcmp(name, "black") || !strcmp(name, "bla")) {
    return YC_BLACK;
  }
  if (!strcmp(name, "white") || !strcmp(name, "whi")) {
    return YC_WHITE;
  }
  if (!strcmp(name, "red") || !strcmp(name, "red")) {
    return YC_RED;
  }
  if (!strcmp(name, "blue") || !strcmp(name, "blu")) {
    return YC_BLUE;
  }
  if (!strcmp(name, "green") || !strcmp(name, "gre")) {
    return YC_GREEN;
  }
  if (!strcmp(name, "yellow") || !strcmp(name, "yel")) {
    return YC_YELLOW;
  }
  if (!strcmp(name, "cyan") || !strcmp(name, "cya")) {
    return YC_CYAN;
  }
  if (!strcmp(name, "magenta") || !strcmp(name, "mag")) {
    return YC_MAGENTA;
  }
  return -1;
}

int yc2oc(int yc,
          int fore) /* convert a yabasic color to operating system color */
{
#ifdef UNIX
  fore = 0; /* stop gcc from complaining */
  if (yc == YC_BLACK) {
    return COLOR_BLACK;
  }
  if (yc == YC_WHITE) {
    return COLOR_WHITE;
  }
  if (yc == YC_RED) {
    return COLOR_RED;
  }
  if (yc == YC_BLUE) {
    return COLOR_BLUE;
  }
  if (yc == YC_GREEN) {
    return COLOR_GREEN;
  }
  if (yc == YC_YELLOW) {
    return COLOR_YELLOW;
  }
  if (yc == YC_CYAN) {
    return COLOR_CYAN;
  }
  if (yc == YC_MAGENTA) {
    return COLOR_MAGENTA;
  }
#else
  if (con_fore_inten == cciLEGACY) {
    if (fore) {
      if (yc == YC_BLACK) {
	return 0;
      }
      if (yc == YC_WHITE) {
	return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
      }
      if (yc == YC_RED) {
	return FOREGROUND_RED;
      }
      if (yc == YC_BLUE) {
	return FOREGROUND_BLUE;
      }
      if (yc == YC_GREEN) {
	return FOREGROUND_GREEN;
      }
      if (yc == YC_YELLOW) {
	return FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
      }
      if (yc == YC_CYAN) {
	return FOREGROUND_GREEN | FOREGROUND_BLUE;
      }
      if (yc == YC_MAGENTA) {
	return FOREGROUND_BLUE | FOREGROUND_RED;
      }
    } else {
      if (yc == YC_BLACK) {
	return 0;
      }
      if (yc == YC_WHITE) {
	return BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
      }
      if (yc == YC_RED) {
	return BACKGROUND_RED;
      }
      if (yc == YC_BLUE) {
	return BACKGROUND_BLUE;
      }
      if (yc == YC_GREEN) {
	return BACKGROUND_GREEN;
      }
      if (yc == YC_YELLOW) {
	return BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
      }
      if (yc == YC_CYAN) {
	return BACKGROUND_GREEN | BACKGROUND_BLUE;
      }
      if (yc == YC_MAGENTA) {
	return BACKGROUND_BLUE | BACKGROUND_RED;
      }
    }
  } else if ( con_fore_inten == cciNORMAL ) {
    if (fore) {
      if (yc == YC_BLACK) {
	return 0;
      }
      if (yc == YC_WHITE) {
	return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
      }
      if (yc == YC_RED) {
	return FOREGROUND_RED;
      }
      if (yc == YC_BLUE) {
	return FOREGROUND_BLUE;
      }
      if (yc == YC_GREEN) {
	return FOREGROUND_GREEN;
      }
      if (yc == YC_YELLOW) {
	return FOREGROUND_GREEN | FOREGROUND_RED;
      }
      if (yc == YC_CYAN) {
	return FOREGROUND_GREEN | FOREGROUND_BLUE;
      }
      if (yc == YC_MAGENTA) {
	return FOREGROUND_BLUE | FOREGROUND_RED;
      }
    } else {
      if (yc == YC_BLACK) {
	return 0;
      }
      if (yc == YC_WHITE) {
	return BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
      }
      if (yc == YC_RED) {
	return BACKGROUND_RED;
      }
      if (yc == YC_BLUE) {
	return BACKGROUND_BLUE;
      }
      if (yc == YC_GREEN) {
	return BACKGROUND_GREEN;
      }
      if (yc == YC_YELLOW) {
	return BACKGROUND_GREEN | BACKGROUND_RED;
      }
      if (yc == YC_CYAN) {
	return BACKGROUND_GREEN | BACKGROUND_BLUE;
      }
      if (yc == YC_MAGENTA) {
	return BACKGROUND_BLUE | BACKGROUND_RED;
      }
    }
  } else if ( con_fore_inten == cciBRIGHT ) {
    if (fore) {
      if (yc == YC_BLACK) {
	return 0;
      }
      if (yc == YC_WHITE) {
	return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
      }
      if (yc == YC_RED) {
	return FOREGROUND_RED | FOREGROUND_INTENSITY;
      }
      if (yc == YC_BLUE) {
	return FOREGROUND_BLUE | FOREGROUND_INTENSITY;
      }
      if (yc == YC_GREEN) {
	return FOREGROUND_GREEN | FOREGROUND_INTENSITY;
      }
      if (yc == YC_YELLOW) {
	return FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
      }
      if (yc == YC_CYAN) {
	return FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
      }
      if (yc == YC_MAGENTA) {
	return FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
      }
    } else {
      if (yc == YC_BLACK) {
	return 0;
      }
      if (yc == YC_WHITE) {
	return BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
      }
      if (yc == YC_RED) {
	return BACKGROUND_RED | BACKGROUND_INTENSITY;
      }
      if (yc == YC_BLUE) {
	return BACKGROUND_BLUE | BACKGROUND_INTENSITY;
      }
      if (yc == YC_GREEN) {
	return BACKGROUND_GREEN | BACKGROUND_INTENSITY;
      }
      if (yc == YC_YELLOW) {
	return BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
      }
      if (yc == YC_CYAN) {
	return BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
      }
      if (yc == YC_MAGENTA) {
	return BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY;
      }
    }
  } else {
    sprintf(estring, "Internal error: Invalid value for console_foreground_intensity: %d", con_fore_inten);
    error(sERROR, estring);
  }
  
#endif
  return -1;
}

int oc2yc(int oc) /* convert an operating system color to yabasic color */
{
#ifdef UNIX
  if (oc == COLOR_BLACK) {
    return YC_BLACK;
  }
  if (oc == COLOR_WHITE) {
    return YC_WHITE;
  }
  if (oc == COLOR_RED) {
    return YC_RED;
  }
  if (oc == COLOR_BLUE) {
    return YC_BLUE;
  }
  if (oc == COLOR_GREEN) {
    return YC_GREEN;
  }
  if (oc == COLOR_YELLOW) {
    return YC_YELLOW;
  }
  if (oc == COLOR_CYAN) {
    return YC_CYAN;
  }
  if (oc == COLOR_MAGENTA) {
    return YC_MAGENTA;
  }
#else
  if (oc == 0) {
    return YC_BLACK;
  }
  if (oc == (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN) ||
      oc == (BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN) ||
      oc == (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY) ||
      oc == (BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY)) {
    return YC_WHITE;
  }
  if (oc == (FOREGROUND_RED) ||
      oc == (BACKGROUND_RED) ||
      oc == (FOREGROUND_RED | FOREGROUND_INTENSITY) ||
      oc == (BACKGROUND_RED | BACKGROUND_INTENSITY)) {
    return YC_RED;
  }
  if (oc == (FOREGROUND_BLUE) ||
      oc == (BACKGROUND_BLUE) ||
      oc == (FOREGROUND_BLUE | FOREGROUND_INTENSITY) ||
      oc == (BACKGROUND_BLUE | BACKGROUND_INTENSITY)) {
    return YC_BLUE;
  }
  if (oc == (FOREGROUND_GREEN) ||
      oc == (BACKGROUND_GREEN) ||
      oc == (FOREGROUND_GREEN | FOREGROUND_INTENSITY) ||
      oc == (BACKGROUND_GREEN | BACKGROUND_INTENSITY)) {
    return YC_GREEN;
  }
  if (oc == (FOREGROUND_RED | FOREGROUND_GREEN) ||
      oc == (BACKGROUND_RED | BACKGROUND_GREEN) ||
      oc == (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY) ||
      oc == (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY)) {
    return YC_YELLOW;
  }
  if (oc == (FOREGROUND_BLUE | FOREGROUND_GREEN) ||
      oc == (BACKGROUND_BLUE | BACKGROUND_GREEN) ||
      oc == (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY) ||
      oc == (BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY)) {
    return YC_CYAN;
  }
  if (oc == (FOREGROUND_RED | FOREGROUND_BLUE) ||
      oc == (BACKGROUND_RED | BACKGROUND_BLUE) ||
      oc == (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY) ||
      oc == (BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY)) {
    return YC_MAGENTA;
  }
#endif
  return -1;
}

void putchars(void) /* put rect onto screen */
{
  char *ch, text, fore[4], back[4];
  int n, sx, sy, x, y, f, b;
  int tox, toy;
  int oldx, oldy;
#ifdef WINDOWS
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD cp;
  WORD attributes;
  char buff[2];
  int written;
#endif

  toy = (int)(pop(stNUMBER)->value);
  tox = (int)(pop(stNUMBER)->value);
  ch = pop(stSTRING)->pointer;
#ifdef UNIX
  getyx(stdscr, oldy, oldx);
#else
  GetConsoleScreenBufferInfo(ConsoleOutput, &csbi);
  attributes = csbi.wAttributes;
  oldx = csbi.dwCursorPosition.X;
  oldy = csbi.dwCursorPosition.Y;
#endif
  if (sscanf(ch, "%d,%d:%n", &sx, &sy, &n) != 2) {
    error(sERROR, "illegal screen string");
    return;
  }
  ch += n;
  for (x = tox; x < tox + sx; x++) {
    if (x < 0 || x >= COLS) {
      continue;
    }
    for (y = toy; y < toy + sy; y++) {
      if (x < 0 || x >= COLS || y < 0 || y >= LINES) {
        for (n = 0; n < 10; n++)
          if (*ch) {
            ch++;
          }
        continue;
      }
      if (!*ch) {
        text = ' ';
        f = YC_BLACK;
        b = YC_BLACK;
      } else {
        text = *ch;
        strncpy(fore, ch + 2, 3);
        fore[3] = '\0';
        strncpy(back, ch + 6, 3);
        back[3] = '\0';
        for (n = 0; n < 10; n++)
          if (*ch) {
            ch++;
          }
        f = name2yc(fore);
        if (f < 0) {
          f = YC_WHITE;
        }
        b = name2yc(back);
        if (b < 0) {
          b = YC_WHITE;
        }
      }
#ifdef UNIX
      if (has_colors()) {
	/* Encoding and decoding around init_pair, COLOR_PAIR and PAIR_NUMBER must match */	
        attrset(COLOR_PAIR(f + b * 8 + 1));
	if (con_fore_inten == cciBRIGHT) {
	  attron(A_BOLD);
	}	
      }
      mvaddch(y, x, text);
#else
      cp.X = x;
      cp.Y = y;
      SetConsoleCursorPosition(ConsoleOutput, cp);
      SetConsoleTextAttribute(ConsoleOutput,
                              (WORD)(yc2oc(f, TRUE) | yc2oc(b, FALSE)));
      buff[0] = text;
      buff[1] = '\0';
      WriteConsole(ConsoleOutput, buff, 1, &written, NULL);
#endif
    }
  }
#ifdef UNIX
  if (has_colors()) {
    attrset(A_NORMAL);
    attron(COLOR_PAIR(0));
  } else {
    attrset(A_NORMAL);
  }
  move(y, x);
  refresh();
#else
  cp.X = oldx;
  cp.Y = oldy;
  SetConsoleCursorPosition(ConsoleOutput, cp);
  SetConsoleTextAttribute(ConsoleOutput, attributes);
#endif

  return;
}

char *getchars(int xf, int yf, int xt, int yt) /* get rect from screen */
{
  int x, y;
#ifdef UNIX
  int c, ct, cc;
#endif
  int cf, cb;
  int oldx, oldy;
  char *res;
  char cols[20];
#ifdef WINDOWS
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD cp;
  char charbuff[2];
  WORD attrbuff[2];
  int read;
#endif

  if (xf > xt) {
    x = xf;
    xf = xt;
    xt = x;
  }
  if (yf > yt) {
    y = yf;
    yf = yt;
    yt = y;
  }

  res = my_malloc(12 + (xt - xf + 1) * (yt - yf + 1) * 12);
  sprintf(res, "%d,%d:", xt - xf + 1, yt - yf + 1);
#ifdef UNIX
  getyx(stdscr, oldy, oldx);
#else
  GetConsoleScreenBufferInfo(ConsoleOutput, &csbi);
  oldx = csbi.dwCursorPosition.X;
  oldy = csbi.dwCursorPosition.Y;
#endif

  for (x = xf; x <= xt; x++) {
    for (y = yf; y <= yt; y++) {
      if (y < 0 || y >= LINES || x < 0 || x >= COLS) {
        strcat(res, " blbl");
      } else {
#ifdef UNIX
        c = mvinch(y, x);
        ct = c & A_CHARTEXT;
        if (!isprint(ct)) {
          ct = ' ';
        }
	/* encoding and decoding around init_pair, COLOR_PAIR and PAIR_NUMBER must match */
        cc = PAIR_NUMBER(c & A_COLOR);
	if (cc == 0) {
	  cf = YC_WHITE;
	  cb = YC_BLACK;
	} else if (cc >= 65) {
	  cf = cc - 65;
	  cb = YC_BLACK;
	} else {
	  cf = (cc - 1) & 7;
	  cb = (cc - 1 - cf) / 8;
	}
        if (has_colors()) {
          sprintf(cols, "%c:%s:%s,", ct, yc2short(cf), yc2short(cb));
        } else {
          sprintf(cols, "%c:???:???,", ct);
        }
#else
        cp.X = x;
        cp.Y = y;
        ReadConsoleOutputCharacter(ConsoleOutput, charbuff, 1, cp, &read);
        charbuff[1] = '\0';
        ReadConsoleOutputAttribute(ConsoleOutput, attrbuff, 1, cp, &read);
        cf = oc2yc(attrbuff[0] &
                   (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE));
        cb = oc2yc(attrbuff[0] &
                   (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE));
        sprintf(cols, "%c:%s:%s,", charbuff[0], yc2short(cf), yc2short(cb));
#endif
        strcat(res, cols);
      }
    }
  }
#ifdef UNIX
  move(oldy, oldx);
#endif
  res[strlen(res) - 1] = '\0';
  return res;
}

char *yc2short(int col) /* convert yabasic colours to short colour name */
{
  static char r1[4], r2[4];
  static char *pr = r1;

  /* switch between two staic buffers for return value */
  if (pr == r1) {
    pr = r2;
  } else {
    pr = r1;
  }

  strcpy(pr, "***");
  
  if (col == YC_BLACK) {
    strcpy(pr, "Bla");
  }
  if (col == YC_WHITE) {
    strcpy(pr, "Whi");
  }
  if (col == YC_RED) {
    strcpy(pr, "Red");
  }
  if (col == YC_BLUE) {
    strcpy(pr, "Blu");
  }
  if (col == YC_GREEN) {
    strcpy(pr, "Gre");
  }
  if (col == YC_YELLOW) {
    strcpy(pr, "Yel");
  }
  if (col == YC_CYAN) {
    strcpy(pr, "Cya");
  }
  if (col == YC_MAGENTA) {
    strcpy(pr, "Mag");
  }

  return pr;
}
