#include "main.h"

/**
 * printf_string_reverse - prints a string in reverse.
 * @args: argument containing the string to reverse.
 * Return: the number of characters printed.
 */
int printf_string_reverse(va_list args)
{
    char *s = va_arg(args, char *);
    int i;
    int j = 0;

    if (s == NULL)
        s = "(null)";

    while (s[j] != '\0')
        j++;

    for (i = j - 1; i >= 0; i--)
        _putchar(s[i]);

    return j;
}

