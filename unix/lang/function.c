/*

    YABASIC ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2019
    more info at www.yabasic.de

    function.c --- code for functions

    This file is part of yabasic and may be copied under the terms of
    MIT License which can be found in the file LICENSE.

*/


/* ------------- includes ---------------- */

#ifndef YABASIC_INCLUDED
#include "yabasic.h"		/* all prototypes and structures */
#endif


/* ------------- external references ---------------- */

extern int mylineno;		/* current line number */
extern int yyparse ();		/* call bison parser */


/* ------------- local functions ---------------- */

static char *fromto (char *, int, int);	/* get portion of string (mid$ et al) */
static void clear_buff ();	/* clear system-input buffers */
static void store_buff (char *, int);	/* store system-input buffer */
static int do_glob (char *, char *);	/* actually do the globbing */
static double other2dec (char *, int);	/* convert hex to decimal */
static char *dec2other (double, int);	/* convert decimal to hex */
static double peek (char *);	/* peek into internals */
static char *peek2 (char *, struct command *);	/* peek into internals */
static char *peek3 (char *, char *);	/* peek into internals */
static int peekfile (int);	/* read a byte from stream */
static int do_system (char *);	/* hand over execution of command to system, return exit code */
static char *do_system2 (char *); /* hand over execution of command to system, return output as string */
static double myrand (); /* generate random number in given range */

/* ------------- global variables ---------------- */

struct command *lastdata = NULL;	/* used to associate all data-commands with each others */
static struct buff_chain *buffroot;	/* start of sys-input buffer */
static struct buff_chain **buffcurr;	/* current entry in buff_chain */
static int buffcount;		/* number of filled buffers */
char *last_inkey;         /* last result of inkey$ */

/* ------------- subroutines ---------------- */


void
token (struct command *cmd)	/* extract token from variable */
{
    int split;
    struct stackentry *s;
    struct symbol *sym;
    struct array *ar;
    int num = 0, i;
    char *p, *q;
    char **pp;
    char *del, *line;
    int wasdel, isdel;


    if (cmd->type == cSPLIT2 || cmd->type == cTOKEN2) {
        del = pop (stSTRING)->pointer;
    } else {
        del = " \t";
    }
    split = (cmd->type == cSPLIT || cmd->type == cSPLIT2);
    s = pop (stSTRINGARRAYREF);
    line = pop (stSTRING)->pointer;
    sym = get_sym (s->pointer, syARRAY, amSEARCH);
    if (!sym || !sym->pointer) {
        sprintf (string, "array '%s()' is not defined", strip (s->pointer));
        error (sERROR, string);
        goto token_done;
    }
    ar = sym->pointer;
    if (ar->dimension > 1) {
        error (sERROR, "only one dimensional arrays allowed");
        goto token_done;
    }

    /* count number of tokens */
    isdel = TRUE;
    if (split && *line) {
        num = 1;
    } else {
        num = 0;
    }
    for (p = line; *p; ++p) {
        wasdel = isdel;
        isdel = (strchr (del, *p) != NULL);
        if (split) {
            if (isdel) {
                num++;
            }
        } else {
            if (isdel && isdel != wasdel) {
                num++;
            }
        }
    }
    if (!split && !isdel) {
        num++;
    }

    /* free previous array content */
    for (i = 0; i < ar->bounds[0]; i++) {
        free (((char **) ar->pointer)[i]);
    }
    free (ar->pointer);
    ar->pointer = my_malloc ((num + 1) * sizeof (char *));
    pp = ar->pointer;
    pp[0] = my_strdup ("");

    /* extract tokens */
    i = 1;
    isdel = TRUE;
    if (*line) {
        for (p = q = line;; p++) {
            wasdel = isdel;
            isdel = (strchr (del, *p) != NULL) || !*p;
            if ((split && isdel) || (!split && (isdel && isdel != wasdel))) {
                while (strchr (del, *q) && q < p) {
                    q++;
                }
                pp[i] = my_strndup (q, p - q + 1);
                pp[i][p - q] = '\0';
                q = p + 1;
                i++;
            }
            if (!*p) {
                break;
            }
        }
    }

    ar->bounds[0] = num + 1;
token_done:
    s = push ();
    s->type = stNUMBER;
    s->value = num;
}


void
tokenalt (struct command *cmd)	/* extract token from variable with alternate semantics */
{
    char *del;			/* delimiter for strings */
    struct stackentry *t;
    char *old, *new, *tok;
    int split;

    if (cmd->type == cSPLITALT2 || cmd->type == cTOKENALT2) {
        del = pop (stSTRING)->pointer;
    } else {
        del = " \t";
    }
    split = (cmd->type == cSPLITALT || cmd->type == cSPLITALT2);

    t = pop (stSTRING);
    old = t->pointer;
    t->pointer = NULL;		/* prevent push from freeing the memory */
    t = push ();
    t->type = stSTRING;
    new = old;
    tok = NULL;
    while (*new) {
        if (!tok && (!strchr (del, *new) || split)) {
            tok = new;    /* found start of token */
        }
        if (tok && strchr (del, *new)) {
            break;    /* found end of token */
        }
        new++;
    }
    if (*new) {
        *new = '\0';		/* terminate token */
        new++;
        if (!split) {
            while (*new) {
                if (!strchr (del, *new)) {
                    break;    /* found start of next token */
                }
                new++;
            }
        }
    }
    t->pointer = my_strdup (tok ? tok : "");	/* copy token */
    /* move rest of string */
    while (*new) {
        *old = *new;
        old++;
        new++;
    };
    *old = '\0';
}


void
glob (void)			/* check, if pattern globs string */
{
    char *str, *pat;
    struct stackentry *stack;
    int res;

    pat = (char *) pop (stSTRING)->pointer;
    str = (char *) pop (stSTRING)->pointer;

    res = do_glob (str, pat);
    stack = push ();
    stack->value = res;
    stack->type = stNUMBER;
}


static int
do_glob (char *str, char *pat)	/* actually do the globbing */
{
    int res;

    if (severity_threshold <= sDEBUG) {
        sprintf (string, "globbing '%s' on '%s'", str, pat);
        error (sDEBUG, string);
    }
    if (*pat == '\0' && *str == '\0') {
        return TRUE;
    } else if (*pat == '\0') {
        return FALSE;
    } else if (*pat == '?' && *str == '\0') {
        return FALSE;
    } else if (*pat == '?') {
        if (*str == '\0') {
            return FALSE;
        }
        pat++;
        str++;
    } else if (*pat == '*') {
        pat++;
        res = FALSE;
        while (*str && !(res = do_glob (str, pat))) {
            str++;
        }
        if (res) {
            return TRUE;
        }
    } else if (*str == '\0') {
        return FALSE;
    } else {
        while (*pat && *pat != '?' && *pat != '*') {
            if (*pat != *str) {
                return FALSE;
            }
            str++;
            pat++;
        }
    }
    return do_glob (str, pat);
}


