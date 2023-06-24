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
				putchar(va_arg(argument, int));
			else if (*format == 's')
				while (*format)
					putchar(*format++);
			else if (*format == '%')
				putchar('%');
		}
		else
		{
			putchar(*format);
		}
		format++;
		length++;
	}
	va_end(argument);
	return (length);
}
