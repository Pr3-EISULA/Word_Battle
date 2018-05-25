#include "Play_state.h"
#include "Game.h"
#include "Setting.h"
#include "State_manager.h"
#include "Resource_manager.h"
#include "Title_state.h"
#include <iostream>

void Play_state::init()
{
	Resource_manager::load_image("");

	grid.init();
}

void Play_state::handle_events(SDL_Event& event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN)
		advance_game();
}

void Play_state::update() { }

void Play_state::render()
{
	grid.render();

	// Dependiendo de una victoria o empate, imprime por terminal el resultado
	if (win_type == grid.player_red)
  	Resource_manager::get_image("")->render();

  else
    if (win_type == grid.player_yellow)
		  Resource_manager::get_image("")->render();

	else
    if (win_type == grid.player_red + grid.player_yellow)
    	Resource_manager::get_image("draw")->render();
}

void Play_state::clean_up()
{
	Resource_manager::unload_image("");

  Resource_manager::unload_image("");

  Resource_manager::unload_image("");

  Resource_manager::unload_image("");

  Resource_manager::unload_sound("");

  Resource_manager::unload_sound("");

  Resource_manager::unload_sound("");

  Resource_manager::unload_sound("");
}

void Play_state::advance_game() {

	// Si no hay ganador
	if (!win_type)
  {
		//Se obtienen las coordenadas del mouse y se normalizan en filas y columnas para saber en qué columna y fila hemos hecho click
    int x, y;

    SDL_GetMouseState(&x, &y);

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    int col = x / ((Setting::actual_window_width + Setting::scale_factor) / Setting::grid_columns);

    int row = y / ((Setting::actual_window_height + Setting::scale_factor) / Setting::grid_rows);

		// Si se hace un movimiento
		if (play_a_move(col, row))
			// Se chequea si ya hubo victoria o empate
			check_for_win_or_draw(col, row);
		// Se emite un sonido de movimiento invalido
		else
			Resource_manager::get_sound("invalid_move")->play();

	}

	// SI hubo una victoria o empate, se reinicia todo
	else
  {
		win_type = false;

  	sprite_to_play = grid.sprite_red;

  	grid.clear();

  	State_manager::set_state(new Title_state());
	}
}

bool Play_state::play_a_move(int col, int row)
{
	// Si el tablero está vacio
	if (grid.cell[col][row].current_sprite == grid.sprite_blank)
  {
		// Aparece el sprite
		grid.cell[col][row].current_sprite = sprite_to_play;

		// Alternamos el sprite
		if (sprite_to_play == grid.sprite_red)
			// Asignamos el color del siguiente sprite a jugar
			sprite_to_play = grid.sprite_letter;

		else
			// Asignamos el color del siguiente sprite a jugars
			sprite_to_play = grid.letter;


		// Reproducimos los sonidos
		Resource_manager::get_sound("valid_move")->play();

		return true;
	}

	return false;
}
