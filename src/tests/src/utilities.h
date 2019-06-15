#ifndef UTILITIES_H
#define UTILITIES_H

    void* loadLibrary(const char* libName);

    void* loadfunctionptr(void* lib, const char* funcName);

    char* fill_strings(char* string, char filling, int size);

#endif /* UTILITIES_H */
