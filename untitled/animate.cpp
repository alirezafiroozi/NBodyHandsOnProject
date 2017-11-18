#include "animate.h"

Animate::Animate()
{
    //creates window
    window.create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Gavity");
    window.setFramerateLimit(FRAME_RATE);

    scaling = 1;

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
    mousePoint.setPosition(sf::Vector2f(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y));

    //=====================END OF ANIMATE CTOR=============================
}

void Animate::ProcessEvent(){
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
                scaling++;
                if(scaling >= 4){
                    scaling = 4;
                }else{
                    view.zoom(2.0);
                }
                cout << "scaling:" << scaling << endl;
                window.setView(view);break;
            case sf::Keyboard::S:
                scaling--;
                if(scaling <= -1){
                    scaling = -1;
                }else{
                    view.zoom(0.5);
                }
                cout << "scaling:" << scaling << endl;
                window.setView(view);break;
            case sf::Keyboard::P:
                pause = !pause;break;
            }
            break;
        case sf::Event::MouseButtonPressed:{
            sf::Vector2f mouse_coord = sf::Vector2f(mousePoint.getPosition().x, mousePoint.getPosition().y);

            cout << "Mouse Coord:" << mouse_coord.x << "," << mouse_coord.y << endl;

//            sf::Vector2f world_coord = window.mapPixelToCoords(mouse_coord);

//            cout << "World Coord:" << world_coord.x << "," << world_coord.y << endl;

            sf::Vector2f vel(1,0);

            Planet p(world_coord, vel, 500, 50, sf::Color::Blue);
            system.Insert(p);

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                line[0] = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                while(sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Event::MouseMoved){
                    line[1] = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                    window.clear();
                    Draw();
                    window.draw(line, 2, sf::Lines);
                    window.display();
                }
            }
        }
        }
    }
}

void Animate::Run(){
    cout << "------------------Gravity Start----------------------" << endl;

    while(window.isOpen()){
        ProcessEvent();
        Update();
        Render();
    }

    cout << "------------------Gravity End----------------------" << endl;

}

void Animate::Draw(){
    system.Draw(window);

    if(mouseIn){
        window.draw(mousePoint);
    }
    //draw the planets
}


void Animate::Update(){
    if(mouseIn){
        mousePoint.setPosition(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
    }

    mousepos = window.mapPixelToCoords(sf::Mouse::getPosition());
    view.setCenter(mousepos);

}

void Animate::Render(){
    window.clear();
    Draw();
    window.display();
}

string mouse_pos_string(sf::RenderWindow &window){

}
