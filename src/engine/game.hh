#pragma once

#include <engine/engine.hh>

namespace ky
{
  class Engine;
  class Game
  {
    friend Engine;
    public:
      Game();

      inline const Engine& engine_get() const { return *engine_; }
    private:
      virtual void start() final;
      virtual void gameloop() final;
      virtual void stop() final;

    private:
      Engine* engine_;
  };
}
