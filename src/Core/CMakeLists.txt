cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME CuteAvalance)

project(${PROJECT_NAME})

set(SRC main.cpp)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} PUBLIC Graphic)