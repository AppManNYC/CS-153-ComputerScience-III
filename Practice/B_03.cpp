#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Write a main() program that prints N random integers in the
 * range 0..9, one per line. Think of this as repeatedly rolling
 * a 10-sided die (with sides numbered 0 to 9). One run of the
 * program outputs:
 * 6
 * 5
 * 4
 * 1
 * 5
 * 7
 * 4
 * 6
 * 8
 * 8
 * Initialize the random number generator using:
 * srand( time(NULL) );
 * Write this program by making a copy of the previous answer, and
 * modifying it. You should need to change only a few lines.
 */

int main03 (int argc, char *argv[])
{
	int i;	
	int N = 10;
	
	/* User can provide an alternate N */
	if (argc == 2)
	{
		N = atoi( argv[1] );
	}

	/* Init rando */
	srand ( time(NULL));

	for (i = 0; i < N; i++)
	{
		/* Discussion of the method used here in the commented out block below. */
		printf ("%2d\n", (int)(10.0*rand()/(RAND_MAX )) );
	}

#if 0
	/* The code in printf is a slightly modified version of the following:

	In Numerical Recipes in C: The Art of Scientific Computing
       (William  H.  Press, Brian P. Flannery, Saul A. Teukolsky,
       William T.  Vetterling;  New  York:  Cambridge  University
       Press,  1990 (1st ed, p. 207)), the following comments are
       made:
              "If you want to generate a random integer between 1
              and 10, you should always do it by

                     j=1+(int) (10.0*rand()/(RAND_MAX+1.0));

              and never by anything resembling

                     j=1+((int) (1000000.0*rand()) % 10);

              (which uses lower-order bits)."

	*/
	/* The answer key code looks to be using the non-preferred method... */
	for ( j=0; j<limit; j++ )
    {
      printf("%6d\n", rand()%10 );
    }

#endif

	system ("pause");
	return 0;
}