#include "main.h"
#include <stdio.h>

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);
	printed_chars = parse_format(format, args);
	va_end(args);

	return (printed_chars);
}

int parse_format(const char *format, va_list args)
{
	int i = 0, j = 0, count = 0;
	char *buffer = malloc(sizeof(char) * 1024);

	if (!buffer)
		return (-1);

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			buffer[j] = format[i];
			j++;
			count++;
		}
		else if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'c')
				count += print_char(args, &buffer[j]);
			else if (format[i] == 's')
				count += print_str(args, &buffer[j]);
			else if (format[i] == '%')
				count += print_percent(&buffer[j]);
			else if (format[i] == '\0')
				return (-1);
			else
			{
				buffer[j] = '%';
				count++;
				j++;
				buffer[j] = format[i];
				count++;
			}
		}
		i++;
		j++;
	}
	write(1, buffer, count);
	free(buffer);
	return (count);
}

int print_char(va_list args, char *buffer)
{
	*buffer = va_arg(args, int);
	return (1);
}

int print_str(va_list args, char *buffer)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (!str)
		str = "(null)";

	while (str[i])
	{
		buffer[i] = str[i];
		i++;
	}

	return (i);
}

int print_percent(char *buffer)
{
	*buffer = '%';
	return (1);
}

