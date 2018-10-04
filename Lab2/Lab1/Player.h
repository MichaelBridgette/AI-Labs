#pragma once
#include<SFML/Graphics.hpp>

class Player
{
public:
	Player(sf::Vector2f pos);
	~Player();
	void Draw(sf::RenderWindow &window);
	void Update(float dt);
	void increaseVelocityX();
	void decreaseVelocityX();
	void increaseVelocityY();
	void decreaseVelocityY();

	void increaseRotation();
	void decreaseRotation();
	void SetSpeed(float s);

	void IncreaseSpeed();
	void DecreaseSpeed();
private:
	sf::Vector2f position;
	float speed;

	sf::Vector2f velocity;
	sf::Texture texture;
	sf::Sprite sprite;
	float rotation;
	float orientation;
};
