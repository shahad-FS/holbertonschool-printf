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

    if (f->width > len)
        padding = f->width - len;

    
    if (!f->minus)
        for (i = 0; i < padding; i++)
            count += _putchar(' ');

   
    for (i = 0; i < len; i++)
        count += _putchar(str[i]);


    if (f->minus)
        for (i = 0; i < padding; i++)
            count += _putchar(' ');

    return count;
}
