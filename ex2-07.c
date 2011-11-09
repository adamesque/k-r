#include <stdio.h>

/* Write a function invert(x,p,n) that returns x with the n bits that
 * begin at position p inverted (i.e., 1 changed into 0 and vice versa),
 * leaving the others unchanged. */
unsigned invert(unsigned x, int p, int n)
{
    /* shift the n bits we care about into the rightmost position,
     * and xor them with a bitmask to flip them.
     *
     * then, slide them back into place, and or them with a copy of x
     * that has the half we just manipulated masked out. */

    /* printf("%4x\n", x);*/
    /* printf("%4x\n", (x >> (p+1-n)));*/
    /* printf("%4x\n", ~(~0 << n));*/
    /* printf("%4x\n", ((x >> (p+1-n)) ^ ~(~0 << n)) << (p+1-n));*/
    return (((x >> (p+1-n)) ^ ~(~0 << n)) << (p+1-n)) | (x & ~(~0 << (p+1-n)));
}

int main()
{
    printf("%x", invert(0xf2fe, 11, 8));
    return 0;
}
