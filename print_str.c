#include "main.h"

/**
 * print_str - prints a string
 * @args: va_list containing the string to print
 * @f: pointer to format_flags_t containing flags and width
 *
 * Return: number of characters printed
 */
int print_str(va_list args, format_flags_t *f)
{
	char *s = va_arg(args, char *);
	int len = 0;

	if (s == NULL)
	{
		s = "(null)";
	}

	while (s[len] != '\0')
	{
		len ++;
	}
	return print_with_width(s, len, f);
}
