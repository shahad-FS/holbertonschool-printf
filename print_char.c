#include "main.h"

/**
 * print_char - prints a single character
 * @args: va_list containing the character to print
 *
 * Return: number of characters printed (1)
 */
int print_char(va_list args)
{
	int ch = va_arg(args, int);

	if (_putchar((char)ch) < 0)
	{
		return (-1);
	}
	return (1);
}
