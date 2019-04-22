/*

    YABASIC ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2019
    more info at www.yabasic.de

    extcall.c --- code for calling external libraries

    This file is part of yabasic and may be copied under the terms of
    MIT License which can be found in the file LICENSE.

*/

/* ------------- includes ---------------- */

#ifndef YABASIC_INCLUDED
#include "yabasic.h"		/* all prototypes and structures */
#endif

/* ------------- define a stub only, if feature is not available ---------------- */

#if defined(UNIX) && !defined(HAVE_DL_FFI)
void
external (int type,double *pvalue,char **ppointer)  /* load and execute function from external library */
{
    error(sERROR, "this build of yabasic does not support calling external libraries");
    return;
}
#else

#define NUM_FFI_TYPES 25

#include <ffi.h>
#include <stdint.h>

/* ------------- types ---------------- */
union FFI_VAL {
    uint8_t ffiuint8;
    int8_t ffisint8;
    uint16_t ffiuint16;
    int16_t ffisint16;
    uint32_t ffiuint32;
    int32_t ffisint32;
    uint64_t ffiuint64;
    int64_t ffisint64;
    float_t ffifloat;
    double_t ffidouble;
    char ffischar;
    ushort ffiushort;
    short ffisshort;
    uint ffiuint;
    int ffisint;
    ulong ffiulong;
    long ffislong;
    void *ffipointer;
};

/* ------------- local functions ---------------- */
static int check_ffi_type (char *, ffi_type *, int, int, int);
static int parse_stack (); /* verify and process arguments from yabasic stack into libffi structures */
static void cast_to_ffi_type (union FFI_VAL *, ffi_type *, double); /* cast and assign double value from yabasic into given (numeric) ffi_type */
static double cast_from_ffi_type (union FFI_VAL *, ffi_type); /* cast and return value from ffi_type to double */

/* ------------- global variables ---------------- */

char *all_types_strings[NUM_FFI_TYPES] = {"void", "uint8", "sint8", "uint16", "sint16", "uint32", "sint32", "uint64", "sint64", "float", "double", "uchar", "schar", "ushort", "sshort", "uint", "sint", "ulong", "slong", "longdouble", "pointer"};

ffi_type all_types_nums[NUM_FFI_TYPES] = {ffi_type_void, ffi_type_uint8, ffi_type_sint8, ffi_type_uint16, ffi_type_sint16, ffi_type_uint32, ffi_type_sint32, ffi_type_uint64, ffi_type_sint64, ffi_type_float, ffi_type_double, ffi_type_uchar, ffi_type_schar, ffi_type_ushort, ffi_type_sshort, ffi_type_uint, ffi_type_sint, ffi_type_ulong, ffi_type_slong, ffi_type_longdouble, ffi_type_pointer};

char *libname;  /* name of library to call */
char *funame;   /* name of function to call */

ffi_cif cif;    /* structure describing arguments for libffi */
int argcnt = 0; /* number of arguments for function, i.e. length of both following lists */
ffi_type *args; /* list of types for all individual arguments */
void *values;   /* actual values that should be passed, see union FFI_VAL above */
ffi_type rtype; /* expected return type of function */


/* ------------- subroutines ---------------- */

void
external (int type,double *pvalue,char **ppointer)  /* load and execute function from external library */
{
    if (!parse_stack) return;
}

