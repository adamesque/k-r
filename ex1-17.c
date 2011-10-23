#include <stdio.h>
#define MAXLINE 81 /* print any line that overflows this */

int getaline(char line[], int maxline);
void copy(char to[], char from[]);

/* print all input lines longer than 80 characters */
main()
{
	int len;				/* current line length */
	int accumulated_len;	/* accumulated line length */
	char line[MAXLINE];

	accumulated_len = 0;
	while ((len = getaline(line, MAXLINE)) > 0) {
		if (line[len-1] != '\n' || accumulated_len > 0) {
			accumulated_len = accumulated_len + len;
			printf("%s", line);
		}

		if (len < MAXLINE-1)
			accumulated_len = 0;
	}
	return 0;
}

/* getaline: read a line into s, return length */
int getaline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
