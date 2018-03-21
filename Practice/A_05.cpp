#include <stdlib.h>
#include <stdio.h>

/* Puzzle A05:  Print out integers 15 down to 0.  one number per line. */

int main05 (int argc, char *argv[]) /* argc = argument counter, argv = argument values */
{
	int j;
	for (j = 15; j >= 0; j--)
	{
		printf(" %3d\n", j);   /* the 3 is right justify padding */
	}
	system("pause");
	return 0;
}