#include "stdlib.h"

/*
int isspace(int ch)
{
    return (unsigned int)(ch - 9) < 5u || ch == ' ';
}
*/
#define isspace(ch) ((unsigned int)((ch) - 9) < 5u || (ch) == ' ')

double strtod(const char* s, char** endptr)
{
    register const char* p = s;
    register long double  value = 0.L;
    int                   sign = 0;
    long double           factor;
    unsigned int          expo;

    while (isspace(*p))
        p++;
    if (*p == '-' || *p == '+')
        sign = *p++;
    while ((unsigned int)(*p - '0') < 10u)
        value = value * 10 + (*p++ - '0');
    if (*p == '.')
    {
        factor = 1.;
        p++;
        while ((unsigned int)(*p - '0') < 10u)
        {
            factor *= 0.1;
            value += (*p++ - '0') * factor;
        }
    }
    if ((*p | 32) == 'e')
    {
        expo = 0;
        factor = 10.L;
        switch (*++p)
        {
        case '-':
            factor = 0.1;
        case '+':
            p++;
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            break;
        default:
            value = 0.L;
            p = s;
            goto done;
        }
        while ((unsigned int)(*p - '0') < 10u)
            expo = 10 * expo + (*p++ - '0');
        while (1)
        {
            if (expo & 1)
                value *= factor;
            if ((expo >>= 1) == 0)
                break;
            factor *= factor;
        }
    }
done:
    if (endptr != 0)
        *endptr = (char*)p;
    return (sign == '-' ? -value : value);
}

double atof(char* str)
{
    return strtod(str, 0);
}
