#include "obstacle.h"
#include <iostream>

Obstacle::Obstacle( std::vector<Ball> &balls):balls1(balls)
{
    int x = rand() % 800;
    int y = rand() % 600;


    setPosition(x,y);

    setSize(sf::Vector2f(60,30));
    setOrigin(30,15);

    int col1 = rand() % 300;
    int col2 = rand() % 300;
    int col3 = rand() % 300;
    setFillColor(sf::Color(col1,col2,col3));
}

void Obstacle::step(float elapsed){
    angle += rot_speed * elapsed;
    this->setRotation(angle);
//    std::cout<<angle<<std::endl;

    auto bounding_box = getGlobalBounds();

    for(auto &it : balls1){
        if (bounding_box.intersects(it.getGlobalBounds())) {
          it.reverseSpeed();
          life = false;
        }
    }
}
