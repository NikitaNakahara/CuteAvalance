cmake_minimum_required(VERSION 3.12)

set(MODULE_NAME Graphic)

set(INCLUDE
    include/Graphic/Window.hpp
)

set(SRC
    src/Window.cpp
)

add_library(${MODULE_NAME} STATIC ${SRC} ${INCLUDE})

target_include_directories(${MODULE_NAME} PUBLIC include)

add_subdirectory(../../libs/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${MODULE_NAME} glfw)

add_subdirectory(../../libs/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${MODULE_NAME} glad)