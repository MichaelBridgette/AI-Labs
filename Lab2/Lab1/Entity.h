#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"Player.h"
enum State {
	Wander,
	Seek,
	Arrive,
	Flee
};
class Entity {

public:
	Entity(sf::Vector2f pos);
	void Draw(sf::RenderWindow &window);
	void Update(float dt, sf::Vector2f playerPos);
	void increaseVelocityX();
	void decreaseVelocityX();
	void increaseVelocityY();
	void decreaseVelocityY();
	void HandleBoundaries();

	void increaseSpeed();
	void decreaseSpeed();
	void increaseRotation();
	void decreaseRotation();

private:
	State state;
	sf::Vector2f position;
	float speed;
	float rotation;
	sf::Vector2f velocity;
	sf::Texture texture;
	sf::Sprite sprite;

	Player *thePlayer;
};