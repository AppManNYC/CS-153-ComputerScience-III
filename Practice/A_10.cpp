#include <stdio.h>
#include <stdlib.h>

/* Write a program that prints the integers from 0 to 24 (inclusive).
 * Print five integers per line. The output of the program is:

  0  1  2  3  4
  5  6  7  8  9
 10 11 12 13 14 
 15 16 17 18 19
 20 21 22 23 24

 */

int main (int argc, char *argv[])
{
	int i;

	for (i = 0; i <= 24; i++)
	{		
		if ( i%5 == 0 )
		{
			printf ("\n");
		}
		printf ("%3d ", i ); /* placed after if to prevent 0 on its own line (because 0 passes mod check) */
	}
	printf ("\n"); /* Because 'press any key to cont' looks terrible on same line as output. */

#if 0
	/* The code above works.  Answer key solution provided here.
	 * This code solves the issue that required me to do
	 * the if check before the printf statement. */
	for (j=0; j<25; j++ )
  {
    printf("%3d", j);
    if ( j%5==4 ) printf("\n"); 
  }
#endif

	system ("pause");
	return 0;
}