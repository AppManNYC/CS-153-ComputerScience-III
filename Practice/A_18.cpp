#include <stdio.h>
#include <stdlib.h>

/* Write a main() program that prints a wedge of stars.
 * Print n stars in row 0, (n-1) stars in row 1, (n-2)
 * stars in row 2, and so on. Here is what this looks like:

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

 * The first star in each line starts in column zero (this
 * is not clear from the above picture.)
 */

int main18 (int argc, char *argv[])
{
	int n, row, col;
	n = 15;

	for ( row = 0; row < n; row++ )
	{
		for ( col = 0; col < (n-row); col++ )
		{
			printf ("*");
		}
		printf ("\n");
	}
	/* Minus some clarifying brackets, the answer key solution is identical to mine. */
	/* Therefore, for this exercise I'll forego my usual inclusion of the answer key. */
	system ("pause");
	return 0;
}