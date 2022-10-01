#include "player.h"
#include "ball.h"
#include "obstacle.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>
int main() {
    std::srand(std::time(nullptr));

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    Player player(800-100,600-15);
    Ball ball(100,100,player);


    std::vector<Ball> balls;
    Ball ball1(100,200,player);
    Ball ball2(200,100,player);
    Ball ball3(100,200,player);

    balls.push_back(ball1);
    balls.push_back(ball2);
    balls.push_back(ball3);

    sf::Clock clock; float elapsed;
    sf::Clock spawnClock; float spawnTime=10;

    std::vector<Obstacle> obstacles;



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

//        if(spawnTime>=2){

//    //        std::cout<<spawnTime<<std::endl;
//            spawnTime=0;
//        }

    player.step(elapsed);


        window.clear(sf::Color::Black);

        window.draw(player);
        window.draw(ball);

        if (ball.step(elapsed) == false) {
          break;
        }

        for(auto & it: obstacles){
            if(it.getLive()){
                window.draw(it);
                it.step(elapsed);
            }
        }

        for(auto & it: balls){
                window.draw(it);
                it.step(elapsed);
        }

        window.display();
        elapsed = clock.restart().asSeconds();

        if(spawnTime>=5){
            spawnClock.restart();
            Obstacle obstacle1(balls);
            obstacles.push_back(obstacle1);
        }
        spawnTime = spawnClock.getElapsedTime().asSeconds();

//       std::cout<<obstacles.size()<<std::endl;
//        std::cout<<spawnTime<<std::endl;
    }

    return 0;
}
