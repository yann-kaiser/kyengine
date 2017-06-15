#include <iostream>

#include <engine/engine.hh>
#include <engine/game.hh>

class MyGame : public ky::Game
{
  public:
    MyGame(std::string& title, int width, int height)
      : ky::Game(title, width, height)
    {}
    void game_started() override;
    void game_stopped() override;
};

void MyGame::game_started()
{
  std::cout << "GAME STARTED" << std::endl;
}

void MyGame::game_stopped()
{
  std::cout << "GAME STOPPED" << std::endl;
}

int main()
{
  std::string title = "NO NAME";
  MyGame game = MyGame(title, 800, 600);
  ky::Engine::instance().start(game);

  return 0;
}
