#include <stdio.h>
#include <stdint.h>
#include <string.h>

void test1()
{
	int a = 12.99;
	printf("%d\n",a);
}

void test2()
{
	double a = 12.99;
	int b = a;
	printf("%d\n",b);
}

void test3()
{
	union{
		double d;
		uint64_t v;
	}c;

	uint64_t low = 1202590843ULL;
	uint64_t high = 1076493025ULL;
	
	uint64_t combined = high << 32 | low;
	c.v = combined;

	printf("%f\n",c.d);
}

void test4()
{
	union{
		double d;
		uint32_t v[2];
	}c;

	c.v[1] = 1076493025;
	c.v[0] = 1202590843;

	printf("%f\n",c.d);
}	

void test5()
{
	double d = 12.99;
	printf("%016llX\n",d);

	uint64_t bits;
	memcpy(&bits,&d,sizeof(bits));

	printf("%016lX\n",bits);
}


void test6()
{
	printf("py_low:1202590843U = %016X\n",1202590843U);
	printf("py_high:1076493025U = %016X\n",1076493025U);

	double d = 12.99;
	char *p = (char*)&d;

	for(int i = 0;i < sizeof(d);i++){
		printf("%02X ",(unsigned char)(*(p+i)));
	}
	printf("\n");
}

void test7()
{
	double d = 12.99;
	unsigned char *p = (unsigned char*)&d;
	
	unsigned char arr[4];
	uint32_t value;

	for(int i = 0; i < 2;i++){
		for(int j = 0;j<4;j++){
			arr[j] = *p;
			p = p + 1;
		}
		memcpy(&value,arr,sizeof(uint32_t));
		printf("value d = %d , X = %08X\n",value,value);
	}
}

int main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
}
