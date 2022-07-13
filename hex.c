#include "main.h"

/**
 * print_x - takes an unsigned int and prints it in lowercase hex notation
 * @list: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_x(va_list list)
{
	unsigned int num;
	int i, j, temp, len;
	char *str;

	num = va_arg(list, unsigned int);
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	len = base_len(num, 16);
	str = malloc((sizeof(char) * len) + 1);
	if (str == NULL)
	{
		return (-1);
	}
	i = 0;
	while (num > 0)
	{
		temp = num % 16;
		if (temp < 10)
		{
			str[i] = temp + 48;
			i++;
		}
		else
		{
			str[i] = temp + 87;
			i++;
		}
		num = num / 16;
	}
	for (j = (i - 1); j >= 0; j--)
	{
		_putchar(str[j]);
	}
	free(str);
	return (len);

}

/**
 * print_X - takes an unsigned int and prints it in uppercase hex notation
 * @list: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_X(va_list list)
{
	unsigned int num;
	int i, j, temp, len;
	char *str;

	num = va_arg(list, unsigned int);
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	len = base_len(num, 16);
	str = malloc((sizeof(char) * len) + 1);
	if (str == NULL)
	{
		return (-1);
	}
	i = 0;
	while (num > 0)
	{
		temp = num % 16;
		if (temp < 10)
		{
			str[i] = temp + 48;
			i++;
		}
		else
		{
			str[i] = temp + 55;
			i++;
		}
		num = num / 16;
	}
	for (j = (i - 1); j >= 0; j--)
	{
		_putchar(str[j]);
	}
	free(str);
	return (len);
}

/**
 * print_u - prints an unsigned in in decimal notation
 * @u: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_u(va_list u)
{
	unsigned int a[10];
	unsigned int i, m, n, sum;
	int count;

	n = va_arg(u, unsigned int);
	m = 1000000000; /* (10 ^ 9) */
	a[0] = n / m;
	for (i = 1; i < 10; i++)
	{
		m /= 10;
		a[i] = (n / m) % 10;
	}
	for (i = 0, sum = 0, count = 0; i < 10; i++)
	{
		sum += a[i];
		if (sum || i == 9)
		{
			_putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}

/**
 * print_o - takes an unsigned int and prints it in octal notation
 * @list: unsigned int to print
 *
 * Return: number of digits printed
 */
int print_o(va_list list)
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
	len = base_len(num, 8);
	str = malloc((sizeof(char) * len) + 1);
	if (str == NULL)
	{
		return (-1);
	}
	i = 0;
	while (num > 0)
	{
		str[i] = num % 8;
		num = num / 8;
		i++;
	}
	for (j = (i - 1); j >= 0; j--)
	{
		_putchar(str[j] + '0');
	}
	free(str);
	return (len);
}
