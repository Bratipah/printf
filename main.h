<<<<<<< HEAD
#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
/**
 * struct operation - a structure containing a
 * char to compare with format specifiers.
 * and then choose the right function when it matches
 * @op: the char we want to compare to
 * @func: the address of the function we want to return if a char matches
 */
typedef struct operation
{
	char op;
	int (*func)(va_list);
} print_formats;

/**
 * struct buffer - buffer structure for our implimentation of printf
 * @buf: buffer to write characters
 * @tmpbuf: tmp buffer to write to before putting in buffer
 * @format: the string passed to our printf
 * @ap: the variadic address point
 * @bp: the current point in the buffer
 * @tp: the current point in the tmp buffer
 * @fp: the current point in the format
 * @printed: the number of chars printed from _write
 */
typedef struct buffer
{
	char *buf;
	char *tmpbuf;
	const char *format;
	va_list ap;
	int bp;
	int tp;
	int fp;
	unsigned int printed;
} buffer;

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list c);
int print_s(va_list s);
int print_d(va_list d);
int print_i(va_list i);
int print_b(va_list list);
int print_u(va_list u);
int print_o(va_list list);
int print_x(va_list list);
int print_X(va_list list);
int print_p(va_list list);
int print_S(va_list list);
int print_r(va_list r);
int print_R(va_list R);
int handle_percent(char ch1, char ch2);
unsigned int base_len(unsigned int num, int base);
char *hex_conv(int num);
int *rev_string(char *s);
void _write(buffer *b_r, char c);
void _write_str(buffer *b_r, char *s);
void _write_tmpbuf(buffer *b_r);
#endif
=======
#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 *get_specifiers - returns pointer to format specifier functions.
 *@ch:character to be used to find pointer function.
 *Return:pointer to function that corresponds with specified format or NULL
 *
 */
int (*get_specifiers(char ch))(va_list)
{
	int i;
	print_formats p[] = {
		{'c', print_c},
		{'s', print_s},
		{'d', print_d},
		{'i', print_i},
		{'b', print_b},
		{'u', print_u},
		{'o', print_o},
		{'X', print_X},
		{'x', print_x},
		{'S', print_S},
		{'p', print_p},
		{'r', print_r},
		{'R', print_R},
		{'\0', NULL}
	};
	for (i = 0; p[i].op; i++)
	{
		if (ch == p[i].op)
		{
			return (p[i].func);
		}

	}
	return (NULL);
}
/**
 *_printf - prints formatted output.
 * @format: the initial string that tell us what is going to be printed
 * Return: the amount of times we write to stdout or -1
 */
int _printf(const char *format, ...)
{
	int i, count;

	int (*f)(va_list);

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	i = count = 0;
	
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1)
			f = get_specifiers(format[i + 1]);
			if (f == NULL)
				count += handle_percent(format[i], format[i + 1]);
			else
				count += f(args);
			i++;
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
>>>>>>> 351b7b145cdbb483e70bd0915ca0556a1412dd2d
