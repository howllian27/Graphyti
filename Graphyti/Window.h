#pragma once
#include <Windows.h>

class Window {
public:
    Window(HINSTANCE hInstance, int nCmdShow);
    ~Window();

    HWND GetHWND() const { return m_hWnd; }

private:
    HWND m_hWnd;
};
