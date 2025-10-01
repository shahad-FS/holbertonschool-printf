#include "main.h"

int specifier(char spec, va_list args, format_flags_t *f)
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
		case 'S':
			res = print_S(args);
			break;
		case '%':
			res = print_pct(args);
			break;
		case 'd':
		case 'i':
			res = print_int(args, f);
			break;
		case 'b':
			res = print_bin(args, f);
			break;
		case 'u':
			res = print_unsigned(args, f);
			break;
		case 'o':
			res = print_octal(args,f);
			break;
		case 'x':
			res = print_hex(args, f, 0);
			break;
		case 'X':
			res = print_hex(args, f, 1);
			break;
		case 'p':
			res = print_pointer(args);
			break;
		default:
			if (_putchar('%') < 0)
				return (-1);
			if (_putchar(spec) < 0)
				return (-1);
			res = 2;
			break;
	}

	return res;
}
