#include <string.h>



/**
 * Returns the number of bytes in a NUL-terminated
 * string. This excludes the NUL byte.
 * 
 * @param   str  The string.
 * @return       The number of bytes before the first NUL byte.
 * 
 * @since  Always.
 */
size_t strlen(const char* str)
{
  const char* s = str;
  while (*str++);
  return (size_t)(str - s - 1);
}
