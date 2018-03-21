#include <stdlib.h>
#include <stdio.h>

/* Puzzle A04:  Print out integers -7 to 7.  one number per line. */

int main04 (int argc, char *argv[]) /* argc = argument counter, argv = argument values */
{
	int j;
	for (j = -7; j <= 7; j++)
	{
		printf(" %3d\n", j);   /* the 3 is right justify padding */
	}
	system("pause");
	return 0;
}