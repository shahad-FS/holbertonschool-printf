#include "main.h"

/**
 * print_char - prints a single character
 * @args: va_list containing the character to print
 * @f: pointer to format_flags_t containing flags
 *
 * Return: number of characters printed (1)
 */
int print_char(va_list args, format_flags_t *f)
{
	int ch = (char)va_arg(args, int);
	char buf[1];

	buf[0] = ch;
	return print_with_width(buf, 1, f);
}
