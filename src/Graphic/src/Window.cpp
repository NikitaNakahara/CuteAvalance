#include "../include/Graphic/Window.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <malloc.h>

struct WindowContext {
    int width;
    int height;
    const char* title;
    GLFWwindow* window;
};

Window::Window(int width, int height, const char* title) {
    mpWindowContext = (WindowContext*)malloc(sizeof(mpWindowContext));

    mpWindowContext->width = width;
    mpWindowContext->height = height;
    mpWindowContext->title = title;

    mLastError = WindowError();
    mLastError.errorCode = WErrorCodes::NOT_ERROR;
    mLastError.errorData = "";

    createWindow();
}

void Window::createWindow() {
    if (glfwInit() != GLFW_TRUE) {
        mLastError.errorCode = WErrorCodes::CANT_INIT_GLFW;
        const char* error = "";
        glfwGetError(&error);
        mLastError.errorData = error;
    }

    if (!(mpWindowContext->window = glfwCreateWindow(
        mpWindowContext->width,
        mpWindowContext->height,
        mpWindowContext->title,
        nullptr, nullptr
    ))) {
        glfwTerminate();

        mpWindowContext = nullptr;

        mLastError.errorCode = WErrorCodes::CANT_CREATE_WINDOW;
        const char* error = "";
        glfwGetError(&error);
        mLastError.errorData = error;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwMakeContextCurrent(mpWindowContext->window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            mLastError.errorCode = WErrorCodes::GLAD_INIT_FAILED;
            mLastError.errorData = "Cant initialize glad";
	}
}

void Window::startMainLoop() {
    if (mpWindowContext == NULL) {
        mLastError.errorCode = WErrorCodes::WINDOW_NOT_CREATED;
        mLastError.errorData = "Cant launch main loop, window isnt created. Call getLastError() after creating Window object for get last error info";
    }

    if (mainLoopStarted) {
        mLastError.errorCode = WErrorCodes::WINDOW_MAIN_LOOP_ALREADY_STARTED;
        mLastError.errorData = "Cant launch main loop, main loop already started. Window can have one main loop only";
    }

    mainLoopStarted = true;

    while (!glfwWindowShouldClose(mpWindowContext->window)) {
        glClearColor(0.0f, .0f, .0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mpWindowContext->window);
        glfwPollEvents();
    }
}