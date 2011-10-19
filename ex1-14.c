#include <stdio.h>

#define MAX_CHARCODE 128

main()
{
	int c, i, j;
	int chars[MAX_CHARCODE];

	for (i = 0; i < MAX_CHARCODE; ++i)
		chars[i] = 0;

	while ((c = getchar()) != EOF)
		if (0 <= c && c < MAX_CHARCODE)
			++chars[c];

	for (i = 0; i < MAX_CHARCODE; ++i) {
		if (chars[i] > 0) {
			if (i == '\n')
				printf("\\n");
			else if (i == '\t')
				printf("\\t");
			else if (i == '\b')
				printf("\\b");
			else {
				putchar(' ');
				putchar(i);
			}
			putchar(' ');
			for (j = 0; j < chars[i]; j++)
				putchar('#');
			putchar('\n');
		}
	}
}
