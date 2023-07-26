#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * handle_x_X - handles the x and X conversion specifiers
 * @c: conversion specifier character (either 'x' or 'X')
 * @args: variable argument list
 *
 * Description: This function retrieves an unsigned
 * integer argument from the variable.
 * argument list and writes its hexadecimal representation to the
 * standard output stream.
 * If c is 'x', it uses lowercase letters; if c is 'X',
 * it uses uppercase letters.
 *
 * Return: the number of characters written
 */
int handle_x_X(char c, va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[12];

	const char *format = (c == 'x') ? "%x" : "%X";
	int len = snprintf(buffer, sizeof(buffer), format, num);

	return (write(1, buffer, len));
}
