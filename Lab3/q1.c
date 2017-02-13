/*
Program to find solution to a system of equations using the Generalized Newton's method
*/

#include <stdio.h>

// useful math functions
double f1 (double x, double y);
double f2 (double x, double y);
void gen_nr(double x_init,double y_init);
double mat_det(double x, double y);

int main()
{
// initialization
double x_init=1.5 ,y_init=0.5 ;

gen_nr(x_init,y_init); 
return 0; 
}

double f1 (double x, double y)
{
return x*x+x*y+y*y-7;
}

double f2 (double x, double y)
{
return x*x*x+y*y*y-9;
}

// determinant of the Jacobian matrix

double mat_det(double x, double y)
{
return 6*x*y*y+3*y*y*y- 3*x*x*x-6*x*x*y;
}

// generalized newton raphson method
void gen_nr(double x_init,double y_init)
{
	double xcurr,ycurr,xnext,ynext;
	int i;
    xcurr= x_init;
	ycurr=y_init;
    
	for(i=1;i<=4;i++)
	{
		// the following two statements can be expressed concisely as
		// V_next= V_curr - inv(Jacobian(V_curr))* F(V_curr)  , this is the vectorized form of the foll		
		xnext= xcurr- (( 3*ycurr*ycurr*f1(xcurr,ycurr) ) + ( (-xcurr-2*ycurr)*f2(xcurr,ycurr) ))/mat_det(xcurr,ycurr) ; 
		ynext= ycurr- (( -3*xcurr*xcurr*f1(xcurr,ycurr) ) + ( (2*xcurr+ycurr)*f2(xcurr,ycurr) ))/mat_det(xcurr,ycurr) ;

		printf("iter %d, x= %f , y= %f\n",i,xnext,ynext) ;

		// updating the previous values
		xcurr = xnext;
		ycurr= ynext ; // silly mistake forgot to update x y
	}

	// display final answer
	printf( "xfinal= %f , yfinal= %f\n",xnext,ynext); 	
}
