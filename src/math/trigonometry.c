#include "math.h"


#define TAYLOR_MAX_ORDER 5


#ifdef __DEBUG__
void (*print_debug)(const char*);

void set_print_debug(void (*fptr)(const char*)) {
	print_debug = fptr;
}

#define TRACE(message) print_debug(message)

#else

#define TRACE(message) 

#endif


unsigned long long int _power(int base, int exponent, unsigned long long int start, int startexponent) {

#ifdef __DEBUG__
	//if(start%base != 0 || start < base) return 0;
#endif
	
    if(exponent == 0) return 1;
    else if(exponent == 1) return base;
    
    int remaingexp = exponent - startexponent;

    if(remaingexp == 0) return base;
    
    unsigned long long int pwr = start;
    
    for(int n = 0; n < remaingexp; n++) {
        pwr *= base;
    }
  
  return pwr;
}

unsigned long long int _factorial(const int n, unsigned long long int start, int factorialstart) {

	if(n == 0 || n == 1) return 1;
	else if(n == factorialstart) return factorialstart;
	else if(n < factorialstart) return 0;

	start = start == 0 ? 1 : start;
	factorialstart = factorialstart == 0 ? 1 : factorialstart;

	for(int i = factorialstart + 1; i <= n; i++)  start *= i;

	return start;
}
	
double tan(double n) {
    return 0.0;
}

double asin(double n) {
    return 0.0;
}

double acos(double n) {
    return 0.0;
}

double atan(double n) {
    return 0.0;
}

double atan2(double a, double b) {
    return 0.0;
}

double sin(double x) {

	TRACE(">>>>>>>>>>>>>>>>>>>>> CALLING SIN(X) <<<<<<<<<<<<<<<<<<<<\n");

	int ordermax = TAYLOR_MAX_ORDER;

	unsigned long long int fact = 1;

	double poweracc = x;

	double sin = 0.0;

	for(int n = 0; n < ordermax; n++) {
		
		int term = (2 * n + 1);

		poweracc = _power(x, term, x, 1);

		if(poweracc <= 0.0) return 0.0;

		fact = _factorial(term, 1, 1);

		sin += (n%2==0?1.0:-1.0) * poweracc/fact;
	}

	return sin;
}

double cos(double x) {

	int ordermax = TAYLOR_MAX_ORDER;

	unsigned long long int fact = 1;

	double poweracc = x;

	double cos = 0.0;

	for(int n = 0; n < ordermax; n++) {
		
		int term = (2 * n);

		poweracc = _power(x, term, x, 1);

		fact = _factorial(term, 1, 1);

		cos += (n%2==0?1.0:-1.0) * poweracc/fact;
	}

	return cos;
}