#include <sstream>
#include <cstdlib>
#include "../h/foodfactory.h"
#include <SFML/System/String.hpp>

Food* FoodFactory::GetRandomFood(int maxX, int maxY){
    int type = rand() % 9 + 1;
    std::ostringstream strPath;
    strPath << "assets/images/fruits/" << type << ".png";
    sf::String path(strPath.str());

    Food *newFood = new Food;
    newFood->X = rand() % maxX;
    newFood->Y = rand() % maxY;
    newFood->ImagePath = path;
    newFood->Value = (type % 5 == 0 ? -1 : type);
    return newFood;
}
