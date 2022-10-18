#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * _printf - formatted output conversion
 * @format: String with 0 or more directives
 * 
 * Return: returns number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0, j, i = 0;
    va_list pa;
    struct format s_format[] = {
        {"c", print_c},
        {"s", print_s},
        {"i", print_i},
        {"f", print_f},
        {NULL, NULL}
    };
    
    va_start(pa, format);
    /*print format*/
    while (format && format[i] != 27){
        if (format[i] != '%')
        {
            _putchar(format[i]);
            count++;
            i++;
            continue;
        }
        i++;
        j = 0;
        /*check for specifier in list*/
        while(s_format[j].specifier != NULL)
        {
            if (*(s_format[j].specifier) == format[i])
            {
                count += s_format[j].f(pa);
                break;
            }
            j++;
        }
        i++;
    }
    va_end(pa);
    return (count);
}   
int print_s(va_list s){
    int count = 0;
    va_arg(s, char *);
    return (count);
}
int print_c(va_list c){
    int count = 0;
    va_arg(c, int);
    return (count);
}
int print_i(va_list i)
{
    int count = 0;
    int num = atoi(va_arg(i, int));
    int sign = 0;
    
    if (num < 0)
    {
        sign = 1;
        num = num * -1;
    }
    return (count);
}
int print_f(va_list f)
{
    int count = 0;
    va_arg(f, double);
    return (count);
}