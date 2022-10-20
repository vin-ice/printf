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
        {"i", print_i},
        {"u", print_u},
        {"o", print_o},
        {"c", print_c},
        {"s", print_s},
        {"d", print_i},
        {"f", print_f},
        {NULL, NULL}
    };
    
    va_start(pa, format);
    /*print format*/
    while (format && format[i] != 27 && format[i] != '\0'){
        if (format[i] != '%')
        {
            _putchar(format[i]);
            count++;
            i++;
            continue;
        }
        _putchar('\0');
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
int print_i(va_list vi)
{
    int count = 0, power, temp, numchar;
    int num = va_arg(vi, int);

    if (num < 0)
	{
		_putchar('-');
		num *= -1;
        count += 1;
	}
    temp = num;
    for (power = 1; num >= 10; num /= 10, power *= 10)  
        ;
    for (; power >= 1; power /= 10, count++)
    {
        numchar = (temp / power) % 10;
        _putchar(numchar + '0');
    }
    return (count);
} 
int print_u(va_list vu)
{
    unsigned long int num = va_arg(vu, unsigned long int);
    
    return (print_unsigned(num));
} 
int print_o(va_list vu)
{
    unsigned long int num = va_arg(vu, unsigned long int);

    if (num)
        num = _itoo(num);
    return (print_unsigned(num));
} 

int print_s(va_list s)
{
    int count = 0;
    char * str = va_arg(s, char *);
    
    for (;str != NULL && *str != '\0' && *str != 27; str++, count++)
        _putchar(*str);
    return (count);
}
int print_c(va_list c)
{
    int count = 0;
    char ch = (char) va_arg(c, int);

    _putchar(ch);
    count++;
    return (count);
}
int print_f(va_list f)
{
    int count = 0;
    va_arg(f, double);
    return (count);
}
int print_unsigned(unsigned long int n)
{
    unsigned int count = 0, power, numchar;
    unsigned long int temp;
    
    temp = n;
    for (power = 1; n >= 10; n /= 10, power *= 10)  
        ;
    for (; power >= 1; power /= 10, count++)
    {
        numchar = (temp / power) % 10;
        _putchar(numchar + '0');
    }
    return (count);
}
unsigned long int _itoo(unsigned long int n)
{
    unsigned long int oct;
    int pos;

    for (pos = 1; n > 0 ; n /= 8, pos *= 10)
        oct += (n % 8) * pos;
    return (oct);
}