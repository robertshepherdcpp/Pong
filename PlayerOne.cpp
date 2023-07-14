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
	window.draw(sprite);
}

void PlayerOne::MoveUp()
{
	current_y += 5;
}

void PlayerOne::MoveDown()
{
	if (current_y > 4)
	{
		current_y -= 5;
	}
}