void
concat ()			/* concatenates two strings from stack */
{
    struct stackentry *c;
    char *aa, *bb, *cc;

    aa = pop (stSTRING)->pointer;
    bb = pop (stSTRING)->pointer;
    cc = (char *) my_malloc (sizeof (char) *
                             (strlen (aa) + strlen (bb) + 1));
    strcpy (cc, bb);
    strcat (cc, aa);
    c = push ();
    c->type = stSTRING;
    c->pointer = cc;
}


void
create_changestring (int type)	/* create command 'changestring' */
{
    struct command *cmd;

    cmd = add_command (cCHANGESTRING, FALSE, NULL);
    cmd->args = type;
}


void
changestring (struct command *current)	/* changes a string */
{
    int type, a2, a3;
    char *newpart;
    char *oldstring;
    int i, len;
    struct stackentry *a1;

    type = current->args;
    newpart = pop (stSTRING)->pointer;
    if (type > fTWOARGS) {
        a3 = (int) pop (stNUMBER)->value;
    }
    if (type > fONEARGS) {
        a2 = (int) pop (stNUMBER)->value;
    }
    a1 = pop (stSTRING);
    oldstring = a1->pointer;
    a1->pointer = NULL;		/* this prevents push from freeing the memory */

    if (!oldstring || !*oldstring) {
        return;
    }
    switch (type) {
    case fMID:
        for (i = 1; i < a2 + a3; i++) {
            if (!oldstring[i - 1]) {
                break;
            }
            if (i >= a2) {
                if (!newpart[i - a2]) {
                    break;
                }
                oldstring[i - 1] = newpart[i - a2];
            }
        }
        break;
    case fMID2:
        len = strlen (oldstring);
        for (i = 1; i <= len; i++) {
            if (!oldstring[i - 1]) {
                break;
            }
            if (i >= a2) {
                if (!newpart[i - a2]) {
                    break;
                }
                oldstring[i - 1] = newpart[i - a2];
            }
        }
        break;
    case fLEFT:
        for (i = 1; i <= a2; i++) {
            if (!oldstring[i - 1] || !newpart[i - 1]) {
                break;
            }
            oldstring[i - 1] = newpart[i - 1];
        }
        break;
    case fRIGHT:
        len = strlen (oldstring);
        for (i = 1; i <= len; i++) {
            if (i > len - a2) {
                if (!newpart[i - 1 - len + a2]) {
                    break;
                }
                oldstring[i - 1] = newpart[i - 1 - len + a2];
            }
        }
        break;
    }
}


void
create_function (int type)	/* create command 'function' */
/* type can be sin,cos,mid$ ... */
{
    struct command *cmd;

    cmd = add_command (cFUNCTION, FALSE, NULL);
    if (severity_threshold <= sDEBUG) {
	sprintf(estring, "function '%s'",fexplanation[type]);
	error (sDEBUG, estring);
    }
    cmd->args = type;
}


