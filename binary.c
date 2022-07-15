#include "main.h"
#include <stdlib.h>
/**
 * print_b - takes an unsigned int and prints it in binary notation
 * @list: unsigned in to print
 *
 * Return: number of digits printed
 */
int print_b(va_list list)
{
	unsigned int num;
	int i, j, len;
	char *str;

	num = va_arg(list, unsigned int);
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	len = base_len(num, 2);
	str = malloc((sizeof(char) * len) + 1);
	if (str == NULL)
		return (-1);

	i = 0;
	while (num > 0)
	{
		str[i] = num % 2;
		num = num / 2;
		i++;
	}
	for (j = (i - 1); j >= 0; j--)
	{
		_putchar(str[j] + '0');
	}
	free(str);
	return (len);
}
