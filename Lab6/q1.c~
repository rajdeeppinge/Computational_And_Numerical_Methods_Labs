#include <stdio.h>
#include <math.h>

double x_arr[]= {-1.5,-1,-0.5,0,0.5,1,1.5};

double f(double x)
{
 return 1/(sqrt(1+x*x));


}

double quad_piece(int i, double x)
{
  return (x-x_arr[i])*(x-x_arr[i+1])*f(x_arr[i-1])/((x_arr[i-1]-x_arr[i]) * (x_arr[i-1]-x_arr[i+1])) +
   (x-x_arr[i-1])*(x-x_arr[i+1])*f(x_arr[i])/((x_arr[i]-x_arr[i-1]) * (x_arr[i]-x_arr[i+1])) +
   (x-x_arr[i-1])*(x-x_arr[i])*f(x_arr[i+1])/((x_arr[i+1]-x_arr[i-1]) * (x_arr[i+1]-x_arr[i]));
}

double cubic_piece(int i, double x)
{
  return (x-x_arr[i])*(x-x_arr[i+1])*(x-x_arr[i+2])*f(x_arr[i-1])/((x_arr[i-1]-x_arr[i]) * (x_arr[i-1]-x_arr[i+1])*(x_arr[i-1]-x_arr[i+2])) +
   (x-x_arr[i-1])*(x-x_arr[i+1])*(x-x_arr[i+2])*f(x_arr[i])/((x_arr[i]-x_arr[i-1]) * (x_arr[i]-x_arr[i+1])*(x_arr[i]-x_arr[i+2]))+
   (x-x_arr[i-1])*(x-x_arr[i])*(x-x_arr[i+2])*f(x_arr[i+1])/((x_arr[i+1]-x_arr[i-1]) * (x_arr[i+1]-x_arr[i])*(x_arr[i+1]-x_arr[i+2]))+
   (x-x_arr[i-1])*(x-x_arr[i])*(x-x_arr[i+1])*f(x_arr[i+2])/((x_arr[i+2]-x_arr[i-1]) * (x_arr[i+2]-x_arr[i])*(x_arr[i+2]-x_arr[i+1]));
}


int main()
{
printf("quad:%f cubic:%f actual_val %f\n",quad_piece(4,0.75),cubic_piece(4,0.75),f(0.75));


FILE *fw = fopen ("piece_final_ans.txt", "w+");
	//FILE *fw = fopen ("fx.txt", "w+");
   


  //plot fx
	float start = -3.0;

   int deg=0;

   
	for(start = -3; start <= 3; start += 0.001)
	{
 		if (start<-1)
			deg=1;
		else if (start<-0.5)
			deg=2;
		else if (start<0)
			deg=3;
		else if (start<0.5)
			deg=4;
		else deg=5;

		fprintf(fw, "%f %f %f %f\n", start, quad_piece(deg,start),cubic_piece(deg,start),f(start) );
	}

	fclose(fw);

return 0;
}


