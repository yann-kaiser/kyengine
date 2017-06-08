#pragma once

#include <engine/engine.hh>

namespace ky
{
  class Engine;
  class Game
  {
    friend Engine;
    public:
      Game(std::string& title, int width, int height);

      inline const Engine& engine_get() const { return *engine_; }

      inline std::string& getTitle() const { return title_; };
      inline int getWidth() const { return width_; };
      inline int getHeight() const { return height_; };

    protected:
      Game() = default;
    private:
      virtual void start() final;
      virtual void game_started() = 0;

      virtual void gameloop() final;

      virtual void stop() final;
      virtual void game_stopped() = 0;

    protected:
      Engine* engine_;
      std::string& title_;
      int width_;
      int height_;
  };
}
