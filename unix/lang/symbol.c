/*

    YABASIC ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2017
    more info at www.yabasic.de

    symbol.c --- code for symbol, stack and library management, handling of arrays

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
extern int switch_nesting;
extern int switch_id;

/* ------------- local functions ---------------- */

static struct symbol *create_symbol (int, char *);	/* create a new symbol */
static void stackdesc (int, char *);	/* give back string describing stackentry */
static void freesym (struct symbol *);	/* free contents of symbol */
static int ind_to_off (int *, int *);	/* convert array of indices to single offset */
static void off_to_ind (int, int *, int *);	/* convert a single offset to an array of indices */


/* ------------- global variables ---------------- */

static struct symstack *symroot = NULL;	/* first element in symbol list */
static struct symstack *symhead = NULL;	/* last element ind symbol list */
struct stackentry *stackroot;	/* lowest element in stack */
struct stackentry *stackhead;	/* topmost element in stack */
extern char *current_function;	/* name of currently defined function */
struct command *lastref;	/* last command in UDS referencing a symbol */
struct command *firstref;	/* first command in UDS referencing a symbol */
int labelcount = 0;		/* count self-generated labels */


/* ------------- subroutines ---------------- */


void
pushsymlist (void)		/* push a new list of symbols on symbol stack */
{
    struct symstack *new;

    new = my_malloc (sizeof (struct symstack));
    if (symhead) {
        symhead->next_in_stack = new;
    } else {
        symroot = new;    /* first time called */
    }
    new->prev_in_stack = symhead;
    new->next_in_stack = NULL;
    new->next_in_list = NULL;
    symhead = new;
}


void
popsymlist (void)		/* pop list of symbols and free symbol contents */
{
    struct symstack *prevstack;
    struct symbol *currsym, *nextsym;
    int count = 0;

    currsym = symhead->next_in_list;
    while (currsym) {
        /* loop through symbol list */
        freesym (currsym);
        count++;
        nextsym = currsym->next_in_list;
        my_free (currsym);
        currsym = nextsym;
    }
    if (infolevel >= DEBUG) {
        sprintf (string, "removed symbol list with %d symbols", count);
        error (DEBUG, string);
    }
    prevstack = symhead->prev_in_stack;
    my_free (symhead);
    prevstack->next_in_stack = NULL;
    symhead = prevstack;
}


static void
freesym (struct symbol *s)	/* free contents of symbol */
{
    int i;
    int total;

    struct array *ar;
    if (s->link) {
        /* it's a link, don't remove memory */
        sprintf (string, "removing linked symbol '%s'", s->name);
        error (DEBUG, string);
        my_free (s->name);
        return;
    }
    if (s->type == sySTRING) {
        if (infolevel >= DEBUG) {
            sprintf (string, "removing string symbol '%s'", s->name);
            error (DEBUG, string);
        }
        my_free (s->pointer);
    } else if (s->type == syARRAY) {
        if (infolevel >= DEBUG) {
            sprintf (string, "removing array symbol '%s()'", s->name);
            error (DEBUG, string);
        }
        ar = s->pointer;
        if (ar->dimension > 0) {
            /* count total amount of memory */
            total = 1;
            for (i = 0; i < ar->dimension; i++) {
                total *= (ar->bounds)[i];
            }
            if (ar->type == 's') {
                /* string array */
                for (i = 0; i < total; i++) {
                    my_free (*((char **) ar->pointer + i));
                }
            }
            my_free (ar->pointer);
        }
        my_free (ar);
    } else if (s->type == syNUMBER) {
        if (infolevel >= DEBUG) {
            sprintf (string, "removing numeric symbol '%s'", s->name);
            error (DEBUG, string);
        }
    }
    my_free (s->name);
    return;
}


void
clearrefs (struct command *cmd)	/* clear references for commands within function */
{
    struct command *curr;
    int n = 0;

    curr = cmd->nextref;
    while (curr) {
        n++;
        curr->symbol = NULL;
        curr = curr->nextref;
    }
    sprintf (string, "removed references from %d symbols", n);
    error (DEBUG, string);
}


