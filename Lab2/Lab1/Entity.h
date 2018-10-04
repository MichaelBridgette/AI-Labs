#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
class Entity {

public:
	Entity(sf::Vector2f pos, sf::Vector2f vel);
	void Draw(sf::RenderWindow &window);
	void Update(float dt);
	void increaseVelocityX();
	void decreaseVelocityX();
	void increaseVelocityY();
	void decreaseVelocityY();

private:
	sf::Vector2f position;
	float speed;

	sf::Vector2f velocity;
	sf::Texture texture;
	sf::Sprite sprite;
};