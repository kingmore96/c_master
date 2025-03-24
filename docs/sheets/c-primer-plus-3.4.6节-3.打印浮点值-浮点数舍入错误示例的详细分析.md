### 前言

小提示：阅读本篇内容，至少需要了解double和float的底层二进制是怎样的。



书中的代码示例如下：



```c
#include <stdio.h>
  
int main(void)
{
  float a,b;
  
  b = 2.0e20 + 1.0;
  a = b - 2.0e20;
  printf("%f \n",a);
  
  return 0;
}
```



a在当前IEEE 754标准下，等于 4008175468544.000000。为什么会产生这样的结果呢？书中的解释不够详细，我在阅读至此处时，自然的产生了深入研究的想法，并将结果写为本篇博客，供大家参考。



我的思路是，针对这个问题，逐行详细分析每一句代码都产生了什么效果，或许就可得知误差出现在哪里。

下面开始逐行分析：



### 逐行分析

首先是第一行：

```c
b = 2.0e20 + 1.0;
```

先从右边的计算开始：



2.0e20首先会被当作double变量进行接收，所以根据double变量的存储规则，它的底层二进制如下：

0 10001000010 0101101011110001110101111000101101011000110001000000



1.0也会被当作double类型来接收，底层二进制如下：

0 01111111111 0000000000000000000000000000000000000000000000000000



可以用这个函数直接打印二进制：

```c
#include <stdio.h>
#include <stdint.h>

void print_bits_float(float f)
{
        union{
                float a;
                uint32_t b;
        }c;
        c.a = f;
    
        for(int i=0;i<32;i++){
                printf("%d",c.b & 1 << (31 - i) ? 1 : 0);    
    
                if(i == 0 || i == 8)
                        printf(" ");
        }
        printf("\n");
}


void print_bits_double(double d)
{
        union{
                double a;
                uint64_t b; 
        }c;
        c.a = d;

        for(int i =0 ;i<64;i++){
        			//caution! 1ULL not 1 because 1 << or >> more than 31 is undefined behaviour.
                printf("%d",c.b & (1ULL << (63 - i)) ? 1 : 0);

                if(i == 0 || i == 11) 
                        printf(" ");
        }
        printf("\n");
}
```



接着做浮点数的加法运算，具体运算规则是这样的：



1. 小阶 对齐 大阶&#x20;

2. 小阶数的小数点移动一下&#x20;

3. 相加/相减&#x20;

4. 把结果转换为规范数









