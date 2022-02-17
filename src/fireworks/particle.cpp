#include "fireworks/fireworks.h"

Particle::Particle(sf::Color color, sf::Vector2f pos) :
	sf::CircleShape(4.f)
{
	this->alive = true;
	this->age = sf::Time::Zero;
	this->life_time = rand(10, 20) / 10.f;

	this->setFillColor(color);

	this->setPosition(pos);

	float momentum = rand(30, 40);
	float angle = rand(0, 360);

	this->vx = momentum * cos(angle);
	this->vy = momentum * sin(angle);
}


void Particle::update(sf::Time elapsed)
{
	if (this->alive)
	{
		this->move(vx * DELTA_T, vy * DELTA_T);
		this->vy += PARTICLE_RESISTENCE * DELTA_T;

		this->age += elapsed;

		if (this->age.asSeconds() >= this->life_time)
		{
			this->alive = false;
		}
	}
}
