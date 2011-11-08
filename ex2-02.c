#include <stdio.h>

#define MAXLINE 72

/* Write a loop equivalent to the following with using && or ||:
 *
 * for (i=0; i<lim-1 && ((c=getchar()) != '\n' && c != EOF; ++i)
 *      s[i] = c;
 *
 */
int main()
{
    int i;
    int len; /* Since we need to break out of the for loop by manipulating i, store the length read somewhere else */
    int lim = MAXLINE;
    char c;
    char s[MAXLINE];

    for (i=len=0; i<lim-1; ++i) {
        c = getchar();
        ++len;
        if (c == '\n')
            i = MAXLINE;
        else if (c == EOF)
            i = MAXLINE;
        else
            s[i] = c;
    }
    return 0;
}
