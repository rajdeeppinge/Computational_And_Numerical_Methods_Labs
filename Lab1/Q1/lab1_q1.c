#include <stdio.h>
#include <math.h>
void newton_rhapson();
float f(float x);
float fderivative(float x);

int main()
{
newton_rhapson();

return 0;
}

void newton_rhapson()
{
    float xinit=5;
    float epsi= 0.0000001;	
    long iteration=0;
    float alpha=0;
    float conv=0;
	  
    float xcurr=xinit;
    float xnext= xcurr- f(xcurr)/fderivative(xcurr);

	int i=0;
	
//(fabs(xnext-xcurr) + fabs(f(xcurr)))
	
while ( i<100)
		{   
            i++;
            xcurr=xnext; 
		    xnext= xcurr- f(xcurr)/fderivative(xcurr);
            iteration++;
            conv= (alpha - xnext)/((alpha- xcurr)*(alpha-xcurr));
            printf("iteration: %ld, rconv is :%f\n",iteration, conv);
		}

     printf("Total iterations=%ld approx root=%f\n",iteration,xnext);
    
 
}

float f(float x)
{
return 1.0- exp(-(x*x));
}

float fderivative(float x)
{
return 2.0*x*exp(-(x*x));
}
