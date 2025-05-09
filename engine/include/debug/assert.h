#pragma once

#include "CubicEngine/defines.h"
#include "CubicEngine/debug/logger.h"

#include <stdlib.h>

#define CUBIC_ASSERT(res, msg) \
    if (!(res)) \
    { \
        CUBIC_LOG_ERROR("assertion failure \"{s}\" at {s} {s} {i}: {s}", #res, __FILE__, __FUNCTION__, __LINE__, msg); \
        abort(); \
    }
