#include "core/logger.h"

int main(void)
{
    LogError("Game", "Logging Error %f", 3.14f);
    LogWarning("Game", "Logging Warning %f", 3.14f);
    LogSuccess("Game", "Logging Success %f", 3.14f);
    LogInfo("Game", "Logging Info %f", 3.14f);

    return 0;
}
