#include "main.h"
#include <stdarg.h>

/*
 * _printf - output a formatted strings 
 * @format: is character string. The format string is composed of zero or more
 * directives
 *
 * Return: The number of characters printed "excluding the null byte
 * used to end output to strings"
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0 , len = 0, count;
	
	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			if (_putchar(format[i] < 0))
			{
				va_end(args);
				return (-1);
			}
			len++;
			i++;
			continue;
		}

		if (format[i+1] == '\0')
		{
			va_end(args);
			return (-1);
		}

		switch (format[i+1])
		{
			case 'c':
			count = _putchar(va_arg(args , int));
			break;
			case 's':
			count = _putstr(args);
			break;
			case '%':
			count = _putpct(args);
			break;
			default:
			_putchar(format[i]);
			_putchar(format[i+1]);
			count = 2;
			break;
		}
		
		len += count;
		i += 2;
	}
	va_end(args);
	return (len);
}
