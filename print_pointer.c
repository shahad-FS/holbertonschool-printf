#include "main.h"

int print_pointer(va_list args)
{
	unsigned long ptr = (unsigned long)va_arg(args, void *);
	char buffer[20];
	char *hex = "0123456789abcdef";
	int i = 0, count = 0;

	if (ptr == 0)
		return (_putchar('(') + _putchar('n') + _putchar('i') + _putchar('l') + _putchar(')'));

	_putchar('0');
	_putchar('x');
	count += 2;

	while (ptr > 0)
	{
		buffer[i++] = hex[ptr % 16];
		ptr /= 16;
	}

	while (i--)
		count += _putchar(buffer[i]);

	return count;
}
