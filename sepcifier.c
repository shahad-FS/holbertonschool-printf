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
	if (spec == 'c')
		return (print_char(args));
	if (spec == 's')
		return (print_str(args));
	if (spec == '%')
		return (print_pct(args));
	return (-1);
}
