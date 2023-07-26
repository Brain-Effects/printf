#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * handle_o - handles the o conversion specifier
 * @args: variable argument list
 *
 * Description: This function retrieves an unsigned
 * integer argument from the variable.
 * argument list and writes its octal representation to the
 * standard output stream.
 *
 * Return: the number of characters written
 */
int handle_o(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[12];

	int len = snprintf(buffer, sizeof(buffer), "%o", num);

	return (write(1, buffer, len));
}
