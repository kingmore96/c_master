#include <stdio.h>
#include <stddef.h>

void test1()
{
	int a[2][3] =  {{1,2,3},{4,5,6}};
	
	int (*p1)[3] = a;
	int (*p2)[2][3] = &a;

	printf("access 6 : %d\n",*(*(p1+1)+2));
	printf("access 6 : %d\n",*(((int*)(p2+1))-1));
	printf("access 6 : %d\n",*((int*)((char*)(*p2) + sizeof(int) * 5)));
}


void test2()
{
	struct Point{
		int x;
		char y;
		double z;
	};
	
	struct Point arr[2] = {{1,'A',3.14},{5,'B',6.28}};
	struct Point *ptr = arr;
	struct Point (*ptr1)[2] = &arr;

	printf("access second Point : y = %c, z = %.2f\n",(ptr + 1)->y,*((double*)((char*)ptr + sizeof(struct Point) + offsetof(struct Point,z))));
	printf("access second Point : y = %c, z = %.2f\n",(*(ptr1 + 1) - 1)->y,*((double*)(ptr1 + 1)-1));
}


void test3()
{
	int *arr[2];

	int a[2] = {10,20};
	int b[3] = {30,40,50};

	arr[1] = a;
	arr[2] = b;

	printf("access a-20 : %d , access b-40 : %d\n",*(arr[1] + 1),arr[2][1]);
}

void test4()
{
	int matrix[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};

	int *ptr = &matrix[0][0];

	printf("access 6 : %d\n",*(ptr + 5));
	printf("access 3 : %d\n",*(*(matrix + 1) - 2));
	printf("access 11 : %d\n",*((int*)(&matrix + 1)-2));
}
	
	


int main(void)
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}

