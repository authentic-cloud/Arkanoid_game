#include "ball.h"
#include <iostream>

Ball::Ball(float X, float Y,const Player &player):player1(player)
{
    setRadius(25.f);
    setPosition(X,Y);
    setFillColor(sf::Color(200,100,100));

    int col1 = rand() % 300;
    int col2 = rand() % 300;
    int col3 = rand() % 300;
    setFillColor(sf::Color(col1,col2,col3));
}

//Ball(const Player &first_player, const Player &second_player)
//    : sf::CircleShape(10), player1(first_player),
//      second_player_(second_player) {
//  set||igin(5, 5);
//  setPosition(400, 300);
//}

//bool Ball::step(float elapsed){
//    auto bounding_box = getGlobalBounds();

//    if (bounding_box.left <= 0 ||
//        bounding_box.left + bounding_box.width >= 800) {
//      return false;
//    }

//    move(speed*elapsed);
//}

bool Ball::step(float elapsed) {
  auto bounding_box = getGlobalBounds();

  if (/*bounding_box.top <= 0 ||*/
      bounding_box.top + bounding_box.height >= 600) {
    return false;
  }

  if (bounding_box.intersects(player1.getGlobalBounds())) {
    speed.y = -std::abs(speed.y);
//    std::cout<<"intersects";
  }
//  } else if (bounding_box.intersects(second_player_.getGlobalBounds())) {
//    speed.x = -std::abs(speed.x);
//  }

  if (bounding_box.top <= 0) {
    speed.y = std::abs(speed.y);
  } else if (bounding_box.left  + bounding_box.width>= 800) {
    speed.x = -std::abs(speed.x);
  } else if (bounding_box.left <=0) {
  speed.x = std::abs(speed.x);
}

  move(speed.x * elapsed, speed.y * elapsed);
  return true;
}

//void Ball::reverseSpeed() const
//{

//}

void Ball::reverseSpeed(){
    speed.y = std::abs(speed.y);
    speed.x = std::abs(speed.x);
}
