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

#define NUM_FFI_TYPES 18

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
static double cast_from_ffi_type (union FFI_VAL *, ffi_type *); /* cast and return value from ffi_type to double */

/* ------------- global variables ---------------- */

char *libname;  /* name of library to call */
char *funame;   /* name of function to call */

ffi_cif cif;    /* structure describing arguments for libffi */
int argcnt = 0; /* number of arguments for function, i.e. length of both following lists */
ffi_type **args; /* list of types for all individual arguments */
union FFI_VAL *values;   /* actual values that should be passed, see union FFI_VAL above */
ffi_type rtype; /* expected return type of function */


/* ------------- subroutines ---------------- */

void
external (int type,double *pvalue,char **ppointer)  /* load and execute function from external library */
{
    if (!parse_stack) return;
    my_free(args);
    my_free(values);
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
	return FALSE;
    }

    st = stfirst;
    for(i=0;i<3;i++) {
	if (st->type != stSTRING) {
	    stackdesc (st->type, stfound);
	    sprintf(string, "argument at position %d needs to be a string, not %s",stfound);
	    error (sERROR, string);
	    return FALSE;
	}
	if (i==0) libname=st->pointer;
	if (i==1 && !check_ffi_type (st->pointer, &rtype, 1, 0, 0)) return FALSE;
	if (i==2) funame=st->pointer;
	st = st->next;
      }
 
    stfirstarg = st;
    for(i=3;i<listlen-1;i+=2,st=st->next->next) {
	if (st->type != stSTRING) {
	    stackdesc (st->type, stfound);
	    sprintf(string, "argument at position %d needs to be a string, not %s",i,stfound);
	    error (sERROR, string);
	    return FALSE;
	}
	    if (!strcmp(st->pointer,"options")) { /* parse rest of arguments as options */
            st=st->next;
	    for(j=i+1;j<listlen;j++,st=st->next) {
		if (st->type != stSTRING) {
		    stackdesc (st->type, stfound);
		    sprintf(string, "argument at position %d needs to be an option string, not %s",j,stfound);
		    error (sERROR, string);
		    return FALSE;
                }
		if (!strcmp(st->pointer,"error"))
                   opt_error=TRUE;
                else if (!strcmp(st->pointer,"noerror"))
                   opt_error=FALSE;
                else {
                   error (sERROR,"options can only be 'error' and 'noerror'");
		}
	    }
        }
	argcnt++;
    }

    args = (ffi_type **) my_malloc(argcnt*sizeof(void *));
    values = (void *) my_malloc(argcnt*sizeof(void *));

    st = stfirstarg;
    for(i=3,j=0;i<3+2*argcnt;i+=2,st=st->next->next,j++) {
	if (st->next->type == stSTRING) {
	    if (!check_ffi_type (st->pointer, args[j], i, NUM_FFI_TYPES-1, 0)) return FALSE;
	    values[j].ffipointer = (char *)st->next->pointer;
	} else {
	    if (!check_ffi_type (st->pointer, args[j], i, 1, 1)) return FALSE;
            cast_to_ffi_type (values+j,args[j],st->next->value);
        }
    }
	
    /* Initialize the cif */
    if (ffi_prep_cif(&cif, FFI_DEFAULT_ABI, argcnt, &rtype, args) == FFI_OK) {
    }    
}

static int
check_ffi_type (char *type_string, ffi_type *type_ptr, int pos, int skip_first, int skip_last) /* check ffi type for correctness and maybe produce error message */
{
    int i;
    static char *ffi_types_string[NUM_FFI_TYPES] = {"uint8", "int8", "uint16", "int16", "uint32", "int32", "uint64", "int64", "float", "double", "char", "ushort", "short", "uint", "int", "ulong", "long", "string"};
    static ffi_type *ffi_types_ptr[NUM_FFI_TYPES];
    static int ffi_types_ptr_initialized = FALSE;

    if (!ffi_types_ptr_initialized) {
	ffi_types_ptr[0] = &ffi_type_uint8;   ffi_types_ptr[1] = &ffi_type_sint8;  ffi_types_ptr[2] = &ffi_type_uint16;
	ffi_types_ptr[3] = &ffi_type_sint16;  ffi_types_ptr[4] = &ffi_type_uint32; ffi_types_ptr[5] = &ffi_type_sint32;
	ffi_types_ptr[6] = &ffi_type_uint64;  ffi_types_ptr[7] = &ffi_type_sint64; ffi_types_ptr[8] = &ffi_type_float;
	ffi_types_ptr[9] = &ffi_type_double;  ffi_types_ptr[10] = &ffi_type_schar; ffi_types_ptr[11] = &ffi_type_ushort;
	ffi_types_ptr[12] = &ffi_type_sshort; ffi_types_ptr[13] = &ffi_type_uint;  ffi_types_ptr[14] = &ffi_type_sint;
	ffi_types_ptr[15] = &ffi_type_ulong;  ffi_types_ptr[16] = &ffi_type_slong; ffi_types_ptr[17] = &ffi_type_pointer;
	ffi_types_ptr_initialized = TRUE;
    }

    for(i=skip_first;i<NUM_FFI_TYPES-skip_last;i++) {
	if (!strcmp(type_string,ffi_types_string[i])) {
	    type_ptr=ffi_types_ptr[i];
	    return TRUE;
	}
    }
    sprintf(string,"invalid type specification '%s', needs to be one of: ",type_string);
    for(i=skip_first;i<NUM_FFI_TYPES-skip_last;i++,strcat(string,",")) {
	strcat(string,ffi_types_string[i]);
    }
    error (sERROR,string);
    return FALSE;
}

