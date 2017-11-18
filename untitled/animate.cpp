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
    mousepos = window.mapPixelToCoords(sf::Mouse::getPosition());
    view.setCenter(mousepos);
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

            cout << "World Coord:" << world_coord.x << "," << world_coord.y << endl;

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                line[0] = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
                while(sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Event::MouseMoved){
                    line[1] = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
                    window.clear();
                    Draw();
                    window.draw(line, 2, sf::Lines);
                    window.display();
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

Animate::Draw(){
    system.Draw(window);
    if(mouseIn){
        window.draw(mousePoint);
    }
    //draw the planets
}


Animate::Update(){
    if(mouseIn){
        mousePoint.setPosition(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
    }

    mousepos = window.mapPixelToCoords(sf::Mouse::getPosition());
    view.setCenter(mousepos);

}

Animate::Render(){
    window.clear();
    Draw();
    window.display();
}