struct symbol *
get_sym (char *name, int type, int add)
/* get the value of a symbol, or create it with given type */
{
    struct symstack *currstack;
    struct symbol **currsym;
    struct symbol *prelink;
    struct symbol *new;
    int stackcount = 0;
    int symbolcount = 0;
    int linked = FALSE;

    if (!name) {
        return NULL;
    }
    /* go through all lists */
    currstack = symhead;		/* start with symhead */
    if (add == amSEARCH_PRE && symhead->prev_in_stack) {
        currstack = symhead->prev_in_stack;
    }
    while (TRUE) {
        stackcount++;
        currsym = &(currstack->next_in_list);
        while (*currsym) {
            prelink = *currsym;
            symbolcount++;
            if ((*currsym)->type == type && !strcmp (name, (*currsym)->name)) {
                /* do the types and names match ? */
                if ((*currsym)->link) {
                    currsym = &((*currsym)->link);
                    linked = TRUE;
                }
                if (infolevel >= DEBUG) {
                    if (linked)
                        sprintf (string,
                                 "found symbol '%s%s', linked to %s after searching %d symbol(s) in %d stack(s)",
                                 name, (type == syARRAY) ? "()" : "",
                                 (*currsym)->name, symbolcount, stackcount);
                    else
                        sprintf (string,
                                 "found symbol '%s%s' after searching %d symbol(s) in %d stack(s)",
                                 name, (type == syARRAY) ? "()" : "",
                                 symbolcount, stackcount);
                    error (DEBUG, string);
                }
                return *currsym;	/* give back address */
            }
            currsym = &((*currsym)->next_in_list);	/* try next entry */
        }
        /* not found in first list */
        if (add == amSEARCH_VERY_LOCAL) {
            return NULL;
        }
        if (add == amADD_LOCAL) {
            new = create_symbol (type, name);
            (*currsym) = new;
            if (infolevel >= DEBUG) {
                sprintf (string, "created local symbol %s%s", name,
                         (type == syARRAY) ? "()" : "");
                error (DEBUG, string);
            }
            return new;
        }
        if (currstack != symroot) {
            currstack = symroot;
        } else {
            break;
        }
    }
    if (add == amADD_GLOBAL) {
        new = create_symbol (type, name);
        (*currsym) = new;
        if (infolevel >= DEBUG) {
            sprintf (string, "created global symbol %s%s", name,
                     (type == syARRAY) ? "()" : "");
            error (DEBUG, string);
        }
        return new;
    }
    return NULL;
}


void
link_symbols (struct symbol *from, struct symbol *to)
{
    /* link one symbol to the other */
    from->link = to;
    if (infolevel >= DEBUG) {
        sprintf (string, "linking symbol '%s' to '%s'", from->name,
                 to->name);
        error (DEBUG, string);
    }
}


void
dump_sym (void)			/* dump the stack of lists of symbols */
{
    struct symstack *currstack;
    struct symbol **currsym;

    /* go through all lists */
    error (DUMP, "head of symbol stack");
    currstack = symhead;
    while (currstack) {
        /* search 'til last element of stack */
        currsym = &(currstack->next_in_list);
        string[0] = '\0';
        while (*currsym) {
            switch ((*currsym)->type) {
            case sySTRING:
                strcat (string, " STRING:");
                break;
            case syNUMBER:
                strcat (string, " NUMBER:");
                break;
            case syFREE:
                strcat (string, " FREE:");
                break;
            case syARRAY:
                strcat (string, " ARRAY:");
                break;
            default:
                sprintf (string, " UNKNOWN:");
                break;
            }
            strcat (string, (*currsym)->name);

            currsym = &((*currsym)->next_in_list);	/* try next entry */
        }
        error (DUMP, string);
        currstack = currstack->prev_in_stack;
    }
    error (DUMP, "root of symbol stack");
    return;
}


static struct symbol *
create_symbol (int type, char *name)  	/* create a new symbol */
{
    struct symbol *new;

    new = my_malloc (sizeof (struct symbol));
    new->type = type;
    new->next_in_list = NULL;
    new->name = my_strdup (name);
    new->pointer = NULL;
    new->args = NULL;
    new->value = 0.0;
    new->link = NULL;

    return new;
}


void
swap ()				/* swap topmost elements on stack */
{
    struct stackentry *a, *b;

    if ((a = stackhead->prev) == NULL || (b = a->prev) == NULL) {
        error (ERROR, "Nothing to swap on stack !");
        return;
    }
    a->prev = b->prev;
    b->next = a->next;		/* just swap the pointers */
    a->next = b;
    b->prev = a;
    stackhead->prev = b;
    (a->prev)->next = a;
}


