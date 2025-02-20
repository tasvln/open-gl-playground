// #define GLFW_INCLUDE_GLCOREARB
// #include <GLFW/glfw3.h>
// #include <iostream>

#define GLAD_GL_IMPLEMENTATION
#include "glad/glad.h"
// #define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include <iostream>

// all the chars could be a string? - std::string?

// define global vars
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Variables
GLFWwindow *window;

unsigned int VBO;
unsigned int EBO;
unsigned int VAO;

unsigned int vertexShader;
unsigned int fragShader;

unsigned int shaderProgram;

// int success;
// char infoLog[512];

float vertices[] = {
    0.5f, 0.5f, 0.0f,   // top right
    0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f   // top left
};

unsigned int indices[] = {0, 1, 3, 1, 2, 3};

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

const char *fragShaderSource = "#version 410 core\n"
                               "out vec4 FragColor;"
                               "void main() {"
                               "  FragColor = vec4(1.0f, 1.5f, 0.2f, 1.0f);"
                               "}";

// functions
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);