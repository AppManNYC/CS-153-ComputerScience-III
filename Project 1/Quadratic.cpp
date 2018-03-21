//
//  main.cpp
//  BMI Calculator & Quadratic Calculator
//
//  Created by Matthew Krieger on 9/16/15.
//  Copyright (c) 2015 Matthew Krieger All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* ------------------------------------HOMEWORK 1 / PROBLEM 2 ------------------------------------------- */



int quad_eval (double a, double b, double c)
{
    
    if (a == 0)
        return 1;
    else if ( (b*b)-(4*a*c) < 0 )
        return 2;
    else if ( (b*b)-(4*a*c) == 0 )
        return 3;
    else
        return 4;
}

void quad_roots (double a, double b, double c, double *r1, double *r2)
{
    
    *r1 = (((-1)*b + sqrt((b*b) - 4*a*c))/(2*a));
    *r2 = (((-1)*b - sqrt((b*b) - 4*a*c))/(2*a));
}

int main02(void)
{
    
    double a, b, c, r1, r2;
    int flag = 1;
    
    printf ("The standard form of a quadratic equation is ax^2 + bx + c = 0.\n");
    printf ("To determine the real (if they exist) roots and their multiplicity, \n");
    printf ("please enter the following (enter 0 for a, b, and c to exit program): \n\n");
    
    
    while (flag)
    {
        
        printf ("\nCoefficient a: \n");
        scanf (" %lf", &a);
        printf ("Coefficient b: \n");
        scanf (" %lf", &b);
        printf ("Constant c: \n");
        scanf (" %lf", &c);
        
        if (a == 0 && b == 0 && c == 0)
        {
            flag = 0;
            printf ("Exiting . . .\n");
            continue;
        }
        
        printf ("The values stored are: a = %g, b = %g, and c = %g.\n", a, b, c);
        
        switch ( quad_eval (a, b, c)) {
                
            case 1:
                printf ("The equation is linear, with one root at x = %g.\n", (-1)*c/b);
                break;
            case 2:
                printf ("The equation has no real roots.\n");
                break;
            case 3:
                quad_roots (a, b, c, &r1, &r2);
                printf ("There is one real root, located at x = %g.\n", r1);
                break;
            case 4:
                quad_roots (a, b, c, &r1, &r2);
                printf ("There are two real roots, located at x = %g and x = %g.\n", r1, r2);
                break;
            default:
                printf ("Error");
        }
        
    }
    
    system ("pause");
    return 1;
    
}