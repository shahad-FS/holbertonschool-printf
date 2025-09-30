#include "main.h"

int print_hex(va_list args, int uppercase)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[20];
	int i = 0, count = 0;
	char offset = uppercase ? 'A' - 10 : 'a' - 10;

	if (n == 0)
		return _putchar('0');

	while (n > 0)
	{
		int digit = n % 16;
		if (digit < 10)
			buffer[i++] = digit + '0';
		else
			buffer[i++] = digit + offset;
		n /= 16;
	}

	while (i--)
		count += _putchar(buffer[i]);

	return count;
}
