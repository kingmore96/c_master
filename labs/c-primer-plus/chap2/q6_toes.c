#include <stdio.h>

/*
 * input:
 * 	void
 * output:
 * 	toes = 10
 * 	two times toes = ?
 * 	squared toes = ?
 */

int main(void)
{
	int toes;

	toes = 10;
	printf("toes = %d\n",toes);
	printf("two times toes = %d\n",toes * 2);
	printf("squared toes = %d\n", toes * toes);
	return 0;
}
