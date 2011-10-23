#include <stdio.h>
#define MAXLINE 20 /* maximum input line size (small for testing) */

int getaline(char line[], int maxline);
void copy(char to[], char from[]);

/* Revise the main routine of the longest-line program
 * so it will correctly print the length of arbitrarily
 * long input lines, and as much as possible of the text.
 *
 * Somewhat better solution c.f.
 * https://github.com/thvdburgt/KnR-The-C-Programming-Language-Solutions/blob/master/Chapter%201/1-16/longestline.c
 *
 * The tricky part is ONLY modifying main() and not getline() */

/* print longest input line */
main()
{
	int i;
	int len, prevlen;		/* current line lengths */
	int max;				/* maximum length seen so far */
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];	/* longest line saved here */
	char temp[MAXLINE];		/* start of line before we ran out of mem */

	max = prevlen = 0;
	while ((len = getaline(line, MAXLINE)) > 0) {
		if (prevlen + len > max) {
			max = prevlen + len;
			if (!prevlen)
				copy(longest, line);
			else
				copy(longest, temp);
		}
		
		if (line[len-1] != '\n') {
			if (!prevlen) /* copy start of line to temp */
				copy(temp, line);
			prevlen = prevlen + len;
		} else 
			prevlen = 0;
	}
	if (max > 0) {	/* there was a line */
		printf("%d\n", max);
		printf("%s", longest);
		if (max > MAXLINE)
			printf("...");
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
