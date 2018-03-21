#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* Easy dice game
|
|  The game consists of 7 rounds.
|  In each round, the computer throws a die, 
|  then the human throws a die.
|  The winner of the round is the player who has the highest throw.
|  In case of a tie, neither player wins.
|  The winner of the game is the player who has won the most rounds.
|
*/

char input[132];   /* user input buffer */

int throwDie()
{
  static int initialized = 0;
  int num;
  
  if ( !initialized )
  {
    printf("Initializing Die!\n\n");
    srand( time(NULL) );
    initialized = 1;
  }
  num = (int)(6.0*rand()/(RAND_MAX)) + 1 ; /* See #if 0 comments for explanation of method. */
  return num;
}
#if 0
/*
       In Numerical Recipes in C: The Art of Scientific Computing
       (William  H.  Press, Brian P. Flannery, Saul A. Teukolsky,
       William T.  Vetterling;  New  York:  Cambridge  University
       Press,  1990 (1st ed, p. 207)), the following comments are
       made:
              "If you want to generate a random integer between 1
              and 10, you should always do it by

                     j=1+(int) (10.0*rand()/(RAND_MAX+1.0));

              and never by anything resembling

                     j=1+((int) (1000000.0*rand()) % 10);

              (which uses lower-order bits)."
*/
#endif

/* Player turn */
int humanTurn()
{
  int toss;
  toss = throwDie();
  printf("\nPlayer rolls a %d\n", toss );
  return toss;
}

/* Robot turn */
int computerTurn()
{
  int toss;
  toss = throwDie();
  printf("\nRobot rolls a %d\n", toss );
  return toss;
}
/* Workaround to avoid the extra includes to get Sleep() for Windows, or sleep() for Unix. */
/* clock_t is the data type returned by clock(); really just a typefef'ed long. */
void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main (int argc, char *argv[])
{
	int round, humanWins=0, computerWins=0;
	int humanToss;
	const int numberOfRounds = 7;
	int yes, ch, numberOfRolls;	
	int humanSum, robotSum, j;

	/* Start game loop. */
	for ( round = 1; round<=numberOfRounds; round++ )
	{
		/* Resets */
		humanSum = robotSum = numberOfRolls = ch = 0;
		yes = 1;

		printf("\nRound %d\n\n", round );
		printf("Player's Turn: (hit enter)");
		gets( input ); /* pause for dramatic effect */
		while ( yes )
		{			
			humanToss = humanTurn();			
			humanSum += humanToss;
			numberOfRolls++;
			printf("\nPlayer total: %d\n", humanSum);
			printf("\nDo you wish to throw again? [Y or N] :");
			scanf ("%s", &ch );
			ch = toupper(ch);			
			if ( ch != 89 )
			{
				yes = 0;
			}			
		}		
		printf("\nRobot's Turn:");
		sleep (1500);
		for (j = 0; j < numberOfRolls; j++)
		{
			printf ("\n");
			robotSum += computerTurn();
			sleep (1500); /* More pause drama. Adjust as personally necessary. */
		}
		/* Determine Winner of the Round */
		if ( humanSum > robotSum )
		{
			humanWins++;
			printf("\nPlayer wins the round.    human: %3d. robot: %3d\n",
				humanWins, computerWins );
		}
		else if ( robotSum > humanSum )
		{
			computerWins++;
			printf("\nRobot wins the round. human:%3d. robot: %3d\n",
				humanWins, computerWins );
		}
		else if ( robotSum == humanSum)
		{
			computerWins++;
			printf("\nTie goes to the robot.    human:%3d. robot: %3d\n",
				humanWins, computerWins );
		}
		/* Round over. */
	}

	/* Determine Winner to the Game */
	if ( humanWins > computerWins )
	{
		printf("\n\nWINNER!! You win the game!\n");
	}
	else if ( computerWins < humanWins )
	{
		printf("\n\nThe robot wins the game!\n");
	}
	else
	{
		printf("\n\nTie Game!\n");
	}
	system ("pause");
	return 0;
}