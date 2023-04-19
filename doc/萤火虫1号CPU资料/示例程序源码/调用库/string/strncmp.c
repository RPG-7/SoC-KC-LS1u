#include <string.h>

int strncmp(const char* s1, const char* s2, int n)
{
	unsigned char c1 = '\0';
	unsigned char c2 = '\0';

	while (n > 0)
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 == '\0' || c1 != c2)
			return c1 - c2;
		n--;
	}

	return c1 - c2;
}
