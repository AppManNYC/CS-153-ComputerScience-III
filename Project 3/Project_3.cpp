//
//  Assignment III.cpp
//
//  Homework III
//
//  Created by Matthew Krieger
//  Copyright (c) Lunchbox Solutions. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include <math.h>

/* ------------------------------------ HOMEWORK: III | PROBLEM: I ------------------------------------ */

int main01(void)
{
    int x, y, z, count = 0;
    printf("Remember, x^2 + y^2 = z.\n");
    printf("Please enter a value for z: ");
    scanf("%d", &z);
    
    for (x = 0; x <= (int) sqrt((double)z); x++)
    {
        for (y = (int) sqrt((double)z); y >= 0; y--)
        {
            if (((x*x)+(y*y)) == z)
            {
                printf("(x: %d, y: %d)\n", x, y);
                count++;
            }
        }
    }
    
    if(count == 0)
    {
        printf("None found.\n");
    }

    return 0;
}


/* ------------------------------------ HOMEWORK: III | PROBLEM: II -------------------------------------- */

int main02(void)
{
    int a, b, c, d, count;
    
    for (a = 0; a <= 6; a++)
    {
        for (b = 0; b <= 6; b++)
        {
            for (c = 0; c <= 6; c++)
            {
                for (d = 0; d <= 6; d++)
                {
                    if ((a + b + c + d) == 6)
                    {
                        printf("%d%d%d%d \n\n", a, b, c, d);
                        count++;
                    }
                }
            }
        }
    }
    
    printf("%d Combinations.\n", count);
    
    return 0;
}


/* ------------------------------------ HOMEWORK: III | PROBLEM: III -------------------------------------- */

int main03(void)
{
    int n, r, c;
    
    printf("Evil Number Analyzer:\n\n");
    printf("Enter a number to determine if it is an Evil Number: ");
    scanf("%d", &n);
    
    while (n > 0)
    {
        r = n % 2;
        if (r == 1)
        {
            c++;
            
        }
        n = n/2;
    }
    
    if ((c % 2) == 0)
    {
        printf("You selected an Evil Number\n");
    }
    else
    {
        printf("You selected a Non-Evil Number\n");
    }
}
