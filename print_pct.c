#include "main.h"

/*
 * print_pct - print '%' character
 * @args: unused
 *
 * Return: 1 on success , -1 on error
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
