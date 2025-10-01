#include "main.h"

int print_unsigned(va_list args, format_flags_t *f)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[32];
	int i = 0, count = 0;
	int len = 0, pad = 0;
	int j;

	if (n == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}

	}
	len = i;
	
	pad = (f->width > len) ? f->width - len : 0;

	if (f->minus)
	{
		for(j = i - 1; j >= 0; j--)
		{
			count += _putchar(buffer[j]);
		}
		for (j = 0; j < pad; j++)
		{
			count += _putchar(' ');
		}
		return (count);
	}

	if (f->zero)
	{
		for (j = 0; j < pad; j++)
		{
			count += _putchar('0');
		}
	}
	else
	{
		for (j = 0; j < pad; j++)
		{
			count += _putchar(' ');
		}
	}

	for (j = i- 1; j >= 0; j--)
	{
		count += _putchar(buffer[j]);
	}
	return (count);
}
