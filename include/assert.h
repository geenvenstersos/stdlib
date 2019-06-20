#ifndef _ASSERT_H
#define _ASSERT_H

#ifdef assert
# undef assert
#endif

void _assert_fail(const char*, int, const char*, int, const char*);

#ifdef NDEBUG
# define assert(expression)   ((void)0)
#else
# define assert(expression)  \
  ((void)((expression) ? 0 : (_assert_fail(#expression, 0, __FILE__, __LINE__, NULL), 0)))
#endif


#endif