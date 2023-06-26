#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - function that produces output
 * according to a format
 * @format: pointer to the formats
 * @...: other unspecified parameters
 *
 * Return: Always 0 success
 */

int _printf(const char *format, ...)
{
	va_list argument;
	int len = 0;

	va_start(argument, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == 'c')
				printf("%c", va_arg(argument, int));
			len++;

			else if (*format == 's')
				printf("%s", va_arg(argument, char *));
			len++;

			else if (*format == 'd' || *format == 'i')
				printf("%d", va_arg(argument, int));
			len++;
		}
		else
		{
			putchar(*format);
			len++;
		}
		format++;
	}
	va_end(argument);
}

	return (len);
}
