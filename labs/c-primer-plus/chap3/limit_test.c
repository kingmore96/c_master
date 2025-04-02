#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>

int safe_add_no_testb(int a,int b)
{
	if(a > 0 && b > INT_MAX - a)
		return INT_MAX;

	if(a < 0 && b < INT_MIN - a)
		return INT_MIN;
	return a+b;
}


int safe_add_testb(int a,int b)
{
	if(a > 0 && b > 0 && b > INT_MAX - a)
		return INT_MAX;

	if(a < 0 && b < 0 && b < INT_MIN - a)
		return INT_MIN;
	return a+b;
}

int test1()
{
	long cal_counts = 2000000000;	
	clock_t start,end;
	
	start = clock();
	for(long i = 0; i< cal_counts;i++){
		safe_add_no_testb(i%2?100:-100,i%3?1:-1);
	}
	end = clock();
	printf("no_testb time = %f\n",(double)(end - start)/CLOCKS_PER_SEC);
	
	start = clock();
	for(long i =0;i<cal_counts;i++){
		safe_add_testb(i%2?100:-100,i%3?1:-1);
	}
	end = clock();
	printf("testb time = %f\n",(double)(end - start)/CLOCKS_PER_SEC);

	return 0;
}

int convert_long_to_int(long value)
{
	if(value > INT_MAX)
		return INT_MAX;

	if(value < INT_MIN)
		return INT_MIN;

	return (int)value;	
}



int test2()
{
	printf("origin 256L = %ld , convert = %d\n",256L,convert_long_to_int(256L));

	printf("origin (long)INT_MAX = %ld , convert = %d\n",(long)INT_MAX,convert_long_to_int((long)INT_MAX));
	printf("origin 0x000000007FFFFFFFL = %ld , convert = %d\n",0x000000007FFFFFFFL,convert_long_to_int(0x000000007FFFFFFFL));

	printf("origin (long)INT_MAX+1 = %ld , convert = %d\n",(long)INT_MAX+1,convert_long_to_int((long)INT_MAX+1));
	printf("origin 0x0000000080000000L = %ld , convert = %d\n",0x0000000080000000L,convert_long_to_int(0x0000000080000000L));

	printf("origin (long)INT_MIN = %ld , convert = %d\n",(long)INT_MIN,convert_long_to_int((long)INT_MIN));
	printf("origin 0xFFFFFFFF800000000L = %ld , convert = %d\n",0xFFFFFFFF80000000L,convert_long_to_int(0xFFFFFFFF80000000L));

	printf("origin (long)INT_MIN-1 = %ld , convert = %d\n",(long)INT_MIN-1,convert_long_to_int((long)INT_MIN-1));
	printf("origin 0xFFFFFFFF7FFFFFFFFL = %ld , convert = %d\n",0xFFFFFFFF7FFFFFFFL,convert_long_to_int(0xFFFFFFFF7FFFFFFFL));
}


void* safe_malloc(size_t count,size_t item_size)
{
	if(item_size <= 0)
		return NULL;
	
	if(count > 0 && count > SIZE_MAX/item_size)
		return NULL;
	
	return malloc(count * item_size);
}

int test3()
{
	printf("SIZE_MAX = %zu,%lx\n",SIZE_MAX,SIZE_MAX);
	printf("size_t bits = %zu\n",sizeof(size_t) * 8);
	printf("safe_malloc(0xFFFFFFFFFFFFFFFF,sizeof(int)) = %s\n",safe_malloc(0xFFFFFFFFFFFFFFFFL,sizeof(int)) == NULL? "falied!":"success!");
	printf("safe_malloc(0xFF,-1) = %s\n",safe_malloc(0xFF,-1) == NULL ? "failed":"success");
	printf("safe_malloc(0xFF,sizeof(int)) = %s\n",safe_malloc(0xFF,sizeof(int)) == NULL ? "falied!":"success!");
}

int main()
{
//	test1();
	test2();
	test3();
	return 0;
}



