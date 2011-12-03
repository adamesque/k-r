#include <stdio.h>

#define MAXLINE 9000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

/* Write a function escape(s, t) that converts characters like newline
 * and tab into visible escape sequences like \n and \t as it copies the
 * string t to s. Use a switch. Write a function for the other direction
 * as well, converting escape sequences into the real characters. */
int main() {
    int i;
    char c;
    char s[MAXLINE], t[MAXLINE];

    i = 0;
    while ((c = getchar()) != EOF && i < (MAXLINE - 1)) {
        t[i] = c;
        i++;
    }
    t[i] = '\0';
    escape(s, t);
    printf("Escaped:\n\n%s\n", s);
    unescape(t, s);
    printf("Unescaped:\n\n%s\n", t);
    return 0;
}

/* escape: copy string t to s, converting characters like newline and
 * tab into visible escape sequences */
void escape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++) {
        switch(t[i]) {
        case '\a':
            s[j++] = '\\';
            s[j++] = 'a';
            break;
        case '\b':
            s[j++] = '\\';
            s[j++] = 'b';
            break;
        case '\f':
            s[j++] = '\\';
            s[j++] = 'f';
            break;
        case '\n': 
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\r':
            s[j++] = '\\';
            s[j++] = 'r';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        case '\v':
            s[j++] = '\\';
            s[j++] = 'v';
            break;
        case '\\':
            s[j++] = '\\';
            s[j++] = '\\';
            break;
        case '\?':
            s[j++] = '\\';
            s[j++] = '?';
            break;
        case '\'':
            s[j++] = '\\';
            s[j++] = '\'';
            break;
        case '\"':
            s[j++] = '\\';
            s[j++] = '\"';
            break;
        default:
            s[j++] = t[i];
        }
    }
    s[j] = '\0';

}

/* unescape: copy string t to s, converting escape sequences into the
 * real characters. */
void unescape(char s[], char t[])
{
    int in_escape = 0;
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++) {
        if (t[i] == '\\' && !in_escape) {
            in_escape = 1;
        } else if (!in_escape) {
            s[j++] = t[i];
        } else {
            switch(t[i]) {
            case 'a':
                s[j++] = '\a';
                break;
            case 'b':
                s[j++] = '\b';
                break;
            case 'f':
                s[j++] = '\f';
                break;
            case 'n': 
                s[j++] = '\n';
                break;
            case 'r':
                s[j++] = '\r';
                break;
            case 't':
                s[j++] = '\t';
                break;
            case 'v':
                s[j++] = '\v';
                break;
            case '\\':
                s[j++] = '\\';
                break;
            case '?':
                s[j++] = '\?';
                break;
            case '\'':
                s[j++] = '\'';
                break;
            case '"':
                s[j++] = '\"';
                break;
            }
            in_escape = 0;
        }
    }
    s[j] = '\0';
}
