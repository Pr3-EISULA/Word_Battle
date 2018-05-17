#ifdef C_WINDOW_H
#define C_WINDOW_H
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

class Window
{
  public:
  
    //La ventana recibe como parámetros un nombre, el ancho y el largo)
    Window(const std::string &, int, int);

    ~Window();
    
    //Funcion para inicializar SDL y cargar datos
    bool init();
    
    //Funcion para evaluar eventos como movimientos de mouse, presión de teclas, etc;
    void events();

    //Determina si la ventana esta abierta. Se utilizar para el loop del juego
    inline bool is_closed() const { return closed; }
    
    //Renderizador que se encargará de cargar las imagenes al programa. 
    //Debe haber un solo renderizador en el programa por lo cual lo hacemos static
    static SDL_Renderer * renderer;

  private:
    
    
    //Nombre de la ventana
    std::string title;
    
    //Ancho de la ventana
    int width;
    
    //Alto de la ventana
    int height;
    
    //Cerrada(true) y abierta(false)
    bool closed;
    
    //Ventana del programa tipo SDL_Window
    //Sus parámetros son:
    //SDL_Window* SDL_CreateWindow(const char* title, int x_position[CENTERED,UNDEFINED], 
    //int y_position [CENTERED,UNDEFINED], 
    //int width, int height, Uint32 flags[FULLSCREEN/RESIZEABLE/UNDEFINED])

    SDL_Window * window = nullptr;
};

#endif
