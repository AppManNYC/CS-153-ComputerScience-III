#include <stdio.h>
#include <stdlib.h>

/* Write a main() program that prints n lines. On line j,
 * print j dots, followed by a single *. For example, for n==15:

*
.*
..*
...*
....*
.....*
......*
.......*
........*
.........*
..........*
...........*
............*
.............*
..............*

 * Things are starting to get a little bit tricky. Several things
 * need to be coordinated in this program. Hard code the value of
 * n, or ask the user.
 */

int main17 (int argc, char *argv[])
{
	int n, outer, inner;
	n = 15;

	for ( outer = 1; outer <= n; outer++ )
	{
		for ( inner = 0; inner < (outer - 1); inner++ )
		{
			printf (".");
		}
		printf ("*\n");
	}
	/* Bam! Worked first try.  I love me. */

#if 0
	/* Answer key solution is similar to mine. */

	int line, col;
    int n=15 ;
  
    for ( line=0; line < n; line++ )
    {
      for ( col=0; col < line; col++ )
        printf(".");
      printf("*\n");
    }  
  printf("\n");

#endif
	system ("pause");
	return 0;
}