#include "Window.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
}

Window::Window(HINSTANCE hInstance, int nCmdShow) {
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"PhysicsEngineWindowClass";
    RegisterClassEx(&wc);

    m_hWnd = CreateWindowEx(0, L"PhysicsEngineWindowClass", L"Physics Engine Visualization", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);
    ShowWindow(m_hWnd, nCmdShow);
}

Window::~Window() {
    // Destructor implementation
    // If you have any cleanup to do when the Window object is destroyed, do it here.
    // For example, you might destroy the window using DestroyWindow().
}