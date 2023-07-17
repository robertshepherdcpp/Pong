#include<SFML/Graphics.hpp>

#include<iostream>

#include "PlayerOne.h"
#include "PlayerTwo.h"
#include "Ball.h"
#include "Eatable.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Pong");

    PlayerOne player_one;
    PlayerTwo player_two;
    Ball ball;

    Eatable eatable_one(5);
    Eatable eatable_two(170);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                std::cout << player_one.score << " - " << player_two.score;
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::W)
                {
                    player_one.MoveUp();
                }
                else if (event.key.code == sf::Keyboard::S)
                {
                    player_one.MoveDown();
                }
                if (event.key.code == sf::Keyboard::I)
                {
                    player_two.MoveUp();
                }
                else if (event.key.code == sf::Keyboard::K)
                {
                    player_two.MoveDown();
                }
            }
        }

        if (eatable_one.sprite.getGlobalBounds().intersects(player_one.sprite.getGlobalBounds()))
        {
            eatable_one.SetHasBeenEaten();
            player_one.score += 1;
        }
        if (eatable_two.sprite.getGlobalBounds().intersects(player_two.sprite.getGlobalBounds()))
        {
            eatable_two.SetHasBeenEaten();
            player_two.score += 1;
        }

        ball.move(player_one, player_two);
        window.clear();
        if (!((ball.sprite.getPosition().x < 5) || (ball.sprite.getPosition().x > (window.getSize().x - ball.sprite.getGlobalBounds().width - 5))))
        {
            player_one.draw(window);
            player_two.draw(window);
            ball.draw(window);
        }
        eatable_one.draw(window);
        eatable_two.draw(window);
        window.display();
    }
}