/*

    YABASIC ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2019
    more info at www.yabasic.de

    foreign.c --- code for calling foreign libraries

    This file is part of yabasic and may be copied under the terms of
    MIT License which can be found in the file LICENSE.

*/

/* See: 

     https://eli.thegreenplace.net/2013/03/04/flexible-runtime-interface-to-shared-libraries-with-libffi 

   for an interesting example on using libffi by Eli Bendersky
*/

/* ------------- includes ---------------- */

#ifndef YABASIC_INCLUDED
#include "yabasic.h"		/* all prototypes and structures */
#endif

/* ------------- externally visible variables ---------------- */

char last_frnfn_call_error_text[INBUFFLEN] = "";    /* last error message produced by foreign call */
int last_frnfn_call_okay = 1;                       /* true, if last foreign call has been okay */

/* ------------- define a stub only, if feature is not available ---------------- */

#if defined(UNIX) && !defined(HAVE_DL_FFI)
void
frnfn_call (int type, double *pvalue, char **ppointer)
{
    error(sERROR, "this build of yabasic does not support calling foreign libraries");
    return;
}
double
frnfn_size (char *type)
{
    error(sERROR, "this build of yabasic does not support calling foreign libraries");
    return;
}
char *
frnbf_new ()
{
    error(sERROR, "this build of yabasic does not support calling foreign libraries");
    return;
}
void
frnbf_free ()
{
    error(sERROR, "this build of yabasic does not support calling foreign libraries");
    return;
}
char *
frnbf_dump ()
{
    error(sERROR, "this build of yabasic does not support calling foreign libraries");
    return my_strdup("");
}
void
frnbf_set ()
{
    error(sERROR, "this build of yabasic does not support calling foreign libraries");
    return;
}
void
frnbf_set2 ()
{
    error(sERROR, "this build of yabasic does not support calling foreign libraries");
    return my_strdup("");
}
double
frnbf_get ()
{
    error(sERROR, "this build of yabasic does not support calling foreign libraries");
    return 0.0;
}
char *
frnbf_get2 ()  /* get a string from a foreign buffer */
{
    error(sERROR, "this build of yabasic does not support calling foreign libraries");
    return my_strdup("");
}
#else

#define NUM_FFI_TYPES 16
#ifdef WINDOWS
#define FFI_BUILDING
#endif

#include <ffi.h>
#include <stdint.h>
#ifdef UNIX
#include <dlfcn.h>
#endif

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
    short ffisshort;
    int ffisint;
    long ffislong;
    void *ffipointer;
    char filler[64];
};

/* ------------- local functions ---------------- */
static int fgn_check_ffi_type (char *, ffi_type **, int, int);
static int frnfn_parse_stack (); /* verify and process arguments from yabasic stack into libffi structures */
static void fgn_cast_to_ffi_type (union FFI_VAL *, ffi_type *, double); /* cast and assign double value from yabasic into given (numeric) ffi_type */
static double fgn_cast_from_ffi_type (union FFI_VAL *, ffi_type *); /* cast and return value from ffi_type to double */
static void frnfn_cleanup (); /* free and cleanup structures after use */
static int fgn_check_type_and_action(char, int, char *); /* make sure, that information from grammar and from arguments match */
int frnbf_parse_handle (char *, int *, void *);  /* parse handle */

/* ------------- global variables ---------------- */

char *libname = NULL;    /* name of library to call */
#ifdef UNIX
void *lib = NULL;        /* handle to library */
#else
HINSTANCE lib = NULL;    /* handle to library */
#endif
char *funame = NULL;     /* name of function to call */
int opt_error = TRUE;    /* should problems with library lead to yabasic-errors ? ffi-problems will in any case */

ffi_cif cif;    /* structure describing arguments for libffi */
int argcnt;    /* number of arguments for function, i.e. length of both following lists */
ffi_type **tvalues; /* list of types for all individual values */
union FFI_VAL *values;   /* actual values that should be passed to call, see union FFI_VAL above */
union FFI_VAL **pvalues;     /* pointers to values */

/* ------------- subroutines ---------------- */

