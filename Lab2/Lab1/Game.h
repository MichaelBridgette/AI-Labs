#ifndef GAME_H
#define GAME_H

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

#include"Entity.h"
#include"Player.h"
class Game
{
public:
	Game();
	~Game();
	void run();
private:
	sf::RenderWindow window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();



	Entity ent;
	Entity ent2;
	Entity ent3;
	Entity ent4;
	Player player;


	sf::Clock clock;
	sf::Time time;

	float dt = 0;
};
#endif