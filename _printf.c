#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function.
 * @format: A format string containing conversion specifiers.
 * @...: Variable number of arguments for the conversion specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    int char_count = 0;
    va_list args;

    va_start(args, format);

    while (format && format[char_count])
    {
        if (format[char_count] == '%')
        {
            char_count++; // Move past '%'

            if (format[char_count] == 'c')
            {
                // Handle %c (character specifier)
                char c = va_arg(args, int);
                write(1, &c, 1); // Write the character
                char_count++; // Move past 'c'
            }
            else if (format[char_count] == 's')
            {
                // Handle %s (string specifier)
                char *s = va_arg(args, char *);
                int len = 0;
                while (s && s[len])
                {
                    len++;
                }
                write(1, s, len); // Write the string
                char_count++; // Move past 's'
            }
            else if (format[char_count] == '%')
            {
                // Handle %%
                write(1, "%", 1); // Write a single %
                char_count++; // Move past the second '%'
            }
            // Add additional cases for other conversion specifiers here
        }
        else
        {
            // Handle regular characters, not conversion specifiers
            write(1, &format[char_count], 1); // Write the character
            char_count++;
        }
    }

    va_end(args);

    return char_count;
}

int main(void)
{
    int len;

    len = _printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d]\n", len);
    len = _printf("Character:[%c]\n", 'H');
    _printf("Length:[%d]\n", len);
   

