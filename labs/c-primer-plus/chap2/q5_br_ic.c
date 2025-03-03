#include <stdio.h>

/*
 * print something.
 * input:
 * 	void
 * output:
 * 	Brazil,Russia
 */
void br(void)
{
	printf("Brazil, Russia");
}


/*
 * print something.
 * input:
 *      void
 * output:
 *     	India,China
 */

void ic(void)
{
	printf("India, China");
}

/*
 * input:
 * 	void
 * output:
 * 	Brazil, Russia, India, China
 * 	India, China,
 * 	Brazil, Russia
 */
int main(void)
{
	br();
	printf(", ");
	ic();
	printf("\n");

	ic();
	printf(",\n");

	br();
	printf("\n");
	return 0;
}

