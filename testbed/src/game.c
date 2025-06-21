#include "core/logger.h"
#include "core/memory.h"
#include "core/string.h"

int main(void)
{
    // startup
    StartupLoggerSystem(LOG_LEVEL_ERROR_BIT | LOG_LEVEL_WARNING_BIT | LOG_LEVEL_SUCCESS_BIT | LOG_LEVEL_INFO_BIT);
    StartupMemorySystem();

    String name = CreateString();
    AsignString(&name, "Nikoloz");
    LogInfo("Game", "Data: %s. Length: %d", name.data, name.length);
    AsignString(&name, "Dito");
    LogInfo("Game", "Data: %s. Length: %d", name.data, name.length);
    DestroyString(&name);

    // shutdown
    ShutdownMemorySystem();
    ShutdownLoggerSystem();

    return 0;
}
