#include "main.h"

/**
 * printf_character - prints a character.
 * @val: arguments.
 * Return: 1.
 */
int printf_character(va_list val)
{
    char c;

    c = va_arg(val, int);
    _putchar(c);
    return (1);
}

