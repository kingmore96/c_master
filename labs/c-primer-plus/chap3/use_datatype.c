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

void print_bits_double(double d)
{
	union{
		double d;
		uint64_t v;
	}c;

	c.d = d;
	
	for(int i = 0;i<64;i++){
		printf("%d",(c.v & 1ULL<<(64-i-1))? 1:0);
		if(i == 0 || i == 11){
			printf(" ");
		}
	}
	printf("\n");
}

void print_bits_float(float f)
{
	union{
		float f;
		uint32_t v;
	}c;
	c.f = f;

	for(int i =0;i<32;i++){
		printf("%d",(c.v &1<<(32-i-1))? 1: 0);
		if(i == 0 || i == 8){
			printf(" ");
		}
	}
	printf("\n");
}
	

void test8()
{
	double d = 3.1415926534;
	print_bits_double(d);
	printf("3.1415926534 = %.15f\n",d);

	float f = d;
	print_bits_float(f);
	printf("3.1415926534 = %.15f\n",f);

	float f2 = 3.1415926534;
	printf("3.1415926534 = %.15f\n",f2);

	union{
		float f2;
		uint32_t v;
	}c;

	c.v = 1078530011U;
	printf("1078530011U = %.15f\n",c.f2);
}

void test9()
{
	int i = 70000;
	short s = i;

	unsigned char *p = (unsigned char*)&i;

	for(int i =0;i<sizeof(i);i++){
		printf("%02X ",*(p+i));
	}

	printf("\n");
	p = (unsigned char*)&i;

	for(int i = 0;i<sizeof(short);i++){
		printf("%02X ",*(p+i));
	}
	printf("\n");
}	

void test10()
{
	unsigned long ul_a = 0xFFFFFFFFFFFFFFFFL;
	unsigned long long ull_b = ul_a;

	printf("ul_a = %lu, ull_b = %llu\n",ul_a,ull_b);

	unsigned int ui_a = 0xFFFFFFFF;
	int i_b = ui_a;
	printf("ui_a = %u, i_b = %d\n",ui_a,i_b);
	
	int i_a = 0xFFFFFFFF;
	unsigned int ui_b = i_a;
	printf("i_a = %d,ui_b = %u\n",i_a,ui_b);

	long l_a = 0xFFFFFFFFFFFFFFFF;
	long long ll_b = l_a;
	printf("l_a = %ld, ll_b = %lld\n",l_a,ll_b);
}

void test11()
{
	uint64_t u64 = 0xFFFFFFFFFFFFFFFFL;
	uint32_t u32 = u64;
	printf("u32 = %u\n",u32);

	int32_t i32 = u64;
	printf("i32 = %d\n",i32);

	int64_t i64 = 0xFFFFFFFFFFFFFFFFL;
	u32 = i64;
	printf("u32 = %u\n",u32);

	i32 = i64;
	printf("i32 = %d\n",i32);
}

void test12()
{
	uint32_t u32 = 0xFFFFFFFF;
	uint64_t u64 = u32;
	printf("u64 = %lu\n",u64);

	uint16_t u16 = 0xFFFF;
	u64 = u16;
	printf("u64 = %lu\n",u64);

	int64_t i64 = u32;
	printf("i64 = %ld\n",i64);
	
	i64 = u16;
	printf("i64 = %ld\n",i64);
	
	int32_t i32 = 0xFFFFFFFF;
	u64 = i32;
	printf("u64 = %lu\n",u64);

	int16_t i16 = 0xFFFF;
	u64 = i16;
	printf("u64 = %lu\n",u64);

	i64 = i32;
	printf("i64 = %ld\n",i64);

	i64 = i16;
	printf("i64 = %ld\n",i64);
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
	test8();
	test9();
	test10();
	test11();
	test12();
}
