#include <stdio.h>
#include <stdlib.h>

/* Puzzle A09 --  program that first asks the user for an integer, N,
 * and then calculates three sums: the sum of the even integers, the
 * sum of the odd integers, and the sum of all integers from 0 to N.
 * However, exclued from these sums those integers that are divisible
 * by 3 or divisible by 4. The output of the program is: 
 * Enter n: 10
 * Sum = 25, Sum of Odd = 13, Sum of Even = 12
 *
 * Use the previous program as the basis for this one. */

int main09 (int argc, char *argv[])
{
  int j, N;
  int eSum = 0;
  int oSum = 0;   /* Don't forget to initialize; garbage output otherwise. */
  
  printf("Enter N: ");
  scanf("%d", &N );
  
  for (j = 0; j <= N; j++)
  {
	  if ( j%2 == 0 && !(j%3 == 0) && !(j%4 == 0) )
	  {
		  eSum += j;
	  }
	  if ( j%2 == 1 && !(j%3 == 0) && !(j%4 == 0) )
	  {
		  oSum += j;
	  }	  
  }

  printf("Sum = %d, Sum of Odd = %d, Sum of Even = %d\n", eSum+oSum, oSum, eSum );

#if 0
  /* The above code works.  Alternate solution from the answer key are: */

  /* Sift mod3, mod4 first, THEN sum the evens, odds. */
  for (j=0; j<=n; j++ )
  {
    if ( j%3 != 0 && j%4 != 0 )
    {
      sumAll += j;
      if ( j%2 == 0 )
        sumEven += j;
      else
        sumOdd  += j;
    }
  }

  /* Similar to mine. */
  if ( (j%3 != 0) && (j%4 != 0) )

  /* Application of DeMorgan's Law */
  if ( !( (j%3 == 0) || (j%4 == 0) ) )

  /* Slick, but may be harder to understand when read later. */
  if (j%3 && j%4)

#endif

  system("PAUSE");	
  return 0;
}