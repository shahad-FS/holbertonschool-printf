#include "main.h"

/**
 * print_str - prints a string
 * @args: va_list containing the string to print
 *
 * Return: number of characters printed
 */
int print_str(va_list args)
{
	char *s = va_arg(args, char *);
	int i = 0;

	if (s == NULL)
	{
		s = "(null)";
	}

	while (s[i] != '\0')
	{
		if (_putchar(s[i]) < 0)
		{
			return (-1);
		}

		i++;
	}
	return (i);
}
