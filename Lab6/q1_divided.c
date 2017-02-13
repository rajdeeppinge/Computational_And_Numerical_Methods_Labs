#include<stdio.h>
#include <math.h>
double x_arr[]= {-1.5,-1,-0.5,0,0.5,1,1.5};

double fx_arr(double x)
{
 return 1/(sqrt(1+x*x));
}

float intervalues(double x, int i)
{
int j;
double product=1;
 for (j=0;j<i;j++)
	product *= (x-x_arr[j]);

return product;
}

float divided_diff(int start, int end)
{
	if( (end-start) == 1) 
		return (fx_arr(x_arr[end]) - fx_arr(x_arr[start]))/(x_arr[end]-x_arr[start]);

	return divided_diff(start+1, end) - divided_diff(start, end-1)/(x_arr[end]-x_arr[start]);
}


float p(int n,double x)
{
int i;
double fin_approx=fx_arr( x_arr[0] );
   for(i=1;i<=n;i++)
		 fin_approx += intervalues(x,i)*divided_diff(0,i);

	return fin_approx;
}


int main()
{
	
	printf("p(-0.25): %0.10f actual_val: %f\n",p(6, 0.75),fx_arr(0.75));
	
FILE *fw = fopen ("divided_final_ans.txt", "w+");
	//FILE *fw = fopen ("fx.txt", "w+");
   


  //plot fx
	float start = -3.0;


   
	for(start = -3; start <= 3; start += 0.001)
	{
 	
		fprintf(fw, "%f %f \n", start, p(6,start));
	}

	fclose(fw);

	return 0;
}


