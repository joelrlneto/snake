#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../h/map.h"

Map::Map(int _width, int _height) : width(_width), height(_height)
{
	currentFood = new Food;
	matrix = new int*[_height];
	for(int i = 0; i < width; i++){
		matrix[i] = new int[_width];
	}	
}

int Map::GetWidth(){
	return width;
}

int Map::GetHeight(){
	return height;
}

Food Map::GetCurrentFood(){
	return *currentFood;
}

void Map::AddFood() {
	srand(time(NULL)*rand());
	
	currentFood->X = rand() % width;
	currentFood->Y = rand() % height; 
}

void Map::Print(){
	system("CLS");
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			if(currentFood->X == i && currentFood->Y == j)
				std::cout << " O ";
			else
				std::cout << " . ";
		}
		std::cout << std::endl;
	}
}