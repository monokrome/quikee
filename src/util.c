 #include <string.h>
#include "util.h"

/**
 * The following code is adopted from K&R, with a small addition to itoa
 * where I've opted to allow the base-n to be provided.
 */

/* reverse:  reverse string s in place */
void reverse(char s[])
{
	int i, j;
	char c;

	for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/* itoa:  convert n to characters in s */
void itoa(int n, char s[], short int base)
{
	int i, sign;

	if ((sign = n) < 0)  /* record sign */
		n = -n;          /* make n positive */

	i = 0;

	do {       /* generate digits in reverse order */
		s[i++] = n % base + '0';   /* get next digit */
	} while ((n /= base) > 0);     /* delete it */

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
}
