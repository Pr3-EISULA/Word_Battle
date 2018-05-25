#pragma once
#include <vector>
#include "State.h"

// State_manager: implementacion que maneja el estado del juego

class State_manager
{
  public:
	/**
	 * Asigna el estado a run()
	 * Es llamado desde el loop Game::run()
	 * Recibe un estado
	 */
	static void set_state(State* state);

	// Retorna una instancia de el estado en ejecución
	static State * get_state();

private:
	// Almecena punteros de tipo State
	static std::vector<State*> states;
};
