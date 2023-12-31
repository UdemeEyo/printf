#include "main.h"

/**
 * flags_only - calculate active flags
 * @format: format string
 * @index: index in format string
 *
 * Return: value of flags
 */
int flags_only(const char *format, int *index)
{
	int flags = 0;
	int i, curr_Index;
	const char FLAGS_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_Index = *index + 1; format[curr_Index] != '\0'; curr_Index++)
	{
		for (i = 0; FLAGS_CHARS[i] != '\0'; i++)
		{
			if (format[curr_Index] == FLAGS_CHARS[i])
			{
				flags |= FLAGS_VALUES[i];
				break;
			}
		}
		if (FLAGS_CHARS[i] == '\0')
			break;
	}
	*index = curr_Index - 1;
	return (flags);
}
