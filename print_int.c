#include "main.h"
#include <stdarg.h>

/**
 * print_int - print an integer from a va_list
 * @args: the va_list containing the int argument
 *
 * Return: number of characters printed
 */

int print_int_helper(unsigned int num);

int print_int(va_list args, format_flags_t *f)
{
    int n = va_arg(args, int);
	int count = 0,len = 0, width = 0, negative =0;
    unsigned int num;
	unsigned int tmp;
	int i;
	

    if (n < 0)
    {
        negative = 1;
		num = -n;
    }
    else
    {
		num = n;
	}
	
	tmp = num;
	if (tmp == 0)
	{
		len = 1;
	}
	else
	{
		len = 0;
		while (tmp > 0)
		{
			tmp /= 10;
			len++;
		}
	}
	
	if (negative || f->plus || f->space)
	{
		len++;
	}

	width = (f->width > len) ? f->width - len : 0;

	if (!f->minus && f->zero)
	{
		if(negative)
		{
			count += _putchar('-');
		}
		else if (f->plus)
		{
			count += _putchar('+');
		}
		else if (f->space)
		{
			count += _putchar(' ');
		}
		for (i = 0; i < width; i++)
		{
			count += _putchar('0');
		}
	}
	else
	{
		if(!f->minus)
		{
			for (i = 0; i < width; i++)
			{
				count += _putchar(' ');
			}
		}
		if (negative)
		{
			count += _putchar('-');
		}
		else if (f->plus)
		{
			count += _putchar('+');
		}
		else if (f->space)
		{
			count += _putchar(' ');
		}
	}

	count += print_int_helper(num);

	if (f->minus)
	{
		for(i = 0; i < width; i++)
		{
			count += _putchar(' ');
		}
	}
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
