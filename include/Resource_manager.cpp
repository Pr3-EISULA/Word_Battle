#include "Resource_manager.h"

// Define vectors to store pointers to instances of resource classes
std::vector<std::pair<std::string, Image_resource*>> Resource_manager::images;

std::vector<std::pair<std::string, Sound_resource*>> Resource_manager::sounds;

Image_resource * Resource_manager::get_image(char* file) {

	// Chequea cada elemento hasta que encuentre el archivo y lo retorna
	for (unsigned int i = 0; i < images.size(); i++)
  {
		if (images[i].first == file)
			return images[i].second;
	}

	return nullptr;
}

Sound_resource* Resource_manager::get_sound(char* file)
{
	for (unsigned int i = 0; i < sounds.size(); i++)
  {
		if (sounds[i].first == file)
			return sounds[i].second;
	}

	return nullptr;
}

Image_resource* Resource_manager::load_image(char* file) {

	// Carga el archivo, almacena la instancia y lo retorna
	Image_resource* image = new Image_resource();
	image->load_from_file(file);
	images.insert(images.end(), std::make_pair(file, image));
	return get_image(file);
}

Sound_resource* Resource_manager::load_sound(char* file) {

	Sound_resource* sound = new Sound_resource();
	sound->load_from_file(file);
	sounds.insert(sounds.end(), std::make_pair(file, sound));
	return get_sound(file);
}

void Resource_manager::unload_image(char* file) {

	for (unsigned int i = 0; i < images.size(); i++) {
		if (images[i].first == file) {

			// Elimina la instancia
			delete images[i].second;
			images[i].second = nullptr;

			// Y la saca del vector
			images.erase(images.begin() + i);
		}
	}
}

void Resource_manager::unload_sound(char* file) {

	for (unsigned int i = 0; i < sounds.size(); i++) {
		if (sounds[i].first == file) {

			delete sounds[i].second;
			sounds[i].second = nullptr;

			sounds.erase(sounds.begin() + i);
		}
	}
}
