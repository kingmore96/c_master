#include <stdio.h>
#include <stdint.h>
#include <string.h>

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
	uint32_t bits;
	memcpy(&bits,&num,sizeof(num));

	const uint32_t exp_mask = 0x7F800000;
	const uint32_t mantissa_mask = 0x007FFFFF;

	uint32_t exp = (bits & exp_mask) >> 23;
	uint32_t mantissa = bits & mantissa_mask;

	//1. 0xFF will be received as int.
		//if the value exceeds the range of int, then try unsigned int,long,unsigned long etc...
	//2. the int type 0xFF is promoted to uint32_t for comparison with exp
		//promotion rules:
		//zero extention: high bits will be padded with zeros.
			//applicable types:unsigned types
		//sign extention: high bits will be padded with the sign bit of the original data type.
			//applicable types:signed types
		//Rule:
		//1. Integer with a width smaller than int(such as short char) will be promoted to int or unsigned int when participating in the operation.
		//2. When operand types are different, the type with the lower priority will be converted to the type with the higher priority.
			//1. The priority of unsigned types is higher than that of signed types.
			//2. Types with greater width have a higher priority.
		//Usage recommendations:
		//1. Prefer using unsigned types for bit operations.
		//2. The signed types may lead to unexpected results when mixed with unsigned types after sign extention.
	if(exp == 0xFF){
		return mantissa ? FLOAT_NAN:FLOAT_INF; 
	}

	if(exp == 0 && mantissa != 0){
		return FLOAT_DEBORMAL;
	}
	return FLOAT_VALID;
}



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

