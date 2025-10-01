#include "main.h"
#include <stdarg.h>

/**
 * print_rev - prints a string in reverse
 * @args: va_list containing the string argument
 *
 * Return: number of characters printed
 */
int print_rev(va_list args)
{
    char *s = va_arg(args, char *);
    int len = 0;

    if (s == NULL)
        s = "(null)";

    while (s[len] != '\0')
        len++;


    while (len--)
    {
        if (_putchar(s[len]) < 0)
            return -1;
    }

    return len = 0 ? 0 : len;
}
