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


	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				putchar(va_arg(argument, int));
			else if (*format == 's')
			{
				s = va_arg(argument, char *);
				while (*s)
				{
					putchar(*s);
					s++;
				}
			}
			else if (*format == '%')
				putchar('%');
		}
		else
			putchar(*format);
		format++;
	}
	va_end(argument);
	return ();
}
