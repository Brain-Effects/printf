#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * handle_b - handles the b conversion specifier
 * @args: variable argument list
 *
 * Description: This function retrieves an unsigned integer
 * argument from the variable.
 * argument list and writes its binary representation to the
 * standard output stream.
 *
 * Return: the number of characters written
 */
int handle_b(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_binary(n));
}
