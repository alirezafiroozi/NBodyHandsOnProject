#include "animate.h"

Animate::Animate()
{
    //creates window
    window.create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT, "Gavity"));
    window.setFramerateLimit(FRAME_RATE);

    //initialize color for the line
    line[0].color = sf::Color::White;
    line[1].color = sf::Color::White;

    //set up view
    view = sf::View(window.getDefaultView());
    window.setView(view);

    //sets up mouse cursor
    mouseIn = true;
    mousePoint = sf::CircleShape(2.0);
    mousePoint.setFillColor(sf::Color::Cyan);

    //=====================END OF ANIMATE CTOR=============================
}

Animate::ProcessEvent(){
    sf::Event event;
    while(window.pollEvent(event)){
        switch(event.type){
        case sf::Event::Closed:
            window.close();break;
        case sf::Event::MouseEntered:
            mouseIn = true;break;
        case sf::Event::MouseLeft:
            mouseIn = false;break;
        case sf::Event::MouseMoved:
            mousePoint.getPosition();break;
        case sf::Event::KeyPressed:
            switch(event.key.code){
            case sf::Keyboard::Escape:
                window.close();
            case sf::Keyboard::A:
                view.zoom(2.0f);
                window.setView(view);break;
            case sf::Keyboard::S:
                view.zoom(0.5f);
                window.setView(view);break;
            case sf::Keyboard::P:
                pause = !pause;break;            }
        }
        case sf::Event::MouseButtonPressed:{
            sf::Vector2i mouse_coord = sf::Vector2i(mousePoint.getPosition().x, mousePoint.getPosition().y);

            cout << "Mouse Coord:" << mouse_coord.x << "," << mouse_coord.y << endl;

            sf::Vector2f world_coord = window.mapPixelToCoords(mouse_coord);

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                while(sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Event::MouseMoved){

                }
            }
        }
    }
}

Animate::Run(){
    cout << "------------------Gravity Start----------------------" << endl;

    while(window.isOpen()){
        ProcessEvent();
        Update();
        Render();
    }

    cout << "------------------Gravity End----------------------" << endl;

}