struct stackentry *
push ()
/* push element on stack and enlarge stack it */
{
    struct stackentry *new;

    if (!stackhead->next) {
        /* no next element */
        /* create new element */
        new = (struct stackentry *) my_malloc (sizeof (struct stackentry));
        /* and initialize it */
        new->next = NULL;
        new->value = 0.0;
        new->type = stFREE;
        new->prev = stackhead;
        new->pointer = NULL;
        stackhead->next = new;
    } else if (stackhead->pointer != NULL
               && (stackhead->type == stSTRING
                   || stackhead->type == stSTRINGARRAYREF
                   || stackhead->type == stNUMBERARRAYREF
                   || stackhead->type == stLABEL)) {
        /* any content is set free */
        my_free (stackhead->pointer);
        stackhead->pointer = NULL;
    }
    stackhead = stackhead->next;	/* advance head */
    return stackhead->prev;
}


struct stackentry *
pop (int etype)
/* pops element to memory and looks for pop-error */
{
    static char expected[50];
    static char found[50];
    int ftype;
    struct stackentry *s;

    /* test if there is something on the stack */
    if (stackhead == stackroot) error (FATAL, "Popped too much.");
    stackhead = stackhead->prev;	/* move down in stack */
    ftype = stackhead->type;
    if (etype == ftype || etype == stANY ||
            (etype == stSTRING_OR_NUMBER
             && (ftype == stNUMBER || ftype == stSWITCH_NUMBER || ftype == stSTRING || ftype == stSWITCH_STRING))
            || (etype == stSTRING_OR_NUMBER_ARRAYREF
                && (ftype == stSTRINGARRAYREF || ftype == stNUMBERARRAYREF))
	|| (etype == stSTRING && ftype == stSWITCH_STRING)
	|| (etype == stNUMBER && ftype == stSWITCH_NUMBER)) {
        return stackhead;    /* this is your value; use it quickly ! */
    }

    /* expected and found don't match */
    stackdesc (etype, expected);
    stackdesc (ftype, found);
    sprintf (string, "expected '%s' but found '%s'", expected, found);
    if (etype == stNUMBER || etype == stSTRING
            || etype == stSTRING_OR_NUMBER) {
        s = push ();
        if (etype == stNUMBER) {
            s->type = stNUMBER;
            s->value = 0.0;
        } else {
            s->type = stSTRING;
            s->pointer = my_strdup ("");
        }
        error (ERROR, string);
        return s;
    } else {
        error (FATAL, string);
    }
    return stackhead;
}


static void
stackdesc (int type, char *desc)	/* give back string describing stackentry */
{
    switch (type) {
    case stGOTO:
        strcpy (desc, "a goto");
        break;
    case stSTRING:
        strcpy (desc, "a string");
        break;
    case stSTRINGARRAYREF:
        strcpy (desc, "a reference to a string array");
        break;
    case stNUMBER:
        strcpy (desc, "a number");
        break;
    case stNUMBERARRAYREF:
        strcpy (desc, "a reference to a numeric array");
        break;
    case stLABEL:
        strcpy (desc, "a label");
        break;
    case stRET_ADDR:
        strcpy (desc, "a return address for gosub");
        break;
    case stRET_ADDR_CALL:
        strcpy (desc, "a return address for a subroutine");
        break;
    case stFREE:
        strcpy (desc, "nothing");
        break;
    case stROOT:
        strcpy (desc, "the root of the stack");
        break;
    case stANY:
        strcpy (desc, "anything");
        break;
    case stSTRING_OR_NUMBER:
        strcpy (desc, "a string or a number");
        break;
    case stSTRING_OR_NUMBER_ARRAYREF:
        strcpy (desc, "reference to a string or an array");
        break;
    case stSWITCH_STRING:
        strcpy (desc, "string for switch");
        break;
    case stSWITCH_NUMBER:
        strcpy (desc, "number for switch");
        break;
    default:
        sprintf (desc, "type %d", type);
        break;
    }
}


void
pushname (char *name)		/* bison: push a name on stack */
{
    struct stackentry *s;

    s = push ();
    s->pointer = my_strdup (name);
    s->type = stSTRING;
}


