#include <stdio.h>
#include <math.h>

int main(void)
{
	printf("5.0 * 0.0 = %f\n",5.0*0.0);
	printf("5.0 * -0.0 = %f\n",5.0*-0.0);
	printf("-5.0 * 0.0 = %f\n",-5.0*0.0);
	printf("-5.0 * -0.0 = %f\n",-5.0*-0.0);

	printf("5.0 - 5.0 = %f\n",5.0 - 5.0);
	printf("-5.0 - -5.0 = %f\n",-5.0 - -5.0);
	
	union{
		unsigned int a;
		float b;
	}converter;
	
	converter.a = 0xFF800000;
	printf("exp result ninf = %f\n",exp(converter.b));

	converter.a = 0x7F800000;
	printf("exp result pinf = %f\n",exp(converter.b));
}
