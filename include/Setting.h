#pragma once
#include <string>

//Setting: clase que contiene los ajustes principales del juego

struct Setting
{
	// Nombre que aparece en la barra de título
	static char * game_name;

	// Ruta a iconos
	static char * icon_path;

	// Ruta a las imágenes
	static const std::string image_path;

	// Ruta a sonidos
	static const std::string sound_path;

  // Asigna el primer elemento a -1 para desactivar el colour keying, de lo contrario asigna {0, 0xFF, 0xFF}
	static const int color_key[];

  // Asigna color de fondo del renderizador
  static const int background_color[];

	// Controla la reproducción de sonidos
	static const bool play_sounds = true;

	// Ancho del sprite recortado de la imagen que se utiliza en la matriz
	static const int grid_sprite_width = 16;

	// Alto del sprite recortado de la imagen que se utiliza en la matriz
  static const int grid_sprite_height = 16;

	// Cantidad de columnas en la matriz. Tambien afecta el tamaño de la ventana y el tamaño actual de la ventana
	static const int grid_columns = 3;

  // Cantidad de filas en la matriz. Tambien afecta el tamaño de la ventana y el tamaño actual de la ventana
	static const int grid_rows = 3;
	
	// Subtracting 1 from the window_width and window_height will hide part of
	// the repeating grid image that we don't want to see

	// Ancho de la ventana de la aplicación
	static const int window_width = 1000; //*grid_columns * grid_sprite_width - 1;

	// Alto de la ventana de la aplicación
  static const int window_height = 600;//grid_rows * grid_sprite_height - 1;

	// Ancho del area de juego sin el factor de escala aplicado
	static const int actual_window_width = window_width ;//* scale_factor;

  // Alto del area de juego sin el factor de escala aplicado
	static const int actual_window_height = window_height;// * scale_factor;
};
