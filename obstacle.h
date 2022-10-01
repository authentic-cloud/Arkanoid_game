#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "ball.h"
#include <vector>
class Obstacle: public sf::RectangleShape
{
public:
    Obstacle( std::vector<Ball> &balls);
    void step(float elapsed);

    bool getLive() {return life;}
private:
    float angle =45.f;
    float rot_speed=25;

    bool life=1;
     std::vector<Ball> &balls1;

};

#endif // OBSTACLE_H
