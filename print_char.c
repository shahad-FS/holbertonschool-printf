#include "main.h"

/*
 * print_char - prints a char from va_list
 * @args: va_list
 *
 * Return: number of printed characters or -1 on error
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
