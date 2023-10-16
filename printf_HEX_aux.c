#include "main.h"

/**
 * printf_hex_aux - prints a lowercase hexadecimal number.
 * @num: number to print.
 * Return: counter.
 */
int printf_hex_aux(unsigned int num)
{
    int i;
    int *array;
    int counter = 0;
    unsigned int temp = num;

    while (num / 16 != 0)
    {
        num /= 16;
        counter++;
    }
    counter++;
    array = malloc(counter * sizeof(int));

    for (i = 0; i < counter; i++)
    {
        array[i] = temp % 16;
        temp /= 16;
    }
    for (i = counter - 1; i >= 0; i--)
    {
        if (array[i] > 9)
            array[i] = array[i] + 87; // Add 87 to get the lowercase letter in ASCII
        _putchar(array[i] + '0');
    }
    free(array);
    return (counter);
}

