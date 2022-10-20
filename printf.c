#include "main.h"
/**
 * _printf - formatted output conversion
 * @format: String with 0 or more directives
 * 
 * Return: returns number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list ap;
    int count = 0, i = 0;
    int (*get_ptr)(va_list);

    va_start(ap, format);
    if (!format)
        return (-1);
    /*print format*/
    while (format && format[i])
    {
        if (format[i] != '%')
        {
            count += _putchar(format[i]);
            i++;
            continue;
        }
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '%')
            {
                count += _putchar(format[i]);
                i++;
                continue;
            }
            if (format[i] == '\0')
                return (-1);
            get_ptr = get_print_func(format[i]);
            if (get_ptr != NULL)
                count += get_ptr(ap);
            else
            {
                count += _putchar(format[i - 1]);
                count += _putchar(format[i]);
            }
            i++;
        }
    }
    va_end(ap);
    return (count);
}
 






