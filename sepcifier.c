#include "main.h"
#include <stdarg.h>

/*
 * specifier - handel single specifier
 * @spec: the specifier character
 * @args: va_list containing the arrgument
 *
 * Return: number of characters or -1 on error
 */
int specifier(char spec, va_list args)
{
	int res;

	switch (spec)
	{
		case 'c':
			res = print_char(args);
			break;
		case 's':
			res = print_str(args);
			break;
		case '%':
			res = print_pct(args);
			break;
		default:
			if (_putchar('%') < 0)
			{
				return (-1);
			}
			if (_putchar(spec) < 0)
			{
				return (-1);
			}
			
			res = 2;
			break;
	}
	return (res);
}
