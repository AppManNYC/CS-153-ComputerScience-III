/*
 File Name: main.cpp
 Author: Matthew Krieger
 Date: 11/15/2015
 Brief Description: Assignment VII Solution I & II
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**************************************** PROBLEM 1 - Scrabble Value ****************************************/

int scrabVal(char* word);

int main01()
{
    
    char *c;
    int x = 1;
    
    while (x != 0)
    {
        
        printf("Enter a word: ");
        gets(c);
        
        
         printf ("String: %s\n", c);
         printf("Length: %lu\n",strlen(c));
        
        if (*c == 'Q' && strlen(c) == 1)
        {
            x = 0;
        }
        else
        {
            printf("Scrabble value: %d\n",scrabVal(c));
        }
    }
    return 0;
}


int scrabVal(char* word)
{
    int sum = 0;
    while(*word)
    {
        
        if (*word == 'i' || *word == 'I' || *word == 'e' || *word == 'E' || *word == 'l' || *word == 'L' || *word == 'a' || *word == 'A' || *word == 'n' || *word == 'N' || *word == 'r' || *word == 'R' || *word == 'o' || *word == 'O'|| *word == 's' || *word == 'S' || *word == 't' || *word == 'T' || *word == 'u' || *word == 'U')
        {
            sum += 1;
        }
        else if(*word == 'd' || *word == 'D' || *word == 'g' || *word == 'G')
        {
            sum += 2;
        }
        else if(*word == 'b' || *word == 'B' || *word == 'c' || *word == 'C' || *word == 'm' ||
                *word == 'M' || *word == 'p' || *word == 'P')
        {
            sum += 3;
        }
        else if(*word == 'f' || *word == 'F' || *word == 'v' || *word == 'V' || *word == 'w' ||
                *word == 'W' || *word == 'y' || *word == 'Y' || *word == 'h' || *word == 'H')
        {
            sum += 4;
        }
        else if(*word == 'k' || *word == 'K')
        {
            sum += 5;
        }
        else if(*word == 'j' || *word == 'J' || *word == 'x' || *word == 'X')
        {
            sum += 8;
        }
        else if(*word == 'q' || *word == 'Q' || *word == 'z' || *word =='Z')
        {
            sum += 10;
        }
        else
        {
            sum += 0;
        }
        word++;
    }
    return sum;
}


/**************************************** PROBLEM 2 - ABRACADABRA ****************************************/

void copyString(char* word, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf (" %c", *word);
        word ++;
    }
}

int main01()
{
    char *c;
    printf("Enter your word: ");
    scanf("%s",c);
    
    int i, length = (int)strlen(c);
    
    for (i = 0; i < length; i++)
    {
        int x = i;
        while (x > 0)
        {
            printf(" ");
            x--;
        }
        copyString(c, length-i);
        printf("\n");
    }
    return 0;
}


