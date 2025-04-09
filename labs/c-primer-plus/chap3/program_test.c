#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

void print_bits_float(uint32_t v)
{
	for(int i = 0;i<32;i++){
		printf("%d",(v & 1<<(32-i-1)) ? 1:0);
		if(i == 0 | i == 8){
			printf(" ");
		}
	}
	printf("\n");
}

int test1()
{
	int a = 0x7FFFFFFF;
	printf("int a = %d\n",a + 1);

	union{
		float a;
		uint32_t v;
	}c;

	c.v = 0x7F7FFFFF;
	printf("float a = %f\n",c.a * 2);

	c.v = 0x00800000;

	for(int i = 0;i<24;i++){
		c.a = c.a / 2.0f;		
		printf("float a = %a\n",c.a);
		print_bits_float(c.v);
	}
	return 0;
}

void test2()
{
	int a;
	printf("please input an ascii value:___\b\b\b");
	scanf("%d",&a);

	if(a < 0 || a>127){
		printf("invalid value = %d, shoule range [0,127]\n",a);
		exit(-1);
	}
	printf("%c\n",a);
}

void test3()
{
	printf("\aStartled by the sudden sound, Sally shouted,\n");
	printf("\"By the great Pumpkin, what was that!\"\n");
}	

void test4()
{
	float f;
	printf("Enter a floating-point value: ");
	scanf("%f",&f);
	printf("fix-point notation: %f\n",f);
	printf("exponential notation: %e\n",f);
	printf("p notation: %a\n",f);
}
/*
输入详解：

123\n -> 可正确读取123，\n被清空

abc\n -> 读取到a即停止读取，abc\n被清空

123abc\n ->读取到123，abc\n被清空

输入abc后按ctrl+d ->需要再按一次ctrl+d 才可正确结束程序，abc被清空

输入123后按ctrl+d ->需要再按一次ctrl+d 才可正确输入数据

123abc后按ctrl+d ->需要再按一次才可正确结束程序

ctrl+d 如果前面是空行，则会正确设置stdin为EOF状态

ctrl+d 如果如果前面非空，则相当于换行符，操作系统会提交输入数据给程序：

如：输入123后按ctrl+d，scanf函数会读取abc这三个字符，等待读取下一个字符，再按一次ctrl+d，操作系统才会把这个输入标记为EOF，此时scanf才会返回。

如：输入abc后按ctrl+d，清空缓冲区的getchar函数，也是类似的，只有再按一次，才会返回EOF。
*/
void test5()
{
	/*why do we use uint64_t instead of double?
	特性		uint64_t				double
	精度		精确表示所有整数（最大到 1.8e19）。	仅能精确表示整数到 2^53（约 9e15）。
	适用场景	需要精确整数计算的场景（如年龄秒数）。	需要小数或极大/极小数但精度不敏感的场景。
	潜在问题	溢出风险（但年龄合理时不可能溢出）。	大数精度丢失（如年龄极大时）。
	
	uint64_t has a smaller range than double but can represent all integers precisely, 
	while double has a larger range, but precision is lost beyond the continuous integer range.

	精确性
	年龄和年秒数均为整数，结果也应为整数。uint64_t 能精确表示所有可能的合理年龄对应的秒数（例如，即使年龄是 100 亿年，结果也仅为 3.156e17，远小于 uint64_t 的最大值 1.8e19
	地球从熔融态到形成固态地壳仅用1-2亿年（45.5→44亿年）。
	
	避免浮点误差
	double 在数值超过 2^53（约 9e15）时无法精确表示每个整数。若年龄极大（如地质时间尺度），计算结果会丢失精度。

	类型一致性
	年龄输入为整数，计算结果应为整数，使用 uint64_t 保持类型一致，避免隐式浮点转换。
	*/
	uint64_t seconds;
	int64_t age;
	int scan_result;
	const uint64_t SECONDS_PER_YEAR = 31560000ULL;
	int valid_result = 0;	

	do{
		printf("Please input an age value: ");
		scan_result = scanf("%ld",&age);
		printf("scan_result: %d\n",scan_result);
		if(scan_result != 1){
			if(scan_result == 0){
				printf("error:invalid value: not integer. Please retry!\n");
			}else{
				printf("error:EOF, but we will reopen it,so you can retry!\n");
			}
		}else{
			if(age < 0 || age > ULONG_MAX/SECONDS_PER_YEAR){
				printf("error:invalid value:age = %ld. Please retry!\n",age);
			}else{
				valid_result = 1;
			}
		}

		
		int c;
		while((c = getchar()) != '\n' && c != EOF){
			printf("char = %c\n",c);
			printf("clear c = %c\n",c);
		}
		printf("clear buf is finished!\n");
		clearerr(stdin);
		printf("EOF is cleared!\n");
	}while(valid_result != 1);

	seconds = age * SECONDS_PER_YEAR;
	printf("seconds of age %ld is %lu\n",age,seconds);
}
	
void test6()
{
	const double WATER_MOLECULE_MASS = 3.0e-23;
	const double GRAMS_PER_QUART_WATER = 950.0;
	
	int valid_result = 0;
	int scan_result;
	int quarts;
	double water_molecule_count;

	do{
		printf("Pleast enter quarts of water: ");
		scan_result = scanf("%d",&quarts);
		if(scan_result != 1){
			if(scan_result == 0){
				printf("error: invalid value: not integer!\n");
			}else{
				printf("error: EOF. But we will reopen it.\n");
			}
		}else{
			if(quarts < 0 || quarts > DBL_MAX * WATER_MOLECULE_MASS /GRAMS_PER_QUART_WATER){
				printf("error: invalid value: %d\n",quarts);
			}else{
				valid_result = 1;
			}
		}

		int c;
		while((c = getchar()) != '\n' && c != EOF);
		clearerr(stdin);
	}while(valid_result != 1);

	water_molecule_count = quarts * GRAMS_PER_QUART_WATER / WATER_MOLECULE_MASS;
	printf("water molecule count = %e\n",water_molecule_count);
}

void test7()
{
	const double CENTIMETER_PER_INCH = 2.54;
	
	int valid_result = 0;
	int scan_result;
	double height_inch;
	double height_cm;

	do{
		printf("Please enter height_inch: ");
		scan_result = scanf("%lf",&height_inch);
		if(scan_result != 1){
			if(scan_result == 0){
				printf("error: invalid value: not double!\n");
			}else{
				printf("error: EOF. But we will reopen it!\n");
			}
		}else{
			if(height_inch < 0 || height_inch > DBL_MAX/CENTIMETER_PER_INCH){
				printf("error: invalid value: %f\n",height_inch);
			}else{
				valid_result = 1;
			}
		}

		int c;
		while((c=getchar())!='\n'&& c != EOF);
		clearerr(stdin);	
	}while(valid_result != 1);
	
	height_cm = height_inch * CENTIMETER_PER_INCH;
	printf("height cm = %.2f,%e\n",height_cm,height_cm);
	
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
	return 0;
}
