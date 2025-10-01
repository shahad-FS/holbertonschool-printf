#include "main.h"

int print_hex(va_list args, format_flags_t *f, int uppercase)
{
    unsigned int n = va_arg(args, unsigned int);
    char buffer[20];
    int i = 0, count = 0;
    int num_len = 0;
    char offset = uppercase ? 'A' - 10 : 'a' - 10;
    int padding = 0;

  
    if (n == 0)
        buffer[i++] = '0';

    
    while (n > 0)
    {
        int digit = n % 16;
        buffer[i++] = (digit < 10) ? (digit + '0') : (digit + offset);
        n /= 16;
    }

    num_len = i;

    if (f->width > num_len)
        padding = f->width - num_len;

    if (!f->minus && !f->zero)
	{
        while (padding-- > 0)
		{
            count += _putchar(' ');
		}
	}

	if (!f->minus && f->zero)
	{
        while (padding-- > 0)
		{
            count += _putchar('0');
		}
	}
	while (i--)
	{
		count += _putchar(buffer[i]);
	}
	if (f->minus)
	{
		while (padding-- > 0)
		{
			count += _putchar(' ');
		}
	}
	return count;
}

int print_hex_lower(va_list args, format_flags_t *f)
{
    return print_hex(args, f, 0);
}

int print_hex_upper(va_list args, format_flags_t *f)
{
    return print_hex(args, f, 1);
}
