#include <stdio.h>

/*
 * print something.
 *
 * input:
 * 	void;
 * output:
 * 	Smile!
 */
void smile(void)
{
	printf("Smile!");
}

/*
 * input:
 * 	void
 * output:
 * 	Smile!Smile!Smile!
 * 	Smile!Smile!
 * 	Smile!
 */
int main(void)
{
	smile();
	smile();
	smile();
	printf("\n");

	smile();
	smile();
	printf("\n");

	smile();
	printf("\n");

	return 0;
}
