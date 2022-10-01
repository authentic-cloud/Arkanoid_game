#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Player: public sf::RectangleShape
{
public:
    Player(float X, float Y);
    void step(float elapsed);
private:
    float speed=350;
};

#endif // PLAYER_H
