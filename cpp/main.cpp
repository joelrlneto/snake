#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include "../h/game.h"



int main(){
	Game g;
	g.Update();
	g.Draw();
	
	while(true){
		g.SendCommand(0);
		g.Update();
		g.Draw();
	}
	return 0;
}