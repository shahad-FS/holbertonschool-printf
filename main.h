#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_str(va_list args);
int print_pct(va_list args);
int proc_format(const char *format, va_list args);
int specifier(char spec, va_list args);
int print_int(va_list args);
int print_bin(va_list val);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase);
int print_S(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);

#endif