static int
parse_stack () /* verify and process arguments from yabasic stack into libffi structures */
{
    struct stackentry *st,*stfirst,*stfirstarg;
    static char stfound[50];
    int listlen = -1;
    int i,j;
    int opt_error = TRUE;
    
    /* go through list of arguments multiple times, check types and transfer them to libffi structures */
    st = stackhead;
    do {
	st = st->prev;
	listlen++;
    } while (st->type != stFREE);
    stfirst = st->next;
    
    if (listlen<3) {
	sprintf(string, "need at least 3 arguments, not %d", listlen);
	error(sERROR, string);
	return;
    }

    st = stfirst;
    for(i=0;i<3;i++) {
	if (st->type != stSTRING) {
	    stackdesc (st->type, stfound);
	    sprintf(string, "argument at position %d needs to be a string, not %s%s",stfound,usage);
	    error (sERROR, string);
	    return;
	}
	if (i==0) libname=st->pointer;
	if (i==1 && !check_ffi_type (st->pointer, &rtype, 1, 0, 0)) return;
	if (i==2) funame=st->pointer;
	st = st->next;
      }
 
    stfirstarg = st;
    for(i=3;i<listlen-1;i+=2,st=st->next->next) {
	if (st->type != stSTRING) {
	    stackdesc (st->type, stfound);
	    sprintf(string, "argument at position %d needs to be a string, not %s",i,stfound);
	    error (sERROR, string);
	    return;
	}
	    if (!strcmp(st->pointer,"options")) { /* parse rest of arguments as options */
            st=st->next;
	    for(j=i+1;j<listlen;j++,st=st->next) {
		if (st->type != stSTRING) {
		    stackdesc (st->type, stfound);
		    sprintf(string, "argument at position %d needs to be an option string, not %s",j,stfound);
		    error (sERROR, string);
		    return;
                }
		if (!strcmp(st->pointer,"error"))
                   opt_error=TRUE;
                elsif (!strcmp(st->pointer,"noerror"))
                   opt_error=FALSE;
                else {
                   error (sERROR,"options can only be 'error' and 'noerror'");
		}
	    }
        }
	argcnt++;
    }

    args = (ffi_type_pointer) my_malloc(argcnt*sizeof(&ffi_type_pointer));
    values = (void **) my_malloc(argcnt*sizeof(void *));

    st = stfirstarg;
    for(i=3,j=0;i<3+2*argcnt;i+=2,st=st->next->next,j++) {
	if (st->next->type == stSTRING) {
	    if !check_ffi_type (st->pointer, args+j, i, NUM_FFI_TYPES-1, 0) return;
	    values[j] = st->next->pointer;
	} else {
	    if !check_ffi_type (st->pointer, args+j, i, 1, 1) return;
            assign_ffi_type (values+j,args[j],st->next->value)
        }
    }
	
    /* Initialize the argument info vectors */    
    args[0] = &ffi_type_pointer;
    values[0] = &s;

    /* Initialize the cif */
    if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, 1, &ffi_type_sint, args) == FFI_OK) {
      s = "Hello World!";
      ffi_call(&cif, puts, &rc, values);
      /* rc now holds the result of the call to puts */
      
      /* values holds a pointer to the function's arg, so to 
         call puts() again all we need to do is change the 
         value of s */
      s = "This is cool!";
      ffi_call(&cif, puts, &rc, values);
    }
    
    }
    my_free(args);
    my_free(values);
}

static int
check_ffi_type (char *type_string, ffi_type *type_num, int pos, int skip_first, int skip_last) /* check ffi type for correctness and maybe produce error message */
{
    int i;
    for(i=skip_first;i<COUNT_FFI_TYPES-skiplast;i++) {
	if (!strcmp(type_string,all_types_strings[i])) {
	    *type_num=all_types_nums[i];
	    return TRUE;
	}
    }
    sprintf(string,"invalid type specification '%s', needs to be one of: ",type_string);
    for(i=skip_first;i<COUNT_FFI_TYPES-skiplast;i++,strcat(string,",")) {
	strcat(string,all_types_strings[i]);
    }
    error (sERROR,string);
    return FALSE;
}

static void
cast_to_ffi_type (union FFI_VAL *value, ffi_type *type, double num) /* cast and assign double value from yabasic into specified (numeric) ffi_type */
{
}

static double
cast_from_ffi_type (union FFI_VAL *value, ffi_type *type) /* cast and return value from ffi_type to double */
{
}

#endif /* HAVE_DL_FFI */
