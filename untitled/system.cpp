#include "system.h"
#include <iostream>

using namespace std;

System::System()
{
//    cout << "System CTOR got called\n";
    Planet planet;


//    sf::Vector2f pos(140 * pow(10, 6), 0);
//    sf::Vector2f vel(-4000, -4000);
//    float massE = 5.97 * pow(10,23);
//    sf::Color colE(sf::Color::Blue);
//    Planet Earth(pos, vel, massE, 6378000, colE);
//    planetVector.push_back(Earth);

//    sf::Vector2f posM(100 * pow(10, 6), 0);
//    sf::Vector2f velM(-4000, -4000);
//    float massM = 3.3 * pow(10,3);
//    sf::Color colM(sf::Color::White);
//    Planet Mercury(posM, velM, massM, 2440000, colM);
//    planetVector.push_back(Mercury);

//    sf::Vector2f posS(0, 0);
//    sf::Vector2f velS(0, 0);
//    float massS = 1.99 * pow(10,30);
//    sf::Color colS(sf::Color::Yellow);
//    Planet Sun(posS, velS, massS, 6950000, colS);
//    planetVector.push_back(Sun);




//    sf::Vector2f pos(140 * pow(10, 6), 0);
//    sf::Vector2f vel(400, 400);
//    float massE = 5.97 * pow(10,23);
//    sf::Color colE(sf::Color::Blue);
//    Planet Earth(pos, vel, massE, 6378000, colE);
//    planetVector.push_back(Earth);

//    sf::Vector2f posS(0, 0);
//    sf::Vector2f velS(0, 0);
//    float massS = 1.99 * pow(10,30);
//    sf::Color colS(sf::Color::Yellow);
//    Planet Sun(posS, velS, massS, 6950000, colS);
//    planetVector.push_back(Sun);

//    sf::Vector2f posM(57 * pow(10, 6), 0);
////    sf::Vector2f velM(0, 0);
//    float massM = 3.3 * pow(10,3);
//    sf::Color colM(sf::Color::White);
//    Planet Mercury(posM, velS, massM, 2440000, colM);
//    planetVector.push_back(Mercury);
////    float xe = 149.6 * pow(10, 6);
////    float ye = pow(10, 6);
//    float masss = pow(10, 5);
//    sf::Color cols(sf::Color::Yellow);
//    Planet Sun(0, 0, 0, 0, masss, 50, cols);
//    planetVector.push_back(Sun);

    //NEEDS TO GET COMPLETED

    cout << "System CTOR END!\n";

}

void System::Draw(sf::RenderWindow &window)
{
    vector<Planet>::iterator it = planetVector.begin();
//    int size = planetVector.size();
    for(int i = 0; i < planetVector.size(); i++)
    {
        if(!it[i].IsAlive())
        {
//            cout << "\nDRAW:: alive: " << it[i].isalive();
            planetVector.erase(it + i);
            it = planetVector.begin();
            break;
        }
        for(int n = 0; n < planetVector.size(); n++)
        {
            if(n != i)
            {
                it[i].Acceleration(it[i].Force(it[n]));
                it[i].Collision(it[n]);
            }
        }
        it[i].Speed();
        it[i].Step();
        it[i].Draw(window);
    }
}

void System::Insert(Planet planet)
{
//    Planet p(planet);
    planetVector.push_back(planet);
}
