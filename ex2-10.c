#include <stdio.h>

int lower(int c);

/* Rewrite the function lower, which converts upper case letters to
 * lower case, with a conditional expression instead of if-else */
int main()
{
    printf("%c%c%c%c", lower('A'), lower('B'), lower('C'), lower('Z'));
    return 0;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
