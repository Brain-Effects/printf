#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

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
