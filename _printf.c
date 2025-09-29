#include "main.h"
#include <stdarg.h>



/**
 * _printf - simplified printf supporting %c, %s, %%
 * @format: format string
 * Return: number of chars printed (excluding null), or -1 on error
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, total = 0, res;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            if (_putchar(format[i]) < 0)
            {
                va_end(args);
                return (-1);
            }
            total++;
            i++;
            continue;
        }

        if (format[i + 1] == '\0')
        {
            va_end(args);
            return (-1);
        }

        switch (format[i + 1])
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
                
                if (_putchar('%') < 0 || _putchar(format[i + 1]) < 0)
                {
                    va_end(args);
                    return (-1);
                }
                res = 2;
                break;
        }

        if (res < 0)
        {
            va_end(args);
            return (-1);
        }

        total += res;
        i += 2;
    }

    va_end(args);
    return (total);
}
