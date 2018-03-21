#include <stdlib.h>
#include <stdio.h>

/* Puzzle A03:  Print out 0,2,4,...,20.  one number per line. */

int main03 (int argc, char *argv[]) /* argc = argument counter, argv = argument values */
{
	int j;
	for (j = 0; j <= 20; j += 2)
	{
		printf(" %3d\n", j);   /* the 3 is right justify padding */
	}

#if 0
	/* Also works. */
	for (j=0; j<=10; j++ )
		{
			printf("%3d\n", 2*j);
		}
#endif

	system("pause");
	return 0;
}