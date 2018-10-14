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
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setRotation(0);
	rotation = 0;

	m_state = State::Pursue;

	srand(time(NULL));
	
	random = rand() % 90 + 0;
	random -= 45;

	if (!m_font.loadFromFile("arial.ttf"))
	{
		std::cout << "Font falied to load" << std::endl;
	}
	m_text.setFont(m_font);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(20);
	m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2);
	m_text.setString("State");

	switch (m_state)
	{
	case State::Arrive:
		m_text.setString("Arrive");
		break;
	case State::Pursue:
		m_text.setString("Pursue");
		break;
	case State::Seek:
		m_text.setString("Seek");
		break;
	case State::Wander:
		m_text.setString("Wander");
		break;
	default:
		break;
	}
}

void Entity::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
	window.draw(m_text);
}

void Entity::Update(float dt, sf::Vector2f playerPos, float playerSpeed, float playerRotation, sf::CircleShape cir, sf::CircleShape innerCir)
{

	m_text.setPosition(sprite.getPosition() + sf::Vector2f(0, -50));
	switch (m_state)
	{
	case State::Seek:
		Seek(playerPos);
		break;

	case State::Wander:
		Wander(playerPos);
		break;
	case State::Arrive:
		Seek(playerPos);
		if (sprite.getGlobalBounds().intersects(cir.getGlobalBounds()))
		{
			if (speed >= 1.5f)
			{
				decreaseSpeed();
			}
		}
		else
		{
			increaseSpeed();
		}

		if (sprite.getGlobalBounds().intersects(innerCir.getGlobalBounds()))
		{
			if (speed > 0)
			{
				decreaseSpeed();
			}
			
			if (speed < 0)
			{
				speed = 0;
			}
		}


		break;
	case State::Pursue:
		Pursue(playerPos,playerSpeed,playerRotation);
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
	if (speed < 4)
	{
		speed += 0.1;
	}
}

void Entity::decreaseSpeed()
{
	if (speed > -4)
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

	currentRotation = sprite.getRotation();


	float dx = pos.x - sprite.getPosition().x;
	float dy = pos.y - sprite.getPosition().y;


	rotation = atan2(dy, dx)*(180 / acos(-1));

	if (rotation < 0)
	{
		rotation = 360 - (-rotation);
	}

	sprite.setPosition((sprite.getPosition().x + cos(rotation*(acos(-1) / 180))*speed), (sprite.getPosition().y + sin(rotation*(acos(-1) / 180))*speed));
	sprite.setRotation(std::round(rotation));
}

void Entity::Wander(sf::Vector2f pos)
{
	currentRotation = sprite.getRotation();


	float dx = pos.x - sprite.getPosition().x;
	float dy = pos.y - sprite.getPosition().y;


	rotation = atan2(dy, dx)*(180 / acos(-1));

	if (rotation < 0)
	{
		rotation = 360 - (-rotation);
	}



	//random = random/100;

	rotation += random;
	std::cout << rotation << std::endl;
	sprite.setPosition((sprite.getPosition().x + cos(rotation*(acos(-1) / 180))*speed), (sprite.getPosition().y + sin(rotation*(acos(-1) / 180))*speed));
	sprite.setRotation(std::round(rotation));
}

void Entity::Pursue(sf::Vector2f pos, float theSpeed, float theRotation)
{
	float x = (theSpeed * cos(theRotation *(acos(-1) / 180)));
	float y = (theSpeed * sin(theRotation *(acos(-1) / 180)));
	sf::Vector2f vel = sf::Vector2f(x, y);
	sf::Vector2f futurePos = pos + (vel * 60.0f);
	Seek(futurePos);
}

void Entity::setState(int state)
{
	m_state = static_cast<State>(state);
	switch (m_state)
	{
	case State::Arrive:
		m_text.setString("Arrive");
		break;
	case State::Pursue:
		m_text.setString("Pursue");
		break;
	case State::Seek:
		m_text.setString("Seek");
		break;
	case State::Wander:
		m_text.setString("Wander");
		break;
	default:
		break;
	}
}