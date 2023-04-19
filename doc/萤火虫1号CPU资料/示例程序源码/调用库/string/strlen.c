#include <string.h>

int strlen(const char* const s)
{
	int i;

	for (i = 0; s[i] != (char)0; ++i);
	return i;
}
