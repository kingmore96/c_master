#include <stdio.h>

#define MAX 100  // 全局定义 MAX 为 100

void func1() {
    #define MAX 200  // 在函数内重新定义 MAX 为 200（影响后续所有代码）
    printf("func1: MAX = %d\n", MAX);  // 输出 200
}

void func2() {
    printf("func2: MAX = %d\n", MAX);  // 输出 200（受 func1 内的宏定义影响）
}

int main() {
	printf("main (before func1): MAX = %d\n", MAX);  // 输出 100
	func1();
	printf("main (after func1): MAX = %d\n", MAX);    // 输出 200
	func2();

	float t = 33554432.0f;
	printf("%d\n",t == 33554432.0f?1:0);

	t = 16777217.0f;
	printf("%.1f\n",t);
	printf("%d\n",t == 16777217.0f?1:0);
	
	t = 16777218.0f;
        printf("%.1f\n",t);
	printf("%d\n",t == 16777216.0f?1:0);
	
	
    return 0;
}

