#include <stdio.h>
#include <stddef.h>

typedef struct A {
	int v1;
	double v2;
	char v3;
} A_t;

typedef struct B {
	int v1;
	double v2;
	char v3;
	int v4;
}__attribute__((aligned(2))) B_t;//struct max align size is 4 in 32bit system,when align 2,it finally use 4;

typedef struct __attribute__((aligned(8))) C {//struct max align size is 4 in 32bit system ,when align 8 ,it finally use 8(max of these two params)
	int v1;
	double v2;
	char v3;
	int v4;
} C_t;

typedef struct __attribute__((packed)) D {
	int v1;
	double v2;
	char v3;
} D_t;

int main(){
	printf("A_t size:%d\n",(int)sizeof(A_t));
	printf("A_t offset v1:%d\n",offsetof(A_t,v1));
	printf("A_t offset v2:%d\n",offsetof(A_t,v2));
	printf("A_t offset v3:%d\n",offsetof(A_t,v3));
	printf("\n");
	printf("B_t size:%d\n",(int)sizeof(B_t));
	printf("B_t offset v1:%d\n",offsetof(B_t,v1));
	printf("B_t offset v2:%d\n",offsetof(B_t,v2));
	printf("B_t offset v3:%d\n",offsetof(B_t,v3));
	printf("B_t offset v4:%d\n",offsetof(B_t,v4));
	printf("\n");
	printf("C_t size:%d\n",(int)sizeof(C_t));
	printf("C_t offset v1:%d\n",offsetof(C_t,v1));
	printf("C_t offset v2:%d\n",offsetof(C_t,v2));
	printf("C_t offset v3:%d\n",offsetof(C_t,v3));
	printf("C_t offset v4:%d\n",offsetof(C_t,v4));
	printf("\n");
	printf("D_t size:%d\n",(int)sizeof(D_t));
	printf("D_t offset v1:%d\n",offsetof(D_t,v1));
	printf("D_t offset v2:%d\n",offsetof(D_t,v2));
	printf("D_t offset v3:%d\n",offsetof(D_t,v3));
	return 0;
}




