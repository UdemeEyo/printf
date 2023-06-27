#include "main.h"
/**
 * print_handler - prints an argument based on its type
 * @formt: formatted string in which to print the arguments
 * @list: list of arguments to be printed
 * @ind: index
 * @buffer: array to handle print
 * @flags: calculate active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: 1 or 2
 */
int print_handler(const char *formt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_type fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].formt != '\0'; i++)
		if (formt[*ind] == fmt_types[i].formt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].formt == '\0')
	{
		if (formt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (formt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (formt[*ind] != ' ' && formt[*ind] != '%')
				--(*ind);
			if (formt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &formt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
