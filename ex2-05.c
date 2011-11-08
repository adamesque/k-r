#include <stdio.h>

int any(char s1[], char s2[]);

/* Write the function any(s1,s2), which returns the first location
 * in the string s1 where any character from the string s2 occurs, 
 * or -1 if s2 contains no characters from s2. (The standard library
 * function strpbrk does the same job but returns a pointer to
 * the location. */
int main()
{
	int i, result;
	char c;
	char str[] = "My dog has fleas.";
	char str_to_find[] = "o.";
	char str_to_find2[] = "z";

	printf("String: %s\n", str);

	printf("Chars to find: %s\n", str_to_find);

	result = any(str, str_to_find);

	if (result >= 0) {
		printf("Match at location: %d\n", result);
	} else {
		printf("No match found.\n");
	}

	printf("Chars to find: %s\n", str_to_find2);

	result = any(str, str_to_find2);

	if (result >= 0) {
		printf("Match at location: %d\n", result);
	} else {
		printf("No match found.\n");
	}

	return 0;
}

/* any: see above for description */
int any(char s1[], char s2[])
{
	int i, j;
	int match = 0;

	for (i = 0; match == 0 && s1[i] != '\0'; i++) {
		for (j = 0; match == 0 && s2[j] != '\0'; j++) {
			if (s1[i] == s2[j]) {
				match = 1;
			}
		}
	}

	if (!match) {
		return -1;
	} else {
		return --i;
	}
}
