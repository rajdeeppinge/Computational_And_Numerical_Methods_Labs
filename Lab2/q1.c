//Program to find root by Newton-Raphson method

#include <stdio.h>
#include <math.h>

void newton_raphson();
double f(double x);
double fderivative(double x);

int main()
{
	newton_raphson();
	return 0;
}

// function implementing newton raphson method
void newton_raphson()
{
	//initial value
    double xinit=1;

    double epsi= 0.000001;	
    long iteration=0;
      
	//fist iteration
    double xcurr=xinit;
    double xnext= xcurr- f(xcurr)/fderivative(xcurr);
	printf("iteration: %ld \n",iteration+1);

	// loop doing the subsequent iterations
	while ( (fabs(xnext-xcurr) + fabs(f(xcurr))) > epsi)	// limiting condition
	{   
		// x(n) for current step = x(n+1) of previous step
        xcurr=xnext;
	
		// finding x(n+1) by formula 
	    xnext= xcurr- f(xcurr)/fderivative(xcurr);

        iteration++;
        printf("iteration: %ld \n",iteration+1);
	}

     printf("Total iterations=%ld approx root=%f funcvalatroot %f \n",iteration+1,xnext,f(xnext));
}

// function
double f(double x)
{
return cos(x)- x*exp(x);
}

// first derivative
double fderivative(double x)
{
return -sin(x)-(exp(x)*(1+x));
}
