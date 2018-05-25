#pragma once
#include <SDL_mixer.h>
#include "Resource.h"

// Sound_resource: implementación para manejar los archivos de audio

class Sound_resource : public Resource
{
public:
	Sound_resource();

	~Sound_resource();

	bool load_from_file(char* file);

	void play();

private:
	// Puntero al dato tipo Mix_Chunk que contine el audio
	Mix_Chunk * chunk;

	// Ruta al archivo de audio
	std::string path;
};
