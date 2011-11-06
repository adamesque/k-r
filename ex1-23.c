#include <stdio.h>

void put_quoted_literal(char quote);
void skip_comment();

/* remove all comments from a C program */
int main()
{
    int starting_comment;
    char c;

    starting_comment = 0;
    while ((c = getchar()) != EOF /* until the end of the file */) {
        if (c == '\'' || c == '"') {
            put_quoted_literal(c);
        } else if (c == '/') {
            starting_comment = 1;
        } else if (c == '*' && starting_comment) {
            skip_comment();
            starting_comment = 0;
        } else {
            if (starting_comment) {
                putchar('/');
                starting_comment = 0;
            }
            putchar(c);
        }
    }
    return 0;
}

/* put_quoted_literal: output a quoted literal beginning with `quote`, return final char */
void put_quoted_literal(char quote)
{
    int escaping;
    char c;

    /* Put starting quote */
    putchar(quote);

    /* Put quoted body */
    escaping = 0;
    while ((c = getchar()) != EOF && c != '\n' && (c != quote || escaping)) {
        if (c == '\\' && escaping != 1) {
            escaping = 1;
        } else {
            escaping = 0;
        }
        putchar(c);
    }

    /* Put end quote or newline */
    if (c != EOF)
        putchar(c);
}

/* skip_comment: fast-forward to the end of a comment without outputting */
void skip_comment()
{
    int exiting;
    char c;

    exiting = 0;
    while ((c = getchar()) != EOF && (c != '/' && exiting != 1)) {
        if (c == '*') {
            exiting = 1;
        } else {
            exiting = 0;
        }
    }
}
