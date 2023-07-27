#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints output according to a format
 * @format: format string containing directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0, i = 0;
	va_list arg;

	va_start(arg, format);

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == '\0')
			{
				va_end(arg);
				return (-1);
			}

			if (format[i] == '%')
			{
				count += _putchar('%');
				i++;
			}
			else if (format[i] == 'c')
			{
				count += _putchar(va_arg(arg, int));
				i++;
			}
			else if (format[i] == 's')
			{
				count += _puts(va_arg(arg, char *));
				i++;
			}
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
				i++;
			}
		}
		else
		{
			count += _putchar(format[i]);
			i++;
		}
	}

	va_end(arg);

	return (count);
}
