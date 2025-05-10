#include <CubicEngine/core.h>
#include <CubicEngine/renderer/backend/background.h>

int main(void)
{
    cubic_math_startup();
    cubic_memory_startup();

    cubic_app* app;
    cubic_app_subscribe(&app);
    cubic_app_startup(400, 400, "Cubic Engine");
    while (app->running)
    {
        CUBIC_LOG_TRACE("random from 3 to 6: {i}", cubic_math_randomInRange(3, 6));
        cubic_app_updateState();
        cubic_setBackground((cubic_vec3){.r = 255.0f, .g = 0.0f, .b = 0.0f});
    }
    cubic_app_shutdown();

    cubic_memory_shutdown();
}
