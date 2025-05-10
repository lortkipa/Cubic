#pragma once

#include "CubicEngine/defines.h"

#define CUBIC_PI 3.14159265359

#define CUBIC_NORMILIZE_COLOR(color) ((color)/255.0)

void cubic_math_startup(void);

u64 cubic_math_random(void);

u64 cubic_math_randomInRange(const u64 min, const u64 max);
