#include <stdio.h>
#include <stdlib.h>

/* Write a main() program that prints a wedge of stars.
 * Print n stars in row 0, (n-1) stars in row 1, (n-2)
 * stars in row 2, and so on. But now, pad the left side
 * of each line with spaces so that each line consists of
 * n characters. Here is what this looks like:

***************
 **************
  *************
   ************
    ***********
     **********
      *********
       ********
        *******
         ******
          *****
           ****
            ***
             **
              *

 * You will need two loops nested inside of the outer loop.
 */

int main19 (int argc, char *argv[])
{
	int n, row, colSpaces, colStars;
	n = 15;

	for ( row = 0; row < n; row++ )
	{
		/* The key insight here is just figuring out how to make
		 * the spaces "grow" as the logic progresses. Iniatilize
		 * the index at the max (n) and "grow" by incrementing
		 * backward (decrementing). */
		for ( colSpaces = n; colSpaces > (n-row); colSpaces-- )
		{
			printf (" ");
		}
		for ( colStars = 0; colStars < (n-row); colStars++ )
		{
			printf ("*");
		}
		printf ("\n");
	}

#if 0
	/* Answer key solution is clever.
	 * No need for two column counters if done this way. 
	 * Note the benefit of just using one column variable
	 * to simplify the condition checks for each loop. */

	for ( row=0; row < n; row++ )
    {
      for ( col=0; col < row; col++ )
        printf(" ");
      for ( ; col < n; col++ )
        printf("*");
      printf("\n");
    }
#endif
	system ("pause");
	return 0;
}