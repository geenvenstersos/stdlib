#include "utilities.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


void* loadLibrary(const char* libName) {
	return dlopen(libName,  RTLD_LAZY | RTLD_GLOBAL);
}

void* getFunctionPointer(void* lib, const char* funcName) {

	assert(lib != NULL);
	assert(funcName != NULL);

    printf("Looking for function pointer %s.\n\n", funcName);

    void* fptr = dlsym(lib, funcName);

    if (!fptr) {
      printf("Could not get function pointer for %s\n  error is: %s\n\n", funcName, dlerror());
      return NULL;
    }
    return fptr;
}