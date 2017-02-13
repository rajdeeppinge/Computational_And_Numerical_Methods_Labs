#include<stdio.h>
#include<math.h>

float x[] = {-1, -0.8, -0.6, -0.4, -0.2, 0, 0.2, 0.4, 0.6, 0.8, 1};

float fx[11];

float h = 0.2;
float n = 10;

float factorial(int x)
{
	if(x==1)
		return 1;
	return x*factorial(x-1);
}

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

float delta5_fx(int i)
{
	return delta4_fx(i+1) - delta4_fx(i); 
}

float delta6_fx(int i)
{
	return delta5_fx(i+1) - delta5_fx(i);
}

float delta7_fx(int i)
{
	return delta6_fx(i+1) - delta6_fx(i);
}

float delta8_fx(int i)
{
	return delta7_fx(i+1) - delta7_fx(i); 
}

float delta9_fx(int i)
{
	return delta8_fx(i+1) - delta8_fx(i);
}

float delta10_fx(int i)
{
	return delta9_fx(i+1) - delta9_fx(i);
}

float forward_diff_soln(float x_find)
{
	float u = (x_find - x[0]) / h;

	return fx[0] + u * delta_fx(0) + u * (u-1) / 2 * delta2_fx(0) + u * (u-1) * (u-2) / 6.0 * delta3_fx(0) + u * (u-1) * (u-2) * (u-3) / 24.0 * delta4_fx(0) + u * (u-1) * (u-2) * (u-3) * (u-4) / 120.0 * delta5_fx(0) + u * (u-1) * (u-2) * (u-3) * (u-4) * (u-5) / 720.0 * delta6_fx(0) + u * (u-1) * (u-2) * (u-3) * (u-4) * (u-5) * (u-6) / 5040.0 * delta7_fx(0) + u * (u-1) * (u-2) * (u-3) * (u-4) * (u-5) * (u-6) * (u-7)/ 40320.0 * delta8_fx(0) + u * (u-1) * (u-2) * (u-3) * (u-4) * (u-5) * (u-6) * (u-7) * (u-8)/ factorial(9) * delta9_fx(0) + u * (u-1) * (u-2) * (u-3) * (u-4) * (u-5) * (u-6) * (u-7) * (u-8) * (u-9)/ factorial(10) * delta10_fx(0);
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

float nabla6_fx(int i)
{
	return nabla5_fx(i) - nabla5_fx(i-1); 
}

float nabla7_fx(int i)
{
	return nabla6_fx(i) - nabla6_fx(i-1);
}

float nabla8_fx(int i)
{
	return nabla7_fx(i) - nabla7_fx(i-1);
}

float nabla9_fx(int i)
{
	return nabla8_fx(i) - nabla8_fx(i-1);
}

float nabla10_fx(int i)
{
	return nabla9_fx(i) - nabla9_fx(i-1); 
}

float backward_diff_soln(float x_find)
{
	float u = (x_find - x[10]) / h;

	return fx[10] + u * nabla_fx(n) + u * (u+1) / 2.0 * nabla2_fx(n) + u * (u+1) * (u+2) / 6.0 * nabla3_fx(n) + u * (u+1) * (u+2) * (u+3) / 24.0 * nabla4_fx(n) + u * (u+1) * (u+2) * (u+3) * (u+4) / 120.0 * nabla5_fx(n) + u * (u+1) * (u+2) * (u+3) * (u+4) * (u+5) / 720.0 * nabla6_fx(n) + u * (u+1) * (u+2) * (u+3) * (u+4) * (u+5) * (u+6) / 5040.0 * nabla7_fx(n) + u * (u+1) * (u+2) * (u+3) * (u+4) * (u+5) * (u+6) * (u+7)/ 40320.0 * nabla8_fx(n) + u * (u+1) * (u+2) * (u+3) * (u+4) * (u+5) * (u+6) * (u+7) * (u+8)/ factorial(9) * nabla9_fx(n)+ u * (u+1) * (u+2) * (u+3) * (u+4) * (u+5) * (u+6) * (u+7) * (u+8) * (u+9)/ factorial(10) * nabla10_fx(n);
}


int main()
{
	FILE *fw = fopen ("fx.txt", "w+");
	//FILE *fw = fopen ("fx.txt", "w+");
   
	int i;
	for(i = 0; i<11; i++) {
		fx[i] = exp(x[i]);
		//fprintf(fw, "%f %f", x[i], fx[i]);
		//printf("%f: %f\n", x[i], fx[i]);
	}


	//plot fx
	float start = -5.0;
	for(start = -5; start <= 5; start += 0.001)
	{
		fprintf(fw, "%f %f %f %f\n", start, exp(start), forward_diff_soln(start), backward_diff_soln(start) );
	}

	fclose(fw);

	float x_find = -0.9;
	float Pn_fwd = forward_diff_soln(x_find);
	float Pn_bwd = backward_diff_soln(x_find);

	printf(" Newton's forward difference method: solution = %f\n", Pn_fwd);
	printf(" Newton's backward difference method: solution = %f\n", Pn_bwd); 
	return 0;
}
