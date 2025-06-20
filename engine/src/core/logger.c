#include "core/logger.h"
#include <stdarg.h>

const char* color_strings[] =
{ "\e[0;31m", "\e[0;33m", "\e[0;32m", "\e[0;34m" };

const char* header_strings[] =
{ "ERROR", "WARNING", "SUCCESS", "INFO" };

void LogV(const LogLevel level, const char* channel, const char* message, va_list list)
{
    // set color, log header and channel
    printf("%s[%s] %s: ", color_strings[level], header_strings[level], channel);

    // log formated
    vprintf(message, list);

    // reset color and start new line
    puts("\e[0;37m");
}

void Log(const LogLevel level, const char* channel, const char* message, ...)
{
    // init list
    va_list list;
    va_start(list, message);

    // log on console
    LogV(level, channel, message, list);

    // terminate list
    va_end(list);
}
