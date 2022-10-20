#include "main.h"
/**
 * get_print_func - returns pointer to function
 * @c: character to be used to find pointer function
 * 
 * Return: pointer to function or NULL
 */
int (*get_print_func(char c))(va_list)
{
    int j;
    struct format s_format[] = {
        {"c", print_c},
        {"s", print_s},
        {"S", print_S},
        {"d", print_i},
        {"i", print_i},
        {"u", print_u},
        {"o", print_o},
        {"x", print_x},
        {"X", print_X},
        {"R", print_R},
        {"r", print_r},
        {"b", print_b},
        {"p", print_p},
        {NULL, NULL}
    };

    for (j = 0; s_format[j].specifier; j++)
    {
        if (c == *(s_format[j].specifier))
        {
            return (s_format[j].f);
        }
    }
    return (NULL);
}