#include <string.h>



/**
 * Searches for the first occurrence of the character c (an unsigned char) 
 * in the first n bytes of the string pointed to, by the argument str.
 * 
 * @param   str  The string.
 * @param   c    The char.
 * @param   n    end of the String
 * @return       This function returns a pointer to the matching byte or 
 *               NULL if the character does not occur in the given memory area.
 * 
 * @since  Always.
 */
void* memchr(const void *str, int c, size_t n)
{
  char* charptr = str;

  while(n--) {
    if(charptr[n] == c) return charptr + n;
  }
  return NULL;
}