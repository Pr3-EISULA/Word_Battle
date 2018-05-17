#include <window.h>

SDL_Renderer * Window::renderer = nullptr;

//Asigno los valores a los atributos
Window::Window(const std::string & t, int w, int h) :
title(t), width(w), height(h) 
{
  //Si la funcion de inicialización se ejecuta sin ningun error entoces 
  //la ventana no esta cerrada
  closed = !init();
}

Window::~Window() 
{
  //Destruyo la ventana y cierro SDL
  SDL_DestroyWindow(window);
  SDL_Quit();
}

bool Window::init()
{
  //Este es un dato de control para determinar la biblioteca funciona
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    std::cerr << "Failed to initialize SDL!\n";
    return false;
  }

  //Creo la ventana con un nombre, centrada en x e y, y asigno las dimensiones
  else
  {
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

     //Si falló la creacion de la ventana
    if (window == nullptr)
    {
      std::cerr << "Failed to create window!\n";
      return false;
    }

    //Creo el renderizador
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if (renderer == nullptr)
    {
      std::cerr << "Failed to create renderer" << '\n';
      return false;
    }
        
    //Este es otro dato de control para ver si las bibliotecas libpng, libjpg... funcionan correctamente
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
      std::cerr << "Failed to initialize SDL Image" << '\n';
      return false;
    }
    
    return true;
  }
}

void Window::events(SDL_Event & event)
{ //Evaluo el evento capturado
  switch(event.type)
  {
    //Si presiono la (x) para cerrar la ventana
    case SDL_QUIT:
      //Se cierra la ventana
      closed = true;
      break;
      
    case SDL_MOUSEMOTION:
      //Muestra por terminal las coordenadas x, y del mouse
      //Esto se utilizará mas adelante para mover las fichas con el mouse y no el teclado
      std::cout << event.motion.x << ", " << event.motion.y << '\n';
      break;
      
    case SDL_MOUSEBUTTONUP:
    //Si presiono o suelto el boton del mouse, imprimelo por terminal 
      std::cout << "Mouse button released\n";
      break;
      
    default:
      break;
  }
}
  

void Window::clear(SDL_Renderer * renderer) const
{
  //Esta funcion presenta el renderizador
  //Asigna un color para rellenar la ventana (en caso de que no haya una imagen)
  //Y limpia el renderizador
  SDL_RenderPresent(renderer);
  SDL_SetRenderDrawColor(renderer,0, 0, 200, 255);
  SDL_RenderClear(renderer);
}
