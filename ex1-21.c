#include <stdio.h>

#define TABSIZE 4                          /* 4 spaces per tab */

int modulo(int divisor, int dividend);     /* test */

/* replace tabs in the input with spaces */
main()
{
    int col, blanks, start, num_tabs, num_spaces;
    char c;

    col = blanks = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
            ++col;
        } else if (c == '\n') {
            col = blanks = 0;
            putchar(c);
        } else if (blanks == 0) {
            putchar(c);
            ++col;
        } else if (blanks == 1) {
            putchar(' ');
            putchar(c);
            blanks = 0;
            ++col;
        } else if (blanks > 1) {
            start = col - blanks;
            num_tabs = (col / TABSIZE) - (start / TABSIZE);
            num_spaces = modulo(col, TABSIZE);
            for (; num_tabs > 0; --num_tabs)
                putchar('\t');
            for (; num_spaces > 0; --num_spaces)
                putchar(' ');
            putchar(c);
            blanks = 0;
            ++col;
        }
    }

    return 0;
}

int modulo(int divisor, int dividend)
{
    return divisor - ((divisor / dividend) * dividend); /* we have not yet encountered the modulo operator */
}
