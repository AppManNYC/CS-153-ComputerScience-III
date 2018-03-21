#include <stdio.h>
#include <stdlib.h>

/* Write a main() program that prints the integers from
 * 1 up to 100 that are not multiples of 3 or 5. Print
 * ten integers per line. The output of the program is:

  1  2  4  7  8 11 13 14 16 17
 19 22 23 26 28 29 31 32 34 37
 38 41 43 44 46 47 49 52 53 56
 58 59 61 62 64 67 68 71 73 74
 76 77 79 82 83 86 88 89 91 92
 94 97 98 

*/

int main13 (int argc, char argv[])
{
	int count = 1;  /* Initialize with 1.  Using 0 causes mod check to pass (1 gets an unwanted newline) */ 
	int i;

	for ( i = 1; i <= 100; i++ )
	{
		if ( !(i%3 == 0 || i%5 == 0) )
		{
			printf ("%3d ", i);
			if ( count%10 == 0 )
			{
				printf ("\n");
			}
			count++;  /* The setup here from printf() to count++ seems necessary to avoid double newlines */
		}
		if (  i == 100 )
		{
			printf ("\n");
		}

#if 0
		/* The above code works.  Provided is the answer key code. */
		for (j=1; j<=n; j++ )
		{
				if ( !(j%3 == 0 || j%5 == 0 ) )
					{
						printf("%3d", j);
						if ( count%10==9 )
						{
								printf("\n");
						}
					count++ ;
			        }
		 }
		if ( count%10 != 9 )
			printf("\n");

#endif

	}
	system ("pause");
	return 0;
}