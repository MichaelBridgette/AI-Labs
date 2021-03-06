#include "Game.h"
#include<iostream>


Game::Game() : window(sf::VideoMode(1920, 1080), "SFML"), player(sf::Vector2f(400, 500)), ent(sf::Vector2f(1000, 500)), ent2(sf::Vector2f(1500,500)), ent3(sf::Vector2f(1000, 250)), ent4(sf::Vector2f(1500,250))
{
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	ent.setState(0);
	ent2.setState(1);
	ent3.setState(2);
	ent4.setState(3);
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
	ent3.Update(dt, player.getPosition(), player.getSpeed(), player.getRotation(), player.getCircle(), player.getInnerCircle());
	ent4.Update(dt, player.getPosition(), player.getSpeed(), player.getRotation(), player.getCircle(), player.getInnerCircle());
	player.Update(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player.increaseRotation();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		player.decreaseRotation();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		player.DecreaseSpeed();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		player.IncreaseSpeed();
	}

	

}

void Game::draw()
{
	window.clear(sf::Color::Black);
	ent.Draw(window);
	ent2.Draw(window);
	ent3.Draw(window);
	ent4.Draw(window);

	player.Draw(window);
	window.display();
	
	
}

void Game::unload()
{
}
