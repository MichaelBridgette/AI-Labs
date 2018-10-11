#include"Player.h"
#include<iostream>
Player::Player(sf::Vector2f pos)
{
	position = pos;
	speed = 0;
	if (!texture.loadFromFile("rsH6n.png"))
	{

	}
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setOrigin(sprite.getGlobalBounds().width / 1.4,sprite.getGlobalBounds().height / 2);
	sprite.setRotation(0);
	sprite.setScale(0.2, 0.2);
	rotation = 0;
	orientation = 0;


	radius = 250;
	m_circle.setPosition(pos);
	m_circle.setRadius(radius);
	m_circle.setOutlineColor(sf::Color::Blue);
	m_circle.setOutlineThickness(1);
	m_circle.setFillColor(sf::Color::Transparent);
	m_circle.setOrigin(radius,radius);
}

Player::~Player()
{
}

void Player::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
	window.draw(m_circle);
}

void Player::Update(float dt)
{
	//sprite.setPosition(sprite.getPosition().x + velocity.x, sprite.getPosition().y + velocity.y);

	sprite.setPosition((sprite.getPosition().x + cos(rotation*(acos(-1)/180))*speed), (sprite.getPosition().y + sin(rotation*(acos(-1) / 180))*speed));
	//orientation += rotation * dt;
	//sprite.setRotation(atan2(velocity.x, velocity.y));
	sprite.setRotation(rotation);
	m_circle.setPosition(sprite.getPosition());


	if (sprite.getPosition().x > 1920)
	{
		sprite.setPosition(-300, sprite.getPosition().y);
	}

	if (sprite.getPosition().y > 1080)
	{
		sprite.setPosition(sprite.getPosition().x, -300);
	}

	if (sprite.getPosition().x < -300)
	{
		sprite.setPosition(1920, sprite.getPosition().y);
	}

	if (sprite.getPosition().y < -300)
	{
		sprite.setPosition(sprite.getPosition().x, 1080);
	}

	
}

void Player::increaseRotation()
{
	rotation += 5;
	if (rotation >= 360)
	{
		rotation = 0;
	}
}

void Player::decreaseRotation()
{
	rotation -= 5;
	if (rotation <= 0)
	{
		rotation = 359;
	}
}

void Player::SetSpeed(float s)
{
	speed = s;
}

void Player::IncreaseSpeed()
{
	if (speed < 5)
	{
		speed += 0.1;
	}
}

void Player::DecreaseSpeed()
{
	if (speed > -5)
	{
		speed -= 0.1;
	}
}

sf::Vector2f Player::getPosition()
{
	return sprite.getPosition();
}

float Player::getSpeed()
{
	return speed;
}

float Player::getRotation()
{
	return rotation;
}

sf::CircleShape Player::getCircle()
{
	return m_circle;
}
