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


/* ------------- defines and enums ---------------- */

enum kind_of_type { ktSIMPLE, ktCOMPLEX, ktANY };


/* ------------- externally visible variables ---------------- */

char last_frnfn_call_error_text[INBUFFLEN] = "";    /* last error message produced by foreign call */
int last_frnfn_call_okay = 1;                       /* true, if last foreign call has been okay */

/* ------------- define a stub only, if feature is not available ---------------- */

#if defined(UNIX) && !defined(USE_DL_FFI)
void
no_frn_error(void)
{
    error(sERROR, "this build of yabasic does not support calling foreign libraries");
}    
void
frnfn_call (int type, double *pvalue, char **ppointer)
{
    no_frn_error();
    return;
}
double
frnfn_size ()
{
    no_frn_error();
    return 0.0;
}
char *
frnbf_alloc ()
{
    no_frn_error();
    return my_strdup("");
}
void
frnbf_free ()
{
    no_frn_error();
    return;
}
int
frnbf_size ()
{
    no_frn_error();
    return 0;
}
char *
frnbf_dump (int type)
{
    no_frn_error();
    return my_strdup("");
}
void
frnbf_set ()
{
    no_frn_error();
    return;
}
void
frnbf_set2 ()
{
    no_frn_error();
    return;
}
double
frnbf_get ()
{
    no_frn_error();
    return 0.0;
}
char *
frnbf_get2 ()
{
    no_frn_error();
    return my_strdup("");
}
char *
frnbf_get_buffer () 
{
    no_frn_error();
    return my_strdup("");
}
void
frnbf_set_buffer ()
{
    no_frn_error();
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
static int frn_decode_ffi_type (char *, ffi_type **, char **, int);
static int frnfn_parse_stack ();
static void frn_cast_to_ffi_type (union FFI_VAL *, ffi_type *, double);
static double frn_cast_from_ffi_type (union FFI_VAL *, ffi_type *);
static void frnfn_cleanup ();
static int frn_check_type_and_action(char, int, char *);
int frnbf_parse_handle (char *, int *, void **);

/* ------------- global variables ---------------- */

char *libname = NULL;    /* name of library to call */
#ifdef UNIX
void *lib = NULL;        /* handle to library */
#else
HINSTANCE lib = NULL;    /* handle to library */
#endif
char *funame = NULL;     /* name of function to call */
int opt_error;                /* should problems with library lead to yabasic-errors ? ffi-problems will in any case */
int opt_copy_string_result;   /* should the string result be copied or passed through */
int opt_unload_library;       /* should the library be unloaded after call */

ffi_cif cif;    /* structure describing arguments for libffi */
int argcnt;    /* number of arguments for function, i.e. length of both following lists */
ffi_type **vtypes; /* list of types for all individual values */
char **vtypestxt; /* list of types for all individual values as text */
ffi_type *rtype; /* expected return type of function */
char *rtypetxt; /* expected return type of function as text */

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
    int is_struct_not_string; /* distinguish return types */
    

    last_frnfn_call_error_text[0] = '\0';
    last_frnfn_call_okay = 0;

    if (!frnfn_parse_stack ()) {
	frnfn_cleanup ();
	return;
    }

    /* Initialize the cif */
    if ((ffi_ret = ffi_prep_cif(&cif, FFI_DEFAULT_ABI, argcnt, rtype, vtypes)) != FFI_OK) {
	if (ffi_ret == FFI_BAD_TYPEDEF) {
	    sprintf(string, "invalid type specification for function '%s' from library '%s'; check arguments", funame, libname);
	} else {
	    sprintf(string, "unknown error when preparing function '%s' from library '%s'", funame, libname);
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
	*pvalue = frn_cast_from_ffi_type (&ffi_result, rtype);
    } else {
	if (!strcmp(rtypetxt,"string")) {
	    if (opt_copy_string_result)
		*ppointer = my_strdup(ffi_result.ffipointer);
	    else
		*ppointer = ffi_result.ffipointer;		
	} else {
	    sprintf(string,"frnbf:%d:%p", ffi_result.ffipointer ? -2:-1, ffi_result.ffipointer);
	    *ppointer = my_strdup(string);
	}
    }
	
    frnfn_cleanup ();
    last_frnfn_call_okay = 1;
}

double
frnfn_size () /* return size of structure */
{
    ffi_type *valtype;

    if (!frn_decode_ffi_type(pop (stSTRING)->pointer, &valtype, NULL, ktSIMPLE)) return 0.0;
    return valtype->size;
}


char *
frnbf_alloc ()  /* create a new foreign buffer */
{
    int size;
    void *buff;
    
    size = (int) pop (stNUMBER)->value;
    if (size<-1) {
	sprintf(estring,"size of buffer cannot be less than -1, not %d",size);
	error(sERROR, estring);
	return my_strdup("");
    } else if (size == -1) {
	buff = NULL;
    } else {
	buff = my_malloc (size);
	memset (buff, 0, size);
    }
    sprintf(string,"frnbf:%d:%p",size,buff);
    return my_strdup(string);
}


void
frnbf_free ()  /* free a foreign buffer */
{
    int size;
    void *ptr;

    if (!frnbf_parse_handle (pop (stSTRING)->pointer, &size, &ptr)) return;
    my_free(ptr);
    return;
}


int
frnbf_size ()  /* get size of buffer */
{
    int size;
    char *ptr;

    if (!frnbf_parse_handle(pop (stSTRING)->pointer, &size, (void **)&ptr)) return 0;
    return size;
}


char *
frnbf_dump (int type)  /* dump a foreign buffer into readable form */
{
    int size,ssize,psize;
    char *ptr;
    char *dump,*d;
    int i;

    if (type == fFRNBF_DUMP2) ssize = (int) pop (stNUMBER)->value;
    if (!frnbf_parse_handle(pop (stSTRING)->pointer, &psize, (void **)&ptr)) return my_strdup("");
    size = (type == fFRNBF_DUMP2) ? ssize : psize;
    if (size<0) size=0;
    d = dump = my_malloc(2*size+1);
    d[size]=d[0] = '\0';
    for(i=0;i<size;i++) {
	d += sprintf (d, "%02X", (unsigned char) ptr[i]);
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
    ffi_type *valtype;

    val = pop (stNUMBER)->value;
    type = pop (stSTRING)->pointer;
    offset = (int) pop (stNUMBER)->value;
    if (!frnbf_parse_handle(pop (stSTRING)->pointer, &size, &ptr)) return;
    if (!frn_decode_ffi_type(type, &valtype, NULL, ktSIMPLE)) return;
    if (size == -1) {
	sprintf(estring, "size of -1 designates a null-pointer");
	error(sERROR,estring);
	return;
    }
    if (offset<0 || ( size >= 0 && offset+valtype->size > size)) {
	sprintf(estring, "overrun: offset of %d plus size of type %s = %d exceeds size of buffer %d",
		offset, type, valtype->size, size);
	error(sERROR, estring);
	return;
    }
    frn_cast_to_ffi_type ((void*)((char*)ptr+offset), valtype, val);
    
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

    str = pop (stSTRING)->pointer;
    slen = strlen(str);
    offset = (int) pop (stNUMBER)->value;
    if (!frnbf_parse_handle(pop (stSTRING)->pointer, &size, &ptr)) return;
    if (size == -1) {
	sprintf(estring, "size of -1 designates a null-pointer");
	error(sERROR,estring);
	return;
    }
    if (offset<0 || (size >= 0 && offset+slen > size)) {
	sprintf(estring, "overrun: offset of %d plus size of string = %d exceeds size of buffer %d",
		offset, slen, size);
	error(sERROR, estring);
	return;
    }
    strcpy((char *) ptr+offset, str);
    
    return;
}


void
frnbf_set_buffer ()  /* set a buffer within a foreign buffer */
{
    int size1,size2;
    void *ptr1,*ptr2;
    int offset;
    ffi_type *bufftype;

    if (!frnbf_parse_handle(pop (stSTRING)->pointer, &size2, &ptr2)) return;
    offset = (int) pop (stNUMBER)->value;
    if (!frnbf_parse_handle(pop (stSTRING)->pointer, &size1, &ptr1)) return;
    frn_decode_ffi_type("buffer", &bufftype, NULL, ktCOMPLEX);
    if (size1 == -1) {
	sprintf(estring, "size of -1 designates a null-pointer");
	error(sERROR,estring);
	return;
    }
    if (offset<0 || (size1 >= 0 && offset+bufftype->size > size1)) {
	sprintf(estring, "overrun: offset of %d plus size of pointer = %d exceeds size of buffer %d",
		offset, bufftype->size, size1);
	error(sERROR, estring);
	return;
    }

    *((char **)((char *)ptr1+offset)) = (size2 == -1) ? NULL:((char *)ptr2);
    
    return;
}


double
frnbf_get ()  /* get a value from a foreign buffer */
{
    int size;
    void *ptr;
    int offset;
    char *type;
    ffi_type *valtype;

    type = pop (stSTRING)->pointer;
    offset = (int) pop (stNUMBER)->value;
    if (!frnbf_parse_handle(pop (stSTRING)->pointer, &size, &ptr)) return 0.0;
    if (!frn_decode_ffi_type(type, &valtype, NULL, ktSIMPLE)) return 0.0;
    if (size == -1) {
	sprintf(estring, "size of -1 designates a null-pointer");
	error(sERROR,estring);
	return 0.0;
    }
    if (offset<0 || (size >= 0 && offset+valtype->size > size)) {
	sprintf(estring, "overrun: offset of %d plus size of type %s = %d exceeds size of buffer %d",
		offset, type, valtype->size, size);
	error(sERROR, estring);
	return 0.0;
    }

    return frn_cast_from_ffi_type ((void*)((char*)ptr+offset), valtype);
}


char *
frnbf_get2 ()  /* get a string from a foreign buffer */
{
    int size;
    void *ptr;
    int offset, len;

    len = (int) pop (stNUMBER)->value;
    offset = (int) pop (stNUMBER)->value;
    if (!frnbf_parse_handle(pop (stSTRING)->pointer, &size, &ptr)) return my_strdup("");
    if (size == -1) {
	sprintf(estring, "size of -1 designates a null-pointer");
	error(sERROR,estring);
	return my_strdup("");
    }
    if (offset<0 || (size >=0 && offset+len > size)) {
	sprintf(estring, "overrun: offset of %d plus length of string %d exceeds size of buffer %d",
		offset, len, size);
	error(sERROR, estring);
	return my_strdup("");
    }
    return my_strndup ((void*)((char*)ptr+offset), len);
}


char *
frnbf_get_buffer ()  /* get a second buffer from a foreign buffer */
{
    int size;
    void *ptr;
    char *ptrptr;
    int offset, len;

    offset = (int) pop (stNUMBER)->value;
    len = sizeof(void *);
    if (!frnbf_parse_handle(pop (stSTRING)->pointer, &size, &ptr)) return my_strdup("");
    if (size == -1) {
	sprintf(estring, "size of -1 designates a null-pointer");
	error(sERROR,estring);
	return my_strdup("");
    }
    if (offset<0 || (size >=0 && offset+len > size)) {
	sprintf(estring, "overrun: offset of %d plus length of string %d exceeds size of buffer %d",
		offset, len, size);
	error(sERROR, estring);
	return my_strdup("");
    }
    ptrptr = *((char **)((char *)ptr+offset));
    sprintf(string,"frnbf:%d:%p", ptrptr ? -2:-1, ptrptr);
    return my_strdup(string);
}


int
frnbf_parse_handle (char *handle, int *size, void **ptr)  /* parse handle */
{
    if (sscanf(handle, "frnbf:%d:%p", size, ptr) != 2) {
	sprintf(estring,"invalid handle for foreign buffer: '%s'", handle);
	error(sERROR, estring);
	return FALSE;
    }
    return TRUE;
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
    void *bufptr;
    int bufsize;
    
    /* In this dunction: go through list of arguments multiple times, check types and transfer them to libffi structures */

    /* count args on stack */
    st = stackhead;
    do {
	st = st->prev;
	listlen++;
    } while (st->type != stFREE);

    /* set options to default values */
    opt_error = TRUE;
    opt_copy_string_result = FALSE;
    opt_unload_library = TRUE; 
    
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

    /* check and retrieve first three arguments, libname, type and funame; they are always present */
    st = stfirst;
    for(i=0;i<3;i++) {
	if (st->type != stSTRING) {
	    stackdesc (st->type, stfound);
	    sprintf(string, "argument at position %d needs to be a string, not %s",i,stfound);
	    error (sERROR, string);
	    return FALSE;
	}
	if (i==0) libname=st->pointer;
	if (i==1 && !frn_decode_ffi_type (st->pointer, &rtype, &rtypetxt, ktANY)) return FALSE;
	if (i==2) funame=st->pointer;
	st = st->next;
    }

    /* check arguments to external function (pairs type and value), check and process options */
    stfirstarg = st;
    argcnt = 0;
    for(i=3;i<listlen-1;i+=2,st=st->next->next) {
	if (st->type != stSTRING) {
	    stackdesc (st->type, stfound);
	    sprintf(string, "argument at position %d needs to be a string, not %s",i,stfound);
	    error (sERROR, string);
	    return FALSE;
	}
	/* after optional string "options", parse rest of arguments as options */
	if (!strcmp(st->pointer,"options")) { 
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
		else if (!strcmp(opt_str,"copy_string_result"))
		    opt_copy_string_result = !opt_has_no;
		else if (!strcmp(opt_str,"unload_library"))
		    opt_unload_library = !opt_has_no;
                else {
		    sprintf(estring,"options can only be 'error', 'copy_string_result' and 'unload_library', optionally preceded by 'no_', not '%s'",opt_str);
		    error (sERROR,estring);
		}
	    }
	    break;
        }
	argcnt++;
    }

    /* allocate memory for ffi structures */
    vtypes = (ffi_type **) my_malloc(argcnt*sizeof(void *));
    vtypestxt = (char **) my_malloc(argcnt*sizeof(char *));
    values = (union FFI_VAL *) my_malloc(argcnt*sizeof(union FFI_VAL));
    pvalues = (union FFI_VAL **) my_malloc(argcnt*sizeof(void *));

    /* sort arguments passed on stack into ffi structures */
    st = stfirstarg;
    for(i=3,j=0;i<3+2*argcnt;i+=2,st=st->next->next,j++) {
	if (st->next->type == stSTRING) {
	    if (!frn_decode_ffi_type (st->pointer, vtypes+j, vtypestxt+j, ktCOMPLEX)) return FALSE;
	    if (!strcmp(vtypestxt[j],"string")) {
		values[j].ffipointer = (char *)st->next->pointer;
	    } else {
		if (!frnbf_parse_handle ((char *)st->next->pointer, &bufsize, &bufptr)) return FALSE;
		if (bufsize == -1) {
		    values[j].ffipointer = NULL;
		} else {
		    values[j].ffipointer = bufptr;
		}
	    }
	} else {
	    if (!frn_decode_ffi_type (st->pointer, vtypes+j, vtypestxt+j, ktSIMPLE)) return FALSE;
            frn_cast_to_ffi_type (values+j,vtypes[j],st->next->value);
        }
	pvalues[j] = values + j;
    }

    return TRUE;
}


static int
frn_decode_ffi_type (char *type_string, ffi_type **type_ptr, char **typetxt, int kind_of_type) /* decode ffi type given by first argument (string) into second argument (pointer to a ffi_type) and maybe produce error message */
{
    int i;
    int from, to;
    static char *ffi_types_string[NUM_FFI_TYPES] = {"uint8", "int8", "uint16", "int16", "uint32", "int32", "uint64", "int64", "float", "double", "char", "short", "int", "long", "buffer", "string"};
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

    switch (kind_of_type) {
    case ktSIMPLE: from = 0; to = NUM_FFI_TYPES-3; break;
    case ktCOMPLEX: from = NUM_FFI_TYPES-2; to = NUM_FFI_TYPES-1; break;
    case ktANY: from = 0; to = NUM_FFI_TYPES-1; break;
    }
    
    for(i=from;i<=to;i++) {
	if (!strcmp(type_string,ffi_types_string[i])) {
	    *type_ptr=ffi_types_ptr[i];
	    if (typetxt) *typetxt = ffi_types_string[i];
	    return TRUE;
	}
    }
    sprintf(string,"invalid type specification '%s', needs to be one of: ",type_string);
    for(i=from;i<=to;i++) {
	strcat(string,ffi_types_string[i]);
	strcat(string,",");
    }
    string[strlen(string)-1]='\0';
    error (sERROR,string);
    return FALSE;
}


static void
frn_cast_to_ffi_type (union FFI_VAL *value, ffi_type *type, double num) /* cast and assign double value from yabasic into specified (numeric) ffi_type */
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
frn_cast_from_ffi_type (union FFI_VAL *value, ffi_type *type) /* cast and return value from ffi_type to double */
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
	if (opt_unload_library) {
#ifdef UNIX
	    dlclose(lib);
#else
	    FreeLibrary(lib);
#endif
	}
	lib = NULL;
    }
    if (vtypes) {
	my_free(vtypes);
	vtypes = NULL;
    }
    if (vtypestxt) {
	my_free(vtypestxt);
	vtypestxt = NULL;
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

#endif /* USE_DL_FFI */
