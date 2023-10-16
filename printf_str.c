#include "main.h"

/**
 * string_length - Returns the length of a string.
 * @s: Type char pointer.
 * Return: Length of the string.
 */
int string_length(char *s)
{
    int c;

    for (c = 0; s[c] != 0; c++)
        ;
    return c;
}

/**
 * constant_string_length - Returns the length of a constant string.
 * @s: Type constant char pointer.
 * Return: Length of the constant string.
 */
int constant_string_length(const char *s)
{
    int c;

    for (c = 0; s[c] != 0; c++)
        ;
    return c;
}

