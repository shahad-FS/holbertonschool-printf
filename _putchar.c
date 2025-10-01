#include "main.h"
#include <unistd.h>

#define BUF_SIZE 1024

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 *
 * Return: On success 1, -1 on error
 */
int _putchar(char c)
{
	static char buf[BUF_SIZE];
	static int index = 0;
	int written;

	if (c == -1)
	{
		if (index > 0)
		{
			written = write(1, buf, index);
			index = 0;
			return (written == -1 ? -1 : 0);
		}
		return (0);
	}

	buf[index++] = c;

	if (index >= BUF_SIZE)
	{
		written = write(1, buf, BUF_SIZE);
		if (written == -1)
		{
			return (-1);
		}
		index = 0;
	}
	return (1);
}
