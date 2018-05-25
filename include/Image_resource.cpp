#include <iostream>
#include <string>
#include "Image_resource.h"
#include "Game.h"
#include "Setting.h"

Image_resource::Image_resource()
{
	texture = nullptr;
	width = 0;
	height = 0;
	position_x = 0;
	position_y = 0;
}

Image_resource::~Image_resource()
{
	if (texture != nullptr)
  {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

bool Image_resource::load_from_file(char * file)
{
	std::string path = Setting::image_path + file;

	// Se carga la imagen desde la ruta
	SDL_Surface* surface = IMG_Load(path.c_str());

  if (surface == nullptr)
  {
		std::cerr << "IMG_Load Error: " << SDL_GetError() << std::endl;
		return false;
	}

	if (Setting::color_key[0] != -1)
  {
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, Setting::color_key[0], Setting::color_key[1], Setting::color_key[2]));
	}

	// Se crea la textura desde la superficie
	texture = SDL_CreateTextureFromSurface(Game::get_renderer(), surface);

	if (texture == nullptr)
  {
		std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return false;
	}

  std::cout << "surface w: " << surface->w << std::endl;

  std::cout << "surface h: " << surface->h << std::endl;

	// Ancho y alto real
	width = surface->w;

	height = surface->h;

	// Elimino la superficie
	SDL_FreeSurface(surface);

	return true;
}

// Actualiza las posiciones (x,y) para el renderizador
void Image_resource::set_position(int x, int y)
{
	position_x = x;

	position_y = y;
}

// Crea un rectangulo que define donde se dibuja la figura y con que dimensiones
void Image_resource::render(SDL_Rect * clip_rect)
{

	SDL_Rect dest_rect = {position_x ,position_y , width, height};

  // Si el rectangulo necesita una dimension de un sprite y no de toda la imagen
	if (clip_rect != nullptr)
  {
		dest_rect.w = clip_rect->w;

		dest_rect.h = clip_rect->h;

    dest_rect.x = clip_rect->x;

		dest_rect.y = clip_rect->y;
	}

  // Copia la textura al renderizador con un rectangulo de origen y destino
  SDL_RenderCopy(Window::renderer,texture, nullptr, & dest_rect);
	//SDL_RenderCopyEx(Game::get_renderer(), texture, clip_rect, &dest_rect, 0.0, nullptr, SDL_FLIP_NONE);
}
