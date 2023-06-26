#include "main.h"
#include <stdio.h>

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

/**
 * handle_integer - entry point
 * @args: contains arguements
 * Return: an integer
 */
int handle_integer(va_list args)
{
	int num = va_arg(args, int);
	int pd_chars = 0;

	if (num < 0)
	{
		putchar('-');
		pd_chars++;
		num = -num;
	}
	pd_chars += print_number(num);
	return (pd_chars);
}

/**
 * print_number - prints integers
 * @num: integer to be printed
 * Return: printed characters
 */
int print_number(int num)
{
	int pd_chars = 0;

	if (num / 10)
		pd_chars += print_number(num / 10);
	putchar('0' + num % 10);
	pd_chars++;
	return (pd_chars);
}
