#include "main.h"

/**
 * print_bin - print binaray number with flags
 * @val: va_list containing unsigned int 
 * @f: pointer to format_flags_t structure
 * 
 * Return: number of characters printed
 */

int print_bin(va_list val, format_flags_t *f)
{
	unsigned int num = va_arg(val, unsigned int);
	char buffer[32];
	int i = 0, count = 0;
	int started = 0;
	int len = 0;
	int pad = 0;
	int j;
	unsigned int mask = 1U << 31;
	
	for (; mask; mask >>=1)
	{
		if (num & mask)
		{
			buffer[i++] = '1';
			started = 1;
		}
		else if (started)
		{
			buffer[i++] = '0';
		}
	}

	if (i == 0)
	{
		buffer[i++] = '0';
	}

	len = i;

	if (f->hash && num != 0)
	{
		len += 2;
	}

	pad = (f->width > len) ? f->width - len : 0;

	if (f-> minus)
	{
		if(f->hash && num != 0)
		{
			_putchar('0');
			_putchar('b');
			count += 2;
		}

		for (j = 0; j < i; j++)
		{
			_putchar(buffer[j]);
			count++;
		}

		for (j = 0; j < pad; j++)
		{
			_putchar(' ');
			count++;
		}

		return (count);
	}

	if (f->zero)
	{
		if (f->hash && num != 0)
		{
			_putchar('0');
			_putchar('b');
			count += 2;
		}
		for (j = 0; j < pad; j++)
		{
			_putchar('0');
			count++;
		}
	}
	else
	{
		for (j = 0; j < pad; j++)
		{
			_putchar(' ');
			count++;
		}

		if (f->hash && num != 0)
		{
			_putchar('0');
			_putchar('b');
			count += 2;
		}
	}
	for (j = 0; j < i; j++)
	{
		_putchar(buffer[j]);
		count++;
	}
	
	return (count);
}
