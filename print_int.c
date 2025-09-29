#include "main.h"
#include <stdarg.h>

/**
 * print_int - print an integer from a va_list
 * @args: the va_list containing the int argument
 *
 * Return: number of characters printed
 */

int print_int_helper(unsigned int num);

int print_int(va_list args)
{
	int n = va_arg(args, int), count = 0;
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}
	if (num / 10)
	{
		count += print_int_helper(num / 10);
	}

	_putchar((num % 10) + '0');
	count++;

	return (count);
}

/**
 * print_int_helper - helper to recursively print number
 * @num: the number to print
 *
 * Return: number of characters printed
 */ 
int print_int_helper(unsigned int num)
{
	int count = 0;

	if (num / 10)
	{
		count += print_int_helper(num / 10);
	}

	_putchar((num % 10) + '0');
	count++;

	return (count);
}
