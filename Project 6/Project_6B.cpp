/*
 File Name: main.cpp
 Author: Matthew Krieger
 Date: 11/9/2015
 Brief Description: Assignment VI Solution II */
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

int main()
{
    double xAverage = 0, yAverage = 0, xStandardDev = 0, yStandardDev = 0, correlation = 0, SumXY = 0;
    int i = 0;
    int n = 0;
    const int MAXSIZE = 100;
    double x[MAXSIZE];
    double y[MAXSIZE];
    scanf("%d", &n);
    
    if (n > MAXSIZE)
    {
        printf("Maximum Size was Exceeded. Try Again");
    }
    else
    {
        
        for (i=0; i<n; i++)
            scanf("%lf %lf", &x[i], &y[i]);
        
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
    }
    
    
    return 0;
}
