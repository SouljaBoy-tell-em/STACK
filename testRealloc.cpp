#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACKNAME(var)(#var)


int main (void) {

	/*

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

	*/

	/*

	int a = 10; // 1010
	printf ("%d\n", a);
	
	a = a | (1 << 0);
	printf ("%d\n", a);

	*/

	/*

	int a = 0;
	char len[10] = STACKNAME (a);
	puts (len);

	*/

	/*
	double a [5]= {1, 2, 3, 4, 5};
	unsigned int save = 0; 
	uint8_t * b = (uint8_t * ) a;
	save = *b;
	printf ("%d\n", save);
	*/

	double * a = (double * ) malloc (2 * sizeof (double));
	* a = 405.87510;
	* (a + 1) = 0;
	uint8_t * b = (uint8_t * ) malloc (sizeof (double));
	b = (uint8_t * )a;

	for (int i = 0; i < sizeof (double); i++)
		printf ("%d ", *(b + i));
	
	


	/*

	for (int i = 0; i < 5; i++) {

		save = * a;
		save = save | (( * b) << 8);
	}
	printf ("SAVE: %d\n", save);

*/
	return 0;
}