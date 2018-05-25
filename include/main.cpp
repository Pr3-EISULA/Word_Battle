#include <iostream>
#include <string>
#include "Game.h"
#include "Setting.h"
#include "State_manager.h"
#include "Title_state.h"

int main()
{
	Game game;

	if (!game.init(Setting::game_name, Setting::window_width, Setting::window_height))
  {
		std::cerr << "Application initialization error. Aborting... " << std::endl;
	}

	State_manager::set_state(new Title_state());

	game.run();

	return 0;
}
