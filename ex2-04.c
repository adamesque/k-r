#include <stdio.h>

#define MAXLINE 1000

void squeeze(char s1[], char s2[]);
int get_line(char s[], int lim);

/* write an alternate version of squeeze(s1,s2) that deletes
 * each character in s1 that matches any character in the string s2. */
int main()
{
	int i;
	char c;
	char str[MAXLINE];
	char str_to_remove[MAXLINE];

	printf("Enter a string: ");
	get_line(str, MAXLINE);

	printf("Enter the chars to remove: ");
	get_line(str_to_remove, MAXLINE);

	squeeze(str, str_to_remove);

	printf("Result:\n\t%s", str);
	return 0;
}

/* squeeze: deletes any char in s2 from s1 */
void squeeze(char s1[], char s2[])
{
	int i, j, k;
	int in_s2;

	for (i = j = 0; s1[i] != '\0'; ++i) {
		for (k = in_s2 = 0; s2[k] != '\0'; ++k) {
			if (s1[i] == s2[k]) {
				in_s2 = 1;
			}
		}

		if (!in_s2) {
			s1[j++] = s1[i];
		}
	}
	s1[j] = '\0';
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
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
