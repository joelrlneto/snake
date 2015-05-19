#ifndef _NODE_
#define _NODE_

#include "orientation.h"

//Cada bloco do corpo da cobra (nomeado como Node para facilitar a referência ao que foi dado em aula)
struct Node {
	int X, Y;
	Orientation Direction;
	Node *Next;
};


#endif