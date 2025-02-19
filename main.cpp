#include "main.h"

void clear()
{
  if (window)
  {
    glfwDestroyWindow(window);
  }
  glfwTerminate();
}

int main(int argc, char *argv[])
{
  if (!glfwInit())
  {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    return -1;
  }

  window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "playground", NULL, NULL);

  if (!window)
  {
    std::cerr << "Failed to create Window" << std::endl;
    clear();
    return -1;
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window))
  {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  clear();

  return 0;
}