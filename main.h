#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct format - match the conversion specifiers for printf
 * @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f: type pointer to function for the conversion specifier
 *
 */
typedef struct format
{
    char *id;
    int (*f)();
} convert_match;

int printf_pointer(va_list val);
int printf_hex_aux(unsigned long int num);
int printf_HEX_aux(unsigned int num);
int printf_special_string(va_list val); // Renamed from printf_exclusive_string
int printf_hex_upper(va_list val); // Renamed from printf_HEX
int printf_hex(va_list val);
int printf_octal(va_list val); // Renamed from printf_oct
int printf_unsigned(va_list args);
int printf_binary(va_list val);
int printf_reverse(va_list args); // Renamed from printf_srev
int printf_int(va_list args);
int printf_decimal(va_list args); // Renamed from printf_dec
int _strlen(char *s);
int *_strcpy(char *dest, char *src);
int _strlenc(const char *s);
int rev_string(char *s);
int printf_percent(void); // Renamed from printf_37
int printf_char(va_list val);
int printf_string(va_list val);
int _putchar(char c);
int _printf(const char *format, ...);

#endif

