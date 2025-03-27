#include <stdio.h>

int main(void)
{
  float a,b;

  b = 2.0e20f + 1.0f;
  a = b - 2.0e20f;
  printf("%f \n",a);

  return 0;
}
