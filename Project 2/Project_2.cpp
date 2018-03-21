/*
//  Project_II.cpp
//  HomeworkII
//
//  Created by Matthew A. Krieger on 9/24/15.
//  Copyright (c) 2015 Lunchbox Software Solutions. All rights reserved.
*/

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>



/* ----------------------------------------- HOMEWORK II PROBLEM I ----------------------------------------- */

int main01(void)
{
    double mean, stDev;
    int count = 0, numInputs;
    
    printf("Enter the mean of the normal distribution: ");
    scanf("%lf", &mean);
    
    printf("Enter the standard deviation of the normal distribution: ");
    scanf("%lf", &stDev);
    
    printf("Enter the number of inputs you will be making for x values: ");
    scanf("%d",&numInputs);
    
    while (count < numInputs)
    {
        double outputValue, inputValue;
        printf("Input value of x: ");
        scanf("%lf", &inputValue);
        
        outputValue = ((1 / (stDev * (sqrt(2 * M_PI)))) * exp(-.5 * ((inputValue - mean)/ stDev) * ((inputValue - mean)/ stDev)));
        printf("When (x) = %.2lf, f(x) = %lf\n", inputValue, outputValue);
        
        count++;
    }
    
    return 0;
}


/* ----------------------------------------- HOMEWORK II PROBLEM II ----------------------------------------- */

long sumDivisors(long n)
{
    long i = 1;
    long sum = 0;
    
    while(i <= n/2)
    {
        if(n%i == 0)
        {
            sum += i;
        }
        i++;
    }
    return(sum);
}


int main02(void)
{
    int lowerBounds, upperBounds;
    long temp;
    
    printf("Enter a lower  bounds: ");
    scanf("%d", &lowerBounds);
    
    printf("Enter an upper bounds: ");
    scanf("%d", &upperBounds);
    
    while (lowerBounds <= upperBounds)
    {
        temp = sumDivisors(lowerBounds);
        
        if (lowerBounds == temp)
        {
            printf("%ld is a PERFECT NUMBER.\n", temp);
        }
        else if (lowerBounds == sumDivisors(temp) && temp != lowerBounds)
        {
            printf("%d & %ld are AMICABLE NUMBERS.\n", lowerBounds, sumDivisors(lowerBounds));
        }
        
        lowerBounds++;
    }
    
    return 0;
}