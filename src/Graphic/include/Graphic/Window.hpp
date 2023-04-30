#pragma once

struct WindowContext;

enum WErrorCodes {
    NOT_ERROR,
    CANT_INIT_GLFW,
    CANT_CREATE_WINDOW,
    WINDOW_NOT_CREATED,
    WINDOW_MAIN_LOOP_ALREADY_STARTED,
    GLAD_INIT_FAILED
};

struct WindowError {
    WErrorCodes errorCode;
    const char* errorData;
};

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window() = default;

    WindowContext* getWindowContext() { return mpWindowContext; }
    WindowError getLastError() { return mLastError; }

    void startMainLoop();

private:
    WindowContext* mpWindowContext = nullptr;
    WindowError mLastError;

    bool mainLoopStarted = false;

    void createWindow();
};