#include<SFML/Graphics.hpp>

#include "Ball.h"

Ball::Ball()
{
	if (!texture.loadFromFile("pong_ball.png"))
	{
		// handle the error
	}
	sprite.setTexture(texture);
	current_x = 80.f;
	current_y = 60.f;

	sprite.setPosition(current_x, current_y);
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Ball::move(PlayerOne& first_player, PlayerTwo& second_player)
{
	if (sprite.getGlobalBounds().intersects(first_player.sprite.getGlobalBounds()) || sprite.getGlobalBounds().intersects(second_player.sprite.getGlobalBounds()))
	{
		if (current_direction == 1)
		{
			current_direction = 2;
		}
		else if (current_direction == 2)
		{
			current_direction = 1;
		}
	}
	if (current_direction == 1)
	{
		current_x += 0.1f;
		sprite.setPosition(current_x, current_y);
	}
	else if (current_direction == 2)
	{
		current_x -= 0.1f;
		sprite.setPosition(current_x, current_y);
	}
}