void
frnfn_call (int type,double *pvalue,char **ppointer)  /* load and execute function from external library */
{
    char *call_err;
    int ffi_ret;
    union FFI_VAL ffi_result;
    void *fu;
    ffi_type *rtype; /* expected return type of function */
    int is_struct_not_string; /* distinguish return types */
    

    last_frnfn_call_error_text[0] = '\0';
    last_frnfn_call_okay = 0;
    
    if (!frnfn_parse_stack ()) {
	frnfn_cleanup ();
	return;
    }

    /* Initialize the cif */
    if ((ffi_ret = ffi_prep_cif(&cif, FFI_DEFAULT_ABI, argcnt, rtype, tvalues)) != FFI_OK) {
	if (ffi_ret == FFI_BAD_TYPEDEF) {
	    sprintf(string, "invalid type specification for function '%s' from library '%s'; check arguments", funame, libname);
	} else {
	    sprintf(string, "unkown error when preparing function '%s' from library '%s'", funame, libname);
	}
	error(sERROR,string);
	frnfn_cleanup ();
	return;
    }
    
#ifdef UNIX
    lib = dlopen(libname, RTLD_LAZY);
#else
    lib = LoadLibrary(libname);
#endif

    if (!lib) {
	  sprintf(string, "could not load library '%s'",libname);
	  if (opt_error) {
	    error(sERROR,string);
	  } else {
	    strcpy (last_frnfn_call_error_text, string);
	  }
	  frnfn_cleanup ();
	  return;
    }

#ifdef UNIX
    dlerror();    /* Clear any existing error */
    fu = dlsym(lib, funame);
#else
    fu = GetProcAddress(lib, funame);
#endif

    if (!fu) {
	sprintf(string, "could not find function '%s' in foreign library '%s'",funame,libname);
	if (opt_error) {
	    error(sERROR,string);
	} else {
	    strcpy (last_frnfn_call_error_text, string);
	}
	frnfn_cleanup ();
	return;
    }
#ifdef UNIX
    call_err = dlerror();
    if (call_err != NULL) {
	sprintf(string,"could not find function '%s' in foreign library '%s': %s", funame, libname, call_err);
	if (opt_error) {
	    error(sERROR, string);
	} else {
	    strcpy (last_frnfn_call_error_text, string);
	}
	frnfn_cleanup ();
	return;
    }
#endif

    ffi_call(&cif, FFI_FN(fu), &ffi_result, (void **)pvalues);
    
    if (type == fFRNFN_CALL) {
	*pvalue = fgn_cast_from_ffi_type (&ffi_result, rtype);
    } else {
	sprintf(string,"frnbf:%d:%p", -1, ffi_result.ffipointer);
	*ppointer = my_strdup(string);
    }
	
    frnfn_cleanup ();
    last_frnfn_call_okay = 1;
}

double
frnfn_size (char *type) /* return size of structure */
{
    ffi_type *valtype;

    if (!fgn_check_ffi_type(type, &valtype, 0, 2)) return 0.0;
    return valtype->size;
}


char *
frnbf_new ()  /* create a new foreign buffer */
{
    int size;
    void *buff;
    
    size = pop (stNUMBER)->value;
    if (size<-1) {
	sprintf(errorstring,"size of buffer cannot be less than -1, not %d",size);
	error(sERROR, errorstring);
	return my_strdup("");
    }
    buff = my_malloc (size);
    memset (buff, 0, size);
    sprintf(string,"frnbf:%d:%p",size,buff);
    return my_strdup(string);
}


void
frnbf_free ()  /* free a foreign buffer */
{
    int size;
    void *ptr;

    if (frnbf_parse_handle (pop (stSTRING)->pointer, &size, &ptr)) return;
    my_free(ptr);
    return;
}


char *
frnbf_dump ()  /* dump a foreign buffer into readable form */
{
    int size;
    char *ptr;
    char *dump,*d;
    int i;

    if (frnbf_parse_handle(pop (stSTRING)->pointer, &size, &ptr)) return my_strdup("");
    d = dump = my_malloc(2*size);
    for(i=0;i<size;i++) {
	d += sprintf (d, "%02X", (int) ptr[i]);
    }
    return dump;
}


void
frnbf_set ()  /* set a value within a foreign buffer */
{
    int size;
    void *ptr;
    double val;
    int offset;
    char *type;
    ffi_type *valtype; /* expected return type of function */

    val = pop (stNUMBER)->value;
    type = pop (stSTRING)->pointer;
    offset = pop (stNUMBER)->value;
    if (frnbf_parse_handle(pop (stSTRING)->pointer, &size, &ptr)) return;
    if (!fgn_check_ffi_type(type, &valtype, 0, 2)) return;
    if (offset<0 || ( size >= 0 && offset+valtype->size > size)) {
	sprintf(errorstring, "overrun: offset of %d plus size of type %s = %d exceeds size of buffer %d",
		offset, type, valtype->size, size);
	error(sERROR, errorstring);
	return;
    }
    fgn_cast_to_ffi_type (ptr+offset, valtype, val);
    
    return;
}


