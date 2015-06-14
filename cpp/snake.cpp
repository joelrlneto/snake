#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../h/snake.h"

Snake::Snake(sf::RenderWindow *_window, int _mapWidth, int _mapHeight) : size(1), window(_window), mapWidth(_mapWidth), mapHeight(_mapHeight) {
	//Inicia a cabeça e a cauda
	srand(time(NULL));
	head = new Node;
	head->Next = NULL;
	head->X = rand() % mapWidth; //TODO: Receber posição máxima da classe game
	head->Y = rand() % mapHeight; //TODO: Receber posição máxima da classe game
	head->Direction = (Orientation)(rand() % 4);
    //lastHeadDirection = head->Direction;
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
			food->Y = (tail->Y + 1) % mapHeight;
		break;
		case Right:
			food->Y = tail->Y;
			food->X = (tail->X - 1) % mapWidth;
		break;
		case Down:
			food->X = tail->X;
			food->Y = (tail->Y - 1) % mapHeight;
		break;
		case Left:
			food->Y = tail->Y;
			food->X = (tail->X + 1) % mapWidth;
		break;
	}

	tail->Next = food;
	tail = food;

	size++;
};

void Snake::MoveUp(){
    if(head->Direction != Down)
        head->Direction = Up;
};

void Snake::MoveRight(){
    if(head->Direction != Left)
        head->Direction = Right;
};

void Snake::MoveDown(){
    if(head->Direction != Up)
        head->Direction = Down;
};

void Snake::MoveLeft(){
    if(head->Direction != Right)
        head->Direction = Left;
};

void Snake::Avancar(){
	Node *temp = head;
	Orientation nodeDirection, nextDirection = head->Direction;

	while(temp != NULL){
		switch(temp->Direction){
			case Up:
				temp->Y--;
				if(temp->Y < 0) temp->Y = mapHeight - 1;
			break;
			case Right:
				temp->X++;
				if(temp->X > mapWidth - 1) temp->X = 0;
			break;
			case Down:
				temp->Y++;
				if(temp->Y > mapHeight - 1) temp->Y = 0;
			break;
			case Left:
				temp->X--;
				if(temp->X < 0) temp->X = mapWidth - 1;
			break;
		}

        if(temp != head){
            nodeDirection = temp->Direction;
            temp->Direction = nextDirection;
            nextDirection = nodeDirection;
        }

		temp = temp->Next;
	}
};

void Snake::Print(){
	std::cout << "Tamanho: " << size << " -> ";
	Node *temp = head;
	while(temp != NULL){
		std::cout << "[" << temp->X << "," << temp->Y << "(" << temp->Direction << ")] ";
		temp = temp->Next;
	}
};

void Snake::Draw(){
    sf::CircleShape shape(10);
    shape.setFillColor(sf::Color(100, 250, 50));
    Node *temp = head;
	while(temp != NULL){
		shape.setPosition(temp->X*20, temp->Y*20);
		window->draw(shape);
		temp = temp->Next;
	}
}

bool Snake::HasBittenItself(){
    Node *temp = head->Next;
	while(temp != NULL){
		if(temp->X == head->X && temp->Y == head->Y)
            return true;
            //TODO: Alterar este método para retornar o bloco que foi mordido,
            // assim, se a cobra tiver esse poder, poderá simplesmente quebrar o corpo neste ponto,
            // mas sem morrer (comida especial)
		temp = temp->Next;
	}
	return false;
}
