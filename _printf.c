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
	int i , str_count, count = 0;
	
	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
		}

		else if (format[i+1] == 'c')
		{
			_putchar(va_arg(args, int));
			i++;
		}
		
		else if (format[i+1] == 's')
		{
			str_count = _putstr(args);
			i++;
			count += (str_count - 1);
		}
		else if (format[i+1] == '%')
		{
			_putchar('%');
		}


		count++;
	}

	va_end(args);
	return(count);
}
