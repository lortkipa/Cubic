#include <CubicEngine/core.h>

int main(void)
{
    i8* data = cubic_memory_allocate(2 * sizeof(i8));
    data[0] = 14;
    data[1] = 16;

    data = cubic_memory_reallocate(data, 3 * sizeof(i8));
    data[2] = 25;

    cubic_memory_clear(data, 3 * sizeof(i8));

    for (fu8 i = 0; i < 3; i++)
    {
        CUBIC_LOG_TRACE("{i}. {i}", i + 1, data[i]);
    }

    data = cubic_memory_free(data);
}
