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
    _pos.x += _vel.x;
    _pos.y += _vel.y;
    _acc.x = 0;
    _acc.y = 0;
    planet.setPosition(_pos);

}

void Planet::Draw()
{
    window.draw(planet);
}

sf::Vector2f Planet::Force(Planet& other)
{
    sf::Vector2f temp;
    double d = sqrt(pow(_pos.x - other._pos.x, 2)
                    + pow(_pos.y - other._pos.y, 2));
    if(d == 0)
    {
        temp.x = 0;
        temp.y = 0;
        return temp;
    }
    double force_temp = (/*G */  _mass * other._mass) / pow(d,2);
    temp.x = force_temp * (_pos.x - other._pos.x) * -1 / d;
    temp.y = force_temp * (_pos.y - other._pos.y) * -1 / d;
    return temp;
}

Planet Planet::Speed()
{
    _vel.x = (_vel.x + _acc.x);
    _vel.y = (_vel.y + _acc.y);
    return *this;
}

Planet Planet::Acceleration()
{
    _acc.x = force.x/_mass;
    _acc.y = force.y/_mass;
    return *this;
}

void Planet::Collision(Planet& other)
{

}

bool Planet::IsAlive()
{
    return _alive;
}
