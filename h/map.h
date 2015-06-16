#ifndef _MAP_
#define _MAP_

#include "food.h"
#include <SFML/Graphics.hpp>

///Classe que representa o mapa (matriz de pontos)
class Map {
	private:
		///Largura (width) e altura (height) do mapa.
		int width, height;
		///Comida atual
		Food *currentFood;
		///Janela onde o mapa será desenhado.
		sf::RenderWindow *window;
	public:
		///Construtor padrão.
		Map(int _width, int _height, sf::RenderWindow *_window);
		///Retorna a largura do mapa.
		int GetWidth();
		///Retorna a altura do mapa.
		int GetHeight();
		///Retorna a comida atualmente no mapa.
		Food GetCurrentFood();
		///Adiciona uma comida em posição aleatória.
		void AddFood();
		///Imprime o mapa no console (para testes).
		void Print();
		///Desenha o mapa na janela.
		void Draw();
};

#endif
