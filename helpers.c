#include "main.h"
#include <stdio.h>

/**
 * print_binary - Entry point
 * @num: num to be printed
 * Return: printed characters
 */
int print_binary(unsigned int num)
{
	int pd_chars = 0;
	unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);

	while (mask > 0)
	{
		putchar((num & mask) ? '1' : '0');
		pd_chars++;
		mask >>= 1;
	}

	return (pd_chars);
}
