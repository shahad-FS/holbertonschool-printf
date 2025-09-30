#include "main.h"

int print_bin(va_list val)
{
	unsigned int num = va_arg(val, unsigned int);
	int i, count = 0;
	int started = 0;
	unsigned int mask = 1 << 31;

	for (i = 0; i < 32; i++)
	{
		if (num & mask)
		{
			_putchar('1');
			count++;
			started = 1;
		}
		else if (started)
		{
			_putchar('0');
			count++;
		}
		mask >>= 1;
	}

	if (count == 0)
	{
		_putchar('0');
		count = 1;
	}

	return count;
}
