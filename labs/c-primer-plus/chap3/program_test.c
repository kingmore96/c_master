#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void print_bits_float(uint32_t v)
{
	for(int i = 0;i<32;i++){
		printf("%d",(v & 1<<(32-i-1)) ? 1:0);
		if(i == 0 | i == 8){
			printf(" ");
		}
	}
	printf("\n");
}

int test1()
{
	int a = 0x7FFFFFFF;
	printf("int a = %d\n",a + 1);

	union{
		float a;
		uint32_t v;
	}c;

	c.v = 0x7F7FFFFF;
	printf("float a = %f\n",c.a * 2);

	c.v = 0x00800000;

	for(int i = 0;i<24;i++){
		c.a = c.a / 2.0f;		
		printf("float a = %a\n",c.a);
		print_bits_float(c.v);
	}
	return 0;
}

void test2()
{
	int a;
	printf("please input an ascii value:___\b\b\b");
	scanf("%d",&a);

	if(a < 0 || a>127){
		printf("invalid value = %d, shoule range [0,127]\n",a);
		exit(-1);
	}
	printf("%c\n",a);
}
	

int main(void)
{
	test1();
	test2();
	
	return 0;
}
