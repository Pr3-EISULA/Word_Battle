#pragma once
#include <string>
#include <SDL.h>
#include "State.h"

// Menu_state: implementacion para los estados en pantalla

class Menu_state : public State
{
  public:

    void init();

    void handle_events(SDL_Event& event);

    void update();

    void render();

    void clean_up();
};
