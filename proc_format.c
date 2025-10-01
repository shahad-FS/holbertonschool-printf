#include "main.h"
#include <stdarg.h>

/**
 * proc_format - iterates over the format string and handles specifiers
 * @format: the format string to parse
 * @args: va_list of arguments to print
 *
 * Return: total number of characters printed, or -1 on error
 */
int proc_format(const char *format, va_list args)
{
    int i = 0, len = 0, count;
	format_flags_t f;
	int w;

    if (format == NULL)
        return (-1);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == '\0')
			{
                return (-1);
			}
			i++;

			f.hash = f.zero = f.minus = f.space = f.plus = 0;
			f.width = 0;

            while (format[i] == '#' || format[i] == '0' || format[i] == '-' ||
				format[i] == ' ' || format[i] == '+')
				{
					if (format[i] == '#')
					{
						f.hash = 1;
					}
					else if (format[i] == '0')
					{
						f.zero = 1;
					}
					else if (format[i] == '-')
					{
						f.minus = 1;
					}
					else if (format[i] == ' ')
					{
						f.space = 1;
					}
					else if (format[i] == '+')
					{
						f.plus = 1;
					}
					i++;
				}
			if (f.plus)
			{
				f.space = 0;
			}

            if (format[i] == '*')
            {
                w = va_arg(args, int);
                if (w < 0)
                {
                    f.minus = 1;
                    w = -w;
                }
                f.width = w;
                i++;
            }
            else
            {
				while (format[i] >= '0' && format[i] <= '9')
				{
				f.width = f.width * 10 + (format[i] - '0');
				i++;
				}
			}
			
			if (format[i] == '\0')
			{
				return (-1);
			}

            count = specifier(format[i], args, &f);
            if (count == -1)
                return (-1);
            len += count;
        }
        else
        {
            if (_putchar(format[i]) < 0)
                return (-1);
            len++;
        }
        i++;
    }
    return (len);
}
