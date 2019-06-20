#include "debug.h"


void set_print_debug(void (*fptr)(const char*)) {
	print_debug = fptr;
}