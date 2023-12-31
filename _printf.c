#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - printf function
 * @format: format
 * Return: printed chars
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] == 'r')
		{
			write(1, "%r", 2); /**Print %r as-is **/
			printed_chars += 2;
			i++; /** Skip the 'r' **/
		}

		else if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = flags_only(format, &i);
			width = width_only(format, &i, list);
			precision = precision_only(format, &i, list);
			size = size_only(format, &i);
			++i;
			printed = print_handler(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - print contents of the buffer if it exist
 * @buffer: array of chars
 * @buff_ind: index at which to add next char, represents the length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
