#include <stdlib.h>
#include <stdio.h>

/* Puzzle A06:  Print out the odd integers from 1 to 99.  one number per line. */

int main06 (int argc, char *argv[]) /* argc = argument counter, argv = argument values */
{
	int j;
	for (j = 0; j < 100; j++)
	{
		if (j%2 == 1)  /* Even numbers mod2 have remainder 0, odds have remainder 1. */
		{
			printf(" %3d\n", j);   /* the 3 is right justify padding */
		}
	}

#if 0
	/* The above code works, but the answer key recommends the following (because less work) */
	for (j=1; j<=99; j+=2 )
		{
			printf("%3d\n", j);
		}
#endif

	system("pause");
	return 0;
}