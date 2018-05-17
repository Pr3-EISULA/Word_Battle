#include <rectangle.h>

//Asigno los valores a los atributos
Rect::Rect(int w, int h, int x, int y, std::string p) :
width(w), height(h), x_pos(x), y_pos(y), path(p)
{
  //Cargo la imagen a la superficie
  surface = IMG_Load(path.c_str());
     
  if (!surface) //Si la carga no fue exitosa entonces
    std::cerr <<"Failed to load surface\n";
  
  //De lo contrario crea la textura de la superficie
  texture = SDL_CreateTextureFromSurface(Window::renderer,surface);
      
  if (!texture) //Si la creaciónno fue exitosa entonces
    std::cerr<< "Failed to create texture\n";
 
  //Y libero la superficie    
  SDL_FreeSurface(surface);
}
    
Rect::void events(SDL_Event & event)
{
  //Si el evento capturado es la presion de una tecla
  if (event.type == SDL_KEYDOWN)
  {  //Que tecla se presionó?
    switch (event.key.keysym.sym)
    { 
        //Flecha izquiera : mueve el rectangulo (la ficha en nuestro caso) a la izquiera de pixel en pixel
       case SDLK_LEFT:
         x_pos -= 1;
         break;
        //Flecha derecha: mueve la ficha a la derecha
       case SDLK_RIGHT:
         x_pos += 1;
         break;
        //Flecha arriba : mueve la ficha hacia arriba 
       case SDLK_UP:
         y_pos -= 1;
         break;
        //Flecha abajo : mueve la ficha hacia abajo
       case SDLK_DOWN:
         y_pos += 1;
         break;
    }

  }
}

Rect::void draw() const
{
  //Asigno las dimensiones al rectangulo
  SDL_Rect rect = {x_pos, y_pos, wid, hei};
      
  if (texture) //Si la textura no es nullptr, la cargo al rectangulo
    SDL_RenderCopy(Window::renderer,texture, nullptr, & rect);
  
  //De lo contrario relleno el rectangulo con colores r, g, b, a y lo paso al renderizador      
  else 
  {       
    SDL_SetRenderDrawColor(Window::renderer,0,0,200,255);
    
    SDL_RenderFillRect(Window::renderer, rect);
  }        
}
    
Rect::~Rect()
{
  //Destruyo la textura
  SDL_DestroyTexture(texture);
}
    