void
pushlabel ()			/* bison: generate goto and push label on stack */
{
    char *st;
    struct stackentry *en;

    st = (char *) my_malloc (sizeof (char) * 20);
    sprintf (st, "***%d", labelcount);
    labelcount++;
    create_goto (st);
    en = push ();
    en->type = stLABEL;
    en->pointer = st;
}


void
poplabel ()			/* bison: pops a label and generates the matching command */
{
    create_label (pop (stLABEL)->pointer, cLABEL);	/* and create it */
}


void
pushgoto ()			/* bison: generate label and push goto on stack */
{
    char *st;
    struct stackentry *en;

    st = (char *) my_malloc (sizeof (char) * 20);
    sprintf (st, "***%d", labelcount);
    labelcount++;
    create_label (st, cLABEL);
    en = push ();
    en->type = stGOTO;
    en->pointer = st;
}


void
popgoto ()			/* bison: pops a goto and generates the matching command */
{
    create_goto (pop (stGOTO)->pointer);	/* and create it */
}


void
storelabel ()			/* bison: push label on stack */
{
    char *st;
    struct stackentry *en;

    st = (char *) my_malloc (sizeof (char) * 20);
    sprintf (st, "***%d", labelcount);
    labelcount++;
    en = push ();
    en->type = stLABEL;
    en->pointer = st;
}


void
matchgoto ()			/* bison: generate goto matching label on stack */
{
    create_goto (stackhead->prev->pointer);
}


void
create_pushdbl (double value)	/* create command 'cPUSHDBL' */
{
    struct command *cmd;

    cmd = add_command (cPUSHDBL, NULL, NULL);
    cmd->pointer = my_malloc (sizeof (double));
    *(double *) (cmd->pointer) = value;
}


void
pushdbl (struct command *cmd)
{
    /* push double onto stack */
    struct stackentry *p;

    p = push ();
    p->value = *(double *) cmd->pointer;
    p->type = stNUMBER;
}


void
pushdblsym (struct command *cmd)
{
    /* push double symbol onto stack */
    struct stackentry *p;

    p = push ();
    if (!cmd->symname) {
        error (WARNING, "invalid pushdblsym");
    }

    if (!cmd->symbol) {
        cmd->symbol = &(get_sym (cmd->symname, syNUMBER, amADD_GLOBAL)->value);
    } else if (infolevel >= DEBUG) {
    	sprintf(string, "reading symbol '%s'", cmd->symname);
	error (DEBUG, string);
    }

    p->value = *(double *) cmd->symbol;
    p->type = stNUMBER;
}


void
popdblsym (struct command *cmd)	/* pop double from stack */
{
    double d;

    d = pop (stNUMBER)->value;
    if (!cmd->symbol) {
        cmd->symbol = &(get_sym (cmd->symname, syNUMBER, amADD_GLOBAL)->value);
    } else if (infolevel >= DEBUG) {
	sprintf(string, "writing symbol '%s'", cmd->symname);
	error (DEBUG, string);
    }
	
    *(double *) (cmd->symbol) = d;
}


void
create_makestatic (char *name, int type)	/* create command 'cMAKESTATIC' */
{
    struct command *cmd;

    cmd = add_command (cMAKESTATIC, name, NULL);
    cmd->args = type;
}


void
makestatic (struct command *cmd)	/* makes symbol static */
{
    struct symbol *l, *g;
    char *at = NULL;


    /* mask function name */
    if ((at = strchr (cmd->symname, '@')) != NULL) {
        *at = '\0';
    }

    if (get_sym (cmd->symname, cmd->args, amSEARCH_VERY_LOCAL)) {
        sprintf (string,
                 "static variable '%s' already defined within this subroutine",
                 strip (cmd->symname));
        error (ERROR, string);
        return;
    }

    /* create global variable with unique name */
    if (at) {
        *at = '@';
    }
    g = get_sym (cmd->symname, cmd->args, amADD_GLOBAL);
    if (at) {
        *at = '\0';
    }

    /* create local variable */
    l = get_sym (cmd->symname, cmd->args, amADD_LOCAL);
    if (at) {
        *at = '@';
    }
    /* link those two together */
    link_symbols (l, g);
}


void
create_arraylink (char *name, int type)	/* create command 'cARRAYLINK' */
{
    struct command *cmd;

    cmd = add_command (cARRAYLINK, name, NULL);
    cmd->pointer = current_function;
    cmd->args = type;
}


