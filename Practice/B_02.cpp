#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Write a main() program that generates N*RAND_MAX random integers.
 * A uniform distribution is when each number is equally likely to
 * occur. If the output of rand() is a uniform distribution then
 * RAND_MAX should occur approximately N times. Sample output:
 *
 * RAND_MAX occured 1012 times in 1000*RAND_MAX trials
 *
 * In this run of the program, rand() appears to be working correctly
 * since you would expect RAND_MAX to occur about 1000 times in 1000*RAND_MAX trials.
 */

int main02 (int argc, char *argv[])
{
	int i;
	int count = 0;
	int N = 1000;
	
	/* User can provide an alternate N */
	if (argc == 2)
	{
		N = atoi( argv[1] );
	}

	/* Init rando */
	srand ( time(NULL));

	for (i = 0; i < N*RAND_MAX; i++)
	{
		if (RAND_MAX == rand())
		{
			count++;
		}
	}
	printf ("RAND_MAX occured %d times in %d*RAND_MAX trials.\n", count, N );

#if 0
	/* Just checking rand max on my machine. (32767) */
	printf ("%d\n", RAND_MAX );

	/* Answer key solution nearly identical to mine.  Curiously,
	 * it didn't need #include <time.h> to use the time function,
	 * whereas my solution did require it. */

#endif

	system ("pause");
	return 0;
}