#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

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
