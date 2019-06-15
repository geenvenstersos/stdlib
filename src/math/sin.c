#include "math.h"


double sin(double x) {
    int ordermax = 10;
    int factorial = 1;
    int poweracc = 1;
    int factorialacc = 0;

    double sin = 0.0;


    for(int n = 0; n < ordermax; n++) {

        sin += (n%2==0?-1:1) * n * poweracc/factorial;

        poweracc *= n*n;
        
        factorial *= (factorialacc+1);
        
        factorialacc += 2;
    }

    return sin;
}
