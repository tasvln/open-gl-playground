// #define GLFW_INCLUDE_GLCOREARB
// #include <GLFW/glfw3.h>
// #include <iostream>

#define GLAD_GL_IMPLEMENTATION
#include "glad/glad.h"
// #define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include <iostream>

// define global vars
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Variables
GLFWwindow *window;

// functions
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);