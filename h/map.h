#ifndef _MAP_
#define _MAP_

#include "food.h"

//Classe que representa o mapa (matriz de pontos)
class Map {
	private:
		int width, height;
		int **matrix;
		Food *currentFood; //Comida atual
	public:
		Map(int _width, int _height);
		int GetWidth();
		int GetHeight();
		Food GetCurrentFood();
		void AddFood(); //Adiciona uma comida em posição aleatória
		void Print(); //Imprime o mapa no console (para testes)
};

#endif