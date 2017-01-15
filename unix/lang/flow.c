/*

    YABASIC ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2017
    more info at www.yabasic.de

    flow.c --- code for subroutines and flow-control

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



/* ------------- global variables ---------------- */
static struct command *labelroot = NULL;	/* first label among commands */
static struct command *labelhead = NULL;	/* last label seen so far */


/* ------------- subroutines ---------------- */

void
create_retval (int is, int should)	/* create command 'cRETVAL' */
{
    struct command *cmd;

    cmd = add_command (cRETVAL, NULL, NULL);
    cmd->args = is;
    cmd->tag = should;
}


void
retval (struct command *cmd)	/* check return value of function */
{
    int is, should;
    struct stackentry *s;

    is = cmd->args;
    should = cmd->tag;
    if (is == should) {
        /* okay, function returns expected type */
    } else if (is == ftNONE) {
        /* no element on stack, create one */
        s = push ();
        if (should == ftNUMBER) {
            s->type = stNUMBER;
            s->value = 0.0;
        } else {
            s->type = stSTRING;
            s->pointer = my_strdup ("");
        }
    } else {
        sprintf (string, "subroutine returns %s but should return %s",
                 (is == ftSTRING) ? "a string" : "a number",
                 (should == ftSTRING) ? "a string" : "a number");
        error (ERROR, string);
    }
    if (infolevel >= DEBUG) {
        s = stackhead->prev;
        if (s->type == stNUMBER) {
            sprintf (string, "subroutine returns number %g", s->value);
        } else if (s->type == stSTRING)
            sprintf (string, "subroutine returns string '%s'",
                     (char *) s->pointer);
        else
            sprintf (string, "subroutine returns something strange (%d)",
                     s->type);
        error (DEBUG, string);
    }
    swap ();
}


void
create_endfunction (void)	/* create command cEND_FUNCTION */
{
    struct command *cmd;

    cmd = add_command (cEND_FUNCTION, NULL, NULL);
    link_label (cmd);
}


void
function_or_array (struct command *cmd)	/* decide whether to perform function or array */
{
    struct command *fu;

    fu = search_label (cmd->symname, smSUB | smLINK);
    if (fu) {
        cmd->type = cCALL;
        cmd->pointer = cmd->symname;
        cmd->symname = NULL;
	if (infolevel >= DEBUG) {
	    sprintf(errorstring, "converting '%s' to '%s'",explanation[cFUNCTION_OR_ARRAY],explanation[cFUNCTION]);
	    error(DEBUG, errorstring);
	}
    } else {
        if (cmd->type == cFUNCTION_OR_ARRAY) {
            cmd->tag = CALLARRAY;
        } else {
            cmd->tag = CALLSTRINGARRAY;
        }
        cmd->type = cDOARRAY;
        cmd->args = -1;
	if (infolevel >= DEBUG) {
	    sprintf(errorstring, "converting '%s' to '%s'",explanation[cFUNCTION_OR_ARRAY],explanation[cDOARRAY]);
	    error(DEBUG, errorstring);
	}
    }
}


void
create_makelocal (char *name, int type)	/* create command 'cMAKELOCAL' */
{
    struct command *cmd;

    cmd = add_command (cMAKELOCAL, name, NULL);
    cmd->args = type;
}


void
makelocal (struct command *cmd)	/* makes symbol local */
{
    if (get_sym (cmd->symname, cmd->args, amSEARCH_VERY_LOCAL)) {
        sprintf (string,
                 "local variable '%s' already defined within this subroutine",
                 strip (cmd->symname));
        error (ERROR, string);
        return;
    }
    get_sym (cmd->symname, cmd->args, amADD_LOCAL);
}


void
create_numparam (void)		/* create command 'cNUMPARAM' */
{
    struct command *cmd;

    /* dotifying numparams at compiletime (as opposed to runtime) is essential,
       because the function name is not known at runtime */
    cmd = add_command (cNUMPARAM, dotify ("numparams", FALSE), NULL);
}


