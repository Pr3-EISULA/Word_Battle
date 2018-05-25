#pragma once
#include <string>
#include <vector>
#include "Image_resource.h"
#include "Sound_resource.h"

// Resource_manager: administra los recursos del juego como imagenes y audios

class Resource_manager
{
  public:

  // Retorna la imagen cargada
	static Image_resource * get_image(char * file);

	// Retorna el archivo de audio cargado
	static Sound_resource * get_sound(char * file);

	// Carga una imagen y la almacena
	static Image_resource * load_image(char * file);

  // Carga una imagen y la almacena
	static Sound_resource * load_sound(char * file);

	// Elimina una imagen
	static void unload_image(char* file);

	// Elimina un audio
	static void unload_sound(char* file);

private:
  // Almacena punteros para instancear de tipo Image_resource
	static std::vector<std::pair<std::string, Image_resource *>> images;

	// Almacena punteros para instancear de tipo Sound_resource
	static std::vector<std::pair<std::string, Sound_resource *>> sounds;
};
