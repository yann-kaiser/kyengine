#pragma once

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
namespace ky
{
  class Display
  {
    public:
      Display(const std::string& title, int width, int height);

      void initialize();
      void clearScreen();
      void postRender(); // Usually swap buffers
      void terminate();

      inline const std::string& getTitle() const { return title_; }
      inline int getWidth() const { return width_; }
      inline int getHeight() const { return height_; }
      inline GLFWwindow* getWindow() const { return window_; }
      inline bool shouldClose() { return this->shouldClose_
        || glfwWindowShouldClose(this->window_); }
      inline void setAntialiasing(bool val) { this->antialiasing_ = val; }
      inline void setFullscreen(bool val) { this->fullscreen_ = val; }
      inline void close(bool close) { this->shouldClose_ = close; }
    private:
      const std::string& title_;
      int width_;
      int height_;

      GLFWwindow *window_;

      bool antialiasing_;
      bool fullscreen_;
      bool shouldClose_;
  };
}