void
frnbf_set2 ()  /* set a string within a foreign buffer */
{
    int size;
    void *ptr;
    char *str;
    int slen;
    int offset;
    ffi_type *valtype; /* expected return type of function */

    str = pop (stNUMBER)->pointer;
    slen = strlen(str);
    offset = pop (stNUMBER)->value;
    if (frnbf_parse_handle(pop (stSTRING)->pointer, &size, &ptr)) return;
    if (offset<0 || (size >= 0 && offset+slen > size)) {
	sprintf(errorstring, "overrun: offset of %d plus size of string = %d exceeds size of buffer %d",
		offset, valtype->size, size);
	error(sERROR, errorstring);
	return;
    }
    strcpy((char *) ptr+offset, str);
    
    return;
}


double
frnbf_get ()  /* get a value from a foreign buffer */
{
    int size;
    void *ptr;
    int offset;
    char *type;
    ffi_type *valtype; /* expected return type of function */

    type = pop (stSTRING)->pointer;
    offset = pop (stNUMBER)->value;
    if (frnbf_parse_handle(pop (stSTRING)->pointer, &size, &ptr)) return 0.0;
    if (!fgn_check_ffi_type(type, &valtype, 0, 2)) return 0.0;
    if (offset<0 || (size >= 0 && offset+valtype->size > size)) {
	sprintf(errorstring, "overrun: offset of %d plus size of type %s = %d exceeds size of buffer %d",
		offset, type, valtype->size, size);
	error(sERROR, errorstring);
	return 0.0;
    }

    return fgn_cast_from_ffi_type (ptr+offset, valtype);
}


char *
frnbf_get2 ()  /* get a string from a foreign buffer */
{
    int size;
    void *ptr;
    int offset, len;
    ffi_type *valtype; /* expected return type of function */

    len = pop (stNUMBER)->value;
    offset = pop (stNUMBER)->value;
    if (frnbf_parse_handle(pop (stSTRING)->pointer, &size, &ptr)) return my_strdup("");
    if (offset<0 || (size >=0 && offset+len > size)) {
	sprintf(errorstring, "overrun: offset of %d plus length of string %d exceeds size of buffer %d",
		offset, len, size);
	error(sERROR, errorstring);
	return my_strdup("");
    }
    return my_strndup (ptr+offset, len);
}


int
frnbf_parse_handle (char *handle, int *size, void *ptr)  /* parse handle */
{
    if (sscanf(handle, "frnbf:%d:%p", size, ptr) != 2) {
	sprintf(errorstring,"invalid handle for foreign buffer: '%s'", handle);
	error(sERROR, errorstring);
	return false;
    }
    return true;
}


static int
frnfn_parse_stack () /* verify and process arguments from yabasic stack into libffi structures */
{
    struct stackentry *st,*stfirst,*stfirstarg;
    static char stfound[50];
    int listlen = -1;
    int i,j;
    char *opt_str;
    int opt_has_no;
    ffi_type *rtype; /* expected return type of function */

    
    /* go through list of arguments multiple times, check types and transfer them to libffi structures */
    st = stackhead;
    do {
	st = st->prev;
	listlen++;
    } while (st->type != stFREE);

    /* pop arguments here, because the function is declared to have zero args */
    for(i=0;i<listlen;i++) {
	pop (stSTRING_OR_NUMBER);
    }
    pop (stFREE);

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
	    sprintf(string, "argument at position %d needs to be a string, not %s",i,stfound);
	    error (sERROR, string);
	    return FALSE;
	}
	if (i==0) libname=st->pointer;
	if (i==1 && !fgn_check_ffi_type (st->pointer, &rtype, 0, 0)) return FALSE;
	if (i==2) funame=st->pointer;
	st = st->next;
    }
 
    stfirstarg = st;
    argcnt = 0;
    for(i=3;i<listlen-1;i+=2,st=st->next->next) {
	if (st->type != stSTRING) {
	    stackdesc (st->type, stfound);
	    sprintf(string, "argument at position %d needs to be a string, not %s",i,stfound);
	    error (sERROR, string);
	    return FALSE;
	}
	if (!strcmp(st->pointer,"options")) { /* parse rest of arguments as options */
            st=st->next;
	    i++;
	    for(;i<listlen;i++,st=st->next) {
		if (st->type != stSTRING) {
		    stackdesc (st->type, stfound);
		    sprintf(string, "argument at position %d needs to be an option string, not %s",i,stfound);
		    error (sERROR, string);
		    return FALSE;
                }
		opt_str = st->pointer;
		opt_has_no = (strncmp(opt_str,"no_",3) == 0);
		if (opt_has_no) opt_str += 3;
		if (!strcmp(opt_str,"error"))
		    opt_error = !opt_has_no;
                else {
                   error (sERROR,"options can only be 'error' optionally preceeded by 'no_'");
		}
	    }
	    break;
        }
	argcnt++;
    }

    tvalues = (ffi_type **) my_malloc(argcnt*sizeof(void *));
    values = (union FFI_VAL *) my_malloc(argcnt*sizeof(union FFI_VAL));
    pvalues = (union FFI_VAL **) my_malloc(argcnt*sizeof(void *));

    st = stfirstarg;
    for(i=3,j=0;i<3+2*argcnt;i+=2,st=st->next->next,j++) {
	if (st->next->type == stSTRING) {
	    if (!fgn_check_ffi_type (st->pointer, tvalues+j, NUM_FFI_TYPES-2, 0)) return FALSE;
	    values[j].ffipointer = (char *)st->next->pointer;
	} else {
	    if (!fgn_check_ffi_type (st->pointer, tvalues+j, 0, 2)) return FALSE;
            fgn_cast_to_ffi_type (values+j,tvalues[j],st->next->value);
        }
	pvalues[j] = values + j;
    }

    return TRUE;
}


