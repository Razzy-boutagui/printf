#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int printed_chars = 0;  // To keep track of the number of characters printed

    while (*format)
    {
        if (*format != '%')
        {
            putchar(*format);
            printed_chars++;
        }
        else
        {
            format++; // Move past '%'
            if (*format == 'c')
            {
                int c = va_arg(args, int);
                putchar(c);
                printed_chars++;
            }
            else if (*format == 's')
            {
                char *s = va_arg(args, char *);
                while (*s)
                {
                    putchar(*s);
                    s++;
                    printed_chars++;
                }
            }
            else if (*format == '%')
            {
                putchar('%');
                printed_chars++;
            }
        }
        format++;
    }

    va_end(args);

    return printed_chars;
}

