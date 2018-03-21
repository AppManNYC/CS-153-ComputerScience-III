#include <stdio.h>
#include <stdlib.h>

/* Puzzle A07 -- print the first N odd integers. Ask the user for N. */
int main07 (int argc, char *argv[])
{
  int j, k, N;
  
  printf("Enter N: ");
  scanf("%d", &N );
  
  for (j = 0; j < N; j++)
  {
	  k = 2*j + 1;    /* Straight from the definition of odd integers from Discrete Math. */
	  printf("%3d\n", k );
  }

#if 0
  /* The above code works, but the answer key has a slicker solution.
   * Use the def of odd right in printf. No need for int k. */
  for (j=0; j < N; j++ )
	  {
		  printf("%3d\n", 2*j+1 );
	  }
#endif

  system("PAUSE");	
  return 0;
}