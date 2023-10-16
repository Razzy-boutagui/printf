#include "main.h"

/**
 * printf_binary - prints a binary number.
 * @val: arguments.
 * Return: counter.
 */
int printf_binary(va_list val)
{
    int flag = 0;
    int counter = 0;
    int i, a = 1, b;
    unsigned int num = va_arg(val, unsigned int);
    unsigned int p;

    for (i = 0; i < 32; i++)
    {
        p = ((a << (31 - i)) & num);
        if (p >> (31 - i))
            flag = 1;
        if (flag)
        {
            b = p >> (31 - i);
            _putchar(b + '0');
            counter++;
        }
    }
    if (counter == 0)
    {
        counter++;
        _putchar('0');
    }
    return (counter);
}

