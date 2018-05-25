#pragma once
#include <SDL.h>
#include "State.h"
#include "Grid.h"

// Play_state: implementación para manejar los estados del juego

class Play_state : public State
{
public:

	void init();

	void handle_events(SDL_Event& event);

	void update();

	void render();

	void clean_up();

private:
	// Instancia de tablero
	Grid grid;

  //El color del sprite que se jugará, se cambiará a lo largo de los movimientos
  //y se establece en sprite_red aquí para que los jugadores rojos vayan primero
	Grid::sprite_sheet sprite_to_play = grid.sprite_red;

	// Sostiene Grid.player_red (1), Grid.player_yellow (2) o Grid.player_red + Grid.player_yellow (3) para un sorteo
	int win_type;

  // Invocado por handle_events () cuando se presiona un botón del mouse y avanza el juego intentando moverlo o despejando la cuadrícula y volviendo al Title_state si hay un ganador
	void advance_game();

  //Intenta jugar un movimiento (coloca una cruz o nada) en la columna y fila dadas
//@param col Grid número de columna para jugar mover en @param row Número de cuadrícula para jugar move in @return Verdadero si se puede hacer un movimiento
	bool play_a_move(int col, int row);

};
