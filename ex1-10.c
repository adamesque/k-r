#include <stdio.h>

/* Copy input to output, replacing each tab by \t, 
 * each backspace by \b, and each backslash by \\ */
main()
{
	int c, is_special;

	while ((c = getchar()) != EOF) {
		is_special = 0;
		if (c == '\t') {
			printf("\\t");
			is_special = 1;
		}

		if (c == '\b') {
			printf("\\b");
			is_special = 1;
		}

		if (c == '\\') {
			printf("\\\\");
			is_special = 1;
		}

		if (is_special == 0)
			putchar(c);
	}
}
