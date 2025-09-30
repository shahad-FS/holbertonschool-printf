#include "main.h"

int print_rev(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0, i;

	if (str == NULL)
		str = "(null)";

	while (str[len] != '\0')
		len++;

	for (i = len - 1; i >= 0; i--)
		_putchar(str[i]);

	return len;
}
