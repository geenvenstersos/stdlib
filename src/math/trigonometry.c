#include "math.h"

unsigned long long int _power(int base, int exponent, int start, int startexponent) {
    
    if(exponent == 0) return 1;
    else if(exponent == 1) return base;
    
    int remaingexp = exponent-startexponent;
    
    if(remaingexp == 0) return base;
    
    int pwr = start;
    
    for(int n=0; n < remaingexp; n++) {
        pwr *= base;
    }
  
  return pwr;
}

unsigned long long int _factorial(int n, int start, int factorialstart) {
	if(start > n) return 0;
	else if(start == n) return 1;

	unsigned long long int ret = factorialstart;
	for(int i = start + 1; i <= n; i++) {
		ret *= i;
	}
	return ret;
}
	
double sin(double x) {
	int ordermax = 4;

	unsigned long long int fact = 1;

	double poweracc = x;

	double sin = 0.0;

	for(int n = 0; n < ordermax; n++) {
		
		int term = (2*n + 1);

		sin += (n%2==0?1:-1) * poweracc/fact;

		fact = _factorial(term+2, term, fact);
		poweracc = _power(x, term+2, poweracc, term);
	}

	return sin;
}

double cos(double n) {
    return 0.0;
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
