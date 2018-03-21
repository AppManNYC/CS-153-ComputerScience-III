#include <stdio.h>
#include <stdlib.h>

/* Write a main() program that computes and prints N
 * sums: 1, 1+2, 1+2+3, ... , 1+2+3+...+N. There is a
 * smart way to do this with just one loop, and a 
 * not-so-smart way that uses nested loops. Try to
 * write the smart way from scratch.
 */

int main15 (int argc, char *argv[])
{
	int i, N;
	N = 15;

	for (i = 1; i <= N; i++)
	{
		printf ("%3d ", (i*(i+1))/2);
		printf ("\n");
	}
	printf ("\n");

#if 0
	/* The above code works (and I like it better).  Answer key solution provided here. */
	/* IMO more CS majors need to take more math courses.  My solution is the first
	 * example in every Intro to Proof by Induction text that I've ever read. */

	int N = 100;   /* line number */
    int sum=0;     /* Sum */
    int j;         /* values 1..100 to add to the sum */

    printf( "N \t Sum\n");
    for (j=1; j<=N; j++)
    {
      sum += j;
      printf("%d \t %d\n", j, sum );
    }

#endif
	system ("pause");
	return 0;
}