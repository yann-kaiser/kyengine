#pragma once

#include <memory>

#include <engine/fwd.hh>
#include <engine/game.hh>
#include <engine/display.hh>

#include <engine/camera.hh>

#include <GLFW/glfw3.h>

namespace ky
{
  class Engine
  {
    public:
      static Engine& instance()
      {
        static Engine inst;
        return inst;
      }

      /**
       * We initialize the engine with the game
       * This is done by the game itself in the main.
       * The game class is also created by user in the main.
       */
      void start(Game& game);
      void stop();

      void windowResized(int width, int height);

      inline const Display& getDisplay() const { return *display_; }
      inline const Camera& getCamera() const { return *camera_; }
      inline void setCamera(Camera& camera)
      { this->camera_ = std::shared_ptr<Camera>(&camera); }
    // Private methods (for singleton)
    private:
      Engine() {}
      Engine(const Engine&) = delete;

      void gameloop();

      Engine& operator=(const Engine) = delete;

    // Private members
    private:
      std::shared_ptr<Game> game_;
      std::unique_ptr<Display> display_;
      std::shared_ptr<Camera> camera_;
  };
}
