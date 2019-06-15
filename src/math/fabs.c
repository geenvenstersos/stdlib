#include "math.h"

/**
 * Computes the absolute value of a float number. 
 * 
 * @param   n  The number.
 * @return  If successful, returns the absolute value of arg (|arg|).
 *          The value returned is exact and does not depend on any rounding modes.
 * 
 * @since  Always.
 */
#define _FABS(f) (f >= 0.0 ? (f) : (-f))

float fabs(float f) {
    return _FABS(f);
}