#include "main.h"

/*
 * _putstr - Function that print string
 * @c: string to be printed 
 *
 * Return: number of byte
 */
int _putstr(va_list args)
{
	char *str;
	int i = 0;

	str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
	}
	
	while(str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
