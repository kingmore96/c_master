#include <stdio.h>

int validate_ipv4(const char* ip)
{
	int digit_count = 0;
	int digits[3] = {-1,-1,-1};
	int segment_count = 0;
	
	while(1){
		char segment_char = *ip;

//		printf("segment_char = %c\n",segment_char);		

		if(segment_char == '.' || segment_char == '\0'){
//			printf("segment_count = %d,digit_count = %d,digits = %d %d %d\n",segment_count,digit_count,digits[0],digits[1],digits[2]);
			segment_count++;

			if(digit_count == 0){
				printf("error:segment number length out of range[1,3] = 0\n");
				return -1;
			}

			if(digit_count > 1 && digits[0] == 0){
				printf("error:exist leading zeros.\n");
				return -1;
			}

			if(digit_count == 3){
				if((digits[0] > 2 || (digits[0] == 2 && digits[1] > 5) || (digits[0] == 2 && digits[1] == 5 && digits[2] >5))){
					printf("error:digits out of range [0,255].%d,%d,%d\n",digits[0],digits[1],digits[2]);
					return -1;
				}
			}
			
			if(segment_char == '\0'){
				break;
			}
			
			digit_count = 0;
			ip++;
		}else if(segment_char >= '0' && segment_char <= '9'){
			if(++digit_count > 3){
				printf("error:segment length out of range [1,3] = %d\n",digit_count);
				return -1;
			}
			
			digits[digit_count - 1] = segment_char - '0';
			ip++;
		}else{
			printf("error:invalid_char:%c,%d\n",segment_char,segment_char);	
			return -1;
		}

	}

	if(segment_count != 4){
		printf("error:segment count is not 4 = %d\n",segment_count);
		return -1;
	}

	return 0;
}

void ints_to_carray(int num[4],char *p)
{
	char *inner_p = p;
	for(int i = 0;i<4;i++){
		int number = num[i];
		if(number == 0){
			*inner_p = '0';
			inner_p = inner_p + 1;
		}else{
			char tmparr[3];
			int tmp_index = 0;
			do{
				int digit = number % 10;
//				printf("digit = %d ",digit);
				tmparr[tmp_index] = digit + '0';
//				printf("tmp[%d] = %d\n",tmp_index,tmparr[tmp_index]);
				number = number/10;
				tmp_index++;
			}while(number != 0);
			
			for(int i = tmp_index-1;i>=0;i--){
				*inner_p = tmparr[i];
//				printf("%c ",*inner_p);
				inner_p = inner_p + 1;
			}
//			printf("\n");
		}

		if(i != 3){
			*inner_p = '.';
			inner_p = inner_p + 1;
		}
	}
	*inner_p = '\0';
//	printf("string: %s\n",p);
}

void test_normal()
{
	for(int i = 0; i<=255;i++){
		for(int j = 0;j<=255;j++){
			for(int m = 0;m<=255;m++){
				for(int n = 0;n <= 255;n++){
//					printf("%d %d %d %d\n",i,j,m,n);
					int num[4];
					num[0] = i;
					num[1] = j;
					num[2] = m;
					num[3] = n;
					char arr[20];
					ints_to_carray(num,arr);	
					if(validate_ipv4(arr) != 0){
						printf("%d.%d.%d.%d error.\n",num[0],num[1],num[2],num[3]);
					}
				}
			}
		}
	}
}

void test_abnormal()
{
	FILE *fp;

	fp = fopen("ip_validate_abnormal.txt","r");
	if(fp == NULL){
		perror("open file error: ");
		return;
	}

	while(1){
		char buf[20];
		char *ret = fgets(buf,sizeof(buf),fp);
		if(ret != NULL){
			int index = 0;
			while(ret[index] != '\0'){
				if(ret[index] == '\r' || ret[index] == '\n'){
					break;
				}
				index++;
			}

			if(index == 0){
				printf("empty line.\n");
				continue;
			}

			ret[index] = '\0';
			
//			int i = 0;
//			while(ret[i] != '\0'){
//				printf("%c",ret[i]);
//				i++;
//			}	

			printf("test case : %s ",ret);
			printf("%s\n",validate_ipv4(ret) == 0 ?"valid":"invalid");
		}else{
			if(feof(fp)){
				printf("end of file!\n");
				break;
			}else if(ferror(fp)){
				perror("fgets error:");
			}

		}
	}
}

int main()
{
//	printf("%d\n",validate_ipv4("192.168.1.10"));
//	printf("%d\n",validate_ipv4("0.0.0.0"));	
//	printf("%d\n",validate_ipv4("0.0.0."));
//	test_normal();	
	test_abnormal();
}	








	
