#include <stdio.h>
#include <stdlib.h>

/* Write a main() program that prints a triangle of stars.
 * Print 1 star in row 0, 3 stars in row 1, 5 stars in row
 * 2, and so on. Here is what this looks like:

...........*...........
..........***..........
.........*****.........
........*******........
.......*********.......
......***********......
.....*************.....
....***************....
...*****************...
..*******************..
.*********************.
***********************

 * For the non-star characters, use dot or space. Often
 * when debugging programs like this it is useful to print
 * dot instead of space so that it is easier to see what
 * the program did.
 */

int main20 (int argc, char *argv[])
{
	int n, i, row, col, mid;
	n = 12;
	mid = (2*n - 1)/2;	

	/* Some key formulas will help make sense of these loops.
	 * The depth of rows is n.  The width of columns is based
	 * on number of stars in final row: 2*n - 1.  The number
	 * of stars to print is based on the row: 2*row + 1. Where
	 * to start printing stars in each row is based on the 
	 * midpoint of the column width, decrementing each row
	 * for the tree effect.  The trick from the previous
	 * puzzle (using a running col for all three loops) was
	 * helpful here, with attention to the need to keep col
	 * incrementing during the middle (stars) loop so it 
	 * picked up in the correct position after the stars.
	 * In summary, the outer loop is for row depth, inner1
	 * is for dots up to mid, inner2 is for stars, inner3
	 * is for dots up to column width.
	 */

	for ( row = 0; row < n; row++ )
	{
		for ( col = 0 ; col < mid; col++ )
		{
			printf (".");
		}
		for (i = 0  ; i < (2*row + 1); i++ , col++ )
		{
			printf ("*");
		}
		for (  ; col < (2*n - 1); col++ )
		{
			printf (".");
		}
		mid--;
		printf ("\n");
	}

#if 0
	/* The answer key code solution was to calculate the number of 
	 * dots and stars at the start of each iteration of the outer
	 * loop, otherwise similar enough that further explantion isn't necessary. */

	for ( row=0; row < n; row++ )
    {
      stars = 2*row+1;
      spaces = (2*n-1-stars)/2;    
      for ( j=0; j < spaces; j++ )
        printf(".");
      for ( j=0; j < stars; j++ )
        printf("*");
      for ( j=0; j < spaces; j++ )
        printf(".");
      printf("\n");
    }

#endif
	system ("pause");
	return 0;
}