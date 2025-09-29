#include "main.h"
#include <stdarg.h>

/**
 * specifier - chooses the correct printing function for a format specifier
 * @spec: the format specifier character (e.g., 'c', 's', '%')
 * @args: va_list containing the arguments to print
 *
 * Return: number of characters printed, or -1 on error
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
		case 'd':
		case 'i':
			res = print_int(args);
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
