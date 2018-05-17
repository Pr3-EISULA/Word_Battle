#ifdef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "rectangle.h"

//Hereda del tipo rectangulo porque va contener una imagen 
//y se encuentra en una coordenada (x,y),

class Token : public Rectangle
{
  private:
    //Valor de la letra
    int val;
    //Letra que contiene la imagen
    char key;
    
   public:
   
   Token(int, char);
   
   ~Token();
   
   inline int get_letter() const { return value; }
   
   inline int get_key() const { return key; }
   
};

#endif