void
function (struct command *current)	/* performs a function */
{
    struct stackentry *stack, *a1, *a2, *a3, *a4;
    char *pointer;
    double value;
    time_t datetime;
    int type, result, len, start, i, max;
    char *str, *str2;

    a3 = NULL;
    type = current->args;
    if (type > fTHREEARGS) {
        a4 = pop (stSTRING_OR_NUMBER);
    }
    if (type > fTWOARGS) {
        a3 = pop (stSTRING_OR_NUMBER);
    }
    if (type > fONEARGS) {
        a2 = pop (stSTRING_OR_NUMBER);
    }
    if (type > fZEROARGS) {
        a1 = pop (stSTRING_OR_NUMBER);
    }

    if (severity_threshold <= sDEBUG) {
	sprintf(estring, "function '%s'",fexplanation[type]);
	error (sDEBUG, estring);
    }

    switch (type) {
    case fSIN:
        value = sin (a1->value);
        result = stNUMBER;
        break;
    case fASIN:
        value = asin (a1->value);
        result = stNUMBER;
        break;
    case fCOS:
        value = cos (a1->value);
        result = stNUMBER;
        break;
    case fACOS:
        value = acos (a1->value);
        result = stNUMBER;
        break;
    case fTAN:
        value = tan (a1->value);
        result = stNUMBER;
        break;
    case fATAN:
        value = atan (a1->value);
        result = stNUMBER;
        break;
    case fEXP:
        value = exp (a1->value);
        result = stNUMBER;
        break;
    case fLOG:
        value = log (a1->value);
        result = stNUMBER;
        break;
    case fLOG2:
        value = log (a1->value) / log (a2->value);
        result = stNUMBER;
        break;
    case fLEN:
        value = (double) strlen (a1->pointer);
        result = stNUMBER;
        break;
    case fSTR:
        sprintf (string, "%g", a1->value);
        pointer = my_strdup (string);
        result = stSTRING;
        break;
    case fSTR2:
    case fSTR3:
        result = stSTRING;
        if (!myformat (string, INBUFFLEN, a1->value, a2->pointer, a3 ? a3->pointer : NULL)) {
            pointer = my_strdup (""); 
            break;
        }
        pointer = my_strdup (string);
        break;
    case fCHOMP:
        result = stSTRING;
	pointer = a1->pointer;
	a1->pointer = NULL;
	pointer[strcspn(pointer, "\r\n")] = 0;
	break;
    case fSQRT:
        value = sqrt (a1->value);
        result = stNUMBER;
        break;
    case fSQR:
        value = a1->value * a1->value;
        result = stNUMBER;
        break;
    case fINT:
        if (a1->value < 0) {
            value = -floor (-a1->value);
        } else {
            value = floor (a1->value);
        }
        result = stNUMBER;
        break;
    case fCEIL:
        value = ceil(a1->value);
        result = stNUMBER;
        break;
    case fFLOOR:
	value = floor(a1->value);
        result = stNUMBER;
        break;
    case fROUND:
	value = round(a1->value);
        result = stNUMBER;
        break;
    case fFRAC:
        if (a1->value < 0) {
            value = a1->value + floor (-a1->value);
        } else {
            value = a1->value - floor (a1->value);
        }
        result = stNUMBER;
        break;
    case fABS:
        value = fabs (a1->value);
        result = stNUMBER;
        break;
    case fSIG:
        if (a1->value < 0) {
            value = -1.;
        } else if (a1->value > 0) {
            value = 1.;
        } else {
            value = 0.;
        }
        result = stNUMBER;
        break;
    case fMOD:
        value = a1->value - a2->value * (int) (a1->value / a2->value);
        result = stNUMBER;
        break;
    case fRAN:
        value = a1->value * myrand ();
        result = stNUMBER;
        break;
    case fRAN2:
        value = myrand ();
        result = stNUMBER;
        break;
    case fMIN:
        if (a1->value > a2->value) {
            value = a2->value;
        } else {
            value = a1->value;
        }
        result = stNUMBER;
        break;
    case fMAX:
        if (a1->value > a2->value) {
            value = a1->value;
        } else {
            value = a2->value;
        }
        result = stNUMBER;
        break;
    case fVAL:
        i = sscanf ((char *) a1->pointer, "%lf", &value);
        if (i != 1) {
            value = 0;
        }
        result = stNUMBER;
        break;
    case fATAN2:
        value = atan2 (a1->value, a2->value);
        result = stNUMBER;
        break;
    case fLEFT:
        str = a1->pointer;
        len = (int) a2->value;
        pointer = fromto (str, 0, len - 1);
        result = stSTRING;
        break;
    case fRIGHT:
        str = a1->pointer;
        max = strlen (str);
        len = (int) a2->value;
        pointer = fromto (str, max - len, max - 1);
        result = stSTRING;
        break;
    case fMID:
        str = a1->pointer;
        start = (int) a2->value;
        len = (int) a3->value;
        pointer = fromto (str, start - 1, start + len - 2);
        result = stSTRING;
        break;
    case fMID2:
        str = a1->pointer;
        start = (int) a2->value;
        pointer = fromto (str, start - 1, strlen (str));
        result = stSTRING;
        break;
    case fINKEY:
        pointer = inkey (a1->value);
	strcpy(last_inkey, pointer);
        result = stSTRING;
        break;
    case fAND:
        value = (unsigned int) a1->value & (unsigned int) a2->value;
        result = stNUMBER;
        break;
    case fOR:
        value = (unsigned int) a1->value | (unsigned int) a2->value;
        result = stNUMBER;
        break;
    case fEOR:
        value = (unsigned int) a1->value ^ (unsigned int) a2->value;
        result = stNUMBER;
        break;
    case fBITNOT:
        value = ~ (unsigned int) a1->value;
        result = stNUMBER;
        break;
    case fSHL:
        value = (unsigned int) a1->value << (int) a2->value;
        result = stNUMBER;
        break;
    case fSHR:
        value = (unsigned int) a1->value >> (int) a2->value;
        result = stNUMBER;
        break;
    case fMOUSEX:
        getmousexybm (a1->pointer, &i, NULL, NULL, NULL);
        value = i;
        result = stNUMBER;
        break;
    case fMOUSEY:
        getmousexybm (a1->pointer, NULL, &i, NULL, NULL);
        value = i;
        result = stNUMBER;
        break;
    case fMOUSEB:
        getmousexybm (a1->pointer, NULL, NULL, &i, NULL);
        value = i;
        result = stNUMBER;
        break;
    case fMOUSEMOD:
        getmousexybm (a1->pointer, NULL, NULL, NULL, &i);
        value = i;
        result = stNUMBER;
        break;
    case fCHR:
        pointer = my_malloc (2);
        i = (int) floor (a1->value);
        if (i > 255 || i < 0) {
            sprintf (string, "can't convert %g to character", a1->value);
            error (sERROR, string);
            return;
        }
        pointer[1] = '\0';
        pointer[0] = (unsigned char) i;
        result = stSTRING;
        break;
    case fASC:
        value = ((unsigned char *) a1->pointer)[0];
        result = stNUMBER;
        break;
    case fBIN:
        pointer = dec2other (a1->value, 2);
        result = stSTRING;
        break;
    case fHEX:
        pointer = dec2other (a1->value, 16);
        result = stSTRING;
        break;
    case fDEC:
        value = other2dec (a1->pointer, 16);
        result = stNUMBER;
        break;
    case fDEC2:
        value = other2dec (a1->pointer, (int) (a2->value));
        result = stNUMBER;
        break;
    case fUPPER:
        str = a1->pointer;
        pointer = my_malloc (strlen (str) + 1);
        i = -1;
        do {
            i++;
            pointer[i] = toupper ((int) str[i]);
        } while (pointer[i]);
        result = stSTRING;
        break;
    case fLOWER:
        str = a1->pointer;
        pointer = my_malloc (strlen (str) + 1);
        i = -1;
        do {
            i++;
            pointer[i] = tolower ((int) str[i]);
        } while (pointer[i]);
        result = stSTRING;
        break;
    case fLTRIM:
        str = a1->pointer;
        while (isspace (*str)) {
            str++;
        }
        pointer = my_strdup (str);
        result = stSTRING;
        break;
    case fRTRIM:
        str = a1->pointer;
        i = strlen (str) - 1;
        while (isspace (str[i]) && i >= 0) {
            i--;
        }
        str[i + 1] = '\0';
        pointer = my_strdup (str);
        result = stSTRING;
        break;
    case fTRIM:
        str = a1->pointer;
        i = strlen (str) - 1;
        while (isspace (str[i]) && i >= 0) {
            i--;
        }
        str[i + 1] = '\0';
        while (isspace (*str)) {
            str++;
        }
        pointer = my_strdup (str);
        result = stSTRING;
        break;
    case fINSTR:
        str = a1->pointer;
        str2 = a2->pointer;
        if (*str2) {
            pointer = strstr (str, str2);
        } else {
            pointer = NULL;
        }
        if (pointer == NULL) {
            value = 0;
        } else {
            value = pointer - str + 1;
        }
        result = stNUMBER;
        break;
    case fINSTR2:
        str = a1->pointer;
        str2 = a2->pointer;
        start = (int) a3->value;
        if (start > (int) strlen (str)) {
            value = 0;
        } else {
            if (start < 1) {
                start = 1;
            }
            pointer = strstr (str + start - 1, str2);
            if (pointer == NULL) {
                value = 0;
            } else {
                value = pointer - str + 1;
            }
        }
        result = stNUMBER;
        break;
    case fRINSTR:
        str = a1->pointer;
        str2 = a2->pointer;
        len = strlen (str2);
        for (i = strlen (str) - 1; i >= 0; i--)
            if (!strncmp (str + i, str2, len)) {
                break;
            }
        value = i + 1;
        result = stNUMBER;
        break;
    case fRINSTR2:
        str = a1->pointer;
        str2 = a2->pointer;
        len = strlen (str2);
        start = (int) a3->value;
        if (start < 1) {
            value = 0;
        } else {
            if (start > (int) strlen (str)) {
                start = strlen (str);
            }
            for (i = start - 1; i >= 0; i--)
                if (!strncmp (str + i, str2, len)) {
                    break;
                }
            value = i + 1;
        }
        result = stNUMBER;
        break;
    case fDATE:
        pointer = my_malloc (100);
        time (&datetime);
        strftime (pointer, 100, "%w-%m-%d-%Y-%a-%b", localtime (&datetime));
        result = stSTRING;
        break;
    case fTIME:
        pointer = my_malloc (100);
        time (&datetime);
        strftime (pointer, 100, "%H-%M-%S", localtime (&datetime));
        sprintf (pointer + strlen (pointer), "-%d",
                 (int) ((current_millis () - compilation_start)/1000));
        result = stSTRING;
        break;
    case fSYSTEM:
        str = a1->pointer;
        value = do_system (str);
        result = stNUMBER;
        break;
    case fSYSTEM2:
        str = a1->pointer;
        pointer = do_system2 (str);
        result = stSTRING;
        break;
    case fFRNFN_CALL:
	frnfn_call (type, &value, &pointer);
        result = stNUMBER;
        break;
    case fFRNFN_CALL2:
	frnfn_call (type, &value, &pointer);
        result = stSTRING;
        break;
    case fFRNBF_ALLOC:
	pointer = frnbf_alloc ();
        result = stSTRING;
        break;
    case fFRNBF_SIZE:
	value = frnbf_size ();
	result = stNUMBER;
        break;
    case fFRNBF_DUMP:
    case fFRNBF_DUMP2:
	pointer = frnbf_dump (type);
        result = stSTRING;
        break;
    case fFRNFN_SIZE:
	value = frnfn_size ();
        result = stNUMBER;
        break;
    case fFRNBF_GET_NUMBER:
	value = frnbf_get ();
        result = stNUMBER;
        break;
    case fFRNBF_GET_STRING:
	pointer = frnbf_get2 ();
        result = stSTRING;
        break;
    case fFRNBF_GET_BUFFER:
	pointer = frnbf_get_buffer ();
        result = stSTRING;
        break;
    case fPEEK:
        str = a1->pointer;
        value = peek (str);
        result = stNUMBER;
        break;
    case fPEEK2:
        str = a1->pointer;
        pointer = peek2 (str, current);
        result = stSTRING;
        break;
    case fPEEK3:
        str = a1->pointer;
        str2 = a2->pointer;
        pointer = peek3 (str, str2);
        result = stSTRING;
        break;
    case fPEEK4:
        value = peekfile ((int) a1->value);
        result = stNUMBER;
        break;
    case fGETBIT:
        pointer =
            getbit ((int) a1->value, (int) a2->value, (int) a3->value,
                    (int) a4->value);
        result = stSTRING;
        break;
    case fGETCHAR:
        pointer =
            getchars ((int) a1->value, (int) a2->value, (int) a3->value,
                      (int) a4->value);
        result = stSTRING;
        break;
    case fTELL:
        i = (int) (a1->value);
        if (badstream (i, 0)) {
            return;
        }
        if (!(stream_modes[i] & (mREAD | mWRITE))) {
            sprintf (string, "stream %d not opened", i);
            error (sERROR, string);
            value = 0;
        } else {
            value = ftell (streams[i]);
        }
        result = stNUMBER;
        break;
    default:
        error (sERROR, "function called but not implemented");
        return;
    }

    stack = push ();
    /* copy result */
    stack->type = result;
    if (result == stSTRING) {
        stack->pointer = pointer;
    } else {
        stack->value = value;
    }
}


