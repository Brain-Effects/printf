#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

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