static void
cast_to_ffi_type (union FFI_VAL *value, ffi_type *type, double num) /* cast and assign double value from yabasic into specified (numeric) ffi_type */
{
    if (type == &ffi_type_uint8) (*value).ffiuint8 = (uint8_t) num;
    if (type == &ffi_type_uint8) (*value).ffiuint8 = (uint8_t) num;
    if (type == &ffi_type_sint8) (*value).ffisint8 = (int8_t) num;
    if (type == &ffi_type_uint16) (*value).ffiuint16 = (uint16_t) num;
    if (type == &ffi_type_sint16) (*value).ffisint16 = (int16_t) num;
    if (type == &ffi_type_uint32) (*value).ffiuint32 = (uint32_t) num;
    if (type == &ffi_type_sint32) (*value).ffisint32 = (int32_t) num;
    if (type == &ffi_type_uint64) (*value).ffiuint64 = (uint64_t) num;
    if (type == &ffi_type_sint64) (*value).ffisint64 = (int64_t) num;
    if (type == &ffi_type_float) (*value).ffifloat = (float_t) num;
    if (type == &ffi_type_double) (*value).ffidouble = (double_t) num;
    if (type == &ffi_type_schar) (*value).ffischar = (char) num;
    if (type == &ffi_type_ushort) (*value).ffiushort = (ushort) num;
    if (type == &ffi_type_sshort) (*value).ffisshort = (short) num;
    if (type == &ffi_type_uint) (*value).ffiuint = (uint) num;
    if (type == &ffi_type_sint) (*value).ffisint = (int) num;
    if (type == &ffi_type_ulong) (*value).ffiulong = (ulong) num;
    if (type == &ffi_type_slong) (*value).ffislong = (long) num;
}

static double
cast_from_ffi_type (union FFI_VAL *value, ffi_type *type) /* cast and return value from ffi_type to double */
{
    if (type == &ffi_type_uint8) return (double) (*value).ffiuint8;
    if (type == &ffi_type_uint8) return (double) (*value).ffiuint8;
    if (type == &ffi_type_sint8) return (double) (*value).ffisint8;
    if (type == &ffi_type_uint16) return (double) (*value).ffiuint16;
    if (type == &ffi_type_sint16) return (double) (*value).ffisint16;
    if (type == &ffi_type_uint32) return (double) (*value).ffiuint32;
    if (type == &ffi_type_sint32) return (double) (*value).ffisint32;
    if (type == &ffi_type_uint64) return (double) (*value).ffiuint64;
    if (type == &ffi_type_sint64) return (double) (*value).ffisint64;
    if (type == &ffi_type_float) return (double) (*value).ffifloat;
    if (type == &ffi_type_double) return (double) (*value).ffidouble;
    if (type == &ffi_type_schar) return (double) (*value).ffischar;
    if (type == &ffi_type_ushort) return (double) (*value).ffiushort;
    if (type == &ffi_type_sshort) return (double) (*value).ffisshort;
    if (type == &ffi_type_uint) return (double) (*value).ffiuint;
    if (type == &ffi_type_sint) return (double) (*value).ffisint;
    if (type == &ffi_type_ulong) return (double) (*value).ffiulong;
    if (type == &ffi_type_slong) return (double) (*value).ffislong;
}

#endif /* HAVE_DL_FFI */
