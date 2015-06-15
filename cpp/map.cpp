#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../h/map.h"
#include "../h/foodfactory.h"

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
	currentFood = FoodFactory::GetRandomFood(width, height);
}

void Map::Print(){

}

void Map::Draw(){
    sf::Texture mapTexture;
    mapTexture.loadFromFile("assets/images/field.png");

    sf::RectangleShape mapShape(sf::Vector2f(0, 0));
    mapShape.setSize(sf::Vector2f(width*20, height*20));
    mapShape.setTexture(&mapTexture);
    window->draw(mapShape);

    sf::Texture foodTexture;
    foodTexture.loadFromFile(currentFood->ImagePath);

    sf::CircleShape foodShape(10);
    foodShape.setTexture(&foodTexture);
    foodShape.setPosition(sf::Vector2f(currentFood->X*20, currentFood->Y*20));
    window->draw(foodShape);
}
