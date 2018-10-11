#include "Entity.h"
#include<iostream>
Entity::Entity(sf::Vector2f pos)
{
	position = pos;
	speed = 2.5f;

	if (!texture.loadFromFile("alien.png"))
	{

	}
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(0.2, 0.2);
	sprite.setOrigin(sprite.getGlobalBounds().width / 1.4, sprite.getGlobalBounds().height / 2);
	sprite.setRotation(0);
	rotation = 0;

	m_state = State::Pursue;


	

}

void Entity::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

void Entity::Update(float dt, sf::Vector2f playerPos, float playerSpeed, float PlayerRotation, sf::CircleShape cir)
{
	//std::cout << m_state << std::endl;

	if (sprite.getGlobalBounds().intersects(cir.getGlobalBounds()))
	{
		//do something
	}

	switch (m_state)
	{
	case State::Seek:
		Seek(playerPos);
		break;
	case State::Pursue:
		float x = (playerSpeed * cos(PlayerRotation *(acos(-1) / 180)));
		float y = (playerSpeed * sin(PlayerRotation *(acos(-1) / 180)));
		sf::Vector2f vel = sf::Vector2f(x,y);
		sf::Vector2f futurePos = playerPos + (vel * 60.0f);
		Seek(futurePos);
		break;

	}
	
	HandleBoundaries();

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
	rotation += 1;
	if (rotation >= 360)
	{
		rotation = 0;
	}
}

void Entity::decreaseRotation()
{
	rotation -= 1;
	if (rotation <= 0)
	{
		rotation = 359;
	}
}

void Entity::Seek(sf::Vector2f pos)
{

	//currentRotation = sprite.getRotation();

	float dx = pos.x - sprite.getPosition().x;
	float dy = pos.y - sprite.getPosition().y;


	rotation = atan2(dy, dx)*(180 / acos(-1));

	if (rotation < 0)
	{
		rotation = 360 - (-rotation);
	}




	//if ((static_cast<int>(std::round(rotation - currentRotation + 360))) % 360 < 180)
	//{
	//	increaseRotation();
	//}
	//else
	//{
	//	decreaseRotation();
	//}

	//std::cout << rotation << std::endl;
	sprite.setPosition((sprite.getPosition().x + cos(rotation*(acos(-1) / 180))*speed), (sprite.getPosition().y + sin(rotation*(acos(-1) / 180))*speed));
	sprite.setRotation(std::round(rotation));
}

void Entity::setState(int state)
{
	m_state = static_cast<State>(state);
}
