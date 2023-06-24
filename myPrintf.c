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

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				printf("%c", va_arg(argument, int));

			else if (*format == 's')
				printf("%s", va_arg(argument, char *));
			else if (*format == 'd' || *format == 'i')
		
				printf("%d", va_arg(argument, int));
					

			format++;
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(argument);

	return (0);
}
