#pragma once
#include<SFML/Graphics.hpp>

class Player
{
public:
	Player(sf::Vector2f pos);
	~Player();
	void Draw(sf::RenderWindow &window);
	void Update(float dt);

	void increaseRotation();
	void decreaseRotation();
	void SetSpeed(float s);

	void IncreaseSpeed();
	void DecreaseSpeed();

	sf::Vector2f getPosition();
	float getSpeed();
	float getRotation();

	sf::CircleShape getCircle();
private:
	sf::Vector2f position;
	float speed;

	sf::Vector2f velocity;
	sf::Texture texture;
	sf::Sprite sprite;
	float rotation;
	float orientation;

	sf::CircleShape m_circle;
	float radius;
};
