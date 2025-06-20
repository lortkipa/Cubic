#include "core/logger.h"
#include "core/assert.h"
#include <stdarg.h>
#include <stdio.h>

static LogLevelBits enabledLevels = 0;

static const char* color_strings[] =
{ "\e[0;31m", "\e[0;33m", "\e[0;32m", "\e[0;34m" };

static const char* header_strings[] =
{ "ERROR", "WARNING", "SUCCESS", "INFO" };

LogLevelBits LogLevelToBit(const LogLevel level)
{
    // return provided level to bit
    switch (level) 
    {
        case LOG_LEVEL_ERROR:
            return LOG_LEVEL_ERROR_BIT;
            break;
        case LOG_LEVEL_WARNING:
            return LOG_LEVEL_WARNING_BIT;
            break;
        case LOG_LEVEL_SUCCESS:
            return LOG_LEVEL_SUCCESS_BIT;
            break;
        case LOG_LEVEL_INFO:
            return LOG_LEVEL_INFO_BIT;
            break;
        default:
            return 0;
            break;
    }
}

b8 StartupLoggerSystem(const LogLevelBits bits)
{
    // make sure system is not started
    Assert("Logger", enabledLevels == 0, "System Is Already Started");

    // make sure valid bits are provided
    Assert("Logger", bits != 0, "Invalid Level Bits Provided");

    // asign provided bits to system bits
    enabledLevels = bits;

    // system init message will be logged only if bits != null
    LogSuccess("Logger", "System Initialized");

    // if valid bits are provided, return success, else - failure
    return bits != 0;
}

void ShutdownLoggerSystem(void)
{
    // make sure system is started
    Assert("Logger", enabledLevels != 0, "System Is Not Started Started");

    // zero out system bits
    LogSuccess("Logger", "System Terminated");
    enabledLevels = 0;
}

void Log(const LogLevel level, const char* channel, const char* message, ...)
{
    // check if message should be logged
    if (!(enabledLevels & LogLevelToBit(level)))
        return;

    // init list
    va_list list;
    va_start(list, message);

    // make sure system is started
    Assert("Logger", enabledLevels != 0, "System Is Not Started Started");

    // set color, log header and channel
    printf("%s[%s] %s: ", color_strings[level], header_strings[level], channel);

    // log formated
    vprintf(message, list);

    // reset color and start new line
    puts("\e[0;37m");

    // terminate list
    va_end(list);
}
