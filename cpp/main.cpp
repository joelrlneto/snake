#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include "../h/game.h"

#include <SFML/Graphics.hpp>

int main(){
	sf::RenderWindow mainRenderWindow(sf::VideoMode(640,480), "Snake");
	Game g(&mainRenderWindow);
	g.LoadContent();
	sf::Clock clock;
	float timeCount = 1;


	while(mainRenderWindow.isOpen()){
        sf::Event event;
        while (mainRenderWindow.pollEvent(event))
        {
            switch(event.type){
                case sf::Event::Closed:
                    mainRenderWindow.close();
                    break;
                case sf::Event::KeyPressed:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                        g.SendCommand(1);
                    };
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                        g.SendCommand(2);
                    };
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                        g.SendCommand(3);
                    };
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                        g.SendCommand(4);
                    };
                    break;
                case sf::Event::MouseButtonReleased:
                        g.Start();
                    break;
            }
        }
        if(clock.getElapsedTime().asSeconds() > timeCount){
             mainRenderWindow.clear();
             g.Update();
             g.Draw();
             timeCount += 0.5f;
        }
        mainRenderWindow.display();
	}
	return 0;
}
