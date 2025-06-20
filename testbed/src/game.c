#include "core/logger.h"
#include "core/memory.h"

int main(void)
{
    // startup
    StartupLoggerSystem(LOG_LEVEL_ERROR_BIT | LOG_LEVEL_WARNING_BIT | LOG_LEVEL_SUCCESS_BIT | LOG_LEVEL_INFO_BIT);
    StartupMemorySystem();

    // shutdown
    ShutdownMemorySystem();
    ShutdownLoggerSystem();

    return 0;
}
