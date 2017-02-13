#include<stdio.h>

float x[] = {0.1, 0.2, 0.3, 0.4, 0.5};
float fx[] = {0.09983, 0.19867, 0.29552, 0.38942, 0.47943};
float h = 0.1;
float n = 4;

float delta_fx(int i)
{
	return fx[i+1] - fx[i];
}

float delta2_fx(int i)
{
	return delta_fx(i+1) - delta_fx(i); 
}

float delta3_fx(int i)
{
	return delta2_fx(i+1) - delta2_fx(i);
}

float delta4_fx(int i)
{
	return delta3_fx(i+1) - delta3_fx(i);
}

float forward_diff_soln(float x_find)
{
	float u = (x_find - x[0]) / h;

	return fx[0] + u * delta_fx(0) + u * (u-1) / 2 * delta2_fx(0) + u * (u-1) * (u-2) / 6.0 * delta3_fx(0) + u * (u-1) * (u-2) * (u-3) / 24.0 * delta4_fx(0);
}


float nabla_fx(int i)
{
	return fx[i] - fx[i-1];
}

float nabla2_fx(int i)
{
	return nabla_fx(i) - nabla_fx(i-1); 
}

float nabla3_fx(int i)
{
	return nabla2_fx(i) - nabla2_fx(i-1);
}

float nabla4_fx(int i)
{
	return nabla3_fx(i) - nabla3_fx(i-1);
}

float nabla5_fx(int i)
{
	return nabla4_fx(i) - nabla4_fx(i-1);
}

float backward_diff_soln(float x_find)
{
	float u = (x_find - x[4]) / h;

	return fx[4] + u * nabla_fx(n) + u * (u+1) / 2 * nabla2_fx(n) + u * (u+1) * (u+2) / 6.0 * nabla3_fx(n) + u * (u+1) * (u+2) * (u+3) / 24.0 * nabla4_fx(n);
}


int main()
{
	float x_find = 0.15;
	float Pn_fwd = forward_diff_soln(x_find);
	float Pn_bwd = backward_diff_soln(x_find);

	printf(" Newton's forward difference method: solution = %f\n", Pn_fwd);
	printf(" Newton's backward difference method: solution = %f\n", Pn_bwd); 
	return 0;
}
