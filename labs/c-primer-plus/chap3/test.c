
#include <stdio.h>
void calc(float* f, int* i) {
    *f = 3.14f;
    *i = 100;
    printf("Result: %.2f\n", *f);
}

int main() {
    union { float f; int i; } u;
    calc(&u.f, &u.i);
}
