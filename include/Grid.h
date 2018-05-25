#pragma once
#include <SDL.h>
#include "Setting.h"

// Grid: clase para la renderización, lógica y manejo de celdas de la matriz

class Grid
{
public:
	// Nombres de los jugadores guardados tipo enum para un facil manejo
	enum players { player = 1, enemy = 2 };

	// Nombre de los sprites utilizados en las celdas tipo enum para un facil manejo
	enum sprite_sheet { sprite_blank, sprite_letter };

	// La estructura de datos por la que esta conformada una celda de la matriz
	struct Cell {

	// Ubicacion del sprite o imagen
	SDL_Point position;

  char

	// Sprite actual en la pantalla
	sprite_sheet current_sprite = sprite_blank;
	};

	// Arreglo de celdas que define el tablero
	Cell cell[Setting::grid_columns][Setting::grid_rows];

	// Inicializa el tablero
	void init();

	// Dibuja el tablero
	void render();

	// Limpia el tablero
	void clear();

	/**
	 * Verifica si un jugador ha ganado. Para esto
	 * Recibe la pila de letras para ver si estan vacias.
	 * Recibe el tiempo para ver si se agotó
   * Recibe el puntaje de un player para ver si se alcanzó o se superó la meta
   * Recibe un player para determinar si se retiró de la partida
	 * Retorna true en caso de una victoria
	 */
	bool check_for_win(int col, int row, sprite_sheet sprite);

	/**
	 * Verifica si el juego ha terminado en empate.
	 * Retorna true en caso de empate
	 */
	bool check_for_draw();


private:
  // Contiene coordenadas de los rectangulos para las celdas
	SDL_Rect sprite_clips;

