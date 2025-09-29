#include "main.h"
#include <stdarg.h>

/*
 * proc_format - iterate over the format string and handel specifier
 * @format: the format string to be parse
 *
 * Return: the total number of character printed , or -1 on error
 */
int proc_format(const char *format, va_list args)
{
	int i = 0, len = 0, count;

	if (format == NULL)
	{
		return (-1);
	}

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i+1] == '\0')
			{
				return (-1);
			}
			i++;
			count = specifier(format[i], args);
			if (count == -1)
			{
				return (-1);
			}
			len += count;
		}
		else
		{
			if (_putchar(format[i]) < 0)
			{
				return (-1);
			}
			len++;
		}
		i++;
	}
	return (len);
}

