#include <iostream>
#include <string>
#include "Sound_resource.h"
#include "Setting.h"

Sound_resource::Sound_resource()
{
	chunk = nullptr;
	path = "";
}

Sound_resource::~Sound_resource()
{
	if (chunk != nullptr)
  {
		Mix_FreeChunk(chunk);
		chunk = nullptr;
	}

	path = "";
}

bool Sound_resource::load_from_file(char * file)
{
	path = Setting::sound_path + file + ".wav";

	//Carga el archivo de sonido tipo WAV
	chunk = Mix_LoadWAV(path.c_str());

  if (chunk == nullptr)
  {
		std::cout << "Mix_LoadWAV Error: Couldn't open " << path << ". SDL_mixer Error: " << Mix_GetError() << std::endl;
		return false;
	}

	return true;
}

void Sound_resource::play()
{
	if (chunk == nullptr)
		std::cout << "Mix_PlayChannel Error: Couldn't play chunk for " << path << ". SDL_mixer Error: " << Mix_GetError() << std::endl;

	else
		if (Setting::play_sounds)
			// Reproduce el sonido sin hacer un loop
		  Mix_PlayChannel(-1, chunk, 0);
}
