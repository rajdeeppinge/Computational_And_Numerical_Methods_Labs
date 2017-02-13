//Program to find root by secant method

#include <stdio.h>
#include <math.h>
void secant();
double f(double x);


int main()
{
	secant();
	return 0;
}

// function implementing secand method
void secant()
{
	// initial values
    double xinit1=40;
    double xinit0=60;

    double epsi= 0.000001;	
    long iteration=0;
    
	//fist iteration
    double xcurr=xinit1;
    double xprev=xinit0; 
    double xnext= xcurr- f(xcurr)*(xcurr-xprev)/(f(xcurr)-f(xprev));
	printf("iteration: %ld \n",iteration+1);

	// loop doing the subsequent iterations
	while ( (fabs(xnext-xcurr) + fabs(f(xnext))) > epsi) // limiting condition
	{   
		// x(n-1) for current step = x(n) of previous step
        xprev=xcurr;

		// x(n) for current step = x(n+1) of previous step
        xcurr=xnext;

		// finding x(n+1) by formula OF SECANT METHOD 
	    xnext=  xcurr- f(xcurr)*(xcurr-xprev)/(f(xcurr)-f(xprev));
        
		iteration++;
        printf("iteration: %ld \n",iteration+1);
	}

     printf("Total iterations=%ld approx root=%f funcvalatroot %f \n",iteration+1, xnext, f(xnext));
}

//function
double f(double x)
{
	return cos(x)- x*exp(x);
}
