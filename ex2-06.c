#include <stdio.h>

int setbits(unsigned x, int p, int n, unsigned y);

/* Write a function setbits(x,p,n,y) that returns x with the n bits that
 * begin at position p set to the rightmost n bits of y, leaving the other
 * bits unchanged. */
int main()
{
	printf("%x", setbits(0xf0f0, 7, 8, 0x3a));
	return 0;
}

/* setbits: see description above. broken into multiple steps for
 * easier readability. */
int setbits(unsigned x, int p, int n, unsigned y)
{
	x = (x & ~(~(~0 << n) << (p+1-n))); /* Set the target bits to 0 */
	y = (y & ~(~0 << n)); /* Mask out the y bits we're not interested in */
	y = y << (p+1-n); /* Shift our bits into the correct position */
	return x | y;
}
