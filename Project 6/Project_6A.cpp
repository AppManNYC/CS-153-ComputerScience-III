/*
 File Name: main.cpp
 Author: Matthew Krieger
 Date: 11/9/2015
 Brief Description: Assignment VI Solution I 
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


double avg (int n, double arr[])
{
    int i;
    double sum = 0;
    
    for (i=0; i<n; i++)
    {
        sum = sum + arr[i];
    }
    
    return sum/n;
}

double standarddev(int n, double arr[], double avg)
{
    int i;
    double sumDifference = 0;
    
    for(i=0; i<n; i++)
    {
        sumDifference = sumDifference + (arr[i] - avg)*(arr[i] - avg);
    }
    
    return sqrt(sumDifference/(n-1));
}

int main(void)
{
    double xAverage = 0, yAverage = 0, xStandardDev = 0, yStandardDev = 0, correlation = 0, SumXY = 0;
    int i = 0;
    int n = 21;
    
    double x[] = {79,70,79,74,70,93,88,94,64,60,62,89,92,73,72,85,94,84,86,82,87};
    double y[] = {94,115,96,104,106,136,99,128,78,48,87,127,140,136,134,115,135,115,82,65,132};
    
    xAverage = avg(n,x);
    yAverage = avg(n,y);
    
    xStandardDev = standarddev(n, x, xAverage);
    yStandardDev = standarddev(n, y, yAverage);
    
    for (i=0; i<n; i++)
    {
        SumXY = SumXY + (x[i] * y[i]);
    }
    
    correlation = (SumXY - (n*xAverage*yAverage))/((n-1)*xStandardDev*yStandardDev);
    printf("n = %d; Correlation Coeffiecient = %.4lf\n", n, correlation);
    
    
    
    return 0;
}

