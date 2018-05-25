#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>


// Resorce: clase abstracta para cargar archivos

class Resource
{
public:

  // Carga un archivo a memoria
	virtual bool load_from_file(char * file) = 0;
};
