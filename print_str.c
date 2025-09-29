#include "main.h"

/*
 * print_str - print string from va_list
 * @args: va_list
 *
 * Return: number of printed characters or -1 on error
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
