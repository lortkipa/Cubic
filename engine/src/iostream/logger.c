#include "CubicEngine/iostream/logger.h"

#include <stdio.h>
#include <stdarg.h>

static const char* const colors[] =
{
    [CUBIC_LOG_TYPE_ERROR]    =  "\e[0;31m",  // red
    [CUBIC_LOG_TYPE_WARNING]  =  "\e[0;33m",  // yellow
    [CUBIC_LOG_TYPE_SUCCESS]  =  "\e[0;32m",  // green
    [CUBIC_LOG_TYPE_TRACE]    =  "\e[0;34m",  // blue
};

void cubic_log(const cubic_log_types type, const char* format, ...)
{
    // log colors
    printf("%s", colors[type]);

    // init args
    va_list arg;
    va_start(arg, format);

    // loop thro every character of format
    fu64 i = 0;
    while (format[i] != '\0')
    {
        // track if valid formater specifier is found
        b formatSpecifierFound = true;

        // try to find format specifier
        if (format[i] == '{' && format[i + 2] == '}')
        {
            switch (format[i + 1]) 
            {
                case 'i': 
                    printf("%d", va_arg(arg, int));
                    break;
                case 'c': 
                    printf("%c", va_arg(arg, int));
                    break;
                case 'f': 
                    printf("%f", va_arg(arg, double));
                    break;
                case 's': 
                    printf("%s", va_arg(arg, char*));
                    break;
                case 'b': 
                    printf("%s", va_arg(arg, int) ? "true" : "false");
                    break;
                default:
                    formatSpecifierFound = false;
                    break;
            }
        } 
        else 
        {
            formatSpecifierFound = false;
        }

        // if format specifier is found, jump '{f}' chars, else - log current one and go to next char
        if (formatSpecifierFound)
        {
            i += 3;
        } 
        else 
        {
            printf("%c", format[i]);
            i++;
        }
    }

    // terminate args
    va_end(arg);

    // reset color and start new line
    puts("\e[0;37m");
}
