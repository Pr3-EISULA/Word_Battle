#include "Menu_state.h"
#include "Game.h"
#include "State_manager.h"
#include "Resource_manager.h"
#include "Title_state.h"

void Menu_state::init()
{
	Resource_manager::load_image("about");

	Resource_manager::load_sound("about")->play();
}

void Menu_state::handle_events(SDL_Event& event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN)
  {
		State_manager::set_state(new Title_state());
	}
}

void Menu_state::update()
{

}

void Menu_state::render()
{
	Resource_manager::get_image("about")->render();
}

void Menu_state::clean_up()
{
	Resource_manager::unload_image("about");

	Resource_manager::unload_sound("about");
}
