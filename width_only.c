#include "main.h"

/**
 * width_only - function that calculates the width for printing
 * @format: formatted string in which to print the arguments
 * @i: List of arguments to be printed
 * @list: list of arguments
 * Return: width
 */
int width_only(const char *format, int *i, va_list list)
{
	int curr_index;
	int width = 0;

	for (curr_index = *i + 1; format[curr_index] != '\0'; curr_index++)
	{
		if (is_digit(format[curr_index]))
		{
			width *= 10;
			width += format[curr_index] - '0';
		}
		else if (format[curr_index] == '*')
		{
			curr_index++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_index - 1;

	return (width);
}
