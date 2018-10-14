#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"Player.h"
#include <stdlib.h>
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
	void Update(float dt, sf::Vector2f playerPos, float playerSpeed, float playerRotation, sf::CircleShape cir, sf::CircleShape innerCir);
	void HandleBoundaries();

	void increaseSpeed();
	void decreaseSpeed();
	void increaseRotation();
	void decreaseRotation();


	void Seek(sf::Vector2f pos);

	void Wander(sf::Vector2f pos);

	void Pursue(sf::Vector2f pos, float speed, float rotation);

	void setState(int state);

private:
	State m_state;
	sf::Vector2f position;
	float speed;
	float rotation;

	float currentRotation;
	float newRotation;

	sf::Vector2f velocity;
	sf::Texture texture;
	sf::Sprite sprite;

	Player *thePlayer;


	sf::CircleShape m_circle;


	float random = 0;


	sf::Text m_text;
	sf::Font m_font;
};