void
numparam (struct command *cmd)	/* count number of function parameters */
{
    struct symbol *sym;

    sym = get_sym (cmd->symname, syNUMBER, amADD_LOCAL);
    sym->value = abs (count_args (FALSE));
}


void
dump_sub (int short_dump)	/* dump the stack of subroutine calls */
{
    struct stackentry *st = stackhead;
    struct command *cmd;
    int first = TRUE;
    do {
        if (st->type == stRETADDCALL) {
            cmd = st->pointer;
            if (cmd->type == cCALL || cmd->type == cQCALL) {
                char *dot;
                dot = strchr (cmd->pointer, '.');
                if (first && !short_dump) {
                    error (DUMP, "Executing in:");
                }
                sprintf (string, "sub %s() called in %s,%d",
                         dot ? (dot + 1) : (char *) cmd->pointer, cmd->lib->l,
                         cmd->line);
                error (DUMP, string);
                first = FALSE;
            }
        }
        st = st->prev;
    } while (st && st != stackroot);
    if (first && !short_dump) {
        if (!short_dump) {
            error (DUMP, "Executing in:");
        }
    }
    if (!short_dump) {
        error (DUMP, "main program");
    }

    return;
}


void
create_goto (char *label)	/* creates command goto */
{
    struct command *cmd;

    cmd = add_command (cGOTO, NULL, label);
    cmd->pointer = my_strdup (label);
    add_switch_state(cmd);
}


void
create_gosub (char *label)	/* creates command gosub */
{
    struct command *cmd;

    cmd = add_command (cGOSUB, NULL, label);
    /* specific info */
    cmd->pointer = my_strdup (label);
}


void
create_call (char *label)	/* creates command function call */
{
    struct command *cmd;

    cmd = add_command (cCALL, NULL, label);
    /* specific info */
    cmd->pointer = my_strdup (label);
}

struct command *
add_switch_state(struct command *cmd) /* add switch state to a newly created command */
{
    cmd->switch_state = my_malloc (sizeof (struct switch_state));
    cmd->switch_state->id = switch_id;
    cmd->switch_state->nesting = switch_nesting;
    cmd;
}

void
link_label (struct command *cmd)	/* link label into list of labels */
{
    if (!labelroot) {
        labelroot = cmd;
    } else {
        labelhead->nextassoc = cmd;
    }
    labelhead = cmd;
}


struct command *
search_label (char *name, int type)  	/* search label */
{
    struct command *curr;
    char *at = NULL;

    curr = labelroot;
    if (type & smGLOBAL) {
        at = strchr (name, '@');
        if (at) *at = '\0';
    }
    while (curr) {
        if ((type & smSUB) && curr->type == cUSER_FUNCTION
                && !strcmp (curr->pointer, name)) {
            if (at) *at = '@';
            return curr;
        }
        if ((type & smLINK) && curr->type == cSUBLINK
                && !strcmp (curr->pointer, name)) {
            if (at) *at = '@';
            return curr->next;
        }
        if ((type & smLABEL) && curr->type == cLABEL
                && !strcmp (curr->pointer, name)) {
            if (at) *at = '@';
            return curr;
        }
        curr = curr->nextassoc;
    }
    return NULL;
}


