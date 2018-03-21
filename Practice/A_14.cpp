#include <stdio.h>
#include <stdlib.h>

/* Write a main() program that prints lines for k==0 up to some limit,
 * say k==11. On each line print those integers from 100*k to 100*k+99 
 * that are multiples of 23. For example, here is the output for k==0 
 * up to k==11:

     0     23     46     69     92
   115    138    161    184
   207    230    253    276    299
   322    345    368    391
   414    437    460    483
   506    529    552    575    598
   621    644    667    690
   713    736    759    782
   805    828    851    874    897
   920    943    966    989
  1012   1035   1058   1081
  1104   1127   1150   1173   1196

  * This is a fairly tricky program. See if you can get it to work by any means. 
  * Once you have some sort of a working program, see if you can improve it.
  */

int main14 (int argc, char *argv[])
{
	int k, j, limit;
	limit = 11;

	for (k = 0; k <= limit; k++)
	{		
		for (j = 100*k ; j <= 100*k+99; j++)
		{
			if ( j%23 == 0 )
				printf ("%4d ", j);
		}
		printf ("\n");
	}
	printf ("\n");

#if 0
	/* This snippet was the logic from my 1st attempt.  Preserved for learning purposes. */
	for (k = 0; k < 3; k++)
	{		
		for (j = k ; j <= k+99; j++)
		{
			if ( (100*j)%23 == 0)
				printf ("%4d ", j);
		}
		printf ("\n");

	/* This is the much more computationally efficient version from the answer key. */
		int j;     /* the current integer */
  int k;     /* the current line number */
  int line;  /* the line the current integer belongs on */

  int maxLine = 11 ; /* number of lines to print */
  
  k = 0;
  
  /* generate multiples of 23 */
  for ( j=0; j<= maxLine*100+99; j+=23 )
  {
    /* find the line number using integer division */
    line = j/100 ; 
    
    /* does the number belong on the current line? */
    if ( line == k+1 )
    {
      printf("\n%5d ", j);
      k++ ;
    }
    else
      printf("%5d ", j );
  }
  printf("\n");
#endif
	system ("pause");
	return 0;
}