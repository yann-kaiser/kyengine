#include <engine/game.hh>

#include <iostream>

namespace ky
{
  Game::Game(std::string& title, int width, int height)
    : title_(title)
    , width_(width)
    , height_(height)
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
