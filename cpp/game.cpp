#include <iostream>
#include <cstdlib>
#include <ctime>

#include "../h/game.h"
#include "../h/node.h"

#include <SFML/Graphics.hpp>

Game::Game(sf::RenderWindow *_window):window(_window), points(0){
    srand(time(NULL)*rand());
	map = new Map(32,20, window);
	snake = new Snake(window, 32, 20);
	map->AddFood();//Inicia com uma comida
}

void Game::Update(){
    snake->Avancar();

    //Verifica se alcançou a comida
    if((snake->GetHead()->X == map->GetCurrentFood().X) && (snake->GetHead()->Y == map->GetCurrentFood().Y)){
        snake->Eat();
        points++;
        map->AddFood();//TODO: Não adicionar dentro do corpo da cobra (verificar posição e gerar novamente)
    }

    //Verifica se a cobra mordeu o próprio corpo
    if(snake->HasBittenItself()){
        IsGameOver = true;
        IsRunning = false;
    }
}

void Game::Draw(){
    if(IsRunning){
        map->Draw();
        snake->Draw();
	}
	else if (IsGameOver){
        ShowGameOver();
	}
	else
        ShowSplashScreen();
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

void Game::ShowGameOver(){
    screenRect.setTexture(&gameOverTexture);
    window->draw(screenRect);
}

void Game::LoadContent(){
    screenRect.setSize(sf::Vector2f(640,480));
    gameOverTexture.loadFromFile("assets/images/gameOver.jpg");
    splashTexture.loadFromFile("assets/images/splash.jpg");
}

void Game::Start(){
    IsRunning = true;
    IsGameOver = false;
}

void Game::ShowSplashScreen(){
    screenRect.setTexture(&splashTexture);
    window->draw(screenRect);
}
