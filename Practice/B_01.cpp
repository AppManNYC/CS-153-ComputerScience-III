#include <stdio.h>
#include <stdlib.h>

/* Write a main() program that prints N random integers one per
 * line. Write the integers to standard output. On a Windows machine,
 * write the integers to the DOS window. Here is the output of one
 * run of the program:

  4068
   213
 12761
  8758
 23056
  7717
 15274
 24508
  4056
 13304

 */

int main01 (int argc, char *argv[])
{
	int j;
	int limit = 25;
	unsigned int seed = 123;

	/* Use cmd line args, if provided. */
	if (argc == 3)
	{
		limit = atoi(argv[1]);
		seed = atoi(argv[2]);
	}

	/* Init rando generator */
	srand (seed);

	for (j = 0; j < limit; j++)
	{
		printf ("%d\n", rand());
	}

#if 0
	/* Answer key solution is nearly indentical. 
	 * Note: using the same seed will cause
	 * rand to generate the same "random" numbers
	 * during subsequent program executions.  A way
	 * to work around that is to have the seed initialized
	 * to something that is continuously changing, like time.
	 */
	srand( time(NULL) );

#endif
	printf ("\n");
	system ("pause");
	return 0;
}