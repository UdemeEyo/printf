#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - writes output according to a format
 * @format: format string
 *
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list arguements;
	int pd_chars = 0;

	va_start(arguements, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			putchar(*format);
			pd_chars++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
				pd_chars += handle_char(arguements);
			else if (*format == 's')
				pd_chars += handle_string(arguements);
			else if (*format == '%')
			{
				putchar('%');
				pd_chars++;
			}
			else
			{
				putchar('%');
				putchar(*format);
				pd_chars += 2;
			}
		}
		format++;
	}
	va_end(arguements);
	return (pd_chars);
}

/**
 * handle_char - handles the 'c' specifier
 * @args: list containing arguements
 * Return: number of printed characters
 */
int handle_char(va_list args)
{
	int c = va_arg(args, int);

	putchar(c);
	return (1);
}

/**
 * handle_string - handiles the 's' specifier
 * @args: list containing arguements
 * Return: number of printed characters
 */
int handle_string(va_list args)
{
	char *s = va_arg(args, char *);
	int pd_chars = 0;

	if (s == NULL)
		s = "(null)";
	while (*s != '\0')
	{
		putchar(*s);
		s++;
		pd_chars++;
	}
	return (pd_chars);
}
