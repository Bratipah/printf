#include "main.h"
#include <stdlib.h>

/**
 * print_c - prints a char
 * @c: char to print
 *
 * Return: always 1
 */
int print_c(va_list c)
{
	char ch = (char)va_arg(c, int);

	_putchar(ch);
	return (1);
}

/**
 * print_s - prints a string
 * @s: string to print
 *
 * Return: number of chars printed
 */
int print_s(va_list s)
{
	int count;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(null)";
	for (count = 0; str[count]; count++)
	{
		_putchar(str[count]);
	}
	return (count);
}
/**
  *print_S - prints the string.
  *@list: list of arguments.
  *
  *Return: length of characters printed.
  */
int print_S(va_list list)
{
	char *hex;
	char *s = va_arg(list, char *);
	unsigned int i = 0, j;
	int c = 0, len;

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i]; i++)
	{
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = base_len(s[i], 16);
			if (len != 2)
			{
				_putchar('0');
				c++;
			}
			c += 2;
			hex = hex_conv(s[i]);
			for (j = 0; hex[j]; j++)
			{
				_putchar(hex[j]);
				c++;
			}
		}
		else
		{
			_putchar(s[i]);
			c++;
		}
	}
	return (c);
}

/**
 * print_r - prints a string in reverse
 * @r: string to print
 *
 * Return: number of characters printed
 */
int print_r(va_list r)
{
	char *str;
	int i, count = 0;

	str = va_arg(r, char *);
	if (str == NULL)
		str = ")llun(";
	for (i = 0; str[i]; i++)
		;
	for (i -= 1; i >= 0; i--)
	{
		_putchar(str[i]);
		count++;
	}
	return (count);
}
/**
 * handle_percent - writes characters after a % if they
 * don't match anything in the struct
 * @ch1: the first char passed (always %)
 * @ch2: the char after the %
 * Return: 1 if ch2 is a % and 2 is ch2 is anything else
 */

int handle_percent(char ch1, char ch2)
{
	if (ch2 == '%')
	{
		write(1, &ch2, 1);
		return (1);
	}
	else
	{
		write(1, &ch1, 1);
		write(1, &ch2, 1);
		return (2);
	}
}
