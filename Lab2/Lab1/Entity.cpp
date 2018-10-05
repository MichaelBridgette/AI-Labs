#include "Entity.h"
#include<iostream>
Entity::Entity(sf::Vector2f pos)
{
	position = pos;
	speed = 1;

	if (!texture.loadFromFile("F5S4.png"))
	{

	}
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(0.4, 0.4);
	sprite.setOrigin(sprite.getGlobalBounds().width / 1.4, sprite.getGlobalBounds().height / 2);
	sprite.setRotation(0);
	rotation = 0;

	state = State::Wander;

}

void Entity::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

void Entity::Update(float dt, sf::Vector2f playerPos)
{
	switch (state)
	{
	case State::Wander:
		float dx = playerPos.x - sprite.getPosition().x;
		float dy = playerPos.y - sprite.getPosition().y;


			rotation = atan2(dy, dx)*(180 / acos(-1));

			if (rotation < 0)
			{
				rotation = 360 - (-rotation);
			}
			sprite.setPosition((sprite.getPosition().x + cos(rotation*(acos(-1) / 180))*speed), (sprite.getPosition().y + sin(rotation*(acos(-1) / 180))*speed));
			sprite.setRotation(rotation);
			std::cout << rotation << std::endl;
		break;
	}
	
	//sprite.setPosition((sprite.getPosition().x + cos(rotation*(acos(-1) / 180))*speed), (sprite.getPosition().y + sin(rotation*(acos(-1) / 180))*speed));
	//sprite.setRotation(rotation);
	HandleBoundaries();

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

void Entity::HandleBoundaries()
{
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

void Entity::increaseSpeed()
{
	if (speed < 10)
	{
		speed += 0.1;
	}
}

void Entity::decreaseSpeed()
{
	if (speed > -10)
	{
		speed -= 0.1;
	}
}

void Entity::increaseRotation()
{
	rotation += 5;
	if (rotation >= 360)
	{
		rotation = 0;
	}
}

void Entity::decreaseRotation()
{
	rotation -= 5;
	if (rotation <= 0)
	{
		rotation = 359;
	}
}
