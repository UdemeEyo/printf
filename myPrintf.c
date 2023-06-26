#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _printf - function that prints everything
 * @format: pointer to specifier
 * @...: other input arguments
 *
 * Return: Always (0) success
 */
int my_printf(const char *format, ...)
{
	va_list arguments;

	va_start(arguments, format);

	int count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				putchar(va_arg(arguments, int));
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(arguments, char *)

				while (*s)
				{
					putchar(*s);
					s++;
					count++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(arguments);
	return (count);
}
