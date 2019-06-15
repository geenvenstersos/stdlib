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


/*

using System;
					
public class Program
{
	public static void Main()
	{
			Console.WriteLine("sin = " + sin(2));
	}
	
	public static double sin(double x) {
		int ordermax = 3;
		int fact = 1;
		double poweracc = 1;

		double sin = 0.0;

		for(int n = 0; n < ordermax; n++) {
			
			int term = (2*n + 1);
			
			Console.WriteLine("n = " + n);
			//Console.WriteLine("factorial = " + fact);
			//Console.WriteLine("term = " + term);
			Console.WriteLine("poweracc = " + poweracc);

			Console.WriteLine("sin = " + sin);

			sin += (n%2==0?-1:1) * x * poweracc/fact;

			fact = factorial(term+2, term, fact);
			poweracc = power(x, term+2, term, poweracc);

			Console.WriteLine("-------------------------------------------------");
		}

		return sin;
	}

	public static double power(double n, int powerend, int powerstart, double poweracc) {
		Console.WriteLine("###############################");
		//Console.WriteLine("power.n = " + n);
		//Console.WriteLine("power.powerend = " + powerend);
		//Console.WriteLine("power.powerstart = " + powerstart);
		//Console.WriteLine("power.poweracc = " + poweracc);

		if(powerstart > powerend) return 0;
		else if(powerstart == powerend) return 1;
	
		double ret = poweracc;

		for(int i = powerstart + 1; i <= powerend; i++) {
			//Console.WriteLine("power.for.i = " + i);
			ret *= n;
			Console.WriteLine("power.for.ret = " + ret);
		}
		Console.WriteLine("power.ret = " + ret);

		Console.WriteLine("###############################");
		return ret;
	}
	
	public static int factorial(int n, int start, int factorialstart) {
		if(start > n) return 0;
		else if(start == n) return 1;

		int ret = factorialstart;
		for(int i = start + 1; i <= n; i++) {
			ret *= i;
		}
		return ret;
	}
}

 */