#include <stdio.h>

/* copy input to output, replacing consecutive spaces
 * with a single space */
main()
{
	int c;

	c = getchar();
	while (c != EOF) {
		if (c == ' ') {
			putchar(c);
			while ((c = getchar()) == ' ')
				;
		}
		putchar(c);
		c = getchar();
	}
}
