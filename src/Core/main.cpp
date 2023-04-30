#include <Graphic/Window.hpp>

#include <iostream>

int main() {
    Window window = Window(1024, 728, "Cute Avalance");
    WindowError lastError = window.getLastError();
    if (lastError.errorCode != WErrorCodes::NOT_ERROR) {
        std::cout << lastError.errorData << "\n";
        return lastError.errorCode;
    }

    WindowContext* context = window.getWindowContext();

    window.startMainLoop();
    lastError = window.getLastError();
    if (lastError.errorCode != WErrorCodes::NOT_ERROR) {
        std::cout << lastError.errorData << "\n";
    }

    return lastError.errorCode;
}