#ifndef BALL_H
#define BALL_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "player.h"


class Ball: public sf::CircleShape
{
public:
    Ball(float X, float Y,const Player &player1);
    bool step(float elapsed);

    void reverseSpeed();

private:
    sf::Vector2f speed =sf::Vector2f(100,100);
    const Player & player1;


};


#endif // BALL_H
