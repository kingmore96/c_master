#include <stdio.h>
#include <stdarg.h>

int sum(int count,...)
{
	int total = 0;
	va_list args;

	va_start(args,count);

	for(int i=0;i<count;i++){
		total += va_arg(args,int);
	}
	
	va_end(args);

	return total;
}

int main(void)
{
	printf("sum of no args = %d\n",sum(0));
	printf("sum of 1,2,3 = %d\n",sum(3,1,2,3));
	printf("sum of 7,8,9,10 = %d\n",sum(4,7,8,9,10));
	return 0;
}

	
	
