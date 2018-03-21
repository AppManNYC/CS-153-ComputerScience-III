#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Write a main() program that generates a large number of random integers
 * in the range 0..9. A histogram is an array that holds the number of times
 * each integer occurred. Initialize the random number generator using: 
 * srand( time(NULL) ). Here is one run of the program, for N==100 000 000:

  0: 10001193
  1: 10001982
  2: 10003463
  3: 10002130
  4:  9999796
  5: 10003199
  6:  9997985
  7: 10000221
  8:  9997708
  9:  9992323

 * You should expect each histogram cell to contain about one tenth the total,
 * about 10 000 000. Of course, there will be small deviations above and below
 * that value. A really big deviation would be a sign that something is wrong.
 */

int main04 (int argc, char *argv[])
{
	int i, temp;
	int zero, one, two, three, four, five, six, seven, eight, nine;
	zero = one = two = three = four = five = six = seven = eight = nine = temp = 0;
	int N = 10000000;
			
	/* User can provide an alternate N */
	if (argc == 2)
	{
		N = atoi( argv[1] );
	}	

	/* Init rando */
	srand( time(NULL));

	for (i = 0; i < N; i++)
	{
		temp = (int)(10.0*rand()/(RAND_MAX ));

		if (temp == 0)
		{
			zero++;
		}
		if (temp == 1)
		{
			one++;
		}
		if (temp == 2)
		{
			two++;
		}
		if (temp == 3)
		{
			three++;
		}
		if (temp == 4)
		{
			four++;
		}
		if (temp == 5)
		{
			five++;
		}
		if (temp == 6)
		{
			six++;
		}
		if (temp == 7)
		{
			seven++;
		}
		if (temp == 8)
		{
			eight++;
		}
		if (temp == 9)
		{
			nine++;
		}		
	}

	printf ("0:%10d\n", zero);
	printf ("1:%10d\n", one);
	printf ("2:%10d\n", two);
	printf ("3:%10d\n", three);
	printf ("4:%10d\n", four);
	printf ("5:%10d\n", five);
	printf ("6:%10d\n", six);
	printf ("7:%10d\n", seven);
	printf ("8:%10d\n", eight);
	printf ("9:%10d\n", nine);

#if 0
	/* Answer key solution initially looks slicker, but it relies on 
	 * the modulo "solution" cautioned against in the comments of
	 * my solution to B03 */
	int j, r, count;
    int histo[] = {0,0,0,0,0,0,0,0,0,0};
  
    srand( time(NULL) );
    for ( j=0; j < limit; j++ )
    {
      r = rand()%10 ;
      histo[r]++ ;
    }
    for ( j=0; j < 10; j++ )
    {
      printf( "%3d: %8d\n", j, histo[j] );
    }

#endif

	system ("pause");
	return 0;
}