#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

typedef struct
{
    int hash;
    int zero;
    int minus;
    int plus;
    int space;
    int width;
}format_flags_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_str(va_list args);
int print_pct(va_list args);
int proc_format(const char *format, va_list args);
int specifier(char spec, va_list args, format_flags_t *f);
int print_int(va_list args, format_flags_t *f);
int print_bin(va_list val, format_flags_t *f);
int print_unsigned(va_list args,format_flags_t *f);
int print_octal(va_list args, format_flags_t *f);
int print_hex(va_list args, format_flags_t *f, int uppercase);
int print_hex_lower(va_list args, format_flags_t *f);
int print_hex_upper(va_list args, format_flags_t *f);
int print_S(va_list args);
int print_pointer(va_list args);

#endif
