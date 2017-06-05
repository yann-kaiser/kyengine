#include <iostream>

#include <engine/engine.hh>
#include <engine/game.hh>

class MyGame : public ky::Game
{
  public:
};


int main()
{
  MyGame *game = new MyGame();
  ky::Engine::instance().start(*game);
  std::cout << "Hello, World!" << std::endl;

  return 0;
}
