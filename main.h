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

unsigned int VBO;
unsigned int VAO;

unsigned int vertexShader;

int success;
char infoLog[512];

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f};

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

// functions
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);