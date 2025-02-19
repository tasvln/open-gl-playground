cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 23)

project(OPENGLINTRO VERSION 1.0.0)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/ext/include)

add_executable(OPENGLINTRO main.cpp ext/glad.c)

target_link_libraries(OPENGLINTRO glfw OpenGL::GL)
