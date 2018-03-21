#include <stdlib.h>
#include <stdio.h>

/* Puzzle A01:  Print out 0 - 14, one number per line. */

int main01 (int argc, char *argv[]) /* argc = argument counter, argv = argument values */
{
	int j;
	for (j = 0; j <= 14; j++)
	{
		printf(" %3d\n", j);   /* the 3 is right justify padding */
	}
	system("pause");
	return 0;
}