static int
do_system (char *cmd)		/* hand over execution of command to system, return exit code */
{
#ifdef UNIX
    int ret;
    if (curinized) {
        reset_shell_mode ();
    }
    ret = system (cmd);
    if (curinized) {
        if (tcsetpgrp(STDIN_FILENO, getpid())) {
	    sprintf(string,"could not get control of terminal: %s",
		    my_strerror(errno));
	    error (sERROR,string);
	    return ret;
	}
	reset_prog_mode ();
    }

    return ret;
#else
    STARTUPINFO start;
    PROCESS_INFORMATION proc;
    DWORD ec;			/* exit code */
    SECURITY_ATTRIBUTES prosec;
    SECURITY_ATTRIBUTES thrsec;
    char *comspec;

    ZeroMemory (&prosec, sizeof (prosec));
    prosec.nLength = sizeof (prosec);
    prosec.bInheritHandle = TRUE;
    ZeroMemory (&thrsec, sizeof (thrsec));
    thrsec.nLength = sizeof (thrsec);
    thrsec.bInheritHandle = TRUE;
    ZeroMemory (&start, sizeof (start));
    start.cb = sizeof (STARTUPINFO);
    start.dwFlags = STARTF_USESTDHANDLES;
    start.hStdOutput = GetStdHandle (STD_OUTPUT_HANDLE);
    start.hStdError = GetStdHandle (STD_ERROR_HANDLE);
    start.hStdInput = GetStdHandle (STD_INPUT_HANDLE);
    comspec = getenv ("COMSPEC");
    if (!comspec) {
        comspec = "command.com";
    }
    sprintf (string, "%s /C %s", comspec, cmd);
    if (!CreateProcess (NULL, string, &prosec, &thrsec, TRUE, 0,
                        NULL, NULL, &start, &proc)) {
        sprintf (string, "couldn't execute '%s'", cmd);
        error (sERROR, string);
        return -1;
    }
    WaitForSingleObject (proc.hProcess, INFINITE);
    if (!GetExitCodeProcess (proc.hProcess, &ec)) {
        ec = -1;
    }
    CloseHandle (proc.hProcess);
    CloseHandle (proc.hThread);
    return ec;
#endif
}


static double
myrand ()
{
    long ran;
	
    ran = (((long) rand ()) & 0x7fffL) << 15 | ((long) rand () & 0x7fffL);

    return ((double) ran) / ((double) 0x3fffffffL);
}


static void
clear_buff ()			/* clear system-input buffers */
{
    buffcurr = &buffroot;
    buffcount = 0;
}


static void
store_buff (char *buff, int len)	/* store system-input buffer */
{
    *buffcurr = my_malloc (sizeof (struct buff_chain));
    memcpy ((*buffcurr)->buff, buff, PIPEBUFFLEN + 1);
    (*buffcurr)->len = len;
    (*buffcurr)->next = NULL;
    buffcurr = &((*buffcurr)->next);
    buffcount++;
}


char *
recall_buff ()			/* recall store buffer */
{
    struct buff_chain *curr, *old;
    char *result;
    int done, len;

    result = (char *) my_malloc (buffcount * (PIPEBUFFLEN + 1));
    curr = buffroot;
    len = 0;
    for (done = 0; done < buffcount && curr; done++) {
        memcpy (result + len, curr->buff, PIPEBUFFLEN);
        len += curr->len;
        old = curr;
        curr = curr->next;
        my_free (old);
    }
    return result;
}


static char *
do_system2 (char *cmd)		/* hand over execution of command to system, return output as string */
{
    static char buff[PIPEBUFFLEN + 1];	/* buffer to store command */
    int len;			/* number of bytes read */
#ifdef UNIX
    FILE *p;			/* points to pipe */
    int c;			/* char read from pipe */
#else
    int ret;
    STARTUPINFO start;
    PROCESS_INFORMATION proc;
    HANDLE piperead, pipewrite;	/* both ends of pipes */
    SECURITY_ATTRIBUTES prosec;
    SECURITY_ATTRIBUTES thrsec;
    char *comspec;
#endif

    clear_buff ();

#ifdef UNIX
    p = popen (cmd, "r");
    if (p == NULL) {
        sprintf (string, "couldn't execute '%s'", cmd);
        error (sERROR, string);
        return my_strdup ("");
    }
    do {
        len = 0;
        while (len < PIPEBUFFLEN) {
            c = fgetc (p);
            if (c == EOF) {
                buff[len] = '\0';
                break;
            }
            buff[len] = c;
            len++;
        }
        store_buff (buff, len);
    } while (c != EOF);
    pclose (p);
#else
    ZeroMemory (&prosec, sizeof (prosec));
    prosec.nLength = sizeof (prosec);
    prosec.bInheritHandle = TRUE;
    ZeroMemory (&thrsec, sizeof (thrsec));
    thrsec.nLength = sizeof (thrsec);
    thrsec.bInheritHandle = TRUE;

    /* create pipe for writing */
    CreatePipe (&piperead, &pipewrite, &prosec, 0);

    ZeroMemory (&start, sizeof (start));
    start.cb = sizeof (STARTUPINFO);
    start.dwFlags = STARTF_USESTDHANDLES;
    start.hStdOutput = pipewrite;
    start.hStdError = pipewrite;
    start.hStdInput = GetStdHandle (STD_INPUT_HANDLE);

    comspec = getenv ("COMSPEC");
    if (!comspec) {
        comspec = "command.com";
    }
    sprintf (string, "%s /C %s", comspec, cmd);
    if (!CreateProcess (NULL, string, &prosec, &thrsec, TRUE, 0,
                        NULL, NULL, &start, &proc)) {
        sprintf (string, "couldn't execute '%s'", cmd);
        error (sERROR, string);
        return my_strdup ("");
    }
    CloseHandle (pipewrite);

    do {
        /* wait for output to arrive */
        if (!ReadFile (piperead, buff, PIPEBUFFLEN, (LPDWORD) & len, NULL)) {
            ret = GetLastError ();
        } else {
            ret = 0;
        }
        buff[len] = '\0';
        if (len > 0) {
            store_buff (buff, len);
        }
    } while (ret != ERROR_BROKEN_PIPE && ret != ERROR_HANDLE_EOF);
    CloseHandle (piperead);
    CloseHandle (proc.hProcess);
    CloseHandle (proc.hThread);
#endif
    return recall_buff ();
}


