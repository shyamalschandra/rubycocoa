/** -*-objc-*-
 *
 *   $Id$
 *
 *   Copyright (c) 2001 FUJIMOTO Hisakuni
 *
 **/

#import <objc/objc-class.h>
#import <stdarg.h>
#import "osx_ruby.h"

#if HAVE_LONG_LONG
/* long long is missing from objc-class.h */
# ifndef _C_LLNG
#  define _C_LLNG 'q'
# endif
# ifndef _C_ULLNG
#  define _C_ULLNG 'Q'
# endif
/* NUM2ULL is missing from ruby.h */
# ifndef NUM2ULL
#  define NUM2ULL(x) (FIXNUM_P(x)?FIX2ULONG(x):rb_num2ull((VALUE)x))
# endif
#endif	/* HAVE_LONG_LONG */

#if !defined(_C_BOOL)
# define _C_BOOL 'B'
#endif

enum osxobjc_nsdata_type {
  _PRIV_C_BOOL = 1024,
  _PRIV_C_PTR,
  _PRIV_C_ID_PTR,
};

int     to_octype       (const char* oc_type_str);
size_t  ocdata_size     (int octype, const char* octype_str);
void*   ocdata_malloc   (int octype, const char* octype_str);
#define OCDATA_ALLOCA(octype,s)     alloca(ocdata_size((octype),(s)))

const char * rbobj_to_cselstr  (VALUE obj);
id           rbobj_to_nsselstr (VALUE obj);
SEL          rbobj_to_nssel    (VALUE obj);
BOOL         rbobj_to_nsobj    (VALUE obj, id* nsobj);
BOOL         rbobj_to_bool     (VALUE obj);
id           rbstr_to_ocstr    (VALUE obj);

VALUE    sel_to_rbobj (SEL val);
VALUE    int_to_rbobj (int val);
VALUE   uint_to_rbobj (unsigned int val);
VALUE double_to_rbobj (double val);
VALUE   bool_to_rbobj (BOOL val);
VALUE   ocid_to_rbobj (VALUE context_obj, id ocid);
VALUE  ocstr_to_rbstr (id ocstr);

BOOL  ocdata_to_rbobj (VALUE context_obj,
		       int octype, const void* ocdata, VALUE* result, BOOL from_libffi);
BOOL  rbobj_to_ocdata (VALUE obj, int octype, void* ocdata, BOOL to_libffi);

void init_rb2oc_cache(void);
void init_oc2rb_cache(void);
void remove_from_rb2oc_cache(VALUE rbobj);
void remove_from_oc2rb_cache(id ocid);

void decode_method_encoding(const char *encoding, unsigned *argc, char **retval_type, char ***arg_types, BOOL strip_first_two_args);
