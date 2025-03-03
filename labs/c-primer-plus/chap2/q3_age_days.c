#include <stdio.h>

/*
 * convert age to days.
 *
 * input:
 *      void
 * output:
 *      age = ?,days = ?.
 */

int main(void)
{
        int age;
        int days;
        
        age = 32;
        days = age * 365;
        printf("age = %d,days =%d.\n",age,days);
        return 0;
}       

