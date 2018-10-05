#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"Player.h"
enum State {
	Wander,
	Seek,
	Arrive,
	Pursue
};
class Entity {

public:
	Entity(sf::Vector2f pos);
	void Draw(sf::RenderWindow &window);
	void Update(float dt, sf::Vector2f playerPos, float playerSpeed, float playerRotation);
	void HandleBoundaries();

	void increaseSpeed();
	void decreaseSpeed();
	void increaseRotation();
	void decreaseRotation();


	void Seek(sf::Vector2f pos);

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