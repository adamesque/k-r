#include <stdio.h>

/* count blanks, tabs, and newlines in input */
main()
{
	int c, nb, nt, nl;

	nb = nt = nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		if (c == '\t')
			++nt;
		if (c == '\n')
			++nl;
	}
	printf("  Blanks: %3d\n", nb);
	printf("    Tabs: %3d\n", nt);
	printf("Newlines: %3d\n", nl);
}
