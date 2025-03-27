#include <stdio.h>
#include <stdint.h>

void print_bits_float(float f)
{
	union{
		float a;
		uint32_t b;
	}c;
	c.a = f;

	printf("float %e print start\n",f);	
	for(int i=0;i<32;i++){
		printf("%d",c.b & 1 << (31 - i) ? 1 : 0);	
		
		if(i == 0 || i == 8)
			printf(" ");
	}
	printf("\n");
}

void print_bits_double(double d)
{
	union{
		double a;
		uint64_t b;
	}c;
	c.a = d;

	printf("double %e print start\n",d);
	for(int i =0 ;i<64;i++){
		printf("%d",c.b & (1ULL << (63 - i)) ? 1 : 0);//caution!!! 1ULL not 1 because 1 << or >> more than 31 is undefined behaviour.

		if(i == 0 || i == 11)
			printf(" ");
	}
	printf("\n");
}

void double_test()
{
	double a,b;
	
	b = 2.0e20 + 1.0;
	print_bits_double(2.0e20);
	print_bits_double(1.0);
	print_bits_double(b);
	a = b - 2.0e20;
	print_bits_double(a);
}

void float_test()
{
	
	float a,b;
	
	b = 2.0e20 + 1.0;
	print_bits_float(b);
	a = b - 2.0e20;
	print_bits_float(a);
	printf("a = %f\n",a);
}

int main(void)
{
	double_test();
	float_test();	
}
