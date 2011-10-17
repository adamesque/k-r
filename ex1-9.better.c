#include <stdio.h>

/* copy input to output, replacing consecutive spaces
 * with a single space; better version
 * c.f. http://www.trunix.org/programlama/c/kandr2/krx109.html */
main()
{
	int c, pc;

	pc = EOF;
	while ((c = getchar()) != EOF) {
		if (c != ' ')
			putchar(c);
		if (c == ' ')
			if (pc != ' ')
				putchar(c);
		pc = c;
	}
}
