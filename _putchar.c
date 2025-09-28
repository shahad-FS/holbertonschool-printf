#include "main.h"

/*
 * _putchar - Function to print a character
 *@c: character to be printed 
 *
 * Return: one character
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
