#include "CubicEngine/renderer/backend/background.h"

#include <GL/glew.h>

void cubic_setBackground(const cubic_vec3 color)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor
        (
         CUBIC_NORMILIZE_COLOR(color.r),
         CUBIC_NORMILIZE_COLOR(color.g),
         CUBIC_NORMILIZE_COLOR(color.b),
         1.0
        );
}