void
getmousexybm (char *s, int *px, int *py, int *pb, int *pm)	/* get mouse coordinates */
{
    int x = 0, y = 0, b = 0, m = 0;
    char c;

    if (!*s) s=last_inkey;
    if (*s) {
        sscanf (s, "MB%d%c+%d:%04d,%04d", &b, &c, &m, &x, &y);
        if (px) {
            *px = x;
        }
        if (py) {
            *py = y;
        }
        if (pb) {
            if (c == 'd') {
                *pb = b;
            } else {
                *pb = -b;
            }
        }
        if (pm) {
            *pm = m;
        }
        return;
    }
    if (px) {
        *px = mousex;
    }
    if (py) {
        *py = mousey;
    }
    if (pb) {
        *pb = mouseb;
    }
    if (pm) {
        *pm = mousemod;
    }
}


static char *
dec2other (double d, int base)	/* convert double to hex or binary number */
{
    int len;
    double dec, dec2;
    char *other;
    int negative = FALSE;

    if (d < 0) {
        dec2 = floor (-d);
        negative = TRUE;
    } else {
        dec2 = floor (d);
    }
    len = negative ? 2 : 1;
    for (dec = dec2; dec >= base; dec /= base) {
        len++;
    }
    other = my_malloc (len + 1);
    other[len] = '\0';
    dec = dec2;
    for (len--; len >= 0; len--) {
        other[len] =
            "0123456789abcdef"[(int)
                               (floor
                                (dec - base * floor (dec / base) + 0.5))];
        dec = floor (dec / base);
    }
    if (negative) {
        other[0] = '-';
    }
    return other;
}


static double
other2dec (char *hex, int base)	/* convert hex or binary to double number */
{
    double dec;
    static char *digits = "0123456789abcdef";
    char *found;
    int i, len;

    if (base != 2 && base != 16) {
        sprintf (string, "Cannot convert base-%d numbers", base);
        error (sERROR, string);
        return 0.;
    }
    dec = 0;
    len = strlen (hex);
    for (i = 0; i < len; i++) {
        dec *= base;
        found = strchr (digits, tolower (hex[i]));
        if (!found || found - digits >= base) {
            sprintf (string, "Not a base-%d number: '%s'", base, hex);
            error (sERROR, string);
            return 0.;
        }
        dec += found - digits;
    }
    return dec;
}


int
myformat (char *dest, int max, double num, char *format, char *sep)	/* format number according to string */
{
    int ret = myformat2 (dest, max, num, format, sep);
    if (ret == 0) return TRUE;
    if (ret == 1) sprintf (estring, "'%s' is not a valid format", format);
    if (ret == 2) sprintf (estring, "length of formatted string exceeds maximum of %d bytes", INBUFFLEN);
    error (sERROR, estring);
    return FALSE;
}


int
myformat2 (char *dest, int max, double num, char *format, char *sep)	/* do the work for myformat */
{
    static char *ctrl = "+- #0";	/* allowed control chars for c-format */
    char formchar;
    char *found, *form;
    int pre, post, len, nread, digit, commas, dots, i, cr;
    int neg = FALSE;
    double ipdbl, fp, round;
    unsigned long ip;
    static char *digits = "0123456789";

    form = format;
    if (*form == '%') {
        /* c-style format */
        form++;
        while ((found = strchr (ctrl, *form)) != NULL) form++;
        if (sscanf (form, "%*u.%*u%c%n", &formchar, &nread) != 1 &&
	    sscanf (form, "%*u.%c%n", &formchar, &nread) != 1 &&
	    sscanf (form, ".%*u%c%n", &formchar, &nread) != 1 &&
	    sscanf (form, "%*u%c%n", &formchar, &nread) != 1 &&
	    sscanf (form, "%c%n", &formchar, &nread) != 1) {
            return 1;
        }
        if (!strchr ("feEgG", formchar) || form[nread]) {
            return 1;
        }
        /* seems okay, let's try to print */
        len = snprintf (dest, max, format, num);
	if (len >= max) {
	    return 2;
	}
    } else {
        /* basic-style format */

	/* make num positive and remember if it has been negative initially */
        if (num < 0) {
            neg = TRUE;
            num = fabs (num);
        }

	/* verify form of ##.###.###,## (e.g.) up front to be able to rely on this; 
	   also count various parts */
        commas = 0;
        dots = 0;
        pre = 0;
        post = 0;
        for (form = format; *form; form++) {
            if (*form == ',') {
                if (dots) {
		    /* commas in fractional part are not supported */
                    return 1; 
                }
                commas++;
            } else if (*form == '.') {
		if (dots) {
		    /* format has more than one decimal dot */
		    return 1;
		}
                dots++;
            } else if (*form == '#') {
                if (dots) {
                    post++;
                } else {
                    pre++;
                }
            } else {
		/* neither '#' nor '.' nor ',' */
                return 1;
            }
        }

	/* prepare destination */
        len = strlen (format);
        dest[len] = '\0';

	/* round to given precision; round away from zero */
        round = 0.5;
        for (i = 0; i < post; i++) {
            round /= 10.;
        }
	/* if number is below round offset, treat it as zero */
        if (num < round) {
            neg = FALSE;
	    num = 0.0;
	} else {
	    /* do the rounding away from zero */
	    num += round;
	}

	/* because we cast to long we cannot cope with numbers larger than its max */
	/* not casting to long on the other hand leads to frequent arithmetic errors */
        if (num > LONG_MAX) {
            strcpy (dest, format);
            return 0;
        }

	/* disassemble in integer and fractional part; both ip and fp will be consumed stepwise in the process */
	fp = modf(num, &ipdbl);
	ip = (unsigned long) ipdbl;
	
	/* variable cr serves as our cursor running from right to left and marks the position to be written next */
	
	/* write integer part */
	cr = pre + commas - 1;
	do {
	    if (format[cr] == '#') {
		/* get digit and reduce integer part */
		digit = ip % 10;
		ip = ip/10;
		dest[cr--] = digits[digit];
	    } else {
		/* format[cr] == ','; i.e. we do not need a new digit */
		dest[cr--] = ip ? ',' : ' ';
	    }
	} while (ip && cr >= 0);

	/* given format does not have enough room, this is an error; just copy format into dest and return */
        if ((neg && cr < 0) || ip) {
            strcpy (dest, format);
            return 0;
        }

	/* minus if appropriate */
        if (neg) {
            dest[cr--] = '-';
        }
	
	/* fill from cursor position back to start */
        while (cr >= 0) {
            dest[cr--] = ' ';
        }

	/* cursor cr now runs from left to right */
	
	/* do we need to write a fractional part ? */
	cr = pre + commas;
	if (dots) {
	    /* write decimal dot */
	    dest[cr++] = '.';
	    /* construct fractional part digit by digit */
	    while (cr < len) {
		fp *= 10;
		digit = ((unsigned long) fp) % 10;
		dest[cr++] = digits[digit];
	    }
	} else {
	    /* no fractional part needed */
	    dest[cr++] = '\0';
	}

	/* until now we used fixed separators ',' for thousands and '.' for decimal; but if
	   user has given his own separators (e.g. german or swiss style) we need to correct this */
        if (sep) {
	    if (sep[0] && sep[1]) {
		for (i = 0; i < len; i++) {
		    if (dest[i] == ',') {
			dest[i++] = sep[0];
		    }
		    if (dest[i] == '.') {
			dest[i++] = sep[1];
		    }
		}
	    } else {
		return 1;
	    }
        }
    }
    return 0;
}


