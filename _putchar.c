#include "main.h"

/*
 * _putchar - Function to print a character
 *@c: character to be printed 
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	if (write(1, &c, 1) != 1)
	{
		return (-1);
	}
	return (1);
}
