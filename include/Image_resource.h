#pragma once
#include <SDL.h>
#include "Resource.h"


// Image_resource: implementación para manejar archivos de imágenes

class Image_resource : public Resource
{
  public:

	  Image_resource();

    ~Image_resource();

	  bool load_from_file(char * file);

	/**
	 * Asigna la posicion de una imagen que será utilizada por el render
   * X es el numero de pixeles desde la izquierda de la ventana
   * Y es el numero de pixeles desde el tope de la ventana
	 * Scale factor is taken into consideration. For example your window
	 * width is 100 before a scale factor of x2, 100 will remain the max width
	 * before the element appears to move off the screen.
	 */
	void set_position(int x = 0, int y = 0);

	/**
	 * Renderiza la imagen.
	 * Recibe un rectangulo con el sprite
	 */
	void render(SDL_Rect * clip_rect = nullptr);

private:
	// Puntero a la imagen almacenada como textura
	SDL_Texture * texture;

	// Ancho de la imagen
	int width;

  // Alto de la imagen
	int height;

	/// Posicion en el eje x actual
	int position_x;

	/// Posicion en el eje y actual
	int position_y;
};
