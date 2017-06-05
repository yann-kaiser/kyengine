#include <iostream>
#include <engine/display.hh>

namespace ky
{
  Display::Display(const std::string& title, int width, int height)
    : title_(title)
    , width_(width)
    , height_(height)
  {}

  void Display::initialize()
  {
    if (!glfwInit())
      std::cout << "ERROR IN GLFWINIT. FIX THIS." << std::endl;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (this->antialiasing_)
      glfwWindowHint(GLFW_SAMPLES, 4);

    GLFWmonitor *monitor = NULL;
    if (this->fullscreen_)
      monitor = glfwGetPrimaryMonitor();

    window_ = glfwCreateWindow(this->width_, this->height_,
        this->title_.c_str(), monitor, NULL);

    if (!window_)
    {
      std::cout << "ERROR WHILE CREATING WINDOW. FIX THIS." << std::endl;
      glfwTerminate();
    }
    glfwMakeContextCurrent(window_);

    glewExperimental = GL_TRUE;
    glewInit();

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
  }

  void Display::clearScreen()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }

  void Display::postRender()
  {
    glfwSwapBuffers(window_);
  }

  void Display::terminate()
  {
    glfwTerminate();
  }
}
