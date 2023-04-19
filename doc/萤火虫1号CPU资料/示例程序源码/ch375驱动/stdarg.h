#ifndef _STDARG

#define _STDARG

typedef char* va_list;

#endif

#define va_start(va_list_ap, last_arg) ((va_list_ap) = (char*)((&(last_arg)) + 1))
#define va_arg(va_list_ap, type) ((va_list_ap) = (char*)((type*)(va_list_ap) + 1), *((type*)(va_list_ap) - 1))
#define va_end(va_list_ap)
