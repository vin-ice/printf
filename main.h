#ifndef _PRINTF_H_
#define _PRINTF_H_
#include <stdarg.h>

struct format{
    char *specifier;
    int (*f)(va_list);
};

int _printf(const char *format, ...);
int _putchar(char c);
int print_c(va_list);
int print_s(va_list);
int print_i(va_list);
int print_f(va_list);
int print_p(va_list);

#endif /*_PRINTF_H*/
