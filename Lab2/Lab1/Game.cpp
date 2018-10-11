#include "Game.h"
#include<iostream>


Game::Game() : window(sf::VideoMode(1920, 1080), "SFML"), player(sf::Vector2f(400, 500)), ent(sf::Vector2f(1000, 500)), ent2(sf::Vector2f(1500,500))
{
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	ent2.setState(2);
}

Game::~Game() {



}

void Game::run()
{

	initialize();

	sf::Event event;

	while (isRunning) {



		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
		time = clock.restart();
		dt = time.asSeconds();
	}

}

void Game::initialize()
{
	isRunning = true;


}

void Game::update()
{
	ent.Update(dt, player.getPosition(),player.getSpeed(),player.getRotation(), player.getCircle(), player.getInnerCircle());
	ent2.Update(dt, player.getPosition(), player.getSpeed(), player.getRotation(), player.getCircle(), player.getInnerCircle());
	player.Update(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		
		//player.increaseVelocityX();
		player.increaseRotation();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//player.decreaseVelocityX();
		player.decreaseRotation();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		//player.increaseVelocityY();
		//player.SetSpeed(-0.5);
		player.DecreaseSpeed();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		//player.decreaseVelocityY();
		//player.SetSpeed(0.5);
		
		player.IncreaseSpeed();
	}

	

}

void Game::draw()
{
	window.clear(sf::Color::Black);
	//ent.Draw(window);
	ent2.Draw(window);
	player.Draw(window);
	window.display();
	
	
}

void Game::unload()
{
}
