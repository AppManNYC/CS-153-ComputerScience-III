#include <stdio.h>
#include <stdlib.h>

/* Write a program that prints the odd integers 1 to N, five per line.
 * Write the integers to standard output. On a Windows machine, this
 * means the integers are written to the DOS window. Make N a variable
 * in the program and initialize it in an assignment statment (or read
 * it from user input, if you want.) When N==53, the output of the
 * program is:

  1  3  5  7  9
 11 13 15 17 19
 21 23 25 27 29
 31 33 35 37 39
 41 43 45 47 49
 51 53

 * Notice that the last line does not contain a full five integers, but
 * it ends with "\n" anyway. This will take some extra logic.*/

int main11 (int argc, char *argv[])
{
	int i, N;

	printf ("Enter N: ");
	scanf (" %d", &N );

	/* Without the N/2 the output prints out N odd numbers
	 * instead of stopping at N as it is supposed to do. */

	for (i = 0; i <= N/2; i++)
	{
		printf ("%3d ", 2*i + 1);
		if ( i%5 == 4 || i == N/2 )
		{
			printf ("\n");
		}
	}

#if 0
	/* The above code works.  The following snippet is from the answer key. */
	for (j=1; j<=n; j+=2 )
  {
    printf("%3d", j);
    if ( j%10==9 ) printf("\n");
  }
  if ( (j-2)%10 != 9 ) printf("\n");
#endif

	system ("pause");
	return 0;
}





