#ifndef _SNAKE_
#define _SNAKE_

#include "node.h"
#include <SFML/Graphics.hpp>

///Classe que representa a cobra (lista encadeada)
class Snake {
	private:
		Node *head, *tail;///
		int size;///
		int mapWidth, mapHeight; ///Limites do mapa.
		sf::RenderWindow *window;///Janela onde será desenhada a cobra;
		sf::Texture bodyTexture, tailTexture, headTexture;///Testuras da corpo, da cauda e cabeça da cobra.
		sf::CircleShape headShape, bodyShape, tailShape;///Shapes da cabeça, do corpo e da cauda da cobra.
	public:
		Snake(sf::RenderWindow *_window, int _mapWidth, int _mapHeight); ///Construtor padrão (inicia a cobra com 3 blocos).
		Node* GetHead();///Retorna a cabeca da cobra.
		void Eat(); ///Come um novo bloco.
		void MoveUp(); ///Move a cobra para cima.
		void MoveRight();///Move a cobra para a direita.
		void MoveDown(); ///Move a cobra para baixo.
		void MoveLeft(); ///Move a cobra para a esquerda.
		void Avancar(); ///Anda na direção atual (avança um passo).
		void Print(); ///Imprime o corpo da cobra (para testes).
		void Draw(); /// Desenha a cobra na janela.
		bool HasBittenItself();///Retorna true se a cobra mordeu a si própria.
		bool HasABodyPartIn(int _x, int _y);///Retorna verdadeiro se um dos blocos da cobra está na posição indicada por X e Y.
};

#endif
