#pragma once
#include <SDL.h>
#include "State.h"

// Title_state: implementacion para manejar el estado del titulo

class Title_state : public State
{
  public:

    void init();

    void handle_events(SDL_Event& event);

    void update();

    void render();

    void clean_up();
};
