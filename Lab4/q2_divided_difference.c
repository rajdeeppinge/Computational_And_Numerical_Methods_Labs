#include<stdio.h>

float divided_diff(float a,float b,float c,float d)
{
	return (a-b)/(c-d);	
}

int main()
{
	float x[] = {1.4,1.6,1.8,2.0};
	float fx[] = {0.9192, 0.9452, 0.9641, 0.9772};
	
	float firstdd1 = divided_diff(fx[1],fx[0],x[1],x[0]);
	printf("f[x0,x1]: %0.10f\n",firstdd1);
	
	float firstdd2 = divided_diff(fx[2],fx[1],x[2],x[1]);
	float firstdd3 = divided_diff(fx[3],fx[2],x[3],x[2]);
	
	float seconddd1 = divided_diff(firstdd2,firstdd1,x[2],x[0]);
	printf("f[x0,x1,x2]: %0.10f\n",seconddd1);
	
	float seconddd2 = divided_diff(firstdd3,firstdd2,x[3],x[1]);
	
	float thirddd1 = divided_diff(seconddd2,seconddd1,x[3],x[0]);
	printf("f[x0,x1,x2,x3]: %0.10f\n",thirddd1);
	
	float Px_1_65 = fx[0] + (1.65-x[0])*firstdd1 + (1.65-x[0])*(1.65-x[1])*seconddd1 + (1.65-x[0])*(1.65-x[1])*(1.65-x[2])*thirddd1;
	printf("P(1.65) = %0s.10f\n",Px_1_65);
		
	return 0;
}


