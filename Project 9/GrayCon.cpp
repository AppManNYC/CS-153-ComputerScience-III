/*
 Author: Matthew Krieger
 Date: 12/01/2015
 Brief Description: Assignment IX - Solution I
 */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void makeCircles( FILE *image, int nrows, int ncols, int minGray, int maxGray, int numCircles )
{
    
    int numofCircles = numCircles;
    int numOfShades = numofCircles + 1;
    int *shades = (int *)malloc(numOfShades);
    double *radius = (double *)malloc(numofCircles);
    int r, c ;
    
    int rc, cc ;
    int rd, cd ;
    int shadeOfPixel;
    double dist ;
    rc = nrows/2;
    cc = ncols/2;
    
    /*figure out which is smaller dimension, base the smallest radius on that*/
    if ( nrows<ncols ) radius[0] = nrows/10;
    else radius[0] = ncols/10;
    /*calculates the radii based on the number of circles*/
    for (int i=1; i<numofCircles; i++)
    {
        radius[i] = (i+1) * radius[0];
    }
    
    int grayDifference = (maxGray - minGray)/numofCircles;
    for(int i = 0; i<numofCircles;i++)
    {
        shades[i] = minGray + grayDifference*i;
    }
    
    for ( r=0; r<nrows; r++ )
    {
        rd = r - rc;
        for ( c=0; c<ncols; c++ )
        {
            cd = c - cc;
            dist = sqrt( (double)(rd*rd + cd*cd) );
            shadeOfPixel = maxGray;
            
            for (int i=(numofCircles-1); i >= 0; i-- )
                if ( dist < radius[i] )
                    shadeOfPixel = shades[i];
            fputc(shadeOfPixel, image );
        }
    }
    free(radius);
    free(shades);
}
void openImage( char *argv[], FILE **image, int *nrows, int *ncols )
{
    
    if ( (*image = fopen( argv[1], "wb") ) == NULL )
    {
        printf("file %s could not be created\n", argv[1] );
        exit( EXIT_FAILURE );
    }
    *nrows = atoi( argv[2] );
    if ( *nrows < 1 )
    {
        printf("number of rows must be positive\n");
        exit( EXIT_FAILURE );
    }
    *ncols = atoi( argv[3] );
    if ( *nrows < 1 )
    {
        printf("number of columns must be positive\n");
        exit( EXIT_FAILURE );
    }
}

void writeHeader( FILE *image, int nrows, int ncols )
{
    fprintf( image, "P5\n");
    fprintf( image, "# Created by makeCircle\n");
    /* width, height, number of gray levels */
    fprintf( image, "%d %d %d\n", ncols, nrows, 255 );
}
int main( int argc, char *argv[] )
{
    int nrows, ncols ;
    int minGray ; /* minimum gray level: inner circle */
    int maxGray ; /* maximum gray level: background */
    FILE *image;
    int numCircles ;
    /* check the command line parameters */
    if ( argc != 7 )
    {
        printf("Ccircles fileName.pgm nrows ncols minGray maxGray numCircles\n");
        return 0;
    }
    minGray = atoi( argv[4] );
    maxGray = atoi( argv[5] );
    numCircles = atoi(argv[6]);
    /* Open the image file, get number of rows and columns */
    openImage( argv, &image, &nrows, &ncols );
    /* write header information */
    writeHeader( image, nrows, ncols );
    /* Create the Image */
    makeCircles( image, nrows, ncols, minGray, maxGray, numCircles );
    /* close the file */
    fclose ( image );
    return 1;
}