#include "utilities.h"

#include "log.h"
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

  log_info("Looking for function pointer '%s'.", funcName);

  void* fptr = dlsym(lib, funcName);

  if (!fptr) {
    log_error("Could not get function pointer for %s\n  error is: %s.", funcName, dlerror());
    return NULL;
  }
  return fptr;
}

char* fill_strings(char* string, char filling, int size) {
  while(size--) {
    string[size] = filling;
  }

  return string;
}