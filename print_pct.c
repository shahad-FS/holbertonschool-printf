#include "main.h"

/**
 * print_pct - prints a percent sign '%'
 * @args: va_list of arguments (not used)
 *
 * Return: number of characters printed (1)
 */
int print_pct(va_list args)
{
	(void)args;
	if (_putchar('%') < 0)
	{
		return (-1);
	}
	return (1);
}
