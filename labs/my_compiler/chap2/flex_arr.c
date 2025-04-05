#include <stdio.h>
#include <stdlib.h>

struct sample{
	int length;
	char str[];
};

int main(void)
{
	struct sample *s = malloc(sizeof(struct sample) + 10 * sizeof(char));
	(*s).str[0] = 'a';
	printf("%c\n",(*s).str[0]);
}
