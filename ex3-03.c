#include <stdio.h>
#include <ctype.h>

#define MAXSTR 9000

int get_line(char s[], int lim);

/* Write a function expand(s1, s2) that expands shorthand notations like
 * a-z in the string s1 into the equivalent complete list abc…xyz in s2.
 * Allow for letters of either case and digits, and be prepared to
 * handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading
 * or trailing - is taken literally. */
void expand(char s1[], char s2[])
{
    int i, j, expanding;
    char start;
    char prev = '\0';

    for (i = j = expanding = 0; s1[i] != '\0'; i++) {
        if (s1[i] == '-' && isalnum(prev)) {
            start = prev;
            expanding = 1;
        } else if (expanding) {
            if (s1[i] > start && ((isdigit(start) && isdigit(s1[i])) || (isupper(start) && isupper(s1[i])) || (islower(start) && islower(s1[i])))) {
                for (start++; start <= s1[i]; start++) {
                    s2[j++] = start;
                }
            } else {
                s2[j++] = '-';
                s2[j++] = s1[i];
            }
            expanding = 0;
        } else {
            // copy from s1 to s2
            s2[j++] = s1[i];
        }
        prev = s1[i];
    }
    s2[j] = '\0';
}

int main()
{
    int n;
    char s[MAXSTR], expanded[MAXSTR];

    while ((n = get_line(s, MAXSTR)) > 0) {
        expand(s, expanded);
        printf("%s", expanded);
    }

    return 0;
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

