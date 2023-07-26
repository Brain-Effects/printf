#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * handle_u - handles the u conversion specifier
 * @args: variable argument list
 *
 * Description: This function retrieves an unsigned
 * integer argument from the variable.
 * argument list and writes its decimal representation to the
 * standard output stream.
 *
 * Return: the number of characters written
 */
int handle_u(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[12];

	int len = snprintf(buffer, sizeof(buffer), "%u", num);

	return (write(1, buffer, len));
}
