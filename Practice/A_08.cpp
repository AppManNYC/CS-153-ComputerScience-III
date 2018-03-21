#include <stdio.h>
#include <stdlib.h>

/* Puzzle A08 --  program that first asks the user for an integer, N,
 * and then calculates three sums: the sum of the even integers, the
 * sum of the odd integers, and the sum of all integers from 0 to N.
 * The output of the program is:
 * Enter n: 7
 * Sum = 28, Sum of Odd = 16, Sum of Even = 12
 *
 * The best way to write this program is to use the formulas that
 * calculate each sum in one step. But, to practice programming,
 * implement this program with a loop. */

int main08 (int argc, char *argv[])
{
  int j, N;
  int eSum = 0;
  int oSum = 0;   /* Don't forget to initialize; garbage output otherwise. */
  
  printf("Enter N: ");
  scanf("%d", &N );
  
  for (j = 0; j <= N; j++)
  {
	  if ( j%2 == 0 )
	  {
		  eSum += j;
	  }
	  else
	  {
		  oSum += j;
	  }	  
  }

  printf("Sum = %d, Sum of Odd = %d, Sum of Even = %d\n", eSum+oSum, oSum, eSum );

#if 0
  /* The answer key code is similar to mine, except it includes a variable for sum total.
   * An alternate method, from the answer key, is also provided. */
  for (j=0; j<=n; j++ )
  {
    sumAll += j;
    if ( j%2 == 0 ) sumEven += j;
  }

  printf("Sum = %4d, Sum of Odd = %4d, Sum of Even = %4d\n", 
      sumAll, sumAll-sumEven, sumEven);
#endif

  system("PAUSE");	
  return 0;
}