static char *
fromto (char *str, int from, int to)	/* gives back portion of string */
/* from and to can be in the range 1...strlen(str) */
{
    int len, i;
    char *part;

    len = strlen (str);
    if (from > to || to < 0 || from > len - 1) {
        /* give back empty string */
        part = my_malloc (1);
        part[0] = '\0';
    } else {
        if (from <= 0) {
            from = 0;
        }
        if (to >= len) {
            to = len - 1;
        }
        part = my_malloc (sizeof (char) * (to - from + 2));	/* characters and '/0' */
        for (i = from; i <= to; i++) {
            part[i - from] = str[i];    /* copy */
        }
        part[i - from] = '\0';
    }
    return part;
}



void
mywait ()			/* wait given number of seconds */
{
    double delay;

#ifdef UNIX
    struct timeval tv;
#else
    MSG msg;
    int timerid;
#endif

    delay = pop (stNUMBER)->value;
    if (delay < 0) {
        delay = 0.;
    }
#ifdef UNIX
    tv.tv_sec = (long) delay;
    tv.tv_usec = (delay - (long) delay) * 1000000;
    select (0, NULL, NULL, NULL, &tv);
#else /* WINDOWS */
    timerid = SetTimer (NULL, 0, (int) (delay * 1000), (TIMERPROC) NULL);
    GetMessage ((LPMSG) & msg, NULL, WM_TIMER, WM_TIMER);
    KillTimer (NULL, timerid);
#endif
}


void
mybell ()			/* ring ascii bell */
{
#ifdef UNIX
    printf ("\007");
    fflush (stdout);
#else /* WINDOWS */
    Beep (1000, 100);
#endif
}



void
create_poke (char flag)		/* create Command 'cPOKE' */
{
    struct command *cmd;

    if (flag == 'S' || flag == 'D') {
        cmd = add_command (cPOKEFILE, FALSE, NULL);
    } else {
        cmd = add_command (cPOKE, FALSE, NULL);
    }
    cmd->tag = flag;
}


void
poke (struct command *cmd)	/* poke into internals */
{
    char *dest, *s, c;
    char *string_arg = NULL;
    double double_arg;
    struct stackentry *stack;
    int count;

    if (cmd->tag == 's') {
        string_arg = pop (stSTRING)->pointer;
    } else {
        double_arg = pop (stNUMBER)->value;
    }

    dest = pop (stSTRING)->pointer;
    for (s = dest; *s; s++) {
        *s = tolower ((int) *s);
    }
    if (!strcmp (dest, "fontheight") && !string_arg) {
        fontheight = (int) double_arg;
#ifdef UNIX
        calc_psscale ();
#endif
    } else if (!strcmp (dest, "font") && string_arg) {
        fontname = my_strdup (string_arg);
    } else if (!strcmp (dest, "dump") && string_arg) {
        dump_commands (string_arg);
    } else if (!strcmp (dest, "dump") && string_arg && !strcmp (string_arg, "symbols")) {
        dump_sym ();
    } else if (!strcmp (dest, "dump") && string_arg &&
               (!strcmp (string_arg, "sub") || !strcmp (string_arg, "subs")
                || !strcmp (string_arg, "subroutine")
                || !strcmp (string_arg, "subroutines"))) {
        dump_sub (0);
    } else if (!strcmp (dest, "textalign") && string_arg) {
        if (!check_alignment (string_arg)) {
            return;
        }
        strncpy (text_align, string_arg, 2);
    } else if (!strcmp (dest, "windoworigin") && string_arg) {
        moveorigin (string_arg);
    } else if (!strcmp (dest, "infolevel") && string_arg) {
        c = tolower ((int) *string_arg);
        switch (c) {
        case 'd':
            severity_threshold = sDEBUG;
            break;
        case 'n':
            severity_threshold = sNOTE;
            break;
        case 'w':
            severity_threshold = sWARNING;
            break;
        case 'e':
            severity_threshold = sERROR;
            break;
        case 'f':
            severity_threshold = sFATAL;
            break;
        default:
            error (sERROR, "invalid infolevel");
            return;
        }
        if (severity_threshold <= sDEBUG) {
            sprintf (string, "switching infolevel to '%c'", c);
            error (sDEBUG, string);
        }
    } else if (!strcmp (dest, "stdout") && string_arg) {
        fputs (string_arg, stdout);
    } else if (!strcmp (dest, "random_seed") && !string_arg) {
        srand((unsigned int) double_arg);
    } else if (!strcmp (dest, "__assert_stack_size") && !string_arg) {
	count = -1;
	stack = stackhead;
	while ( stack != stackroot) {
	    count++;
	    stack = stack->prev;
	}
	if (count != (int) double_arg) {
	    sprintf (string, "assertion failed for number of entries on stack; expected = %d, actual = %d",(int) double_arg,count);
	    error (sFATAL, string);
	}
    } else if (dest[0] == '#') {
        error (sERROR, "don't use quotes when poking into file");
    } else {
	sprintf(string,"invalid poke: '%s'",dest);
        error (sERROR, string);
    }
    return;
}