void
arraylink (struct command *cmd)	/* link a local symbol to a global array */
{
    struct symbol *l, *g;
    struct array *ar;

    if (get_sym (cmd->symname, cmd->args, amSEARCH_VERY_LOCAL)) {
        sprintf (string, "'%s()' already defined within this subroutine",
                 strip (cmd->symname));
        error (ERROR, string);
        return;
    }
    /* get globally defined array */
    g = get_sym (pop (cmd->args)->pointer, syARRAY, amSEARCH_PRE);
    /* create local array */
    l = get_sym (cmd->symname, syARRAY, amADD_LOCAL);
    if (!l) {
        return;
    }
    if (!g || !g->pointer) {
        /* no global array supplied, create one */
        error (DEBUG, "creating dummy array");
        ar = create_array ((cmd->args == stNUMBERARRAYREF) ? 'd' : 's', 0);
        l->pointer = ar;
        if (infolevel >= DEBUG) {
            sprintf (string, "creating 0-dimensional dummy array '%s()'",
                     cmd->symname);
            error (DEBUG, string);
        }
    } else {
        /* link those two together */
        link_symbols (l, g);
    }
}


void
create_pusharrayref (char *name, int type)	/* create command 'cPUSHARRAYREF' */
{
    struct command *cmd;

    cmd = add_command (cPUSHARRAYREF, name, NULL);
    cmd->args = type;
}


void
pusharrayref (struct command *cmd)	/* push an array reference onto stack */
{
    struct stackentry *s;
    s = push ();
    s->type = cmd->args;
    s->pointer = my_strdup (cmd->symname);
}


void
create_require (int type)	/* create command 'cREQUIRE' */
{
    struct command *cmd;

    cmd = add_command (cREQUIRE, NULL, NULL);
    cmd->args = type;
}


void
require (struct command *cmd)	/* check, that item on stack has right type */
{
    char *expected, *supplied;
    struct stackentry *s;

    if (stackhead->prev->type == cmd->args) {
        return;    /* okay, they match */
    }

    if (stackhead->prev->type == stFREE) {
        /* no argument supplied, create it */
        s = push ();
        if (cmd->args == stSTRING) {
            s->type = stSTRING;
            s->pointer = my_strdup ("");
            return;
        } else if (cmd->args == stNUMBER) {
            s->type = stNUMBER;
            s->value = 0.0;
            return;
        } else {
            /* create array */
            s->type = cmd->args;
            s->pointer = NULL;
            return;
        }
    }

    s = stackhead->prev;
    if (s->type == stSTRING) {
        supplied = "string";
    } else if (s->type == stNUMBER) {
        supplied = "number";
    } else if (s->type == stSTRINGARRAYREF) {
        supplied = "string array";
    } else if (s->type == stNUMBERARRAYREF) {
        supplied = "numeric array";
    } else if (s->type == stFREE) {
        supplied = "nothing";
    } else {
        supplied = "something strange";
    }

    if (cmd->args == stSTRING) {
        expected = "string";
    } else if (cmd->args == stNUMBER) {
        expected = "number";
    } else if (cmd->args == stSTRINGARRAYREF) {
        expected = "string array";
    } else if (cmd->args == stNUMBERARRAYREF) {
        expected = "numeric array";
    } else if (cmd->args == stFREE) {
        expected = "nothing";
    } else {
        expected = "something strange";
    }

    sprintf (string, "invalid subroutine call: %s expected, %s supplied",
             expected, supplied);
    error (ERROR, string);
}


void
create_dblbin (char c)		/* create command for binary double operation */
{
    switch (c) {
    case '+':
        add_command (cDBLADD, NULL, NULL);
        break;
    case '-':
        add_command (cDBLMIN, NULL, NULL);
        break;
    case '*':
        add_command (cDBLMUL, NULL, NULL);
        break;
    case '/':
        add_command (cDBLDIV, NULL, NULL);
        break;
    case '^':
        add_command (cDBLPOW, NULL, NULL);
        break;
    }
    /* no specific information needed */
}


