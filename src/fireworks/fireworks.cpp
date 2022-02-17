#include "fireworks.h"


void addParticle(std::vector<Particle>& grp, sf::Color color, sf::Vector2f pos)
{
	int n = rand(20, 40);
	bool colorful = rand(0, 2) == 1;

	for (int i = 0; i < n; i++)
	{
		if (colorful)
		{
			grp.emplace_back(randColor(), pos);
		}
		else
		{
			grp.emplace_back(color, pos);
		}
	}
}


Fireworks::Fireworks(sf::Color color, float y_, float x_top) :
	sf::CircleShape(8.f)
{
	this->alive = true;
	this->vy = -rand(100, 150);
	this->setFillColor(color);
	this->setPosition(rand(0, int(x_top) - 15), y_);
}


void Fireworks::update()
{
	if (this->alive)
	{
		this->move(0, vy * DELTA_T);
		this->vy += G * DELTA_T;
		if (this->vy > -1)
		{
			this->alive = false;
		}
	}
}