void
jump (struct command *cmd)
/* jump to specific Label; used as goto, gosub or function call */
{
    struct command *label;
    struct stackentry *ret;
    int type;
    char *dot;

    type = cmd->type;
    if (type == cGOSUB || type == cQGOSUB || type == cCALL || type == cQCALL) {
        /* leave return address for return */
        ret = push ();
        ret->pointer = current;
        if (type == cGOSUB || type == cQGOSUB) {
            ret->type = stRETADD;
        } else {
            ret->type = stRETADDCALL;
            reshuffle_stack_for_call (ret);
        }
    }

    if (type == cQGOSUB || type == cQGOTO || type == cQCALL) {
        current = (struct command *) cmd->jump;	/* use remembered address */
        return;
    }
    label = search_label (cmd->pointer, smSUB | smLINK | smLABEL);
    if (!label && type == cCALL && (dot = strchr (cmd->pointer, '.'))) {
        strcpy (string, "main");
        strcat (string, dot);
        label = search_label (string, smLINK);
    }
    if (label) {
        /* found right label */
        current = label;		/* jump to new location */
        /* use the address instead of the name next time */
        cmd->jump = label;
        switch (cmd->type) {
        case cGOTO:
            cmd->type = cQGOTO;
            break;
        case cGOSUB:
            cmd->type = cQGOSUB;
            break;
        case cCALL:
            cmd->type = cQCALL;
            break;
        }
    } else {
        /* label not found */
        sprintf (string, "can't find %s '%s'",
                 (type == cCALL) ? "subroutine" : "label",
                 strip ((char *) cmd->pointer));
        if (strchr (cmd->pointer, '@')) {
            strcat (string, " (not in this sub)");
        }
        error (ERROR, string);
    }
    if (cmd->type == cQGOTO ) {
	check_leave_switch ("GOTO", cmd, label);
    }
}


/*
  
  Some background for the switch-statement (a note to self):
  
  The switch-statement ist tricky, because it needs a switch-value on
  stack against which to compare the different cases; if the program
  leaves the switch-statement prematurely (e.g. by 'goto' some other
  place), this switch-value is still in place and needs to be
  removed. This removal needs to be done differently depending on how
  the switch-statement is left.

  There are four ways to leave a switch-statement: return, continue,
  break and goto; each one has its own method to clean up left-over
  switch-values, and the case of nested switch-statements needs to be
  handled too (e.g. by removing more than one switch-value). Moreover,
  most of these commands are converted during their first execution;
  e.g. cBREAK is converted to cQGOTO, if it has been executed once. So
  any logic within the function break (which implements the command
  cBRAK) is executed only once. Therefore, cBREAK is preceded by
  cPOP_MULTI and cBREAD (before beeing converted to cQGOTO) stores the
  right number of values to be popped in cPOP_MULTI.

  return: Simply remove all values up to the return address

  
 */

void
check_leave_switch (char *name, struct command *from, struct command *to)   /* check, if goto or continue enters or leaves a switch_statement */
{
    if (from->switch_state->id == to->switch_state->id) {
	/* okay, move within a single switch statement or jump and land outside of switch statement */
    } else if (from->switch_state->nesting == 1 && to->switch_state->nesting == 0) {
	/* okay, move out of single switch statement */
	pop(stANY);
    } else if (from->switch_state->id == 0 && to->switch_state->id != 0) {
	sprintf(string, "%s into a switch-statement", name);
	error (ERROR, string);
    } else if (from->switch_state->nesting != 0 && to->switch_state->nesting == 0) {
	sprintf (string, "%s out of multiple switch-statements", name);
	error (ERROR, string);
    } else {
	sprintf (string, "%s out of multiple switch-statements", name);
	error (ERROR, "GOTO between switch-statements");
    }
}


void
create_label (char *label, int type)	/* creates command label */
{
    struct command *cmd;

    /* check, if label is duplicate */
    if (search_label (label, smSUB | smLINK | smLABEL)) {
        sprintf (string, "duplicate %s '%s'",
                 (type == cLABEL) ? "label" : "subroutine", strip (label));
        error (ERROR, string);
        return;
    }

    cmd = add_command (type, NULL, label);
    cmd->pointer = my_strdup (label);
    add_switch_state(cmd);

    link_label (cmd);
}


void
decide ()			/*  skips next command, if not 0 on stack */
{
    if (pop (stNUMBER)->value != 0) {
        current = current->next;    /* skip one command */
	std_diag ("skipping", current->type, current->symname, current->diag);
    } else {
	if (infolevel >= DEBUG)	error (DEBUG, "(no command skipped)");
    }
}


