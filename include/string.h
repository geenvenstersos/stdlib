#ifndef _STRING_H
#define _STRING_H


#include <bits/types.h>

/**
 * `NULL`'s canonical header is <stddef.h>
 */
#ifndef NULL
# define NULL  ((void*)0)
#endif


/**
 * Returns the number of bytes in a NUL-terminated
 * string. This excludes the NUL byte.
 * 
 * @param   str  The string.
 * @return       The number of bytes before the first NUL byte.
 * 
 * @since  Always.
 */
size_t strlen(const char*);


#endif