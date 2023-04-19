#include "string.h"

#define NULL 0

char * strchr(const char * string, int ch)
{
   while (*string && *string != (char)ch)
        string++;
   if (*string == (char)ch)
       return((char *)string);
    return(NULL);
}
