#include "CubicEngine/app/app.h"

#ifdef CUBIC_PLATFORM_LINUX // compile on linux only

#include "CubicEngine/app/app_linux.h"
#include "CubicEngine/debug/assert.h"
#include "CubicEngine/debug/logger.h"

#include <X11/Xutil.h>

static cubic_app app;
static cubic_linuxApp_state linuxState;

void cubic_app_startup(const u16 width, const u16 height, const char* const title)
{
    // start the app
    app.running = true;

    // fill up app structure
    app.width = width;
    app.height = height;

    // create display
    linuxState.display = XOpenDisplay(NULL);
    CUBIC_ASSERT(linuxState.display != NULL, "can not create Xlib display");

    // get screen
    linuxState.screen = DefaultScreen(linuxState.display);

    // get root window
    linuxState.root = RootWindow(linuxState.display, linuxState.screen);

    // create window
    linuxState.window = XCreateSimpleWindow
        (
         linuxState.display, 
         linuxState.root, 
         0, 0,
         width, height, 0, 0, 0
        );
    CUBIC_LOG_SUCCESS("application window created: {i}x{i} \"{s}\"", width, height, title);

    // select window events
    XSelectInput(linuxState.display, linuxState.window, KeyPressMask | KeyReleaseMask | ExposureMask);

    // set window title
    XStoreName(linuxState.display, linuxState.window, title);
    XClassHint classHint = { (char*)title, (char*)title };
    XSetClassHint(linuxState.display, linuxState.window, &classHint);

    // init user exit call
    linuxState.exitMessage = XInternAtom(linuxState.display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(linuxState.display, linuxState.window, &linuxState.exitMessage, 1);

    // show the window
    XMapWindow(linuxState.display, linuxState.window);
}

void cubic_app_shutdown(void)
{
    // end the app
    app.running = false;

    // destroy window
    XDestroyWindow(linuxState.display, linuxState.window);
    CUBIC_LOG_SUCCESS("application window destroyed");

    // destroy connection
    XCloseDisplay(linuxState.display);
}

void cubic_app_subscribe(cubic_app** pp_app)
{
    *pp_app = &app;
}

void cubic_app_updateState(void)
{
    // continue if there are pending events
    while (XPending(linuxState.display))
    {
        // get next pending event
        XNextEvent(linuxState.display, &linuxState.event);

        // store window new dimensions here if resized
        XWindowAttributes attBuffer;

        switch (linuxState.event.type) 
        {
            case ClientMessage: // from user
                
                // close the window on user request
                if (linuxState.event.xclient.data.l[0] == (u32)linuxState.exitMessage)
                {
                    app.running = false;
                }

                break;
            case Expose: // resize
                         
                // get resized window new attributes
                XGetWindowAttributes(linuxState.display, linuxState.window, &attBuffer);

                // asing new window size to app structure
                app.width = attBuffer.width;
                app.height = attBuffer.height;
                CUBIC_LOG_TRACE("application window resized: {i}.{i}", app.width, app.height);

                break;
            case KeyPress:
                CUBIC_LOG_TRACE("key pressed with code: {i}", linuxState.event.xkey.keycode);
                break;
        }
    }
}

b cubic_app_keyDown(const u16 key)
{
    // check if key is pressed and if it is same key user is looking for
    if (linuxState.event.type == KeyPress && linuxState.event.xkey.keycode == key)
    {
        return true;
    }

    // return false as default if true is not returned in code above
    return false;
}

#endif
