#pragma once

#include "CubicEngine/math/math.h"

typedef struct cubic_vec3 {
    union { f64 x; f64 r; f64 s; };
    union { f64 y; f64 g; f64 t; };
    union { f64 z; f64 b; f64 p; };
} cubic_vec3;
