#include "player.h"
#include<iostream>

Player::Player(float X, float Y)
{
 setSize(sf::Vector2f(140,30));
 setPosition(X,Y);
 setFillColor(sf::Color(100,100,100));
}

void Player::step(float elapsed){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        move(speed*elapsed,0);
//        std::cout<<speed*elapsed<<std::endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        move(-speed*elapsed,0);
}
