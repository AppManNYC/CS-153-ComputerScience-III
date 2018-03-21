/************************************************************************************
 Matthew Allen Krieger
 CS 153: Computer Science III
 Assignment IV
 10/14/2015
 *************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void combineTime(int *totalSec, int hours, int minutes, int seconds)
{
    *totalSec = (hours*3600) + (minutes*60) + (seconds);
}

void splitTime(int totalSec, int *hours, int *minutes, int *seconds)
{
    *seconds = totalSec % 60;
    *minutes = totalSec/60;
    *hours = *minutes /60;
    *minutes = *minutes % 60;
}

int main(void)
{
    int hours, minutes, seconds, start, current, difference;
    
    printf ("Start Hours: ");
    scanf ("%d", &hours);
    printf ("Start Minutes ");
    scanf ("%d", &minutes);
    printf ("Start Seconds ");
    scanf ("%d", &seconds);
    
    if (hours < 0 || minutes < 0 || seconds < 0)
    {
        printf ("Invalid Input. Please adjust your input so inut is 0 or greater.");
    }
    else
    {
        combineTime(&start, hours, minutes, seconds);
        
        printf ("\nCurrent Hours: ");
        scanf ("%d", &hours);
        printf ("Current Minutes: ");
        scanf ("%d", &minutes);
        printf ("Current Seconds: ");
        scanf ("%d", &seconds);
        
        if (hours < 0 || minutes <0 || seconds < 0)
        {
            printf ("Invalid Input. Please adjust your input so inut is 0 or greater.");
        }
        else
        {
            combineTime(&current, hours, minutes, seconds);
            
            if (current < start)
            {
                printf ("Current time must be after the start time.");
            }
            else
            {
                difference = current - start;
                splitTime (difference, &hours, &minutes, &seconds);
                printf("\nTime difference: %d hours, %d minutes, %d seconds", hours, minutes, seconds);
            }
        }
    }
}


