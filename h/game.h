#ifndef _GAME_
#define _GAME_

#include "map.h"
#include "snake.h"

//Classe que encapsula os elementos do jogo
class Game{
	private:
		int **matrix;
		Map *map;
		Snake *snake;		
	public:
		Game();
		void Update(); 
		void Draw();
		void SendCommand(int command);
};

#endif