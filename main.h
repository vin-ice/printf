#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>
#include <stdlib.h>

struct format{
    char *specifier;
    int (*f)(va_list);
};

int (*get_print_func(char c))(va_list);
int _printf(const char *format, ...);
int _putchar(char c);
int print_c(va_list);
int print_s(va_list);
int print_S(va_list);
int print_i(va_list);
int print_u(va_list);
int print_o(va_list);
int print_x(va_list);
int print_X(va_list);
int print_R(va_list);
int print_r(va_list);
int print_b(va_list);
int print_p(va_list);
int print_unsigned(unsigned long);

#endif /*_PRINTF_H*/
