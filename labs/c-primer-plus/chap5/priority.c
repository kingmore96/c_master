#include <stdio.h>
#define SQR(X) X*X
#define SQR_NEW(X) (X)*(X)
#define SQR_FIN(X) ((X) * (X))

int main(void)
{
	int a = 16;
	int k = 2;
	int m = 1;

	a /= SQR(k+m)/SQR(k+m);
	printf("SQR(X) X*X ; a/= SQR(k+m)/SQR(k+m) = %d\n",a);

	a = 16;
	a /= SQR_NEW(k+m)/SQR_NEW(k+m);
	printf("SQR_NEW(X) (X)*(X) ; a/= SQR_NEW(k+m)/SQR_NEW(k+m) = %d\n",a);
	
	a = 16;
	a /= SQR_FIN(k+m)/SQR_FIN(k+m);
	printf("SQR_FIN(X) ((X)*(X)) ; a/= SQR_FIN(k+m)/SQR_FIN(k+m) = %d\n",a);



	a = 16/SQR_NEW(k+m);	
	printf("SQR_NEW(X) (X)*(X); a= 16/SQR_NEW(k+m) = %d\n",a);


	a = 16/SQR_FIN(k+m);
	printf("SQR_FIN(X) ((X)*(X)); a= 16/SQR_FIN(k+m) = %d\n",a);

	return 0;
}

