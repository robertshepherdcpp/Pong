#include<SFML/Graphics.hpp>

#include "PlayerOne.h"
#include "PlayerTwo.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    PlayerOne player_one;
    PlayerTwo player_two;

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
        window.clear();
        player_one.draw(window);
        window.display();
    }
}