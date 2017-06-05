#include <engine/game.hh>

#include <iostream>

namespace ky
{
  Game::Game()
  {}

  void Game::start()
  {
    std::cout << "Starting" << std::endl;
  }

  void Game::gameloop()
  {}

  void Game::stop()
  {
    std::cout << "Stopping" << std::endl;
  }
}
