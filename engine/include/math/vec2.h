#pragma once

#include "CubicEngine/math/math.h"

typedef struct cubic_vec2 {
    union { f64 x; f64 r; f64 s; };
    union { f64 y; f64 g; f64 t; };
} cubic_vec2;
