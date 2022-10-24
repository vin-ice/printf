#include "main.h"
/**
 * print_i - prints integer values
 * @vi - list of arguments(pointer to next)
 * 
 * Retunr: length of output
 */
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

/**
 * print_o - handles octal specifier
 * @vo: ppointer to next arg
 * 
 * Return: return size
 */
int print_o(va_list vo)
{
    unsigned int n, a[20];
    int count, i;

	n = va_arg(vo, unsigned int);
	for (i = 0; n > 0; n /= 8, i += 1)
        a[i] = n % 8;
    for (count = 0, i -= 1; i >= 0; i--, count += 1)
    {
        _putchar(a[i] + '0');
    }
	return (count);
}
/**
 * print_u - print unsigned integer
 * @vu: pointer to arguments list
 * 
 * Return: returns length of print out
 */
int print_u(va_list vu)
{
    unsigned long int num = va_arg(vu, unsigned long int);
    
    return (print_unsigned(num));
} 
/**
 * print_b - takes an unsigned int and prints it in binary notation
 * @b: unsigned in to print
 *
 * Return: number of digits printed
 */
int print_b(va_list b)
{
	unsigned int a[32], n;
	int count, i;

	n = va_arg(b, unsigned int);    
	for (i = 0; n > 0; n /= 2, i++)
		a[i] = n % 2;
	for (count = 0, i -= 1; i >= 0; count += 1, i--)
	{
		_putchar(a[i] + '0');
	}
	return (count);
}

/**
 * print_unsigned - prints unsigned int
 * n: integer
 * 
 * Return: return length of printout
 */
int print_unsigned(unsigned long n)
{
    unsigned int count = 0, power, numchar;
    unsigned long temp;
    
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