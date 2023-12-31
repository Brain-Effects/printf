#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives
 *
 * Description: This function writes output to the standard output stream,
 * according to a format string that specifies how subsequent arguments are
 * converted for output. It handles the following conversion specifiers:
 * c, s, %, d, i, b, u, o, x, and X.
 *
 * Return: the number of characters printed (excluding the null byte used
 * to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i;
	char c;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
	{
	i++;
	c = format[i];
	switch (format[i])
	{
		case 'c':
			count += handle_c(args);
			break;
		case 's':
			count += handle_s(args);
			break;
		case '%':
			count += handle_percent();
			break;
		case 'd':
		case 'i':
			count += handle_d_i(args);
			break;
		case 'b':
			count += handle_b(args);
			break;
		case 'u':
			count += handle_u(args);
			break;
		case 'o':
			count += handle_o(args);
			break;
		case 'x':
		case 'X':
			count += handle_x_X(c, args);
			break;
		}
	}
		else
		count += write(1, &format[i], 1);
	}

	va_end(args);

	return (count);
}

/**
 * handle_c - handles the c conversion specifier
 * @args: variable argument list
 *
 * Description: This function retrieves a character argument from the
 * variable argument list and writes it to the standard output stream.
 *
 * Return: the number of characters written
 */
int handle_c(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * handle_s - handles the s conversion specifier
 * @args: variable argument list
 *
 * Description: This function retrieves a string argument from the variable
 * argument list and writes it to the standard output stream.
 *
 * Return: the number of characters written
 */
int handle_s(va_list args)
{
	int count = 0;
	char *str = va_arg(args, char *);

	while (*str)
	count += write(1, str++, 1);

	return (count);
}

/**
 * handle_percent - handles the % conversion specifier
 *
 * Description: This function writes a % character to the standard
 * output stream.
 *
 * Return: the number of characters written
 */
int handle_percent(void)
{
	return (write(1, "%", 1));
}

/**
 * handle_d_i - handles the d and i conversion specifiers
 * @args: variable argument list
 *
 * Description: This function retrieves an integer argument from the variable
 * argument list and writes its decimal representation to the
 * standard output stream.
 *
 * Return: the number of characters written
 */
int handle_d_i(va_list args)
{
	int n = va_arg(args, int);

	return (print_number(n));
}
