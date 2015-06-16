#ifndef _FOODFACTORY_
#define _FOODFACTORY_
#include <cstring>

#include "food.h"

///Classe que gera comidas aleatórias.
class FoodFactory {
    public:
        ///Retornar a posição aleatória da comida
        static Food* GetRandomFood(int _x, int _y);
};

#endif
