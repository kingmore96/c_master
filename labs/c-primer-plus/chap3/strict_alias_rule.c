#include <stdio.h>

/*
 * result: 0x40000000 (2.00)  
 * */
void set_value(float* f,int* i)
{
	*i = 0x3F800000;
	*f = 2.0f;
}

/*
 * int main() {
    int i = 0;
    float* f = (float*)&i;  // 被忽略的无效操作

    // 由于假设i不会被修改，直接删除循环
    printf("%d ", 0);
    putchar('\n');
}
result : only print 0 and the program finished.
-------------------------------------------------
1. 启用严格别名警告
gcc -Wstrict-aliasing=2 -O2 XX.c

strict_alias_rule.c: In function ‘inf_while’:
strict_alias_rule.c:26:21: warning: dereferencing type-punned pointer will break strict-aliasing rules [-Wstrict-aliasing]
   26 |  float* f =(float*) &i;
      |                     ^~
strict_alias_rule.c: In function ‘main’:
strict_alias_rule.c:42:20: warning: dereferencing type-punned pointer will break strict-aliasing rules [-Wstrict-aliasing]
   42 |  set_value((float*)&value,&value);
      |                    ^~~~~~
strict_alias_rule.c:43:49: warning: dereferencing type-punned pointer will break strict-aliasing rules [-Wstrict-aliasing]
   43 |  printf("result: 0x%X (%.2f)\n",value,*((float*)&value));
      |                                                 ^~~~~~

(Q-need to fix)2. 未定义行为检测（UBSan）
gcc -fsanitize=undefined -O2 XX.c

3. 反汇编验证
通过gcc -S -fverbose-asm观察：

合法方案会生成cmpl指令用于循环条件判断

 * */
void inf_while()
{
	int i = 0;
	float* f =(float*) &i;

	while(i < 10){
		printf("%d ",i);
		(*f)++;
	}
	printf("\n");
}	



typedef struct{
	int x;
}A;

typedef struct{
	float y;
}B;

void access_struct(A* a, B* b)
{
	a->x = 100;
	b->y = 200.0f;
}

/* result : 3.14
 *
 * 关键行为分析：

	*f = 3.14f：将 3.14 的二进制表示 0x4048f5c3 写入 rdi 指向的内存（即联合体的 f 成员）。
	*i = 100：将 100 写入 rsi 指向的内存（即联合体的 i 成员，与 f 共享内存）。
	printf 参数硬编码：movsd .LC1(%rip), %xmm0 直接将双精度 3.14 加载到 xmm0，而非从内存重新读取 *f 的值。
		(严格别名规则误导：编译器假设 float* f 和 int* i 不指向同一内存，因此：*i = 100 不会影响 *f 的值。printf 中的 *f 可替换为原始常量 3.14。)
 *
 * */
void calc(float* f, int* i) {
    *f = 3.14f;
    *i = 100;
    printf("Result: %.2f\n", *f);
    printf("Result: %e\n",*f);
}


int main(void)
{
	printf("test set value start:\n");
	int value;
	set_value((float*)&value,&value);
	printf("result: 0x%X (%.2f)\n",value,*((float*)&value));


	printf("test inf while start:\n");
	inf_while();

	printf("test access struct start:\n");
	A a;
	access_struct(&a,(B*)&a);
	printf("x=%d,y=%.1f\n",a.x,*(float*)&a);

	printf("test calc start:\n");
	union{float f;int i;}u;
	calc(&u.f,&u.i);
	return 0;


}
