#include "State_manager.h"

std::vector<State*> State_manager::states;

void State_manager::set_state(State * state)
{
	//Llama a clean_up () en el estado anterior, lo libera de la memoria y lo elimina del vector
	if (!states.empty())
  {
		// Llama el ultimo estado y lo libera de memoria
		states.back()->clean_up();

		// Elimina la ultima instancia que fue creada con new
		delete states.back();
		states.back() = nullptr;

		// Remueve el ultimo elemento (nulo) del vector
		states.pop_back();
	}

	// Almacena el nuevo vector y llama a init()
	states.push_back(state);

	states.back()->init();
}

State * State_manager::get_state() {
	return states.back();
}
