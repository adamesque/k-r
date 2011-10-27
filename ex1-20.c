#include <stdio.h>

#define TABSIZE 4				/* 4 spaces per tab */

int expand_tab(int col_num);	/* test */

/* replace tabs in the input with spaces */
main()
{
	int col;
	char c;

	col = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			col = col + expand_tab(col);
		}
		else if (c == '\n') {
			putchar(c);
			col = 0;
		}
		else {
			putchar(c);
			++col;
		}
	}
	return 0;
}

/* expand_tab: given a tab in column col, output the appropriate 
 * number of spaces */
int expand_tab(int col)
{
	int i, num_spaces, remainder;

	remainder = col - ((col / TABSIZE) * TABSIZE); /* we have not yet encountered the modulo operator */
	num_spaces = TABSIZE - remainder;
	for (i = num_spaces; i > 0; --i)
		putchar(' ');

	return num_spaces;
}
