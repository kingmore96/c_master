#include <stdio.h>
#include <stddef.h>

typedef short t;

typedef struct __attribute__((aligned(4))) A {
	t v1;
	char v2;
	int v3;
	short v4;
} A_t;

typedef struct B {
	char v1;
	A_t v2;
} B_t;

typedef struct __attribute__((aligned(32))) C {
	char v1;
	A_t v2;
} C_t;

int main(){
	printf("A_t size:%d\n",(int)sizeof(A_t));
	printf("A_t offset v1:%d\n",offsetof(A_t,v1));
	printf("A_t offset v2:%d\n",offsetof(A_t,v2));
	printf("A_t offset v3:%d\n",offsetof(A_t,v3));
	printf("A_t offset v4:%d\n",offsetof(A_t,v4));

	printf("\n");

	printf("B_t size:%d\n",(int)sizeof(B_t));
	printf("B_t offset v1:%d\n",offsetof(B_t,v1));
	printf("B_t offset v2:%d\n",offsetof(B_t,v2));

	printf("\n");


	printf("C_t size:%d\n",(int)sizeof(C_t));
	printf("C_t offset v1:%d\n",offsetof(C_t,v1));
	printf("C_t offset v2:%d\n",offsetof(C_t,v2));
	return 0;
}

	
