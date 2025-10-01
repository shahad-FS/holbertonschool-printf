#include "main.h"

int print_octal(va_list args, format_flags_t *f)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[32];
	int i = 0, count = 0;
	int len = 0;
	int pad = 0;
	int j;

	if (n == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 8) + '0';
			n /= 8;
		}
	}


	len = i;
	if(f->hash && buffer[i - 1] !='0')
	{
		len += 1;
	}

	pad = (f->width > len) ? f->width - len : 0;

	if (f-> minus)
	{
		if (f->hash && buffer[i - 1] != '0')
		{
			_putchar('0');
			count++;
		}

		for (j = i - 1; j >= 0; j--)
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
		if(f->hash && buffer[i-1] != '0')
		{
			_putchar('0');
			count++;
		}
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

		if (f->hash && buffer[i - 1] != '0')
		{
			_putchar('0');
			count++;
		}
	}

	for (j = i - 1; j >= 0; j--)
	{
		count += _putchar(buffer[j]);
	}

	return (count);
}
