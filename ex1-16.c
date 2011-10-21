#include <stdio.h>
#define MAXLINE 20 /* maximum input line size (small for testing) */

int getaline(char line[], int maxline);
void copy(char to[], char from[]);

/* Revise the main routine of the longest-line program
 * so it will correctly print the length of arbitrarily
 * long input lines, and as much as possible of the text.
 *
 * The tricky part is ONLY modifying main() and not getline() */

/* print longest input line */
main()
{
	int i;
	int len, extralen;		/* current line lengths */
	int max;				/* maximum length seen so far */
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while ((len = getaline(line, MAXLINE)) > 0) {
		extralen = len;
		/* if the line buffer is full but the last
		 * character isn't a new line, take another
		 * bite */
		while (extralen==MAXLINE-1 && line[MAXLINE-2] != '\n' && (extralen = getaline(line, MAXLINE)) > 0) {
			len = len + extralen;	
		}

		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0) {	/* there was a line */
		printf("%d\n", max);
		if (max > MAXLINE)
			printf("...");
		printf("%s", longest);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
