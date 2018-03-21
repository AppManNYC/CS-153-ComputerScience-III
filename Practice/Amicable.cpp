#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long sumDivisors ( long n );

int main (void)
{
	/* The array stores the 2nd element in the pairs check, to avoid printing repeats like (220, 284) --> (284, 200) */
	long temp1, temp2, n, N;
	long dblCheck[500];
	int arryIndex;
	int numElems = 0;
	int flag = 1;
	int flag2 = 1;

	printf ("\nPlease enter a lower bound: \n");
	scanf (" %ld", &n );
	printf ("\nPlease enter an upper bound: \n");
	scanf (" %ld", &N );

	while ( n <= N )
	{
		for ( arryIndex = 0 ; arryIndex < numElems ; arryIndex++ )
		{
			if ( dblCheck[arryIndex] == n )
			{
				flag2 = 0;
			}
		}

	temp1 = sumDivisors (n);
	temp2 = sumDivisors (temp1);

	if ( temp1 == n )
	{
		printf ("\nPerfect: %d\n", temp1 );
		flag = 0;
	}
	if ( (temp2 == n) && flag && flag2 )
	{
		printf ("\nAmicable: %d\t%d\n", n, temp1 );
		dblCheck[numElems] = temp1;
		numElems++;
	}
	flag = 1;
	flag2 = 1;
	n++;
	}
	
	system ("pause");
	return 0;
}

long sumDivisors (long n)
{
	long sum, i;
	sum = i = 0;
	while ( ++i <= n/2 )
	{
		if ( n%i == 0 )
		{
			sum += i;
		}
	}
	return sum;
}
