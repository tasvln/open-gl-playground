cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 23)

project(OPENGLINTRO VERSION 1.0.0)

add_executable(OPENGLINTRO main.cpp)

find_package(glfw3 REQUIRED)

target_link_libraries(OPENGLINTRO glfw)
