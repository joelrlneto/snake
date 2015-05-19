#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../h/snake.h"

Snake::Snake() : size(1) {
	//Inicia a cabeça e a cauda
	srand(time(NULL));
	head = new Node;
	head->Next = NULL;
	head->X = rand() % 10; //TODO: Receber posição máxima da classe game
	head->Y = rand() % 10; //TODO: Receber posição máxima da classe game
	head->Direction = (Orientation)(rand() % 4);
		
	tail = head;
	
	//Comer 2 vezes para criar o corpo com total de 3 blocos
	Eat();
	Eat();
};

Node* Snake::GetHead(){
	return head;
}

void Snake::Eat(){
	//Adicionar um novo bloco ao fim
	Node *food = new Node;
	food->Next = NULL;
	food->Direction = tail->Direction;
	//TODO: Definir posição do novo bloco de acordo com a posição e direção da cauda
	switch(tail->Direction){
		case Up:
			food->X = tail->X;
			food->Y = (tail->Y + 1) % 10;
		break;
		case Right:
			food->Y = tail->Y;
			food->X = (tail->X + 1) % 10;
		break;
		case Down:
			food->X = tail->X;
			food->Y = (tail->Y - 1) % 10;
		break;
		case Left:
			food->Y = tail->Y;
			food->X = (tail->X - 1) % 10;
		break;
	}
	
	tail->Next = food;
	tail = food;
	
	size++;
};

void Snake::MoveUp(){
	head->Direction = Up;
	std::cout << "Moveu para cima" << std::endl;
};

void Snake::MoveRight(){
	std::cout << "Moveu para a direita" << std::endl;
};

void Snake::MoveDown(){
	std::cout << "Moveu para baixo" << std::endl;
};

void Snake::MoveLeft(){
	std::cout << "Moveu para a esquerda" << std::endl;
};

void Snake::Avancar(){
	Node *temp = head;
	while(temp != NULL){
		switch(temp->Direction){
			case Up:
				temp->Y--;
				if(temp->Y < 0) temp->Y = 9;
			break;
			case Right:
				temp->X++;
				if(temp->X > 9) temp->X = 0;
			break;
			case Down:
				temp->Y++;
				if(temp->Y > 9) temp->Y = 0;
			break;
			case Left:
				temp->X--;
				if(temp->X <0) temp->X = 9;
			break;
		}
		if(temp != tail)
			temp->Next->Direction = temp->Direction;
		temp = temp->Next;
	}
	system("pause");
};

void Snake::Print(){
	std::cout << "Tamanho: " << size << " -> ";
	Node *temp = head;
	while(temp != NULL){
		std::cout << "[" << temp->X << "," << temp->Y << "(" << temp->Direction << ")] ";
		temp = temp->Next;
	}
};