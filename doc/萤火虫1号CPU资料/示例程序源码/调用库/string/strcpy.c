char* strcpy(char* dst, const char* src) {
	char* cp = dst;

	while ((*cp++ = *src++) != (char)0)
		;
	return (dst);
}
