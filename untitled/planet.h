#ifndef PLANET_H
#define PLANET_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "math.h"

using namespace std;

class Planet
{
public:
    Planet();
    Planet(sf::Vector2f pos, sf::Vector2f vel,
           float mass, int radius, sf::Color col);
    void Step();
    void Draw(sf::RenderWindow& window);
    sf::Vector2f Force(Planet& other);
    Planet Speed();
    Planet Acceleration(sf::Vector2f force);
    void Collision(Planet& other);
    bool IsAlive();

private:
    sf::CircleShape planet;
    sf::Vector2f _vel;
    sf::Vector2f _acc;
    sf::Vector2f _force;
    sf::Vector2f _pos;
    sf::Color _col;
    float _mass;
    int _radius;
    bool _alive = true;
};

#endif // PLANET_H
