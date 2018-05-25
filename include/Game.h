#pragma once
#include <SDL.h>

/**
* Clase Game: clase es la principal del juego. Maneja la ventana, los eventos,
* renderiza imagenes, controla el loop y cualquier otra
* función necesaria
*/

class Game
{
public:
    ~Game();

    /**
     * Retorna un puntero de tipo SDL_Window.
     * Es de tipo estático porque sólo existe
     * una ventana en todo el juego
     */
    static SDL_Window * get_window();

    /**
     * Retorna un puntero de tipo SDL_Renderer.
     * Es de tipo estático porque sólo existe un
     * renderizador en todo el juego
     */
    static SDL_Renderer * get_renderer();

    /**
     * Inicializa el juego con los siguientes parámetros:
     * título, ancho y alto de la ventana. Retorna true
     * si fue exitosa
     */
    bool init(char * title, int width, int height);

    /**
     * Corre el loop del juego
     */
    void run();

    /**
     * Detiene el loop del juego y los subsistemas de SDL
     */
    void stop();

    /**
     * Returns by reference the X and Y axis positions of the mouse cursor
     * divided by the scale factor
     */
    static void get_mouse_position(int* mouse_x, int* mouse_y);

private:
    // Bandera utilizada por run() para ver si el juego se está ejecutando
    bool running = true;

    // Evento SDL que permite manejar movientos de mouse, pulsaciones de teclas, etc.
    SDL_Event event;

    // Puntero de utilizado en SDL_CreateWindow para inicializar la ventana
    static SDL_Window * window;

  // Puntero de utilizado en SDL_CreateRenderer para inicializar el renderizador
    static SDL_Renderer * renderer;
};
