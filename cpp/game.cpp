#include <iostream>
#include <cstdlib>

#include "../h/game.h"
#include "../h/node.h"

Game::Game(){
	map = new Map(10,10);
	snake = new Snake;
	map->AddFood();//Inicia com uma comida
	
	matrix = new int*[map->GetHeight()];
	for(int i = 0; i < map->GetHeight(); i++){
		matrix[i] = new int[map->GetWidth()];
	}
}

void Game::Update(){
	int width = map->GetWidth();
	int height = map->GetHeight();
	
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			matrix[i][j] = 0;
		}
	}
	
	matrix[map->GetCurrentFood().X][map->GetCurrentFood().Y] = 1;
	
	Node *temp = snake->GetHead();

	while(temp != NULL){
		matrix[temp->X][temp->Y] = 2;
		temp = temp->Next;
	}
}

void Game::Draw(){
	int width = map->GetWidth();
	int height = map->GetHeight();
	
	system("cls");
	
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			switch(matrix[i][j]){
				case 0:
					std::cout << " . ";
					break;
				case 1:
					std::cout << " O ";
					break;
				case 2:
					std::cout << " X ";
					break;					
			}
		}
		std::cout << std::endl;
	}
}

void Game::SendCommand(int command){
	switch(command){
		case 0:
			snake->Avancar();
			break;
		case 1:
			snake->MoveUp();
			break;
		case 2:
			snake->MoveRight();
			break;
		case 3:
			snake->MoveDown();
			break;
		case 4:
			snake->MoveLeft();
			break;
	}
}