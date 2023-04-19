char* strncpy(char* dst0, const char* src0, int count)
{
    char* dscan;
    const char* sscan;

    dscan = dst0;
    sscan = src0;
    while (count > 0)
    {
        --count;
        if ((*dscan++ = *sscan++) == '\0')
            break;
    }
    while (count-- > 0)
        *dscan++ = '\0';

    return dst0;
}
