#include"Player.h"
#include<iostream>
Player::Player(sf::Vector2f pos)
{
	position = pos;
	speed = 0;
	if (!texture.loadFromFile("F5S4.png"))
	{

	}
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setOrigin(sprite.getGlobalBounds().width / 1.4,sprite.getGlobalBounds().height / 2);
	sprite.setRotation(0);
	sprite.setScale(0.4, 0.4);
	rotation = 0;
	orientation = 0;
}

Player::~Player()
{
}

void Player::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

void Player::Update(float dt)
{
	//sprite.setPosition(sprite.getPosition().x + velocity.x, sprite.getPosition().y + velocity.y);

	sprite.setPosition((sprite.getPosition().x + cos(rotation*(acos(-1)/180))*speed), (sprite.getPosition().y + sin(rotation*(acos(-1) / 180))*speed));
	//orientation += rotation * dt;
	//sprite.setRotation(atan2(velocity.x, velocity.y));
	sprite.setRotation(rotation);


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

void Player::increaseVelocityX()
{
	if (velocity.x < 0.5)
	{
		velocity.x += 0.01f;
	}
}

void Player::decreaseVelocityX()
{
	if (velocity.x > -0.5)
	{
		velocity.x -= 0.01f;
	}
}

void Player::increaseVelocityY()
{
	if (velocity.y < 0.5)
	{
		 velocity.y+= 0.01f;
	}
}

void Player::decreaseVelocityY()
{
	if (velocity.y > -0.5)
	{
		velocity.y -= 0.01f;
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