void
dblbin (struct command *cmd)	/* compute with two numbers from stack */
{
    struct stackentry *d;
    double a, b, c;

    b = pop (stNUMBER)->value;
    a = pop (stNUMBER)->value;
    d = push ();
    switch (cmd->type) {
    case (cDBLADD):
        c = a + b;
        break;
    case (cDBLMIN):
        c = a - b;
        break;
    case (cDBLMUL):
        c = a * b;
        break;
    case (cDBLDIV):
        if (fabs (b) < DBL_MIN) {
            sprintf (string, "Division by zero, set to %g", DBL_MAX);
            error (NOTE, string);
            c = DBL_MAX;
        } else {
            c = a / b;
        }
        break;
    case (cDBLPOW):
        if ((a == 0 && b <= 0) || (a < 0 && b != (int) b)) {
            error (ERROR, "result is not a real number");
            return;
        } else {
            c = pow (a, b);
        }
        break;
    }
    d->value = c;
    d->type = stNUMBER;
}


void
negate ()			/* negates top of stack */
{
    stackhead->prev->value = -stackhead->prev->value;
}


void
pushstrptr (struct command *cmd)	/* push string-pointer onto stack */
{
    struct stackentry *p;

    p = push ();
    if (!cmd->symbol) {
        cmd->symbol = &(get_sym (cmd->symname, sySTRING, amADD_GLOBAL)->pointer);
    }
    p->pointer = *(char **) cmd->symbol;
    if (!p->pointer) {
        p->pointer = my_strdup ("");
    }
    p->type = stSTRING;
}


void
pushstrsym (struct command *cmd)	/* push string-symbol onto stack */
{
    struct stackentry *p;

    p = push ();
    if (!cmd->symbol) {
        cmd->symbol = &(get_sym (cmd->symname, sySTRING, amADD_GLOBAL)->pointer);
    }
    p->pointer = my_strdup (*(char **) cmd->symbol);
    p->type = stSTRING;
}


void
popstrsym (struct command *cmd)	/* pop string from stack */
{
    if (!cmd->symname) {
        return;
    }
    if (!cmd->symbol) {
        cmd->symbol = &(get_sym (cmd->symname, sySTRING, amADD_GLOBAL)->pointer);
    }
    if (*(char **) cmd->symbol != NULL) {
        my_free (*(char **) cmd->symbol);
    }
    *(char **) cmd->symbol = my_strdup (pop (stSTRING)->pointer);
}


void
create_pushstr (char *s)	/* creates command pushstr */
{
    struct command *cmd;

    cmd = add_command (cPUSHSTR, NULL, s);
    cmd->pointer = my_strdup (s);	/* store string */
}


void
pushstr (struct command *cmd)
{
    /* push string onto stack */
    struct stackentry *p;

    p = push ();
    p->pointer = my_strdup ((char *) cmd->pointer);
    p->type = stSTRING;
}


void
duplicate (void)		/* duplicate topmost number on stack */
{
    struct stackentry *s;
    double actual;

    actual = stackhead->prev->value;
    s = push ();
    s->type = stNUMBER;
    s->value = actual;
}


void
create_dim (char *name, char type)	/* create command 'dim' */
/* type can be 's'=string or 'd'=double Array */
{
    struct command *cmd;

    cmd = add_command (cDIM, name, name);
    cmd->tag = type;		/* type: string or double */
    cmd->args = -1;
}


