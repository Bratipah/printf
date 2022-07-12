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
 *
 *  *_printf - prints formatted output.
 *
 *   * @format: the initial string that tell us what is going to be printed
 *
 *    * Return: the amount of times we write to stdout or -1
 *
 *     */

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

																									return (-1);

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
