#pragma once

#include "CubicEngine/math/math.h"

typedef struct cubic_vec4 {
    union { f64 x; f64 r; f64 s; };
    union { f64 y; f64 g; f64 t; };
    union { f64 z; f64 b; f64 p; };
    union { f64 w; f64 a; f64 q; };
} cubic_vec4;
