#include <stdio.h>

int bitcount(unsigned x);

/* Leverage two's complement to write a faster version of bitcount */
int main()
{
    printf("%d\n", bitcount(0x0111101));
    return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x-1))
        b++;

    return b;
}
