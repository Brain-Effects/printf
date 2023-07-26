#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_binary - prints an unsigned integer in binary format
 * @n: unsigned integer to print
 *
 * Description: This function prints an unsigned integer in
 * binary format to the standard
*
* Return: the number of characters written
*/
int print_binary(unsigned int n)
{
	int count = 0;

	if (n / 2)
		count += print_binary(n / 2);
	count += write(1, &"01"[n % 2], 1);

	return (count);
}
