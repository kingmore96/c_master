#include <stdio.h>

int main(void)
{
  double a,b;

  b = 2.0e20 + 1.0;
  a = b - 2.0e20;
  printf("%f \n",a);

  return 0;
}
