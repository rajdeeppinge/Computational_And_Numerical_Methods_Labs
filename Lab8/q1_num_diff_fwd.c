#include<stdio.h>

float x[] = {6.0, 6.1, 6.2, 6.3, 6.4};
float fx[] = {0.175,-0.1998,-0.2223,-0.2422,-0.2596};

float h = 0.1;
float n = 4;

float delta_fx(int i, int deg)
{
	if(deg == 1)
		return fx[i+1] - fx[i];

	return delta_fx(i+1, deg-1) - delta_fx(i, deg-1);
}


float nabla_fx(int i, int deg)
{
	if(deg == 1)
		return fx[i] - fx[i-1];

	return nabla_fx(i, deg-1) - nabla_fx(i-1, deg-1);
}

int main()
{
	float fd_6 = ((double)1/h) * (delta_fx(0, 1) - (0.5*delta_fx(0, 2)) + ((1/(double)3)*delta_fx(0, 3)) - ((1/(double)4)*delta_fx(0, 4)) );

	float fdd_6_3 = ((double)1/h*h) * (nabla_fx(3, 2) + nabla_fx(3, 3));

	printf("f'(6.0) = %f\nf''(6.3) = %f\n", fd_6, fdd_6_3);

	return 0;
}
