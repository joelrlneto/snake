#ifndef _FOOD_
#define _FOOD_
#include <string>
#include <SFML/System/String.hpp>

///Estrutura das caracteristicas da comida.
struct Food {
	///Posição horizontal (X) e vertical (Y) da comida.
	int X, Y;
	///Caminho da imagem.
	sf::String ImagePath;
	///Pontuação da comida.
	int Value;
};

#endif
