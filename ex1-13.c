#include <stdio.h>

#define IN	1 /* inside a word */
#define OUT	0 /* outside a word */
#define MAX 50 /* longest word we care about */

/* print a histogram of the lengths of words in input */
main()
{
	int c, i, j, state, lword;
	int nwords[MAX];

	for (i = 0; i < MAX; ++i)
		nwords[i] = 0;

	state = OUT;
	lword = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;

			if (lword > MAX)
				lword = MAX;

			if (lword <= MAX && lword > 0)
				++nwords[lword-1];

		} else if (state == OUT) {
			state = IN;
			lword = 1;
		} else {
			++lword;
		}
	}

	for (i = 0; i < MAX; ++i) {
		if (nwords[i] > 0) {
			printf("%2d: ", i+1);
			for (j = 0; j < nwords[i]; j++)
				putchar('#');
			putchar('\n');
		}
	}
}
