#include <window.h>

int main()
{
 //Se crea la ventana con un nombre y sus dimensiones 
  Window window("Window test", 1300, 700);

  //Rectangulo que va a contener las imagenes
  Rect rect(window,180, 180, 0, 0, "/media/images/design.png");

  //Evento SDL. Este dato captura todos los dispositos I/O
  SDL_Event event; 
 
  //Mientras que la ventana este abierta (no presiones la x en la esquina superior)
  while (!window.is_closed())
  {
    //Imprime los eventos del rectangulo por terminal
    rect.events();
    
    //Imprime los eventos de la ventana por terminal
    window.events();
    
    //Dibuja el rectangulo
    rect.draw();
    
    //Dibuja en la ventana
    window.clear();

  }
  return 0;
}
