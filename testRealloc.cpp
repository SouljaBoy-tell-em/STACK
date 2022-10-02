#include <stdio.h>
#include <stdlib.h>

int main (void) {

	double * ptr = (double * ) calloc (10, sizeof (double));

	for (int i = 0; i < 10; i++) {

		ptr [i] = i;
		printf ("%lf %p\n", ptr[i], &ptr[i]);
	}

	puts ("After: ");

	ptr = (double * ) realloc (ptr, sizeof (double) * 11);
	ptr [10] = 228;
	for (int i = 0; i < 11; i++) {

		printf ("%lf %p \n", ptr[i], &ptr[i]);
	}

	return 0;
}