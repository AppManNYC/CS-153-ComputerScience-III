#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main (void)
{	
	int ch;
	int i = 0;

	/* Populate the key char array w/ adjustment for "modulo 25" check */
	int key[5];
	key[0] = getchar() - 65;
	key[1] = getchar() - 65;
	key[2] = getchar() - 65;
	key[3] = getchar() - 65;
	key[4] = getchar() - 65;

	/* Test code to verify key */
#if 0
	int j;
	for (j=0;j<5;j++)
		printf(" %d\t", key[j]);
	printf("\n\n");
#endif

	/* "Eats" the char after the key so we aren't left with an ugly space in position 0 */
	getchar();

	while ( (ch = getchar()) != EOF )
	{
		if ( ch > 64 && ch < 91 )                /* 65-90 is range of upper case letters */
		{
			if (((ch - 65) + key[i%5]) > 25 )    /* -65 necessary to perform "modulo 25" check */ 
			{
				putchar ((ch + key[i%5]) - 26);  /* But the chars we really want to print are 65-90 */
				i++;
			}
			else
			{
				putchar ((ch + key[i%5]));
				i++;
			}
		}
		else if ( ispunct(ch) )                 /* Per the program specs, punctuation gets printed "as is" */
			putchar (ch);
		else if ( isspace(ch) )                 /* And spaces too */
			putchar (ch);
		else
			continue;		
	}
}