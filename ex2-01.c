#include <stdio.h>
#include <limits.h>

/* Determine the ranges of char, short, int, and long variables */
int main()
{
	char c_min, c_max;
	unsigned char uc_max;

	/* print from headers */
	printf("RANGES FROM HEADERS:\n\n");

	/* char */
	printf("char:\n");
	printf("\tCHAR_MIN:\t%21d\n", CHAR_MIN);
	printf("\tCHAR_MAX:\t%21d\n", CHAR_MAX);
	printf("\tSCHAR_MIN:\t%21d\n", SCHAR_MIN);
	printf("\tSCHAR_MAX:\t%21d\n", SCHAR_MAX);
	printf("\tUCHAR_MAX:\t%21d\n", UCHAR_MAX);

	/* short */
	printf("short:\n");
	printf("\tSHRT_MIN:\t%21d\n", SHRT_MIN);
	printf("\tSHRT_MAX:\t%21d\n", SHRT_MAX);
	printf("\tUSHRT_MAX:\t%21d\n", USHRT_MAX);

	/* int */
	printf("int:\n");
	printf("\tINT_MIN:\t%21d\n", INT_MIN);
	printf("\tINT_MAX:\t%21d\n", INT_MAX);
	printf("\tUINT_MAX:\t%21u\n", UINT_MAX);

	/* long */
	printf("long:\n");
	printf("\tLONG_MIN:\t%21ld\n", LONG_MIN);
	printf("\tLONG_MAX:\t%21ld\n", LONG_MAX);
	printf("\tULONG_MAX:\t%21lu\n", ULONG_MAX);

	/* print via direct computation */
	printf("\nDIRECT COMPUTATION:\n\n");

	/* char */
	printf("char:\n");
	c_min = c_max = 0;
	while (--c_min < 0);
	while (++c_max > 0);
	printf("\tCHAR_MIN:\t%21d\n", ++c_min);
	printf("\tCHAR_MAX:\t%21d\n", --c_max);

	uc_max = 0;
	printf("\tUCHAR_MAX:\t%21d\n", --uc_max);

	/* Okay, so supposedly integer overflow behavior is undefined, 
	 * so this isn't really a "correct" method (citation needed).
	 *
	 * Also, this exercise is dumb. */

	return 0;
}
