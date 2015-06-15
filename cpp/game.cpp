#include <ctime>
#include <cstring>
#include <sstream>

#include "../h/game.h"
#include "../h/node.h"

#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>

Game::Game(sf::RenderWindow *_window):window(_window), points(0) ,level(1){
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
        points += map->GetCurrentFood().Value;
        if(points < 0)
            points = 0;
        map->AddFood();//TODO: Não adicionar dentro do corpo da cobra (verificar posição e gerar novamente)
    }

    CheckLevel();

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
        ShowScore();
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
    scoreRect.setSize(sf::Vector2f(640,80));
    scoreRect.setPosition(sf::Vector2f(0,400));

    gameOverTexture.loadFromFile("assets/images/gameOver.jpg");
    splashTexture.loadFromFile("assets/images/splash.jpg");
    scoreTexture.loadFromFile("assets/images/score.png");
    defaultFont.loadFromFile("assets/fonts/Anson.ttf");

    scoreRect.setTexture(&scoreTexture);
    scoreText.setFont(defaultFont);
    scoreText.setCharacterSize(28);
    scoreText.setColor(sf::Color(0,0,0));
    scoreText.setPosition(sf::Vector2f(510, 430));

    levelText.setFont(defaultFont);
    levelText.setCharacterSize(12);
    levelText.setColor(sf::Color(0,0,0));
    levelText.setPosition(sf::Vector2f(550, 460));
}

void Game::Start(){
    if(IsGameOver){
        map = new Map(32,20, window);
        snake = new Snake(window, 32, 20);
        map->AddFood();//Inicia com uma comida
        IsGameOver = false;
        points = 0;
    }

    IsRunning = true;
}

void Game::ShowSplashScreen(){
    screenRect.setTexture(&splashTexture);
    window->draw(screenRect);
}

void Game::ShowScore(){
    std::ostringstream StrP2;
    StrP2 << points;
    std::string scoreP2(StrP2.str());
    sf::String text(scoreP2);
    scoreText.setPosition(sf::Vector2f(570-scoreP2.size()*20, 430));

    scoreText.setString(text);
    window->draw(scoreRect);
    window->draw(scoreText);
    window->draw(levelText);
}

void Game::CheckLevel(){
    switch(level){
        case 1:
            if (points >= 20){
                level = 2;
            }
        break;
        case 2:
            if (points >= 50){
                level = 3;
            }
        break;
    }
    std::ostringstream StrP2;
    StrP2 << "level " << level;
    sf::String text(StrP2.str());
    levelText.setString(text);
}
