#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Modify the previous program so that it prints out a bar graph of stars
 * in addition to printing out the values in each histogram bin. Write the
 * program so that the bars of the graph span the page for whatever value
 * of N is being used. To do this, look through the histogram for its maximum
 * value. Divide the maximum number of stars by this value to find the ratio
 * of stars to values. A sample output for N==500 is:

  0 (   50):*****************************************
  1 (   59):*************************************************
  2 (   42):***********************************
  3 (   49):****************************************
  4 (   41):**********************************
  5 (   53):********************************************
  6 (   60):**************************************************
  7 (   47):***************************************
  8 (   54):*********************************************
  9 (   45):*************************************

 * This program is too long to write as one big main(). (My solution is about
 * 30 lines long, not counting comments and blank lines.) Make the histogram
 * array a global variable, and write three functions that use it: generate(),
 * findMax(), and plot(). Write main() using these three functions.
 */

int histo[] = {0,0,0,0,0,0,0,0,0,0};

void generate (int);
double findMax (int);
void plot (double);

int main (int argc, char *argv[])
{
	int N = 500;
	double temp;

	/* User can provide an alternate N */
	if (argc == 2)
	{
		N = atoi( argv[1] );
	}

	generate(N);
	temp = findMax(N);

	printf ("Ratio test: %g\n", temp );

	plot (temp);


	system ("pause");
	return 0;
}

void generate (int N)
{
	int i;
	int temp = 0;
	srand( time(NULL));

	for (i = 0; i < N; i++)
	{
		temp = (int)(10.0*rand()/(RAND_MAX ));

		if (temp == 0)
		{
			histo[0]++;
		}
		if (temp == 1)
		{
			histo[1]++;
		}
		if (temp == 2)
		{
			histo[2]++;
		}
		if (temp == 3)
		{
			histo[3]++;
		}
		if (temp == 4)
		{
			histo[4]++;
		}
		if (temp == 5)
		{
			histo[5]++;
		}
		if (temp == 6)
		{
			histo[6]++;
		}
		if (temp == 7)
		{
			histo[7]++;
		}
		if (temp == 8)
		{
			histo[8]++;
		}
		if (temp == 9)
		{
			histo[9]++;
		}		
	}
}

double findMax (int N)
{
	int i;
	int max = histo[0];

	for (i = 1; i < 9; i++)
	{
		if ( histo[i] > max )
		{
			max = histo[i];
		}
	}

	return (double)max/N;
}

void plot (double temp)
{
	int i, j;

	for (i = 0; i < 9; i++)
	{
		printf ("%d (  %2d):", i, histo[i]);
		for (j = 0; j < histo[i]; j++)
		{
			printf ("*");
		}
		printf ("\n");
	}
}