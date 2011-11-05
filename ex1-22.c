#include <stdio.h>

#define MAX_COL 72      /* column to fold before */

int get_line(char s[], int lim);
int put_split_string(char s[], int len);

/* "Fold" long input lines into two or more lines after the last non-blank character that occurs before the n-th column of input. */
main()
{
    int len, max;
    char line[MAX_COL+1]; /* current input line */

    max = MAX_COL;
    while ((len = get_line(line, max+1)) > 0) {
        // If we can squeeze in a full line before hitting max, print it
        if (len < max || line[max] == '\n') {
            printf("%s", line);
            max = MAX_COL;
        } else {
            // print up to the last non-blank, and then print a newline instead of the blank.
            // print the rest of our long line, and reduce max by the number of chars already printed.
            max = MAX_COL - put_split_string(line, len);
        }
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

/* put_split_string: print a string, inserting a newline after the last non-blank character
 *  return number of chars printed after the newline */
int put_split_string(char s[], int len)
{
    int i, last_non_blank;

    last_non_blank = len;
    while (last_non_blank > -1 && s[last_non_blank] != ' ')
        --last_non_blank;

    if (last_non_blank == -1) {
        printf("%s\n", s);
        return 0;
    } else {
        for (i = 0; i < last_non_blank; ++i)
            putchar(s[i]);
        putchar('\n');
        for (i = last_non_blank + 1; i < len; ++i)
            putchar(s[i]);
        return len - last_non_blank;
    }
}
