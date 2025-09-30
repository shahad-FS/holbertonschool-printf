#include "main.h"

int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[20];
	int i = 0, count = 0;

	if (n == 0)
		return _putchar('0');

	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}

	while (i--)
		count += _putchar(buffer[i]);

	return count;
}
