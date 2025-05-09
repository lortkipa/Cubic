#include <CubicEngine/defines.h>
#include <CubicEngine/iostream/logger.h>

int main(void)
{
    CUBIC_LOG_ERROR("logging error {f}", 3.14);
    CUBIC_LOG_WARNING("logging error {f}", 3.14);
    CUBIC_LOG_SUCCESS("logging error {f}", 3.14);
    CUBIC_LOG_TRACE("logging error {f}", 3.14);
    CUBIC_LOG("logging error {f}", 3.14);
}
