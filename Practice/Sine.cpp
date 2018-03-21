#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define START -.5

int main (void) {

	int lc;
	double x;
	double const increment_base = 20;

	printf ("x          sin(x)\n");
	printf ("=================\n");

	for (lc = 0; lc <= 20; lc++) {
		x = START + lc/increment_base;
		if (x >= 0)
			printf (" %g\t %g\n", x, sin(x));
		else
			printf ("%g\t%g\n", x, sin(x));
	}
	
	system ("pause");
	return 1;
}