void
skipper ()
/* used for on_goto/gosub, skip specified number of commands */
{
    int i, len;
    struct command *ahead;	/* command to follow */

    len = (int) pop (stNUMBER)->value;
    i = 1;
    current = current->next;	/* advance to first goto/gosub */
    for (i = 1; i < len; i++) {
        ahead = current->next->next;	/* skip interleaving findnop statement */
        if (ahead->type == cNOP) {
            break;
        } else {
            current = ahead;
        }
    }
}


void
skiponce (struct command *cmd)	/* skip next command exectly once */
{
    if (cmd->tag) {
        current = current->next;
    }
    cmd->tag = 0;
}


void
resetskiponce (struct command *cmd)	/* find and reset next skip */
{
    struct command *c;

    c = cmd;
    while (c->type != cSKIPONCE) {
        c = c->next;
    }
    c->tag = 1;
}

void
pop_switch_value (struct command *cmd) /* remove switch value from stack, keeping return value */
{
    struct stackentry *keep, *kept;
    char *kept_string;
    double kept_value;
    int kept_type;

    keep = pop (stANY);
    kept_type = keep->type;
    if (keep->type==stSTRING) {
	kept_string=my_strdup((char *)keep->pointer);
    } else if (keep->type==stNUMBER) {
	kept_value=keep->value;
    } else {
	error (FATAL, "expecting only string or number on stack");
    }

    pop (stANY); /* discard switch value */

    /* push back kept value */
    kept=push();
    if (kept_type==stSTRING) {
	kept->pointer = kept_string;
    } else {
	kept->value = kept_value;
    }
}

void
pop_multi (struct command *cmd) /* pop and discard multiple values from stack */
{
    int to_pop = cmd->tag;
    struct stackentry *popped;

    while (to_pop > 0) {
	popped = pop(stSTRING_OR_NUMBER);
	to_pop--;
    }
}

void load_pop_multi (struct command *cmd, int to_pop) /* put correct value into preceding pop_multi-statement */
{
    if (cmd->prev->type != cPOP_MULTI) {
	sprintf(string, "while trying to load pop_multi; preceding command is rather '%s'", explanation[cmd->prev->type]);
	error(FATAL, string);
    }
    cmd->prev->tag = to_pop;
    if (infolevel >= DEBUG) {
	sprintf(string, "loading previous pop_multi-command with %d", to_pop);
	error(DEBUG, string);
    }

    /* and execute it for the first time */
    pop_multi(cmd->prev);
}

void
mybreak (struct command *cmd)	/* find break_here statement */
{
    struct command *curr;
    int loop_nesting = 0;
    int switch_nesting = 0;
    int to_break;
    int to_pop = 0;

    if (cmd->type == cBREAK_MULTI) {
	to_break = (int) pop(stNUMBER)->value;
	if (to_break > 3 || to_break < 1) {
	    sprintf(string, "invalid number of levels to break: %d; only 1,2 or 3 are allowed",to_break);
	    error(ERROR,string);
	}
    } else {
	to_break = 1;
    }
    curr = cmd;
    while (to_break) {
	while (curr->type != cBREAK_HERE || loop_nesting || switch_nesting) {
	    if (curr->type == cBEGIN_LOOP_MARK) {
		loop_nesting++;
	    }
	    if (curr->type == cEND_LOOP_MARK) {
		loop_nesting--;
	    }
	    if (curr->type == cBEGIN_SWITCH_MARK) {
		switch_nesting++;
		to_pop--;
	    }
	    if (curr->type == cEND_SWITCH_MARK) {
		switch_nesting--;
		to_pop++;
	    }
	    curr = curr->next;
	    if (!curr) {
		sprintf(string,"break has left program (loop_nesting=%d, switch_nesting=%d)",loop_nesting,switch_nesting);
		error (FATAL, string);
	    }
	}
	to_break--;
    }
    cmd->type = cQGOTO;
    if (infolevel >= DEBUG) {
	sprintf(errorstring, "converting '%s' to '%s'",explanation[cBREAK],explanation[cQGOTO]);
        error (DEBUG, errorstring);
    }
    load_pop_multi(cmd, to_pop);
    cmd->jump = current = curr;
}


