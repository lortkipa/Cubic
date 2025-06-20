#pragma once

#include "defines.h"
#include <stdio.h>

typedef enum LogLevel {
    LOG_LEVEL_ERROR,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_SUCCESS,
    LOG_LEVEL_INFO
} LogLevel;

void LogV(const LogLevel level, const char* channel, const char* message, va_list list);

EXPORT void Log(const LogLevel level, const char* channel, const char* message, ...);

#define LogError(channel, message, ...) Log(LOG_LEVEL_ERROR, channel, message, ##__VA_ARGS__)

#define LogWarning(channel, message, ...) Log(LOG_LEVEL_WARNING, channel, message, ##__VA_ARGS__)

#define LogSuccess(channel, message, ...) Log(LOG_LEVEL_SUCCESS, channel, message, ##__VA_ARGS__)

#define LogInfo(channel, message, ...) Log(LOG_LEVEL_INFO, channel, message, ##__VA_ARGS__)
