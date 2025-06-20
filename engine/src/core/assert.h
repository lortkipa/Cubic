#pragma once

#include "defines.h"

#if defined(_MSC_VER)
    #define DebugBreak() __debugbreak()
#elif defined(__clang__) || defined(__GNUC__)
    #define DebugBreak() __builtin_trap()
#else
    #define DebugBreak() ((void)0)
#endif

EXPORT void ReportAssertionFailure(const char* channel, const char* action, const char* message, const char* file, const char* function, const u8 line);

#if defined(DEBUG)

#define Assert(channel, action, message) \
    if (!(action))                                                                              \
    {                                                                                           \
        ReportAssertionFailure(channel, #action, message, __FILE__, __FUNCTION__, __LINE__);    \
        DebugBreak();                                                                          \
    }

#else

#define Assert(channel, action, message);

#endif
