#include <stdio.h>


void test_one_div_zero()
{

	int result;

	result = 1/0;
	printf("1/0 = %d\n",result);
}

void test_fone_div_zero()
{
	float result;

	result = 1.0/0;
	printf("1.0/0 = %f\n",result);
}

void test_fone_div_fzero()
{
	float result;
	
	result = 1.0/0.0;
	printf("1.0/0.0 = %f\n",result);

	result = 1.0/-0.0;
	printf("1.0/-0.0 = %f\n",result);
}

int main(void)
{
	//test_one_div_zero();
	test_fone_div_zero();
	test_fone_div_fzero();
	return 0;
}
