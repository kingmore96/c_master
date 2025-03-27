#include <stdio.h>
#include <errno.h>
#include <string.h>
//-lm 
#include <math.h>

int main(void)
{
	//test asin
	errno = 0;
	double asin_result = asin(2);
	
	if(errno != 0){
		printf("asin_result:%f\nerrno:%s\n",asin_result,strerror(errno));
	}

	//test exp
	errno = 0;
	double exp_result = exp(1000);
	
	if(errno != 0){
		printf("exp_result:%f\nerrno:%s\n",exp_result,strerror(errno));
	}

	//test log
	errno = 0;
	double log_result = log(0.0);
	
	if(errno != 0){
		printf("log_result:%f\nerrno:%s\n",log_result,strerror(errno));
	}

	return 0;
}
