#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int handle_c(va_list args);
int handle_s(va_list args);
int handle_percent(char c);
int handle_d_i(va_list args);

#endif