void
dim (struct command *cmd)	/* get room for array */
{
    struct array *nar, *oar;
    char *nul;
    int ntotal, ototal, esize, i, j;
    int ind[10], nbounds[10], larger;
    struct symbol *s;
    int local;

    local = ((cmd->tag == tolower (cmd->tag)) ? TRUE : FALSE);
    if (cmd->args < 0) {
        cmd->args = count_args (FALSE);
    }
    if (cmd->args < 0) {
        error (ERROR, "only numerical indices allowed for arrays");
        return;
    }
    s = get_sym (cmd->symname, syARRAY, local ? amADD_LOCAL : amADD_GLOBAL);
    if (search_label (cmd->symname, srmSUBR | srmLINK)) {
        sprintf (string, "array '%s()' conflicts with user subroutine",
                 strip (cmd->symname));
        error (ERROR, string);
        return;
    }

    /* check for dimensions */
    if (cmd->args > 10) {
        error (ERROR, "more than 10 indices");
        return;
    }
    oar = s->pointer;
    if (oar) {
        /* check, if old and new array are compatible */
        if (cmd->args != oar->dimension) {
            sprintf (string,
                     "cannot change dimension of '%s()' from %d to %d",
                     strip (cmd->symname), oar->dimension, cmd->args);
            error (ERROR, string);
        }
    }
    /* check, if redim is actually needed */
    for (i = 0; i < 10; i++) {
        nbounds[i] = 0;
    }
    larger = FALSE;
    for (i = 0; i < cmd->args; i++) {
        nbounds[i] = 1 + (int) pop (stNUMBER)->value;
        if (nbounds[i] <= 1) {
            sprintf (string, "array index %d is less or equal zero",
                     cmd->args - i);
            error (ERROR, string);
            return;
        }
        if (oar) {
            if (nbounds[i] > oar->bounds[i]) {
                larger = TRUE;
            } else {
                nbounds[i] = oar->bounds[i];
            }
        }
    }
    pop (stFREE);			/* remove left over stFREE */
    if (oar && !larger) {
        return;    /* new array won't be larger than old one */
    }

    /* create array */
    nar = create_array (tolower (cmd->tag), cmd->args);

    /* count needed memory */
    ntotal = 1;
    for (i = 0; i < nar->dimension; i++) {
        (nar->bounds)[i] = nbounds[i];
        ntotal *= nbounds[i];
    }
    esize = (nar->type == 's') ? sizeof (char *) : sizeof (double);	/* size of one array element */
    nar->pointer = my_malloc (ntotal * esize);

    if (oar) {
        /* array already exists, get its size */
        ototal = 1;
        for (i = 0; i < oar->dimension; i++) {
            ototal *= (oar->bounds)[i];
        }
    }

    /* initialize Array */
    for (i = 0; i < ntotal; i++) {
        if (nar->type == 's') {
            nul = my_malloc (sizeof (char));
            *nul = '\0';
            ((char **) nar->pointer)[i] = nul;
        } else {
            ((double *) nar->pointer)[i] = 0.0;
        }
    }

    if (oar) {
        /* copy contents of old array onto new */
        for (i = 0; i < ototal; i++) {
            off_to_ind (i, oar->bounds, ind);
            j = ind_to_off (ind, nar->bounds);
            if (nar->type == 's') {
                my_free (((char **) nar->pointer)[j]);
                ((char **) nar->pointer)[j] = ((char **) oar->pointer)[i];
            } else {
                ((double *) nar->pointer)[j] = ((double *) oar->pointer)[i];
            }
        }
        my_free (oar->pointer);
        my_free (oar);
    }

    s->pointer = nar;
    cmd->symbol = nar;
}


static int
ind_to_off (int *ind, int *bound)	/* convert array of indices to single offset */
{
    int i;
    int cur, off;

    off = 0;
    cur = 1;
    for (i = 0; i < 10 && bound[i]; i++) {
        off += ind[i] * cur;
        cur *= bound[i];
    }
    return off;
}


static void
off_to_ind (int off, int *bound, int *ind)	/* convert a single offset to an array of indices */
{
    int i;
    int cur;

    cur = 1;
    for (i = 0; i < 10; i++) {
        if (bound[i]) {
            cur *= bound[i];
        }
        ind[i] = 0;
    }
    for (i = 9; i >= 0; i--) {
        if (bound[i]) {
            cur /= bound[i];
            ind[i] = off / cur;
            off -= ind[i] * cur;
        } else {
            ind[i] = 0;
        }
    }
}


void
query_array (struct command *cmd)	/* get value from array */
{
    int index;
    struct stackentry *s;
    struct array *ar;
    struct symbol *sym;

    if (cmd->type == cARSIZE) {
        index = (int) pop (stNUMBER)->value;
    }

    s = pop (stSTRING_OR_NUMBER_ARRAYREF);

    if (!cmd->symbol) {
        sym = get_sym (s->pointer, syARRAY, amSEARCH);
        if (!sym || !sym->pointer) {
            sprintf (string, "array '%s()' is not defined",
                     strip (s->pointer));
            error (ERROR, string);
            return;
        }
        cmd->symbol = sym;
    }

    ar = ((struct symbol *) cmd->symbol)->pointer;

    if (cmd->type == cARSIZE && (index < 1 || index > ar->dimension)) {
        sprintf (string, "only indices between 1 and %d allowed",
                 ar->dimension);
        error (ERROR, string);
        return;
    }
    s = push ();
    s->type = stNUMBER;
    if (cmd->type == cARSIZE) {
        s->value = ar->bounds[ar->dimension - index] - 1;
    } else {
        s->value = ar->dimension;
    }

    return;
}


