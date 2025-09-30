#include "main.h"

int print_S(va_list args)
{
    char *str = va_arg(args, char *);
    int i = 0, count = 0;
    unsigned char c;
    char hex_chars[] = "0123456789ABCDEF";

    if (str == NULL)
        str = "(null)";

    while (str[i])
    {
        c = (unsigned char)str[i];
        if (c > 0 && (c < 32 || c >= 127))
        {
            count += _putchar('\\');
            count += _putchar('x');
            count += _putchar(hex_chars[c / 16]);
            count += _putchar(hex_chars[c % 16]);
        }
        else
        {
            count += _putchar(c);
        }
        i++;
    }
    return count;
}
