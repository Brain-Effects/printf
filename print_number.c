#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_number - prints an integer in decimal format
 * @n: integer to print
 *
 * Description: This function prints an integer in
 * decimal format to the standard
 * output stream using recursion.
 *
 * Return: the number of characters written
 */
int print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n / 10)
		count += print_number(n / 10);
	count += write(1, &"0123456789"[n % 10], 1);
	return (count);
}
