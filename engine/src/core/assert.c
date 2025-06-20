#include "core/assert.h"
#include "core/logger.h"

void ReportAssertionFailure(const char* channel, const char* action, const char* message, const char* file, const char* function, const u8 line)
{
    LogError(channel, "Assertion Failure: \"%s\": %s in \"%s\" %s() at %d",
            action, message, file, function, line);
}
