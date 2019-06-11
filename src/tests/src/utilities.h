#ifndef UTILITIES_H
#define UTILITIES_H

void* loadLibrary(const char* libName);

void* getFunctionPointer(void* lib, const char* funcName);

#endif /* UTILITIES_H */
