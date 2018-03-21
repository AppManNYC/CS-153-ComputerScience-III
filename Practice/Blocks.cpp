#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main (void)
{
	int blockIndex = 1;
	int lineIndex = 0;
	int ch;

	while ( (ch = getchar()) != EOF )
	{
		/* Convert to uppercase, only proceed if chars we want (i.e. in ANSI char range 65 - 90) */
		ch = toupper(ch);  
		if ( ch < 65 )
			continue;
		else if ( ch > 90 )
			continue;				
		else
		{						
			if ( blockIndex%6 == 0 )      /* Kludgey but it works for block/line partitions */
			{				
				putchar (' ');
				blockIndex++;
				lineIndex++;
				if ( lineIndex%10 == 0 )
					putchar ('\n');				
			}		
			putchar (ch);
			blockIndex++;
		}
	}
}