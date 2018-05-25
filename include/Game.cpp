#include <iostream>
#include <string>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include "Game.h"
#include "Setting.h"
#include "State_manager.h"
#include "Resource_manager.h"
#include "Title_state.h"

// Se inicializan los miembros estáticos
SDL_Window * Game::window = nullptr;

SDL_Renderer * Game::renderer = nullptr;

//Se libera memoria y se sale de los subsistemas SDL
Game::~Game()
{
    SDL_DestroyRenderer(renderer);

    renderer = nullptr;

    SDL_DestroyWindow(window);

    window = nullptr;

    Mix_Quit();

    SDL_Quit();
}

SDL_Window * Game::get_window()
{
    return window;
}

SDL_Renderer * Game::get_renderer()
{
    return renderer;
}

bool Game::init(char * title, int width, int height)
{
    // Inicializa SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
      std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
      return false;
    }

    // Creamos la ventana
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    width * Setting::scale_factor, height * Setting::scale_factor, SDL_WINDOW_RESIZABLE);

    if (window == nullptr)
    {
      std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
      return false;
    }

    // Asignamos el icono de la barra de título
    if (Setting::icon_path)
    {
      SDL_Surface * icon = IMG_Load(Setting::icon_path);

      if (icon == nullptr)
      {
        std::cerr << "IMG_Load Error: " << SDL_GetError() << std::endl;
        return false;
      }

      SDL_SetWindowIcon(window, icon);

      SDL_FreeSurface(icon);
    }

    // Se crea el renderizador para la ventana
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr)
    {
      std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
      return false;
    }

    // Asignamos los colores de fondo
    SDL_SetRenderDrawColor(renderer, Setting::background_color[0], Setting::background_color[1], Setting::background_color[2], Setting::background_color[3]);

    // Inicializamos SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
      std::cerr << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
      return false;
    }

    return true;
}

void Game::run()
{
    while (running)
    {
        // Se mantiene el ciclo hasta que no queden eventos en la cola
        while (SDL_PollEvent(&event)) {

            // El estado maneja el evento
            State_manager::get_state()->handle_events(event);

            // Si se cierra la ventana
            if (event.type == SDL_QUIT) {
                Game::stop();
            }
        }

        // Actualiza el estado del juego
        State_manager::get_state()->update();

        // Limpia la pantalla
        SDL_RenderClear(renderer);

        // Renderiza el estado
        State_manager::get_state()->render();

        // Refresca la pantalla
        SDL_RenderPresent(renderer);

    }
}

void Game::stop()
{
    running = false;
}

void Game::get_mouse_position(int * mouse_x, int * mouse_y)
{
    SDL_GetMouseState(mouse_x, mouse_y);

    * mouse_x = * mouse_x;
    * mouse_y = * mouse_y;
}
