#pragma once

#include "CubicEngine/defines.h"

#define CUBIC_OPENGL_MAJOR_VERSION 3
#define CUBIC_OPENGL_MINOR_VERSION 3

typedef struct cubic_app {
    b running;
    u16 width;
    u16 height;
} cubic_app;

void cubic_app_startup(const u16 width, const u16 height, const char* const title);

void cubic_app_shutdown(void);

void cubic_app_subscribe(cubic_app** pp_app);

cubic_app cubic_app_getApp(void);
 
void cubic_app_updateState(void);

b cubic_app_keyDown(const u16 key);
