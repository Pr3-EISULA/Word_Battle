#ifdef RECT_H
#define RECT_H
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "window.h"

class Rectangle :
{
  public:
    
    //Recibe como parametros un renderizador, coord x, coord y, ancho, 
    //largo y la ruta a la imagen que va a contener
    Rectangle(const SDL_Renderer *, int , int , int , int , std::string);

    //Evalua los eventos del teclado y mouse
    void events(SDL_Event &);

    //Dibuja en pantalla el rectangulo
    void draw() const;
    
    ~Rectangle();

  private:
  
    //Rectangulo SDL
    SDL_Rect rect;
  
    int widht;
    
    int height;

    int y_pos;

    int x_pos;

    std::string path;

    //Superficie SDL sobre la cual se renderiza un imagen
    SDL_Surface * surface = nullptr;

    //Textura SDL, es el dato que contiene la imagen
    SDL_Texture * texture = nullptr;
};

#endif
