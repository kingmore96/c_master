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

	return 0;


}
