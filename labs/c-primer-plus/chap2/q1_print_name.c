#include <stdio.h>

/* print fisrt name and last name in different ways.
 *
 * input: 
 * 	void
 * output:
 * 	Linxuan Wang -->Call the printf function once to print fisrtname and lastname on the same line.
 * 	Linxuan      -->Call the printf function once to print firstname and lastname on two lines.
 * 	Wang         
 * 	Linxuan Wang -->Call the printf function twice to print firstname and lastname on two lines.
 */
int main(void)
{
	char first_name[] = "Linxuan";
	char last_name[] = "Wang";

	printf("%s %s\n",first_name,last_name);
	printf("%s\n%s\n",first_name,last_name);
	printf("%s ",first_name);
	printf("%s\n",last_name);
	return 0;
}
