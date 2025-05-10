#include <CubicEngine/core.h>

int main(void)
{
    cubic_memory_startup();

    cubic_app* app;
    cubic_app_subscribe(&app);
    cubic_app_startup(400, 400, "Cubic Engine");
    while (app->running)
    {
        cubic_app_updateState();
    }
    cubic_app_shutdown();

    cubic_memory_shutdown();
}
