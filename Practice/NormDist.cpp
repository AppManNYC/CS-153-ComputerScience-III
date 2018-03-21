#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Normal Pdf as defined in the program specs. */
void gauss ( double u, double s, double x );

int main (void) {

	double mean, stddev, x;
	int numN;
	int flag = 1;

	/* Boolean check not strictly necessary; implemented in case the 'ask only once' requirement changes. */
	while (flag) {

	printf ("Please enter the mean: \n");
	scanf (" %lf", &mean );
	printf ("The mean stored is: %g .\n\n\n", mean);

	printf ("Please enter the standard deviation: \n");
	scanf (" %lf", &stddev );
	printf ("The stddev stored is: %g .\n\n\n", stddev);

	printf ("Please enter the number of function queries: \n");
	scanf (" %d", &numN );
	printf ("The function will ask you for %d values of x.\n\n\n", numN);

	flag = 0;

	}

	int loopIndex;

	for ( loopIndex = 0 ; loopIndex < numN ;  loopIndex++ ) {

		printf ("\nPlease enter a value for x: \n");
		scanf (" %lf", &x );
		gauss ( mean, stddev, x );

	}
	
	system ("pause");
	return 1;
}

/* End user has not been spared scientific notation for extreme tail function outputs. */
void gauss ( double u, double s, double x ) {
	
	double partA, partB;

	partA = 1/(s * sqrt(2*M_PI));
	partB = exp (-.5*(((x-u)/s)*((x-u)/s)));
	printf ("f(%g)= %g\n", x, partA*partB);

}