#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format
 * @format: A character string containing zero or more directives
 * @...: The optional arguments that need to be formatted
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	if (format && format[0])
	{
		int i = 0;
		int check = 0;

		while (format[i])
		{
			if (format[i] != '%')
			{
				_putchar(format[i]);
				count++;
			}
			else if (format[i] == '%')
			{
				check = i;
				while (format[i] && format[i] != 'c' && format[i] != 's' &&
				       format[i] != '%' && format[i] != 'd' && format[i] != 'i')
					i++;

				if (format[i] == 'c')
					count += printf_char(va_arg(args, int));
				else if (format[i] == 's')
					count += printf_string(va_arg(args, char *));
				else if (format[i] == 'd' || format[i] == 'i')
					count += printf_int(va_arg(args, int));
				else if (format[i] == '%')
					count += _putchar('%');
				else
				{
					_putchar('%');
					count++;
					i = check;
				}
			}
			i++;
		}
	}
	va_end(args);
	return (count);
}

