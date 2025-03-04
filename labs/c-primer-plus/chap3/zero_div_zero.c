#include <stdio.h>
#include <stdint.h>

void print_float_binary(float num)
{
	union
	{
		float f;
		uint32_t u;
	}converter;

	int i;

	converter.f = num;
	uint32_t bits = converter.u;

	for(i = 31;i >= 0;i--)
	{
		printf("%d",((bits>>i)&1)? 1 : 0);
		if(i == 31 || i == 23)
		{
			printf(" ");
		}
	}
	printf("\n");
}	


int main(void)
{
	float a = 0/0.0;
	float b = 0.0/0.0;
	float c = -0.0/0.0;

	float d = 0/-0.0;
	float e = 0.0/-0.0;
	float f = -0.0/-0.0;

	float g = 0.0/0;
	float h = -0.0/0;

	printf("0/0.0 = %f\n",a);
	printf("0.0/0.0 = %f\n",b);
	printf("-0.0/0.0 = %f\n",c);

	printf("0/-0.0 = %f\n",d);
	printf("0.0/-0.0 = %f\n",e);
	printf("-0.0/-0.0 = %f\n",f);

	printf("0.0/0 = %f\n",g);
	printf("-0.0/0 = %f\n",h);

	print_float_binary(a);
	print_float_binary(b);
	print_float_binary(c);
	print_float_binary(d);

	return 0;
}


