#include "main.h"
#include <stdarg.h>

/**
 * _printf - simplified printf supporting %c, %s, %%
 * @format: format string
 * Return: number of chars printed (excluding null)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	va_start(args, format);

	len = proc_format(format, args);

	va_end(args);

	_putchar(-1);
	return (len);
}
