#if defined(PLATFORM_WINDOWS) // compile only on windows

#include "platform/window/platform_win32.h"
#include "core/assert.h"
#include "core/logger.h"

static AppWindow window;
static Win32Window win32Window;
static b8 initialized = false;

static LRESULT CALLBACK eventCallback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

b8 CreateAppWindow(AppWindow* p_window, const char* title, const u16 width, const u16 height)
{
    // make sure window is not already created
    Assert("Win32 Window", initialized == false, "Window Is Already Created");
    
    // check params
    Assert("Win32 Window", p_window != null, "Invalid Pointer To Window");
    Assert("Win32 Window", title != null, "Invalid Title");
    Assert("Win32 Window", width > 0, "Width Should Be Greater Than 0");
    Assert("Win32 Window", height > 0, "Height Should Be Greater Than 0");

    // get instance
    win32Window.instance = GetModuleHandleA(NULL);

    // check if valid instance is returned
    if (!win32Window.instance)
    {
        LogError("Win32 Window", "Invalid Instance Returned");
        return false;
    }

    // register class
    WNDCLASS class = 
    {
        .hInstance = win32Window.instance,
        .lpszClassName = WINDOW_CLASS_NAME,
        .lpfnWndProc = eventCallback
    };
    if (!RegisterClass(&class))
    {
        LogError("Win32 Window", "Class \"%s\" Not Registered", WINDOW_CLASS_NAME);
        return false;
    }

    // create window
    win32Window.window = CreateWindowEx
        (
         0,
         WINDOW_CLASS_NAME,
         title,
         WS_OVERLAPPEDWINDOW,
         0, 0, 
         width, height,
         NULL, NULL, 
         win32Window.instance,
         NULL
         );

    // check if window was created
    if (!win32Window.window)
    {
        LogError("Win32 Window", "Window Creation Failed");
        return false;
    }

    // show window
    ShowWindow(win32Window.window, SW_SHOW);

    // init window structure
    window.width = width;
    window.height = height;
    window.title = CreateString();
    AsignString(&window.title, title);

    LogSuccess("Win32 Window", "Window Created \"%s\" %dx%d",
            window.title, window.width, window.height);
    return true;
}

void DestroyAppWindow(void)
{
    // make sure window is created
    Assert("Win32 Window", initialized == true, "Window Is Not Created Yet");

    // destroy windwo
    DestroyWindow(win32Window.window);

    // free memory from heap
    DestroyString(&window.title);
}

void ProccessWindowEvents(void)
{
    // get next window message
    MSG msg;
    GetMessage(&msg, win32Window.window, 0, 0);

    // if there is any messages, call callback
    DispatchMessage(&msg);
}

Win32Window* GetWin32Window(void)
{
    // make sure window is created
    Assert("Win32 Window", initialized == true, "Window Is Not Created Yet");

    // return win32 window pointer
    return &win32Window;
}

static LRESULT CALLBACK eventCallback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
    // default return value
    return DefWindowProc(window, msg, wParam, lParam);
}

#endif
