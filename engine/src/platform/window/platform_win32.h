#pragma once

#include "platform/window/window.h"
#include <windows.h>

typedef struct Win32Window {
    HINSTANCE instance;
    HWND window;
} Win32Window;

Win32Window* GetWin32Window(void);
