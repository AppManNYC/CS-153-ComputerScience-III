#include <stdlib.h>
#include <stdio.h>

/* Puzzle A02:  Print out 1 - 15, one number per line. */

int main02 (int argc, char *argv[]) /* argc = argument counter, argv = argument values */
{
	int j;
	for (j = 1; j <= 15; j++)
	{
		printf(" %3d\n", j);   /* the 3 is right justify padding */
	}
	system("pause");
	return 0;
}