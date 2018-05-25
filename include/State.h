#pragma once
#include <SDL.h>

/**
 * State: clase abstracta y base que será utilizada por derivadas para manejar
 * interfaces, ya que, los juegos poseen muchos estados y necesitan repetir las mismas
 * funciones. Por ejemplo, el estado cuando esta presente el menu principal es diferente
 * a cuando el usuario está jugando.
 */
class State
{
public:
	/**
	 * Se llama cuando se inicializa un estado
	 */
	virtual void init() = 0;

	/**
	 * Es lo primero en llamarse en el loop del juego para manejar eventos
   * como pulsaciones de un botón, clics del mouse, cambio de tamaño de
   * la ventana, etc.
	 */
	virtual void handle_events(SDL_Event & event) = 0;

	/**
	 * Es lo segundo en llamarse en el loop del juego para actualizar elementos
   * como imágenes, posiciones, puntajes, etc. Toda la lógica del juego, es
   * manejada por esta función
	 */
	virtual void update() = 0;

	/**
	 * Es lo tercero en llamarse en el loop del juego. Esta es la única función
   * encargada de crear o representar los elementos en la ventena
	 */
	virtual void render() = 0;

	/**
	 * Es utilizada para liberar la memoria utilizada por un estado
	 */
	virtual void clean_up() = 0;
};
