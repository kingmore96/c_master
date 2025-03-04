#include <stdio.h>
#include <stdint.h>

#define print_binary(x) _Generic((x), \
        float: print_float_binary, \
        double: print_double_binary \
)(x)

#define FLOAT_VALID	0
#define FLOAT_NAN	1
#define FLOAT_INF	2
#define FLOAT_DENORMAL	3
#define ERROR_INVALID_INPUT 0x8001

int valid_float(float num)
{
	//Strict Aliasing Rule
	




void print_bits(uint64_t bits,int max_bits_index,int exponent_length)
{
	for(int i = max_bits_index ; i >= 0 ; i--){
		printf("%d",((bits >> i) & 1) ? 1:0);
		if(i == max_bits_index || i == max_bits_index - exponent_length){
			printf(" ");
		}
	}
}


void print_float_binary(float num)
{
	union{
		float f;
		uint32_t u;
	}converter;

	converter.f = num;
	print_bits(converter.u,31,8);
}

void print_double_binary(double num)
{
	union{
		double d;
		uint64_t u;
	}converter;

	converter.d = num;
	print_bits(converter.u,63,11);
}

int main(void)
{
	double d = 435.25;
	float f = 435.25f;

	print_binary(d);
	printf("\n");
	print_binary(f);
	printf("\n");

	return 0;
}

