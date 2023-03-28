#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
    int i, j, state = 0;
    char *str;
    va_list args;
    va_start(args, format);
    
    for (i = 0; format[i]; i++)
    {
        if (state == 0)
        {
            if (format[i] == '%')
                state = 1;
            else
                putchar(format[i]);
        }
        else if (state == 1)
        {
            switch (format[i])
            {
                case 'c':
                    putchar(va_arg(args, int));
                    break;
                case 's':
                    str = va_arg(args, char *);
                    for (j = 0; str[j]; j++)
                        putchar(str[j]);
                    break;
                
            }
            state = 0;
        }
    }
    va_end(args);
    return 0;
}
