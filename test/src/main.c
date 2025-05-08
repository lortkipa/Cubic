#include <CubicEngine/defines.h>
#include <CubicEngine/iostream/logger.h>

int main(void)
{
    CUBIC_ERROR("logging error {f}", 3.14);
    CUBIC_WARNING("logging error {f}", 3.14);
    CUBIC_SUCCESS("logging error {f}", 3.14);
    CUBIC_TRACE("logging error {f}", 3.14);
}
