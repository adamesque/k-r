#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getaline(char line[], int maxline);
int chomp(char line[], int len);

/* Remove trailing blanks and tabs. Omit empty lines. */
main()
{
	int len;				/* current line length */
	int chomped_len;		/* chomped line length */
	char line[MAXLINE];		/* current input line */

	while ((len = getaline(line, MAXLINE)) > 0) {
		chomped_len = chomp(line, len);

		if (chomped_len > 1)
			printf("%s", line);
	}
	return 0;
}

/* chomp: remove trailing blanks and tabs from an input line */
int chomp(char line[], int len)
{
	int i;       

	for (i=len-2; i>-1 && (line[i]==' ' || line[i]=='\t'); --i)
		;

	line[i+1] = '\n';
	line[i+2] = '\0';
	return i+2;
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
