#include<SFML/Graphics.hpp>

#include "PlayerTwo.h"

PlayerTwo::PlayerTwo()
{
	if (!texture.loadFromFile("PlayerOne.png"))
	{
		// deal with the error
	}
	sprite.setTexture(texture);
	sprite.setPosition(current_x, current_y);
}

void PlayerTwo::draw(sf::RenderWindow& window)
{
	window_size_x = window.getSize().x;
	window_size_y = window.getSize().y;
	current_x = window.getSize().x - sprite.getGlobalBounds().width - 5;
	window.draw(sprite);
}

void PlayerTwo::MoveUp()
{
	if (current_y > 4)
	{
		current_y -= 5;
		sprite.setPosition(current_x, current_y);
	}
}

void PlayerTwo::MoveDown()
{
	if (current_y < (window_size_y - sprite.getGlobalBounds().height))
	{
		current_y += 5;
		sprite.setPosition(current_x, current_y);
	}
}