void
pokefile (struct command *cmd)	/* poke into file */
{
    char *sarg = NULL;
    double darg;
    int stream;

    if (cmd->tag == 'S') {
        sarg = pop (stSTRING)->pointer;
    } else {
        darg = pop (stNUMBER)->value;
    }
    stream = (int) (pop (stNUMBER)->value);

    if (badstream (stream, 0)) {
        return;
    }

    if (!(stream_modes[stream] & mWRITE)) {
        sprintf (string, "Stream %d not open for writing", stream);
        error (sERROR, string);
        return;
    }
    if (sarg) {
        fputs (sarg, streams[stream]);
    } else {
        if (darg < 0 || darg > 255) {
            error (sERROR, "stream poke out of byte range (0..255)");
            return;
        }
        fputc ((int) darg, streams[stream]);
    }
}


static double
peek (char *dest)		/* peek into internals */
{
    char *s;
    time_t now;

    for (s = dest; *s; s++) {
        *s = tolower ((int) *s);
    }
    if (!strcmp (dest, "winwidth")) {
        return winwidth;
    } else if (!strcmp (dest, "winheight")) {
        return winheight;
    } else if (!strcmp (dest, "fontheight")) {
        return fontheight;
    } else if (!strcmp (dest, "screenheight")) {
        return LINES;
    } else if (!strcmp (dest, "screenwidth")) {
        return COLS;
    } else if (!strcmp (dest, "argument") || !strcmp (dest, "arguments")) {
        return yabargc;
    } else if (!strcmp (dest, "version")) {
        return strtod (VERSION, NULL);
    } else if (!strcmp (dest, "error")) {
        return errorcode;
    } else if (!strcmp (dest, "isbound")) {
        return is_bound;
    } else if (!strcmp (dest, "last_foreign_function_call_okay") || !strcmp (dest, "last_frnfn_call_okay")) {
        return (double) last_frnfn_call_okay;
    } else if (!strcmp (dest, "secondsrunning")) {
	return (double)((current_millis () - compilation_start)/1000);
    } else if (!strcmp (dest, "millisrunning")) {
	return (double)(current_millis () - compilation_start);
    } else if (dest[0] == '#') {
        error (sERROR, "don't use quotes when peeking into a file");
        return 0;
    }

    error (sERROR, "invalid peek");
    return 0;
}


static int
peekfile (int stream)		/* read a byte from stream */
{
    if (stream && badstream (stream, 0)) {
        return 0;
    }
    if (stream && !(stream_modes[stream] & mREAD)) {
        sprintf (string, "stream %d not open for reading", stream);
        error (sERROR, string);
        return 0;
    }
    return fgetc (stream ? streams[stream] : stdin);
}


static char *
peek2 (char *dest, struct command *curr)	/* peek into internals */
{
    char *s;

    for (s = dest; *s; s++) {
        *s = tolower ((int) *s);
    }
    if (!strcmp (dest, "infolevel")) {
        if (severity_threshold == sDEBUG) {
            return my_strdup ("debug");
        } else if (severity_threshold == sNOTE) {
            return my_strdup ("note");
        } else if (severity_threshold == sWARNING) {
            return my_strdup ("warning");
        } else if (severity_threshold == sERROR) {
            return my_strdup ("error");
        } else if (severity_threshold == sFATAL) {
            return my_strdup ("fatal");
        } else {
            return my_strdup ("unknown");
        }
    } else if (!strcmp (dest, "textalign")) {
        return my_strdup (text_align);
    } else if (!strcmp (dest, "windoworigin")) {
        return my_strdup (winorigin);
    } else if (!strcmp (dest, "error")) {
        return my_strdup (estring);
    } else if (!strcmp (dest, "program_file_name")) {
        return my_strdup(main_file_name);
    } else if (!strcmp (dest, "program_name")) {
        return my_strdup(progname);
    } else if (!strcmp (dest, "interpreter_path")) {
	return my_strdup(inter_path);
    } else if (!strcmp (dest, "library")) {
        return my_strdup (curr->lib->short_name);
    } else if (!strcmp (dest, "version")) {
        return my_strdup (PACKAGE_VERSION);
    } else if (!strcmp (dest, "os")) {
#ifdef UNIX
        return my_strdup ("unix");
#else
        return my_strdup ("windows");
#endif
    } else if (!strcmp (dest, "font")) {
        return my_strdup (fontname);
    } else if (!strcmp (dest, "last_foreign_function_call_error_text") || !strcmp (dest, "last_frnfn_call_error_text")) {
	return my_strdup (last_frnfn_call_error_text);
    } else if (!strcmp (dest, "argument") || !strcmp (dest, "arguments")) {
        if (yabargc > 0) {
            s = yabargv[0];
            yabargc--;
            yabargv++;
        } else {
            s = "";
        }
        return my_strdup (s);
    } else {
        error (sERROR, "invalid peek");
    }
    return my_strdup ("");
}


static char *
peek3 (char *dest, char *cont)	/* peek into internals */
{
    char *s;

    for (s = dest; *s; s++) {
        *s = tolower ((int) *s);
    }
    if (!strcmp (dest, "env") || !strcmp (dest, "environment")) {
        return my_strdup (getenv (cont));
    } else {
        error (sERROR, "invalid peek");
    }
    return my_strdup ("");
}


void
create_exception (int flag)	/* create command 'exception' */
{
    struct command *cmd;

    cmd = add_command (cEXCEPTION, FALSE, NULL);
    cmd->args = flag;
}


void
exception (struct command *cmd)	/* change handling of exceptions */
{
    if (cmd->args) {
        signal (SIGINT, signal_handler);	/* enable keyboard interrupt */
#ifdef SIGHUP
        signal (SIGHUP, signal_handler);
#endif
#ifdef SIGQUIT
        signal (SIGQUIT, signal_handler);
#endif
#ifdef SIGABRT
        signal (SIGABRT, signal_handler);
#endif
#ifdef SIGTERM
        signal (SIGTERM, signal_handler);
#endif
    } else {
        signal (SIGINT, SIG_IGN);	/* ignore keyboard interrupt */
#ifdef SIGHUP
        signal (SIGHUP, SIG_IGN);
#endif
#ifdef SIGQUIT
        signal (SIGQUIT, SIG_IGN);
#endif
#ifdef SIGABRT
        signal (SIGABRT, SIG_IGN);
#endif
#ifdef SIGTERM
        signal (SIGTERM, SIG_IGN);
#endif
    }
    return;
}


long long current_millis() {  /* return current number of milliseconds */
#ifdef WINDOWS
    return GetTickCount();
#else
    struct timespec tsnow;
    clock_gettime(CLOCK_MONOTONIC, &tsnow);
    return tsnow.tv_sec*1000LL + tsnow.tv_nsec/1000000LL;
#endif
}


void
create_restore (char *label)	/* create command 'restore' */
{
    struct command *c;

    c = add_command (cRESTORE, FALSE, label);
    c->pointer = my_strdup (label);
}


