#include <stdio.h>
#include <stdlib.h>

/* Write a main() program that prints N lines of M stars each,
 * as follows for N==7 M==21:

*********************
*********************
*********************
*********************
*********************
*********************
*********************

* If you want, ask the user for the value N and M; or else, just
* hard-wire those values into your program.
*/

int main16 (int argc, char *argv[])
{
	int i, j, N, M;
	N = 7;
	M = 21;

	for (i = 0; i < N; i++ )
	{		
		for (j = 0; j < M; j++ )
		{
			printf ("*");
		}
		printf ("\n");
	}
	printf ("\n");

#if 0
	/* Answer key code is essentially the same as mine.
	 * I like its use of naming the index variable row
	 * and column.  My future code will try to incorporate
	 * this convention. */

	int row, col;
    int n=7, m=21;
  
    for ( row=0; row < n; row++ )
    {
      for ( col=0; col < m; col++ )
        printf("*");
      printf("\n");
    }

#endif

	system ("pause");
	return 0;
}