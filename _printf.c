#include "main.h"

/**
 * _printf - a function that selects the correct function to print based on format.
 * @format: a format string.
 * Return: the length of the printed string.
 */
int _printf(const char *format, ...)
{
    convert_match m[] = {
        {"%s", printf_string}, {"%c", printf_char},
        {"%%", printf_percent},
        {"%i", printf_int}, {"%d", printf_decimal}, {"%r", printf_reverse},
        {"%R", printf_rot13}, {"%b", printf_binary}, {"%u", printf_unsigned},
        {"%o", printf_octal}, {"%x", printf_hex}, {"%X", printf_hex_upper},
        {"%S", printf_special_string}, {"%p", printf_pointer}
    };

    va_list args;
    int i = 0, j, len = 0;

    va_start(args, format);
    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    while (format[i] != '\0')
    {
        j = 13;
        while (j >= 0)
        {
            if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
            {
                len += m[j].f(args);
                i = i + 2;
                goto end_of_loop;
            }
            j--;
        }
        _putchar(format[i]);
        len++;
        i++;
    }

end_of_loop:
    va_end(args);
    return (len);
}