void
create_doarray (char *symbol, int command)	/* creates array-commands */
{
    struct command *cmd;

    cmd = add_command (cDOARRAY, symbol, symbol);
    cmd->tag = command;		/* operation to perform */
    cmd->args = -1;
}


void
doarray (struct command *cmd)	/* call an array */
{
    struct array *ar;
    struct stackentry *stack;
    struct symbol *sym;
    void *p;
    char **str;
    double *dbl;
    int i, j, bnd, index, cur, rval;


    if (!cmd->symbol) {
        sym = get_sym (cmd->symname, syARRAY, amSEARCH);
        if (!sym || !sym->pointer) {
            sprintf (string, "'%s()' is neither array nor subroutine",
                     strip (cmd->symname));
            error (ERROR, string);
            return;
        }
        cmd->symbol = sym;
    }
    rval = (current->tag == CALLARRAY || current->tag == CALLSTRINGARRAY
            || current->tag == GETSTRINGPOINTER);
    if (cmd->args < 0) {
        cmd->args = count_args (!rval);
    }
    if (cmd->args < 0) {
        error (ERROR, "only numerical indices allowed for arrays");
        return;
    }
    cmd->args = abs (cmd->args);
    if (!cmd->args) {
        /* no indizes supplied, create a reference to an array */
        pop (stFREE);		/* remove left over stFREE */
        stack = push ();
        if (cmd->tag == CALLARRAY) {
            stack->type = stNUMBERARRAYREF;
        } else {
            stack->type = stSTRINGARRAYREF;
        }
        stack->pointer = my_strdup (cmd->symname);
        return;
    }

    ar = ((struct symbol *) cmd->symbol)->pointer;

    if (!ar->dimension) {
        sprintf (string, "array parameter '%s()' has not been supplied",
                 strip (cmd->symname));
        error (ERROR, string);
        return;
    }
    if (cmd->args != ar->dimension) {
        sprintf (string, "%d indices supplied, %d expected for '%s()'",
                 cmd->args, ar->dimension, strip (cmd->symname));
        error (ERROR, string);
        return;
    }

    if (!rval) {
        stack = pop (stSTRING_OR_NUMBER);
    }
    index = 0;
    cur = 1;
    for (i = 0; i < ar->dimension; i++) {
        bnd = (ar->bounds[i]);
        j = (int) pop (stNUMBER)->value;
        if (j < 0 || j >= bnd) {
            sprintf (string, "index %d (=%d) out of range",
                     ar->dimension - i, j);
            error (ERROR, string);
            return;
        }
        index += j * cur;
        cur *= bnd;
    }

    pop (stFREE);			/* remove left over stFREE */
    if (rval) {
        stack = push ();
    }

    p = ar->pointer;
    switch (current->tag) {
    case CALLARRAY:
        dbl = (double *) p + index;
        stack->value = *dbl;
        stack->type = stNUMBER;
        break;
    case ASSIGNARRAY:
        dbl = (double *) p + index;
        *dbl = stack->value;
        break;
    case CALLSTRINGARRAY:
        str = ((char **) p + index);
        stack->pointer = my_strdup (*str);
        stack->type = stSTRING;
        break;
    case ASSIGNSTRINGARRAY:
        str = ((char **) p + index);
        if (*str != NULL) {
            my_free (*str);
        }
        *str = my_strdup (stack->pointer);
        break;
    case GETSTRINGPOINTER:
        str = ((char **) p + index);
        stack->pointer = *str;
        stack->type = stSTRING;
        break;
    }
}


struct array *
create_array (int type, int dimension)  	/* create an array */
{
    int i;
    struct array *ar;

    ar = my_malloc (sizeof (struct array));
    ar->type = type;
    ar->dimension = dimension;
    ar->pointer = NULL;
    for (i = 0; i < 10; i++) {
        ar->bounds[i] = 0;
    }

    return ar;
}


int
count_args (int skipfirst)	/* count number of numeric arguments on stack */
{
    int i = 0;
    int sign = 1;
    struct stackentry *curr;

    curr = stackhead->prev;
    if (skipfirst) {
        curr = curr->prev;
    }
    while (curr) {
        if (curr->type == stFREE) {
            return i * sign;
        }
        if (curr->type != stNUMBER) {
            sign = -1;
        }
        curr = curr->prev;
        i++;
    }
    return -1;
}


