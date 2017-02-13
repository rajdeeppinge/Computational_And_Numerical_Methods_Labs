#include<stdio.h>

float x_find = 0.15;
float x[] = {0.1, 0.2, 0.3, 0.4, 0.5};
float fx[] = {0.09983, 0.19867, 0.29552, 0.38942, 0.47943};
float h = 0.1;
float n = 4;

float factorial(int x)
{
	if(x==1)
		return 1;
	return x*factorial(x-1);
}

float delta_fx(int i, int deg)
{
	if(deg == 1)
		return fx[i+1] - fx[i];

	return delta_fx(i+1, deg-1) - delta_fx(i, deg-1);
}

float u_terms_fwd(int deg)
{
	float u = (x_find - x[0]) / h;
	float ans = 1;	
	int i;
	for(i = 0; i < deg; i++)
	{
		ans *= (u-i);
	}

	return ans;
}

float forward_diff_soln(float x_find)
{
	float final_ans = fx[0];

	int i;
	for(i = 1; i <= n; i++)
	{
		final_ans += u_terms_fwd(i)/factorial(i) * delta_fx(0, i);
	}

	return final_ans;
}


float nabla_fx(int i, int deg)
{
	if(deg == 1)
		return fx[i] - fx[i-1];

	return nabla_fx(i, deg-1) - nabla_fx(i-1, deg-1);
}

float u_terms_back(int deg)
{
	float u = (x_find - x[4]) / h;
	float ans = 1;	
	int i;
	for(i = 0; i < deg; i++)
	{
		ans *= (u+i);
	}

	return ans;
}

float backward_diff_soln(float x_find)
{
	float final_ans = fx[4];

	int i;
	for(i = 1; i <= n; i++)
	{
		final_ans += u_terms_back(i)/factorial(i) * nabla_fx(n, i);
	}

	return final_ans;
}


int main()
{
	float Pn_fwd = forward_diff_soln(x_find);
	float Pn_bwd = backward_diff_soln(x_find);

	printf(" Newton's forward difference method: solution = %f\n", Pn_fwd);
	printf(" Newton's backward difference method: solution = %f\n", Pn_bwd); 
	return 0;
}
