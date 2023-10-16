#include "main.h"

/**
 * printf_string - prints a string.
 * @val: argument.
 * Return: the length of the string.
 */
int printf_string(va_list val)
{
    char *s;
    int i, len;

    s = va_arg(val, char *);

    if (s == NULL)
    {
        s = "(null)";
        len = string_length(s);
        for (i = 0; i < len; i++)
            _putchar(s[i]);
        return len;
    }
    else
    {
        len = string_length(s);
        for (i = 0; i < len; i++)
            _putchar(s[i]);
        return len;
    }
}

