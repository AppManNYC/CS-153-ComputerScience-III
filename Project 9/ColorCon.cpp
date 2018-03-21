/*
 Author: Matthew Krieger
 Date: 12/02/2015
 Brief Description: Assignment IX - Solution II
 */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

void makeCircle( FILE *image, int nrows, int ncols, int cntrR, int cntrG, int cntrB, int cnrR, int cnrG, int cnrB)
{
    /* DECLARATIONS */
    int r = 0, c = 0, cd = 0, rd = 0, rc = 0, cc = 0;
    int rAMT, gAMT, bAMT;
    double length = 0.0, dist = 0.0;
    
    length = sqrt((nrows * nrows + ncols*ncols)) / 2.0 ;
    rc = nrows/2;
    cc = ncols/2;
    
    /* pixel data */
    for (r = 0; r < nrows; r++)
    {
        rd = r - rc;
        for (c=0;c<ncols;c++)
        {
            cd = c - cc;
            bAMT = (int)(cntrB + (cnrB - cntrB) * (1.0 - dist / length));
            gAMT = (int)(cntrG + (cnrG - cntrG) * (1.0 - dist / length));
            rAMT = (int)(cntrR + (cnrR - cntrR) * (1.0 - dist / length));
            
            dist = sqrt((double)(rd*rd + cd*cd));

            fputc( rAMT, image);
            fputc( gAMT, image);
            fputc( bAMT, image);
        }
    }
}

void openIMG(char *argv[], FILE **image, int *ncols, int *nrows )
{
    if ((*image = fopen(argv[1], "wb")) == NULL)
    {
        printf("%s was not created\n", argv[1]);
        exit( EXIT_FAILURE );
    }
    
    *nrows = atoi( argv[2]);
    if (*nrows < 1)
    {
        printf("Must have a positive number of rows\n");
        exit( EXIT_FAILURE );
    }
    
    *ncols = atoi( argv[3]);
    if (*ncols < 1)
    {
        printf("Must have a positive number of columns\n");
        exit( EXIT_FAILURE );
    }
}

void writeHeader(FILE *image, int nrows, int ncols)
{
    fprintf( image, "P6 ");
    fprintf( image, "# Created by circularGrad\n");
    fprintf( image, "%d %d %d ", ncols, nrows, 255 );
}

int main(int argc, char *argv[])
{
    int nrows, ncols, cntrR, cntrG, cntrB, cnrR, cnrG, cnrB;
    FILE *image;
    
    if (argc != 10)
    {
        printf("circularGrad image.ppm nrows ncols cntrR cntrG cntrB cnrR cnrG cnrB");
        return 0;
    }
    openIMG(argv, &image, &ncols, &nrows);
    writeHeader(image, nrows, ncols);
    
    cntrR = atoi(argv[4]);
    if (cntrR < 0 || cntrR > 255)
    {
        printf("cntrR must be in between 0 and 255\n");
        exit( EXIT_FAILURE );
    }
    cntrG = atoi(argv[5]);
    if (cntrR < 0 || cntrR > 255)
    {
        printf("cntrG must be in between 0 and 255\n");
        exit( EXIT_FAILURE );
    }
    cntrB = atoi(argv[6]);
    if (cntrB < 0 || cntrB > 255)
    {
        printf("cntrB must be in between 0 and 255\n");
        exit( EXIT_FAILURE );
    }
    cnrR = atoi(argv[7]);
    if (cnrR < 0 || cnrR > 255)
    {
        printf("cnrR must be in between 0 and 255\n");
        exit( EXIT_FAILURE );
    }
    
    cnrG = atoi(argv[8]);
    if (cnrR < 0 || cnrR > 255)
    {
        printf("cnrG must be in between 0 and 255\n");
        exit( EXIT_FAILURE );
    }
    
    cnrB = atoi(argv[9]);
    if (cnrB < 0 || cnrB > 255)
    {
        printf("cnrB must be in between 0 and 255\n");
        exit( EXIT_FAILURE );
    }
    makeCircle(image, nrows, ncols, cntrR, cntrG, cntrB, cnrR, cnrG, cnrB); /* create image */
    fclose (image); /* close */
}

