#pragma once

#include "defines.h"

typedef enum LogLevel : u8 {
    LOG_LEVEL_ERROR,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_SUCCESS,
    LOG_LEVEL_INFO
} LogLevel;

typedef enum LogLevelBit : u8 {
    LOG_LEVEL_ERROR_BIT = 0x1,
    LOG_LEVEL_WARNING_BIT = 0x2,
    LOG_LEVEL_SUCCESS_BIT = 0x4,
    LOG_LEVEL_INFO_BIT = 0x8,
} LogLevelBits;

LogLevelBits LogLevelToBit(const LogLevel level);

EXPORT b8 StartupLoggerSystem(const LogLevelBits bits);

EXPORT void ShutdownLoggerSystem(void);

EXPORT void Log(const LogLevel level, const char* channel, const char* message, ...);

#define LogError(channel, message, ...) Log(LOG_LEVEL_ERROR, channel, message, ##__VA_ARGS__)

#define LogWarning(channel, message, ...) Log(LOG_LEVEL_WARNING, channel, message, ##__VA_ARGS__)

#define LogSuccess(channel, message, ...) Log(LOG_LEVEL_SUCCESS, channel, message, ##__VA_ARGS__)

#define LogInfo(channel, message, ...) Log(LOG_LEVEL_INFO, channel, message, ##__VA_ARGS__)
