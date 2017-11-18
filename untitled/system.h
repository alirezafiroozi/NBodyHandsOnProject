#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <iostream>
#include "planet.h"

using namespace std;

class System
{
public:
    System();
    void Draw(sf::RenderWindow& window);
    void Insert(Planet planet);

private:
    vector<Planet> planetVector;
};

#endif // SYSTEM_H
