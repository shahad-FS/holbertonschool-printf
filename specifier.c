#include "main.h"

int specifier(char spec, va_list args)
{
	int res;

	switch (spec)
	{
		case 'c':
			res = print_char(args);
			break;
		case 's':
			res = print_str(args);
			break;
		case '%':
			res = print_pct(args);
			break;
		case 'd':
		case 'i':
			res = print_int(args);
			break;
		case 'b':
			res = print_bin(args);
			break;
		case 'u':
			res = print_uns(args);
			break;
		case 'o':
			res = print_oct(args);
			break;
		case 'x':
			res = print_hex_lower(args);
			break;
		case 'X':
			res = print_hex_upper(args);
			break;
		case 'S':
			res = print_S(args);
			break;
		case 'p':
			res = print_ptr(args);
			break;
		case 'r':
			res = print_reverse(args);
			break;
		default:
			if (_putchar('%') < 0)
				return (-1);
			if (_putchar(spec) < 0)
				return (-1);
			res = 2;
			break;
	}
	return (res);
}

