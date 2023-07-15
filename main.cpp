#include<SFML/Graphics.hpp>

#include "PlayerOne.h"
#include "PlayerTwo.h"
#include "Ball.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    PlayerOne player_one;
    PlayerTwo player_two;
    Ball ball;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
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
        ball.move(player_one, player_two);
        window.clear();
        if (!((ball.sprite.getPosition().x < 5) || (ball.sprite.getPosition().x > (window.getSize().x - ball.sprite.getGlobalBounds().width - 5))))
        {
            player_one.draw(window);
            player_two.draw(window);
            ball.draw(window);
        }
        window.display();
    }
}