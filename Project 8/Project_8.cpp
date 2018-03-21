/*
 File Name: main.cpp
 Author: Matthew Krieger
 Date: 11/23/2015
 Brief Description: Assignment VIII
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main (int argc, char** argv )
{
    int Key = atoi(argv[2]);
    FILE *in, *out;
    int ch = *argv[1];
    
    if(Key > 255 || Key < 0)
    {
        fprintf(stderr, "key must be between 0 and 255");
        return(EXIT_FAILURE);
    }
    
    if ( argc != 5 || (*argv[1] != 'e' && *argv[1] != 'd' && *argv[1] != 'E' && *argv[1] != 'D') )
    {
        fprintf( stderr, "only enter e to encipher or d to decipher\n");
        return( EXIT_FAILURE );
    }
    
    if ( (in = fopen( argv[3], "rb")) == NULL )
    {
        perror( argv[3] );
        return( EXIT_FAILURE );
    }
    
    if ( (out = fopen( argv[4], "wb")) == NULL )
    {
        perror( argv[4] );
        return( EXIT_FAILURE );
    }
    
    while ( (ch = fgetc(in)) != EOF )
    {
        if(strcmp(argv[1], "e") == 0 || strcmp(argv[1], "E") == 0)
        {
            ch = (ch + Key) % 256;
            fputc( ch, out );
            Key++ % 256;
        }
        
        if(strcmp(argv[1], "d") == 0 || strcmp(argv[1], "D") == 0)
        {
            ch = (ch - Key) % 256;
            fputc( ch, out );
            Key++ % 256;
        }
    }
    
    if ( fclose( in ) == EOF )
    {
        perror( argv[1] );
        return( EXIT_FAILURE );
    }
    
    if ( fclose( out ) == EOF )
    {
        perror( argv[2] );
        return( EXIT_FAILURE );
    }
    
    return( EXIT_SUCCESS );
}
