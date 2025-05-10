#include "CubicEngine/math/math.h"

#include <time.h>
#include <stdlib.h>

void cubic_math_startup(void)
{
    srand(time(NULL));
}

u64 cubic_math_random(void)
{
    return rand();
}

u64 cubic_math_randomInRange(const u64 min, const u64 max)
{
    return cubic_math_random() % (max - min + 1) + min;
}
