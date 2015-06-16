#ifndef _GAME_
#define _GAME_

#include "map.h"
#include "snake.h"

///Classe que encapsula os elementos do jogo
class Game{
	private:
		///Mapa do jogo.
		Map *map;
		///Cobra do jogo.
		Snake *snake;
		///Pontuação atual.
		int points;
		///Janela onde o jogo sera desenhado.
		sf::RenderWindow *window;
		///Texturas das telas de game over, splash screen e barra de pontuação e nivel.
		sf::Texture gameOverTexture, splashTexture, scoreTexture;
		///Shapes da tela principal e da barra de pontuação e nivel.
		sf::RectangleShape screenRect, scoreRect;
		///Textos para os pontos e os niveis.
		sf::Text scoreText, levelText;
		///Fonte padrão do jogo.
        sf::Font defaultFont;
		///Nivel do jogo.
        int level;
		///Tempo, em segundos, de cada "passo" da cobra.
        float stepTime;
	public:
		///Será verdadeiro quando o jogo estiver rodando
        bool IsRunning = false;
		///Será verdadeiro quando o jogo for perdido
        bool IsGameOver = false;
		///Construtor padrão.
		Game(sf::RenderWindow *_window);
		///Atualiza os elementos do jogo.
		void Update();
		///Desenha os elementos do jogo.
		void Draw();
		///Envia comandos de teclas pressionadas.
		void SendCommand(int command);
		///Mostra a tela de game over.
		void ShowGameOver();
		///Carrega os recursos que serão usados durante o jogo.
		void LoadContent();
		///Inicia o jogo.
		void Start();
		///Mostra a tela inicial.
		void ShowSplashScreen();
		///Mostra o painel de pontuação.
		void ShowScore();
		///Verifica o nivel atual do jogo.
		void CheckLevel();
		///Retorna o tempo.
		float GetStepTime();
};

#endif
