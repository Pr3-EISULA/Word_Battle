#include <iostream>
#include <string>
#include "Grid.h"
#include "Setting.h"
#include "Resource_manager.h"

void Grid::init()
{
	// Asgigna los rectangulos de los sprites
	for (int i = 0; i < 3; i++) {
		sprite_clips[i].x = 0;
		sprite_clips[i].y = 0;
		sprite_clips[i].w = Setting::grid_sprite_width;
		sprite_clips[i].h = Setting::grid_sprite_height;
	}
}

/**
 * El tablero esta comprendido por un sprite que se repite.
 * Este sprite contiene una imagen para los blanks, las fichas y los bonos
 */
void Grid::render()
{
	// Iteramos sobre las columnas y filas
	for (int col = 0; col < Setting::grid_columns; col++) {
		for (int row = 0; row < Setting::grid_rows; row++) {

			// Se posicionan los sprites en el tablero
			Resource_manager::get_image("cell_sprite")->set_position(col * Setting::grid_sprite_width, row  * Setting::grid_sprite_height);

			// Se renderiza el sprite en el rectangulo
			Resource_manager::get_image("cell_sprite")->render(&sprite_clips[cell[col][row].current_sprite]);
		}
	}
}

// Limpia el tablero cambiando todos los sprites a blanks
void Grid::clear()
{
	for (int col = 0; col < Setting::grid_columns; col++) {
		for (int row = 0; row < Setting::grid_rows; row++) {
			//Asigna los sprite como blank
			cell[col][row].current_sprite = sprite_blank;
		}
	}
}

