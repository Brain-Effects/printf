#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...);
int handle_c(va_list args);
int handle_s(va_list args);
int handle_percent(char c);
int handle_d_i(va_list args);

/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives
 *
 * Description: This function writes output to stdout.
 * The format string is composed of zero or more directives, which are ordinary
 * characters (not %), which are copied unchanged to the output stream, or
 * conversion specifications, each of which results in fetching zero or more
 * subsequent arguments. Each conversion specification is introduced by the
 * character %, and ends with a conversion specifier. The function handles the
 * c, s, and % conversion specifiers.
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				count += handle_c(args);
				break;
			case 's':
				count += handle_s(args);
				break;
			case '%':
				count += handle_percent(format[i]);
				break;
			case 'd':
			case 'i':
				count += handle_d_i(args);
				break;
				;
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
 * @args: the variable argument list
 *
 * Description: This function retrieves the next argument from the variable
 * argument list as a character and writes it to standard output.
 *
 * Return: the number of characters printed
 */
int handle_c(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}
/**
 * handle_s - handles the s conversion specifier
 * @args: the variable argument list
 *
 * Description: This function retrieves the next argument from the variable
 * argument list as a string and writes each character of the string to
 * standard output.
 *
 * Return: the number of characters printed
 */
int handle_s(va_list args)
{
	int count = 0;
	char *str = va_arg(args, char *);
	int j;

	for (j = 0; str[j] != '\0'; j++)
	count += write(1, &str[j], 1);
	return (count);
}
/**
 * handle_percent - handles the % conversion specifier
 * @c: the character to print
 *
 * Description: This function writes the character c to standard output.
 *
 * Return: the number of characters printed
 */
int handle_percent(char c)
{
	return (write(1, &c, 1));
}
/**
 * handle_d_i - handles the d and i conversion specifiers
 * @args: the variable argument list
 *
 * Description: This function retrieves the next argument from the variable
 * argument list as an integer, formats it as a decimal string using the
 * snprintf function, and writes it to standard output.
 *
 * Return: the number of characters printed
 */
int handle_d_i(va_list args)
{
	int num = va_arg(args, int);
	char buffer[12];
	int len = snprintf(buffer, sizeof(buffer), "%d", num);

	return (write(1, buffer, len));
}
