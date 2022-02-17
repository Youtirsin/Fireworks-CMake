#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "util/util.h"


const std::vector<sf::Color> color_list = { {244, 214, 215}, {55, 20, 88}, {151, 68, 114}, {230, 190, 146}, {244, 252, 255}, {230, 197, 246}, {181, 180, 222}, {191, 85, 177}, {255, 199, 209}, {200, 50, 66}, {223, 219, 216}, {158, 167, 164}, {173, 254, 255}, {185, 219, 149}, {72, 141, 235}, {252, 117, 249}, {232, 169, 180}, {155, 157, 170}, {182, 98, 130}, {248, 215, 20}, {136, 214, 253}, {221, 0, 27} };


inline sf::Color randColor()
{
	return color_list[rand(0, color_list.size())];
}


// physics
const float DELTA_T = 1 / 60.f;
const float G = 19.6;
const float PARTICLE_RESISTENCE = 9.8;


class Particle : public sf::CircleShape
{
public:
	Particle(sf::Color color, sf::Vector2f pos);
	void update(sf::Time elapsed);
	bool isAlive() const
	{
		return this->alive;
	}
private:
	float vx;
	float vy;
	bool alive;
	sf::Time age;
	float life_time;
};


void addParticle(std::vector<Particle>& grp, sf::Color color, sf::Vector2f pos);


class Fireworks : public sf::CircleShape
{
public:
	Fireworks(sf::Color color, float y_, float x_top);
	void update();
	inline void explore(std::vector<Particle>& grp)
	{
		addParticle(grp, this->getFillColor(), this->getPosition());
	}
	bool isAlive() const
	{
		return this->alive;
	}
private:
	float vy;
	bool alive;
};
