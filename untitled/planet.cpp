#include "planet.h"

Planet::Planet()
{

}

Planet::Planet(sf::Vector2f pos, sf::Vector2f vel,
               float mass, int radius, sf::Color col):
    _pos(pos), _vel(vel), _mass(mass), _radius(radius) ,_col(col)
{
    planet.setRadius(_radius);
    planet.setFillColor(_col);
    planet.setPosition(_pos);
    planet.setOrigin(sf::Vector2f(_radius, _radius));
    _alive = true;
}

void Planet::Step()
{

}

void Planet::Draw()
{

}

sf::Vector2f Planet::Force(Planet& other)
{

}

Planet Planet::Speed()
{

}

Planet Planet::Acceleration()
{

}

void Planet::Collision(Planet& other)
{

}

bool Planet::IsAlive()
{

}
