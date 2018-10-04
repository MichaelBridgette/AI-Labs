#include "Entity.h"
#include<iostream>
Entity::Entity(sf::Vector2f pos, sf::Vector2f vel)
{
	position = pos;
	velocity = vel;

	if (!texture.loadFromFile("F5S4.png"))
	{

	}
	sprite.setTexture(texture);
	sprite.setPosition(pos);
}

void Entity::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

void Entity::Update(float dt)
{

	
	sprite.setPosition(sprite.getPosition().x + velocity.x, sprite.getPosition().y + velocity.y);

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

void Entity::increaseVelocityX()
{
	if (velocity.x < 1)
	{
		velocity.x += 0.01f;
	}
}

void Entity::decreaseVelocityX()
{
	if (velocity.x > 0)
	{
		velocity.x -= 0.01f;
	}
}

void Entity::increaseVelocityY()
{
	if (velocity.y < 1)
	{
		velocity.y += 0.01f;
	}
}

void Entity::decreaseVelocityY()
{
	if (velocity.y > 0)
	{
		velocity.y -= 0.01f;
	}
}
