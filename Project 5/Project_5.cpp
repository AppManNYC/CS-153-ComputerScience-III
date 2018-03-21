/*CS 153 PROGRAM 5 - Monte Carlo
 AUTHOR: Matthew Allen Krieger
 DATE:10/20/2015
 DESCRIPTION: Estimates the integral of the
 function 0.1(x^2)-0.2x+2 from 0 to 10
 by using random dart throws.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void ThrowDart(double *x, double *y)
{
    int srand(time(NULL));
    *x = ((double)rand() / (RAND_MAX)) * 10;
    *y = ((double)rand() / (RAND_MAX)) * 10;
}

double Fun(double x)
{
    return (0.1*x*x) - (0.2*x) + 2;
}

int main()
{
    int i, n, hit=0;
    double x, y,integral;
    
    printf("N(How many Darts)? ");
    scanf("%d", &n);
    
    for (i = 0; i <= n; i++)
    {
        ThrowDart(&x, &y);
        if (y <= Fun(x))
        {
            hit++;
        }
    }
    
    integral = ((double)hit / n) * 100;
    printf("N: %d\nIntegral: %lf\n", n, integral);
    
    system("pause");
    return 0;
}