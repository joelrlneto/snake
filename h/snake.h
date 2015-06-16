#ifndef _SNAKE_
#define _SNAKE_

#include "node.h"
#include <SFML/Graphics.hpp>

///Classe que representa a cobra (lista encadeada)
class Snake {
	private:
		Node *head, *tail;
		int size;
		///Limites do mapa.
		int mapWidth, mapHeight; 
		sf::RenderWindow *window;///Janela onde será desenhada a cobra;
		sf::Texture bodyTexture, tailTexture, headTexture;///Testuras da corpo, da cauda e cabeça da cobra.
		///Shapes da cabeça, do corpo e da cauda da cobra.
		sf::CircleShape headShape, bodyShape, tailShape;
	public:
		///Construtor padrão (inicia a cobra com 3 blocos).		
		Snake(sf::RenderWindow *_window, int _mapWidth, int _mapHeight);
		///Retorna a cabeca da cobra.
		Node* GetHead();		
		///Come um novo bloco.
		void Eat(); 
		///Move a cobra para cima.
		void MoveUp(); 
		///Move a cobra para a direita.
		void MoveRight();
		///Move a cobra para baixo.
		void MoveDown(); 
		///Move a cobra para a esquerda.
		void MoveLeft(); 
		///Anda na direção atual (avança um passo).
		void Avancar(); 
		///Imprime o corpo da cobra (para testes).
		void Print(); 
		/// Desenha a cobra na janela.
		void Draw(); 
		///Retorna true se a cobra mordeu a si própria.
		bool HasBittenItself();
		///Retorna verdadeiro se um dos blocos da cobra está na posição indicada por X e Y.
		bool HasABodyPartIn(int _x, int _y);
};

#endif
