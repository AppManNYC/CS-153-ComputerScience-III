//
//  main.cpp
//  BMI Calculator & Quadratic Calculator
//
//  Created by Matthew Krieger on 9/16/15.
//  Copyright (c) 2015 Matthew Krieger All rights reserved.
//

#include <stdio.h>



/* ------------------------------------HOMEWORK 1 / PROBLEM 1 ------------------------------------------- */


/* Calculates height in feet */
double heightCalc (double heightIN)
{
    return (heightIN / 12);
}

/* Calculates BMI */
double bmiCalc (double heightFT, double weight)
{
    return ((weight * 4.88) / (heightFT * heightFT));
}

int main(void)
{
    /* Declaration Statement */
    double heightIN, weight, heightFT, bmi;
    
    
    printf("Please enter your height (inches):\n");
    scanf("%lf", &heightIN);
    
    heightFT = heightCalc(heightIN);
    
    printf("Please enter your weight (pounds):\n");
    scanf("%lf", &weight);
    
    bmi = bmiCalc(heightFT, weight);
    
    /* Displays BMI & BMI category */
    if (bmi < 20)
    {
        printf("BMI: %lf (You are UNDERWEIGHT)", bmi);
    }
    else if (bmi >= 20 && bmi < 25)
    {
        printf("BMI: %lf (You are NORMAL)", bmi);
    }
    else if (bmi >= 25 && bmi < 30)
    {
        printf("BMI: %lf (You are SLIGHTLY OVERWEIGHT)", bmi);
    }
    else if (bmi >= 30 && bmi < 40)
    {
        printf("BMI: %lf (You are OVERWEIGHT)", bmi);
    }
    else
    {
        printf("BMI: %lf (You are EXTREMELY OVERWEIGHT)", bmi);
    }
    
}
