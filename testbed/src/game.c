#include "core/logger.h"
#include "core/memory.h"
#include "platform/window/window.h"

int main(void)
{
    // startup
    StartupLoggerSystem(LOG_LEVEL_ERROR_BIT | LOG_LEVEL_WARNING_BIT | LOG_LEVEL_SUCCESS_BIT | LOG_LEVEL_INFO_BIT);
    StartupMemorySystem();

    AppWindow window;
    CreateAppWindow(&window, "Cubic Game", 1000, 800);

    while (true)
    {
        ProccessWindowEvents();
    }

    DestroyAppWindow();


    // shutdown
    ShutdownMemorySystem();
    ShutdownLoggerSystem();

    return 0;
}
