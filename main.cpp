#include "main.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
  {
    glfwSetWindowShouldClose(window, true);
  }
}

void clear()
{
  if (window)
  {
    glfwDestroyWindow(window);
  }
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  // glDeleteProgram(shaderProgram);
  glfwTerminate();
}

int main(int argc, char *argv[])
{
  if (!glfwInit())
  {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "playground", NULL, NULL);

  if (!window)
  {
    std::cerr << "Failed to create Window" << std::endl;
    clear();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cerr << "Failed to initialize GLAD\n";
    return -1;
  }

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  // glEnableVertexAttribArray(0);
  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

  // shaders
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  // checking if the shader has been compiled
  // glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

  // if (!success)
  // {
  //   glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
  //   std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
  //             << infoLog << std::endl;
  // }

  while (!glfwWindowShouldClose(window))
  {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    processInput(window);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  clear();

  return 0;
}