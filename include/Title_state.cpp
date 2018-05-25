#include "Title_state.h"
#include "Game.h"
#include "Setting.h"
#include "State_manager.h"
#include "Resource_manager.h"
#include "Play_state.h"
#include "Menu_state.h"
#include <iostream>

bool title_sound_has_played;

void Title_state::init()
{
	Resource_manager::load_image("cover.png");

	title_sound_has_played = false;
}

void Title_state::handle_events(SDL_Event& event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN)
  {
        // Obtiene las coordenadas del mouse
        int mouse_x, mouse_y;
        Game::get_mouse_position(&mouse_x, &mouse_y);

		// Calcula la distancia escalada desde la parte superior derecha en píxeles
      std::cout << "x: " << mouse_x << std::endl;
      std::cout << "y: " << mouse_y << std::endl;

		int pixels_from_right = Setting::window_width - mouse_x;
		int pixels_from_top = mouse_y;

		// Si el clic cae dentro de 10px desde la derecha y 10px desde la parte superior, el usuario ha presionado el botón de menu
    if (pixels_from_right <= 10 and pixels_from_top <= 10)
      State_manager::set_state(new Menu_state());

		else
			State_manager::set_state(new Play_state());
	}
}

void Title_state::update()
{
		if (!title_sound_has_played) {
			Resource_manager::get_sound("title")->play();
			title_sound_has_played = true;
		}
}


void Title_state::render() {
	Resource_manager::get_image("cover.png")->render();
}

void Title_state::clean_up()
{
	Resource_manager::unload_image("cover.png");
	Resource_manager::unload_sound("title");
}
