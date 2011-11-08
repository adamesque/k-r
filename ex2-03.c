#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

/* Write the function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 through 9, a through f, and A through F. */
int main()
{
	printf("c = %d\n", htoi("c"));
	printf("1A = %d\n", htoi("1A"));
	printf("0xfe = %d\n", htoi("0xfe"));
	printf("0X4B9 = %d\n", htoi("0X4B9"));
	printf("0zYB9 = %d\n", htoi("0zYB9"));
	return 0;
}

/* htoi: convert hex ASCII string to int */
int htoi(char s[])
{
	int i, n;
	int x; /* holds integer value of the current hex char */

	n = 0;
	if (s[0] == '0' && tolower(s[1]) == 'x') {
		i = 2;
	} else {
		i = 0;
	}

	while (isxdigit(s[i])) {
		if (isdigit(s[i])) {
			x = s[i] - '0';
		} else {
			x = tolower(s[i]) - 'a' + 10;
		}
		n = 16 * n + x; 
		++i;
	}

	return n;
}