void
mycontinue (struct command *cmd)	/* find continue_here statement */
{
    struct command *curr;
    int loop_nesting = 0;
    int to_pop = 0;

    curr = cmd;

    while (curr->type != cCONTINUE_HERE || loop_nesting) {
        if (curr->type == cBEGIN_LOOP_MARK) {
            loop_nesting++;
        }
        if (curr->type == cEND_LOOP_MARK) {
            loop_nesting--;
        }
	if (curr->type == cBEGIN_SWITCH_MARK) {
	    to_pop++;
	}
	if (curr->type == cEND_SWITCH_MARK) {
	    to_pop--;
	}
        curr = curr->prev;
        if (!curr) {
            sprintf(string,"continue has left program (loop_nesting=%d)",loop_nesting);
            error (FATAL, string);
        }
    }
    cmd->type = cQGOTO;
    if (infolevel >= DEBUG) {
	sprintf( errorstring, "converting '%s' to '%s'",explanation[cCONTINUE],explanation[cQGOTO]);
	error (DEBUG, errorstring);
    }

    check_leave_switch ("CONTINUE", cmd, curr);
    
    cmd->jump = current = curr;
}


void
next_case (struct command *cmd)	/* find next_case_here statement */
{
    struct command *curr;
    int loop_nesting = 0;
    int switch_nesting = 0;

    curr = cmd;
    while (curr->type != cNEXT_CASE_HERE || loop_nesting || switch_nesting) {
        if (curr->type == cBEGIN_LOOP_MARK) {
            loop_nesting++;
        }
        if (curr->type == cEND_LOOP_MARK) {
            loop_nesting--;
        }
        if (curr->type == cBEGIN_SWITCH_MARK) {
            switch_nesting++;
        }
        if (curr->type == cEND_SWITCH_MARK) {
            switch_nesting--;
        }
        curr = curr->next;
        if (!curr) {
            sprintf(string,"search for next case has left program (loop_nesting=%d, switch_nesting=%d)",loop_nesting,switch_nesting);
            error (FATAL, string);
        }
    }
    cmd->type = cQGOTO;
    if (infolevel >= DEBUG) {
	sprintf(errorstring,"converting '%s' to '%s'",explanation[cNEXT_CASE],explanation[cQGOTO]);
        error (DEBUG, errorstring);
    }
    cmd->jump = current = curr;
}


void
findnop ()
/* used for on_gosub, find trailing nop command */
{
    while (current->type != cNOP) {
        current = current->next;	/* next label */
    }
}


void
forcheck (void)			/* check, if for-loop is done */
{
    double start, bound, step, val;

    val = pop (stNUMBER)->value;
    step = pop (stNUMBER)->value;
    bound = pop (stNUMBER)->value;
    start = stackhead->prev->value;
    if ((val <= bound && val >= start && step >= 0)
            || (val <= start && val >= bound && step <= 0)) {
        stackhead->prev->value = 1.;
    } else {
        stackhead->prev->value = 0.;
    }
}


void
forincrement (void)		/* increment value on stack */
{
    /* expecting on stack: BOUND,STEP,VAL,stackhead
      where for VAL=START to BOUND step STEP */
    stackhead->prev->value += stackhead->prev->prev->value;
}


void
startfor (void)			/* compute initial value of for-variable */
{
    struct stackentry *p;

    p = push ();
    p->value =
        stackhead->prev->prev->prev->prev->value -
        stackhead->prev->prev->value;
    p->type = stNUMBER;

    return;
}
