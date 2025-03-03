#include <stdio.h>

/*print something
 * input:
 * 	void
 *output:
 * 	For he's a jolly good fellow!
*/
void jolly(void)
{
	printf("For he's a jolly good fellow!\n");
}

/* print something.
 * input:
 *      void
 *output:
 *      Which nobody can deny!
*/
void deny(void)
{
        printf("Which nobody can deny!\n");
}


/*
 * call jolly function three times and call deny function one time to print something.
 *
 * input:
 * 	void
 * output:
 * 	For he's a jolly fellow!
 * 	For he's a jolly fellow!
 * 	For he's a jolly fellow!
 * 	Which nobody can deny!
 * */
int main()
{
	jolly();
	jolly();
	jolly();
	deny();
	return 0;
}
