#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * handle_percent - handles the % conversion specifier
 *
 * Description: This function writes a % character to the
 * standard output stream.
 *
 * Return: the number of characters written
 */
int handle_percent(void)
{
	return (write(1, "%", 1));
}
