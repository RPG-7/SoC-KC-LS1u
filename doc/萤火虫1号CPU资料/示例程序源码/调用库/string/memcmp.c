#include <string.h>

int memcmp(const void *buffer1, const void *buffer2, int count) 
{ 
   if (!count) 
      return(0); 
   while ( --count && *(char *)buffer1 == *(char *)buffer2) 
   { 
      buffer1 = (char *)buffer1 + 1; 
        buffer2 = (char *)buffer2 + 1; 
   } 
   return( *((unsigned char *)buffer1) - *((unsigned char *)buffer2) ); 
} 
