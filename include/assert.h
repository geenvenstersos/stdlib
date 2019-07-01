#ifdef assert
# undef assert
#endif

#ifdef NDEBUG
    #define assert(expression)   ((void)0)
#else

    void __assert_fail(const char* expression, int errnum, const char* file, int line, const char* func);

    # define assert(expression)  \
        ((void)((expression) ? (void)0 : (_assert_fail(#expression, 0, __FILE__, __LINE__, NULL), 0)))
#endif