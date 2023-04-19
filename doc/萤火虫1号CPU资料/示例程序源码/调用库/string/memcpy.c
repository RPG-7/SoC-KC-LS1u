#include <string.h>

void * memcpy(void *dst,const void *src,int count)
{
   void * ret = dst;
   while (count--) 
   {
      *(char *)dst = *(char *)src;
      dst = (char *)dst + 1;
      src = (char *)src + 1;
   }
   return(ret);
}
