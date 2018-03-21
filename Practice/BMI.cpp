#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void h_conversion (double *h) {
	*h = *h/12;
}

int bmi_category (double h, double w, double b) {
	b = (w * 4.88)/(h * h);
	if (b < 20)
		return 1;
	else if (b >= 20 && b < 25)
		return 2;
	else if (b >= 25 && b < 30)
		return 3;
	else if (b >= 30 && b < 40)
		return 4;
	else
		return 5;
}

int main01 (void) {

	double height, weight, bmi;
	double *h, *w, *b;
	h = &height;
	w = &weight;
	b = &bmi;

	printf ("Please enter height (inches): \n");
	scanf (" %.2lf", &height);
	
	while ( h <= 0 ) {
		printf ("Weee, this is fun! Try again.\n");
		scanf (" %.2lf", &height);
	}
	
	if ( *h < 42 || *h > 84 ) 
		printf ("Your entry falls outside the norm for an adult.\n");

	h_conversion( h );

	printf ("Please enter weight (lbs): \n");
	scanf (" %.2lf", &weight);

	while ( w <= 0 ) {
		printf ("This is why we can't have nice things.  Try again.\n");
		scanf (" %.2lf", &weight);
	}

	switch ( bmi_category(*h, *w, *b)) {

	case 1:
		printf ("BMI: %d. Underweight.", (int)&bmi);
		break;
	case 2:
		printf ("BMI: %d. Normal weight.", (int)&bmi);
		break;
	case 3:
		printf ("BMI: %d. Slightly overweight.", (int)&bmi);
		break;
	case 4:
		printf ("BMI: %d. Overweight.", (int)&bmi);
		break;
	case 5:
		printf ("BMI: %d. Extremely overweight.", (int)&bmi);
		break;
	default:
		printf ("error condition\n");
	}
	system ("pause");
	return 1;
}




		

