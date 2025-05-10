#pragma once

#include "CubicEngine/defines.h"

#ifdef CUBIC_PLATFORM_LINUX // include on linux only

#include <X11/Xlib.h>

typedef struct cubic_linuxApp_state {
    Display* display;
    i32 screen;
    Window root;
    Window window;
    XEvent event;
    Atom exitMessage;
} cubic_linuxApp_state;

cubic_linuxApp_state cubic_app_getLinuxState(void);

#endif
