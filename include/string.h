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


/**
 * Searches for the first occurrence of the character c (an unsigned char) 
 * in the first n bytes of the string pointed to, by the argument str.
 * 
 * @param   str  The string.
 * @param   c    The char.
 * @return       This function returns a pointer to the matching byte or 
 *               NULL if the character does not occur in the given memory area.
 * 
 * @since  Always.
 */
void *memchr(const void *str, int c, size_t n);

#endif