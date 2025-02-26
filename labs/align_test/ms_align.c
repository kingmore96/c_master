#include <stdio.h>

typedef struct A {
  char v1[4];
  int v2;
  double v3;
  short v4;
} A_t;

int main(){
  printf("A_t size:%d\n",(int)sizeof(A_t));
  return 0;
}

