#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - function that produces output
 * according to a format
 * @format: pointer to the formats
 * @...: other unspecified parameters
 *
 * Return: Always 0 (success)
 */

int _printf(const char *format, ...)
{
	va_list argument;

	va_start(argument, format);

	int length = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int ch = va_arg(argument, int);

				putchar(ch);
			}
			else if (*format == 's')
			{
				char *string = va_arg(argument, char *);

				while (*string != '\0')
				{
					putchar(*string);
					string++;
					length++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				length;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(argument, int);

				putchar(num);
			}
		}
		else
		{
			putchar(*format);
			length++;
		}
		format++;
	}
	va_end(argument);
	return (0);
}