static int
fgn_check_ffi_type (char *type_string, ffi_type **type_ptr, int skip_first, int skip_last) /* check ffi type for correctness and maybe produce error message */
{
    int i;
    static char *ffi_types_string[NUM_FFI_TYPES] = {"uint8", "int8", "uint16", "int16", "uint32", "int32", "uint64", "int64", "float", "double", "char", "short", "int", "long", "buffer", "bf"};
    static ffi_type *ffi_types_ptr[NUM_FFI_TYPES];
    static int ffi_types_ptr_initialized = FALSE;

    if (!ffi_types_ptr_initialized) {
	ffi_types_ptr[0] = &ffi_type_uint8;   ffi_types_ptr[1] = &ffi_type_sint8;  ffi_types_ptr[2] = &ffi_type_uint16;
	ffi_types_ptr[3] = &ffi_type_sint16;  ffi_types_ptr[4] = &ffi_type_uint32; ffi_types_ptr[5] = &ffi_type_sint32;
	ffi_types_ptr[6] = &ffi_type_uint64;  ffi_types_ptr[7] = &ffi_type_sint64; ffi_types_ptr[8] = &ffi_type_float;
	ffi_types_ptr[9] = &ffi_type_double;  ffi_types_ptr[10] = &ffi_type_schar; 
	ffi_types_ptr[11] = &ffi_type_sshort; ffi_types_ptr[12] = &ffi_type_sint;
	ffi_types_ptr[13] = &ffi_type_slong; ffi_types_ptr[14] = &ffi_type_pointer; ffi_types_ptr[15] = &ffi_type_pointer;
	ffi_types_ptr_initialized = TRUE;
    }

    for(i=skip_first;i<NUM_FFI_TYPES-skip_last;i++) {
	if (!strcmp(type_string,ffi_types_string[i])) {
	    *type_ptr=ffi_types_ptr[i];
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
fgn_cast_to_ffi_type (union FFI_VAL *value, ffi_type *type, double num) /* cast and assign double value from yabasic into specified (numeric) ffi_type */
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
    if (type == &ffi_type_sshort) (*value).ffisshort = (short) num;
    if (type == &ffi_type_sint) (*value).ffisint = (int) num;
    if (type == &ffi_type_slong) (*value).ffislong = (long) num;
}


static double
fgn_cast_from_ffi_type (union FFI_VAL *value, ffi_type *type) /* cast and return value from ffi_type to double */
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
    if (type == &ffi_type_sshort) return (double) (*value).ffisshort;
    if (type == &ffi_type_sint) return (double) (*value).ffisint;
    if (type == &ffi_type_slong) return (double) (*value).ffislong;
    error(sFATAL, "internal error, unknown type");
    return 0.0;
}


static void frnfn_cleanup () /* free and cleanup structures after use */
{
    if (lib) {
#ifdef UNIX
	dlclose(lib);
#else
		FreeLibrary(lib);
#endif
	lib = NULL;
    }
    if (tvalues) {
	my_free(tvalues);
	tvalues = NULL;
    }
    if (values) {
	my_free(values);
	values = NULL;
    }
    if (pvalues) {
	my_free(pvalues);
	pvalues = NULL;
    }
}

#endif /* HAVE_DL_FFI */
