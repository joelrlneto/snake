#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../h/map.h"

#include <SFML/Graphics.hpp>

Map::Map(int _width, int _height, sf::RenderWindow *_window) : width(_width), height(_height), window(_window)
{
	currentFood = new Food;
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

void Map::Draw(){
    sf::RectangleShape mapShape(sf::Vector2f(0, 0));
    mapShape.setSize(sf::Vector2f(width*20, height*20));
    window->draw(mapShape);

    sf::CircleShape foodShape(10);
    foodShape.setFillColor(sf::Color(255, 0, 0));
    foodShape.setPosition(sf::Vector2f(currentFood->X*20, currentFood->Y*20));
    window->draw(foodShape);
}
