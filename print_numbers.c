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
    unsigned long  num = va_arg(vo, unsigned long);
    return (_pitoo(num));
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
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	n = va_arg(b, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			_putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}
/**
 * _pitoo - converts int to octal and prints
 * @n: int
 * 
 * Return: returns size of printed output
 */
int _pitoo(unsigned long n)
{
    int pos, count;

    for (pos = 1, count = 0; n > 0 ; n /= 8, pos *= 10)
        count +=_putchar(((n % 8) * pos) + '0') ;
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