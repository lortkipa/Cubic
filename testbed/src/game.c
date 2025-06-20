#include "core/logger.h"

int main(void)
{
    StartupLoggerSystem(LOG_LEVEL_ERROR_BIT | LOG_LEVEL_WARNING_BIT | LOG_LEVEL_SUCCESS_BIT | LOG_LEVEL_INFO_BIT);

    LogError("Game", "Logging Error %f", 3.14f);
    LogWarning("Game", "Logging Warning %f", 3.14f);
    LogSuccess("Game", "Logging Success %f", 3.14f);
    LogInfo("Game", "Logging Info %f", 3.14f);

    ShutdownLoggerSystem();

    return 0;
}
