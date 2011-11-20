#include <stdio.h>

#define MAX 2000000

int binsearch(int x, int v[], int n);

/* Write a version of binary search with only one test inside the loop
 * and measure the difference in run-time. */
int main()
{
    int i;
    int v[MAX];
    for (i = 0; i < MAX-1; i++) {
        v[i] = i;
    }

    printf("%d\n", binsearch(-1, v, MAX));

    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1; /* no match */
}
