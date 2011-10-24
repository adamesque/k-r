#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getaline(char line[], int maxline);
void reverse(char s[]);

/* Remove trailing blanks and tabs. Omit empty lines. */
main()
{
	int len;				/* current line length */
	char line[MAXLINE];		/* current input line */

	while ((len = getaline(line, MAXLINE)) > 0) {
		line[len-1] = '\0'; // chop off the newline
		reverse(line);
		printf("%s\n", line);
	}
	return 0;
}

/* reverse: reverses string s */
void reverse(char s[])
{
	int i, j;
	char tmp;

	/* find the end of the string */
	for (j=0; s[j]!='\0'; ++j)
		;
	--j; // j points at the last char in the string

	for (i=0; j>i; ++i) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		--j;
	}

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
