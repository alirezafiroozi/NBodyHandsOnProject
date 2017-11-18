#ifndef ANIMATE_H
#define ANIMATE_H
#include <SFML/Graphics.hpp>
#include "system.h"
#include <constancts.h>

class Animate
{
public:
    Animate();
    void Run();
    void ProcessEvent();
    void Update();
    void Render();
    void Draw();
private:
    sf::RenderWindow window;
    sf::CircleShape mousePoint;
    sf::View view;
    sf::Vertex line[2];
    sf::Vector2f mousepos;
    System system;
    Planet planet;
    bool mouseIn;
    bool pause;
    double scaling;
};
std::string mouse_pos_string(sf::RenderWindow& window);

#endif // ANIMATE_H
