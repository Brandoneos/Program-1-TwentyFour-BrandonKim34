#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	int i;   	// counting variable

	srand(1);	// Initialize random number generator.
				// Only do this ONCE in your program!
				// Use srand( time(0)); to give different values each time.	

	// In this example we use the % operator to give 5 random numbers
	// that range from 0 to 4
	for ( i = 0; i < 5; i++)  {
		printf("%d ", (rand() % 5) );
	}
	
	return 0;
}