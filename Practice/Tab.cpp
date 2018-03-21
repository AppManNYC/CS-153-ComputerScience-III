#include <stdio.h>
#include <string.h>

#define N 15

void main (void)
{
	int index, ch;

	while ( (ch = getchar()) != EOF )
	{
		if ( ch == '\t' )
		{
			for ( index = 0 ; index < N ; index++ )
			{
				ch = ' ';
				putchar (ch);
			}
		}
		else
			putchar (ch);
	}
}
