#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
  {
    va_list args;
    int count = 0;
    int i;
    va_start(args, format);
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
              {
                case 'c':
                {
                   char c = va_arg(args, int);
                    count += write(1, &c, 1);
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char *);
                    int j;
                    for (j = 0; str[j] != '\0'; j++)
                        count += write(1, &str[j], 1);
                    break;
                }
                case '%':
                    count += write(1, &format[i], 1);
                    break;        
          case 'd':
case 'i':
{
    int num = va_arg(args, int);
    char buffer[12]; 
    int len = snprintf(buffer, sizeof(buffer), "%d", num);
    count += write(1, buffer, len);
    break;
}
case 'u':
{
    unsigned int num = va_arg(args, unsigned int);
    char buffer[12]; 
    int len = snprintf(buffer, sizeof(buffer), "%u", num);
    count += write(1, buffer, len);
    break;
}
case 'o':
{
    unsigned int num = va_arg(args, unsigned int);
    char buffer[12]; 
    int len = snprintf(buffer, sizeof(buffer), "%o", num);
    count += write(1, buffer, len);
    break;
}
case 'x':
case 'X':
{
    unsigned int num = va_arg(args, unsigned int);
    char buffer[12]; 
    int len = snprintf(buffer, sizeof(buffer), format[i] == 'x' ? "%x" : "%X", num);
    count += write(1, buffer, len);
    break;
}
case 'p':
{
    void *ptr = va_arg(args, void *);
    char buffer[20];  
    int len = snprintf(buffer, sizeof(buffer), "%p", ptr);
    count += write(1, buffer, len);
    break;
}
case 'r':
{
    count += write(1, &format[i - 1], 2);
   
    break;
}

        }
        }
        else
            count += write(1, &format[i], 1);
    }
    va_end(args);
    return count;
}}