void
restore (struct command *cmd)	/* reset data pointer to given label */
{
    struct command *label;
    struct command **datapointer;

    datapointer = &(cmd->lib->datapointer);
    if (cmd->type == cRESTORE) {
        /* first time; got to search the label */
        if (*((char *) cmd->pointer) == '\0') {
            /* no label, restore to first command */
            label = cmd->lib->firstdata;
        } else {
            label = search_label (cmd->pointer, srmLABEL | srmGLOBAL);
            if (!label) {
                /* did not find label */
                sprintf (string, "can't find label '%s'",
                         (char *) cmd->pointer);
                error (sERROR, string);
                return;
            }
        }
        *datapointer = label;
        if (lastdata) {
            while ((*datapointer)->type != cDATA
                    && (*datapointer) != cmdhead) {
                *datapointer = (*datapointer)->next;
            }
        }
        cmd->pointer = *datapointer;
        cmd->type = cQRESTORE;
    } else {
        *datapointer = cmd->pointer;
    }
    return;
}


void
create_dbldata (double value)	/* create command dbldata */
{
    struct command *c;

    c = add_command (cDATA, FALSE, NULL);
    c->pointer = my_malloc (sizeof (double));
    if (lastdata) {
        lastdata->nextassoc = c;
    }
    lastdata = c;
    *((double *) c->pointer) = value;
    c->tag = 'd';			/* double value */
}


void
create_strdata (char *value)	/* create command strdata */
{
    struct command *c;

    c = add_command (cDATA, FALSE, NULL);
    if (lastdata) {
        lastdata->nextassoc = c;
    }
    lastdata = c;
    c->pointer = my_strdup (value);
    c->tag = 's';			/* string value */
}


void
create_readdata (char type)	/* create command readdata */
{
    struct command *cmd;

    cmd = add_command (cREADDATA, FALSE, NULL);
    cmd->tag = type;
}


void
readdata (struct command *cmd)	/* read data items */
{
    struct stackentry *read;
    char type;
    struct command **datapointer;

    datapointer = &(cmd->lib->datapointer);
    type = cmd->tag;
    while (*datapointer
            && ((*datapointer)->type != cDATA
                || cmd->lib != (*datapointer)->lib)) {
        *datapointer = (*datapointer)->nextassoc;
    }
    if (!*datapointer) {
        error (sERROR, "run out of data items");
        return;
    }
    if (type != (*datapointer)->tag) {
        error (sERROR, "type of READ and DATA don't match");
        return;
    }
    read = push ();
    if (type == 'd') {
        /* read a double value */
        read->type = stNUMBER;
        read->value = *((double *) (*datapointer)->pointer);
    } else {
        read->type = stSTRING;
        read->pointer = my_strdup ((*datapointer)->pointer);
    }
    *datapointer = (*datapointer)->nextassoc;	/* next item */
}


void
create_dblrelop (char c)	/* create command dblrelop */
{
    int type;

    switch (c) {
    case '=':
        type = cEQ;
        break;
    case '!':
        type = cNE;
        break;
    case '<':
        type = cLT;
        break;
    case '{':
        type = cLE;
        break;
    case '>':
        type = cGT;
        break;
    case '}':
        type = cGE;
        break;
    }
    add_command (type, FALSE, NULL);
}


void
dblrelop (struct command *type)	/* compare topmost double-values */
{
    double a, b, c;
    struct stackentry *result;

    b = pop (stNUMBER)->value;
    a = pop (stNUMBER)->value;
    switch (current->type) {
    case cEQ:
        c = (a == b);
        break;
    case cNE:
        c = (a != b);
        break;
    case cLE:
        c = (a <= b);
        break;
    case cLT:
        c = (a < b);
        break;
    case cGE:
        c = (a >= b);
        break;
    case cGT:
        c = (a > b);
        break;
    }
    result = push ();
    result->value = c;
    result->type = stNUMBER;
}


void
create_strrelop (char c)	/* create command strrelop */
{
    int type;

    switch (c) {
    case '=':
        type = cSTREQ;
        break;
    case '!':
        type = cSTRNE;
        break;
    case '<':
        type = cSTRLT;
        break;
    case '{':
        type = cSTRLE;
        break;
    case '>':
        type = cSTRGT;
        break;
    case '}':
        type = cSTRGE;
        break;
    }
    add_command (type, FALSE, NULL);
}


void
strrelop (struct command *type)	/* compare topmost string-values */
{
    char *a, *b;
    double c;
    struct stackentry *result;

    b = pop (stSTRING)->pointer;
    a = pop (stSTRING)->pointer;
    switch (current->type) {
    case cSTREQ:
        c = (strcmp (a, b) == 0);
        break;
    case cSTRNE:
        c = (strcmp (a, b) != 0);
        break;
    case cSTRLT:
        c = (strcmp (a, b) < 0);
        break;
    case cSTRLE:
        c = (strcmp (a, b) <= 0);
        break;
    case cSTRGT:
        c = (strcmp (a, b) > 0);
        break;
    case cSTRGE:
        c = (strcmp (a, b) >= 0);
        break;
    }
    result = push ();
    result->value = c;
    result->type = stNUMBER;
}

void
switch_compare (void)		/* compare topmost values for switch statement */
{
    struct stackentry *result, *first, *second;
    double r = 0.;
    
    first = pop (stANY);
    second = stackhead->prev;

    /* stSWITCH_STRING and stSWITCH_NUMBER compare true to any string or number */
    if ((second->type == stSWITCH_STRING || second->type == stSTRING)
	&& first->type == stSTRING) {
	if (second->type == stSWITCH_STRING) {
	    r = 1.;
	} else {
	    r = (strcmp (first->pointer, second->pointer) == 0) ? 1. : 0.;
	}
    } else if ((second->type == stSWITCH_NUMBER || second->type == stNUMBER)
	       && first->type == stNUMBER) {
	if (second->type == stSWITCH_NUMBER) {
	    r = 1.;
	} else {
	    r = (first->value == second->value) ? 1. : 0.;
	}
    } else {
	error (sERROR,
	       "mixing strings and numbers in a single switch statement is not allowed");
    }

    /* if comparison was successful once, remember this for all future comparisons */
    if (r == 1.) {
	if (second->type == stNUMBER) second->type=stSWITCH_NUMBER;
	if (second->type == stSTRING) second->type=stSWITCH_STRING;
    }

    result = push ();
    result->type = stNUMBER;
    result->value = r;
}


void
logical_shortcut (struct command *type)	/* shortcut and/or if possible */
{
    struct stackentry *result;
    double is;

    is = stackhead->prev->value;
    if ((type->type == cORSHORT && is != 0)
            || (type->type == cANDSHORT && is == 0)) {
        result = push ();
        error (sDEBUG, "logical shortcut taken");
        result->type = stNUMBER;
        result->value = is;
    } else {
        current = current->next;
    }
}


void
create_boole (char c)		/* create command boole */
{
    int type;

    switch (c) {
    case '|':
        type = cOR;
        break;
    case '&':
        type = cAND;
        break;
    case '!':
        type = cNOT;
        break;
    }
    add_command (type, FALSE, NULL);
}


void
boole (struct command *type)	/* perform and/or/not */
{
    int a, b, c;
    struct stackentry *result;

    a = (int) pop (stNUMBER)->value;
    if (current->type == cNOT) {
        c = !a;
    } else {
        b = (int) pop (stNUMBER)->value;
        if (current->type == cAND) {
            c = a && b;
        } else {
            c = a || b;
        }
    }
    result = push ();
    result->value = c;
    result->type = stNUMBER;
}
