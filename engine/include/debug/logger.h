#pragma once

#include "CubicEngine/defines.h"

typedef enum cubic_log_types {
    CUBIC_LOG_TYPE_NORMAL,
    CUBIC_LOG_TYPE_ERROR,
    CUBIC_LOG_TYPE_WARNING,
    CUBIC_LOG_TYPE_SUCCESS,
    CUBIC_LOG_TYPE_TRACE,
    CUBIC_LOG_TYPE_COUNT
} cubic_log_types;

void cubic_log(const cubic_log_types type, const char* format, ...);

#define CUBIC_LOG(format, ...) cubic_log(CUBIC_LOG_TYPE_NORMAL, format, ##__VA_ARGS__)
#define CUBIC_LOG_ERROR(format, ...) cubic_log(CUBIC_LOG_TYPE_ERROR, format, ##__VA_ARGS__)
#define CUBIC_LOG_WARNING(format, ...) cubic_log(CUBIC_LOG_TYPE_WARNING, format, ##__VA_ARGS__)
#define CUBIC_LOG_SUCCESS(format, ...) cubic_log(CUBIC_LOG_TYPE_SUCCESS, format, ##__VA_ARGS__)
#define CUBIC_LOG_TRACE(format, ...) cubic_log(CUBIC_LOG_TYPE_TRACE, format, ##__VA_ARGS__)
