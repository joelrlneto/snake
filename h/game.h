#ifndef _GAME_
#define _GAME_

#include "map.h"
#include "snake.h"

//Classe que encapsula os elementos do jogo
class Game{
	private:
		Map *map;
		Snake *snake;
		int points;
		sf::RenderWindow *window;
		sf::Texture gameOverTexture, splashTexture, scoreTexture;
		sf::RectangleShape screenRect, scoreRect;
		sf::Text scoreText, levelText;
        sf::Font defaultFont;
        int level;
        float stepTime;
	public:
        bool IsRunning = false; //Será verdadeiro quando o jogo estiver rodando
        bool IsGameOver = false; //Será verdadeiro quando o jogo for perdido
		Game(sf::RenderWindow *_window);
		void Update();
		void Draw();
		void SendCommand(int command);
		void ShowGameOver();
		void LoadContent(); //Carrega os recursos que serão usados durante o jogo
		void Start();//Inicia o jogo
		void ShowSplashScreen();
		void ShowScore();
		void CheckLevel();
		float GetStepTime();
};

#endif
