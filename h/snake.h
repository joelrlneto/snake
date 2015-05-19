#ifndef _SNAKE_
#define _SNAKE_

#include "node.h"

//Classe que representa a cobra (lista encadeada)
class Snake {
	private:
		Node *head, *tail;
		int size;
	public:
		Snake(); //Construtor padrão (inicia a cobra com 3 blocos)
		Node* GetHead();
		void Eat(); //Come um novo bloco
		void MoveUp(); //Move a cobra para cima
		void MoveRight(); //Move a cobra para a direita
		void MoveDown(); //Move a cobra para baixo
		void MoveLeft(); //Move a cobra para a esquerda
		void Avancar(); //Anda na direção atual (avança um passo)
		void Print(); //Imprime o corpo da cobra (para testes)	
};

#endif