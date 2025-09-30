#include "main.h"

int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[20];
	int i = 0, count = 0;

	if (n == 0)
		return _putchar('0');

	while (n > 0)
	{
		buffer[i++] = (n % 8) + '0';
		n /= 8;
	}

	while (i--)
		count += _putchar(buffer[i]);

	return count;
}
