#include "main.h"

int print_hex(va_list args, int uppercase, format_flags_t *f)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[32];
	int i = 0, printed = 0;
	char offset = uppercase ? ('A' - 10) : ('a' - 10);
	int need_prefix = 0, content_len = 0;
	int prefix_len = 0, total = 0;
	int pad = 0;
	int width = f->width;
	int minus_flag = f->minus;
	int a, b, k, p;

	if (f->hash && n != 0)
	{
		need_prefix = 1;
	}

	if (n == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		unsigned int tmp = n;
		while (tmp > 0)
		{
			int digit = tmp % 16;
			buffer[i++] = (digit < 10) ? (digit + '0') : (digit + offset);
			tmp /= 16;
		}
		for (a = 0, b = i - 1; a < b; a++, b--)
		{
			char t = buffer[a];
			buffer[a] = buffer[b];
			buffer[b] = t;
		}
	}
	content_len = i;
	prefix_len = need_prefix ? 2 : 0;
	total = prefix_len + content_len;

	if (width > total)
	{
		pad = width - total;
	}

	if (minus_flag)
	{
		if (need_prefix)
		{
			_putchar('0');
			_putchar(uppercase ? 'X' : 'x');
			printed += 2;
		}
		for (k = 0; k < content_len; k++)
		{
			_putchar(buffer[k]);
			printed++;
		}
		for (p = 0; p < pad; p++)
		{
			_putchar('0');
			printed++;
		}
		for (k = 0; k < content_len; k++)
		{
			_putchar(buffer[k]);
			printed++;
		}
	}
	else
	{
		for (p = 0; p < pad; p++)
		{
			_putchar(' ');
			printed++;
		}
		if (need_prefix)
		{
			_putchar('0');
			_putchar(uppercase ? 'X' : 'x');
			printed += 2;
		}
		for (k = 0; k < content_len; k++)
		{
			_putchar(buffer[k]);
			printed++;
		}
	}
	return (printed);
}

