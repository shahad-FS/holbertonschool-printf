#include "main.h"

/**
 * print_with_width - prints a string or a single character with width and left-adjust flag
 * @str: the string to print (can be a single char as string)
 * @len: length of the string
 * @f: pointer to format_flags_t containing flags
 *
 * Return: number of characters printed
 */
int print_with_width(const char *str, int len, format_flags_t *f)
{
    int count = 0;
    int padding = 0;
    int i;

    if (f == NULL)
    {
        for (i = 0; i < len; i++)
        {
            if (_putchar(str[i]) < 0)
                return -1;
            count++;
        }
        return count;
    }

        if (f->width > len)
        padding = f->width - len;
    else
        padding = 0;

    if (!f->minus)
    {
        for (i = 0; i < padding; i++)
        {
            if (_putchar(' ') < 0)
                return -1;
            count++;
        }
    }


    for (i = 0; i < len; i++)
    {
        if (_putchar(str[i]) < 0)
            return -1;
        count++;
    }


    if (f->minus)
    {
        for (i = 0; i < padding; i++)
        {
            if (_putchar(' ') < 0)
                return -1;
            count++;
        }
    }

    return count;
}
