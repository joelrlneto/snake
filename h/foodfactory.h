#ifndef _FOODFACTORY_
#define _FOODFACTORY_
#include <cstring>

#include "food.h"

class FoodFactory {
    public:
        static Food* GetRandomFood(int maxX, int maxY);
};

#endif
