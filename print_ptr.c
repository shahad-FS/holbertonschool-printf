#include "main.h"

int _puts(char *str)
{
    int count = 0;

    if (!str)
        return 0;

    while (*str)
    {
        if (_putchar(*str++) < 0)
            return -1;
        count++;
    }
    return count;
}

int print_hex_address(unsigned long int num)
{
    char buffer[20];
    int i = 0, count = 0;
    char digits[] = "0123456789abcdef";

    if (num == 0)
        return _putchar('0');

    while (num > 0)
    {
        buffer[i++] = digits[num % 16];
        num /= 16;
    }

    while (i--)
        count += _putchar(buffer[i]);

    return count;
}

int print_ptr(va_list args)
{
    unsigned long int p = (unsigned long int)va_arg(args, void *);
    int count = 0;

    if (p == 0)
        return _puts("(nil)");

    count += _putchar('0');
    count += _putchar('x');
    count += print_hex_address(p);

    return count;
}
