#include<SFML/Graphics.hpp>

#include "PlayerOne.h"

PlayerOne::PlayerOne()
{
	if (!texture.loadFromFile("PlayerOne.png"))
	{
		// deal with the error
	}
	sprite.setTexture(texture);
	sprite.setPosition(current_x, current_y);
}

void PlayerOne::draw(sf::RenderWindow& window)
{
	window_size_x = window.getSize().x;
	window_size_y = window.getSize().y;
	window.draw(sprite);
}

void PlayerOne::MoveUp()
{
	if (current_y > 4)
	{
		current_y -= 5;
		sprite.setPosition(current_x, current_y);
	}
}

void PlayerOne::MoveDown()
{
	if (current_y < (window_size_y - sprite.getGlobalBounds().height))
	{
		current_y += 5;
		sprite.setPosition(current_x, current_y);
	}
}
