#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int handle_c(va_list args);
int handle_s(va_list args);
int handle_percent(void);
int handle_d_i(va_list args);
int handle_u(va_list args);
int handle_o(va_list args);
int handle_x_X(char c, va_list args);
int print_number(int n);
int handle_b(va_list args);
int print_binary(unsigned int n);

#endif
