#pragma once

#include "core/string.h"

#define WINDOW_CLASS_NAME "Cubic Engine"

typedef struct AppWindow {
    String title;
    u16 width;
    u16 height;
} AppWindow;

EXPORT b8 CreateAppWindow(AppWindow* p_window, const char* title, const u16 width, const u16 height);

EXPORT void DestroyAppWindow(void);

EXPORT void ProccessWindowEvents(void);
