#ifndef _DEBUG_H
#define _DEBUG_H


void (*print_debug)(const char*);
void set_print_debug(void (*fptr)(const char*));

#ifndef NDEBUG

#define TRACE(message) print_debug(message)

#else

#define TRACE(message) ((void)0)

#endif



#endif