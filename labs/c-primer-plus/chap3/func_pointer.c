#include <stdio.h>

void test1()
{
	int add(int a,int b){
		return a+b;
	}

	int sub(int a,int b){
		return a-b;
	}

	int (*func_ptr)(int,int) = add;
	printf("add 3,5 = %d\n",func_ptr(3,5));

	func_ptr = sub;
	printf("sub 3,5 = %d\n",func_ptr(3,5));
}


void test2()
{
	void greet_english(char *name){
		printf("Hello,%s\n",name);
	}

	void greet_spanish(char *name){
		printf("Hola,%s\n",name);
	}

	void welcome(void (*greet)(char*),char *name){
		greet(name);
	}

	welcome(greet_english,"Alice");
	welcome(greet_spanish,"Alice");
}


void test3()
{
	int square(int x){
		return x*x;
	}
	
	int cube(int x){
		return x * x * x;
	}

	int (*funcs[2])(int) = {square,cube};
	
	for(int i = 0; i<2;i++){
		printf("%d ",funcs[i](3));
	}

	printf("\n");

}

int double_val(int x){
	return 2*x;
}

int triple_val(int x){
	return 3*x;
}

int (*get_operation(int mode))(int)
{
	return (mode == 1) ? double_val : triple_val;
} 

void test4()
{
	int (*op)(int) = get_operation(1);
	printf("get_operation mode 1 = %d\n",op(5));

	op = get_operation(2);
	printf("get_operation mode 2 = %d\n",op(5));	
}


typedef int (*CompareFunc)(int,int);

int ascending(int a,int b)
{
	return a-b;
}

int descending(int a,int b)
{
	return b-a;
}

void sort_simple_swap(int *arr,int size,CompareFunc compare)
{
	for(int i = 0;i<size-1;i++){
		for(int j = i+1;j<size;j++){
			if(compare(arr[i],arr[j]) > 0){
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void print_array(int *arr,int size)
{	
	for(int i = 0;i < size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void test5()
{
	int arr[5] ={9,25,6,1,788};
	sort_simple_swap(arr,5,ascending);
	print_array(arr,5);

	int arr2[5] = {9,25,6,1,788};
	sort_simple_swap(arr2,5,descending);
	print_array(arr2,5);
}


void sort_bubble_no_flag(int *arr,int size,CompareFunc compare)
{
	for(int i = 0; i < size - 1; i++){
		for(int j = size - 2; j >= i;j--){
			//printf("j = %d ",j);
			//printf("arr[%d] = %d , arr[%d] = %d\n",j,arr[j],j+1,arr[j+1]);
			if(compare(arr[j],arr[j+1]) > 0){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
} 

void sort_bubble_with_flag(int *arr,int size,CompareFunc compare)
{
	int flag;
	for(int i = 0;i<size-1;i++){
		flag = 0;
		for(int j = size - 2;j>=i;j--){
			if(compare(arr[j],arr[j+1]) > 0){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				flag = 1;
			}
		}

		if (flag == 0)
			break;
	}
}
			

void test6()
{
	int arr[9] = {1,9,2,5,8,3,7,4,6};
	sort_bubble_no_flag(arr,9,ascending);
	print_array(arr,9);

	int arr2[9] = {1,9,2,5,8,3,7,4,6};
	sort_bubble_no_flag(arr2,9,descending);
	print_array(arr2,9);
}


void test7()
{
	int arr[9] = {1,9,2,5,8,3,7,4,6};
	sort_bubble_with_flag(arr,9,ascending);
	print_array(arr,9);

	int arr2[9] = {1,9,2,5,8,3,7,4,6};
	sort_bubble_with_flag(arr2,9,descending);
	print_array(arr2,9);
}

struct Calculator{
	int (*add)(int,int);
	int (*sub)(int,int);
};

int my_add(int a,int b){
	return a+b+1;
}

int my_sub(int a,int b){
	return a-b-1;
}

void test8()
{
	struct Calculator c;
	c.add = my_add;
	c.sub = my_sub;

	printf("c.add(3,2) = %d\n",c.add(3,2));
	printf("c.sub(5,1) = %d\n",c.sub(5,1));

}


int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	return 0;
}
