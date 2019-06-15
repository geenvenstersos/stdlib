#include "math.h"

/**
 * Computes the absolute value of an integer number. 
 * The behavior is undefined if the result cannot be represented by the return type.
 * 
 * @param   n  The number.
 * @return  The absolute value.
 * 
 * @since  Always.
 */
#define _ABS(n) (n >= 0 ? (n) : (-n))

int abs(int n) {
    return _ABS(n);
}

long labs(long n) {
    return _ABS(n);
}