#include <stdio.h>
#include <stdlib.h>

/* Write a main() program that prints the odd integers from start
 * down to finish, seven per line. Make start and finish variables
 * that are initialized by assignment (or by user input, if you 
 * want.) When start==147, and finish==59, the output of the program is:

 147 145 143 141 139 137 135
 133 131 129 127 125 123 121
 119 117 115 113 111 109 107
 105 103 101  99  97  95  93
  91  89  87  85  83  81  79
  77  75  73  71  69  67  65
  63  61  59

 * The integers that end each line are less regular than in previous programs.
 * It is probably wise to maintain a separate variable that counts the
 * integers as they are printed. The last line does not contain the full five
 * integers, but it ends with "\n" anyway. Click here for a skeleton: Skeleton.
 *
 * I would guess that your odds of getting this program correct on the very first
 * try are about one in five. See if you can beat the odds! */  

int main12 (int argc, char *argv[])
{
	int start, finish;
	int counter = 0;

	printf ("Enter start: ");
	scanf (" %d", &start );
	printf ("\nEnter finish: ");
	scanf (" %d", &finish );

	while ( start >= finish )
	{
		if ( start%2 == 1)
		{
			printf ("%3d ", start );
			start--;
			counter++;
		}		
		if ( counter%7 == 0  )
		{
			
			printf ("\n");			
		}
		if ( start < finish )
		{
			printf ("\n");
		}
		/* Need to tighten my if-else game; it took me too long to move
		*  the else down here (was getting double newlines until the change) */
		else
		{
			start--;			
		}

#if 0
		/* The above code works, although I like the answer key version better. */
		for (j=start; j>=finish; j -= 2 )
		{
				printf("%4d", j);
				if ( count%7==6 )
					{
						printf("\n");
						count++ ;
					}
		}
		if ( count%7 != 0 )
		{
				printf("\n");
		}

#endif


	}
	system ("pause");
	return 0;
}