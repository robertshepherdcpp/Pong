#include<SFML/Graphics.hpp>

#include<random>
#include<iostream>

#include "Eatable.h"

Eatable::Eatable(int x)
{
	random_x = x;
	texture.loadFromFile("fruit.png");
	sprite.setTexture(texture);
}

void Eatable::draw(sf::RenderWindow& window)
{
	window_size = window.getSize();
	window_size_x = window_size.x - sprite.getGlobalBounds().width * 2;
	window_size_y = window_size.y - sprite.getGlobalBounds().height * 2;
	if (should_be_hidden == false)
	{
		random_position();
		sprite.setPosition(random_x, random_y);
		window.draw(sprite);
	}
}

void Eatable::random_position()
{
	if (has_been_eaten)
	{
		std::random_device dev_two;
		std::mt19937 rng_two(dev_two());
		std::uniform_int_distribution<std::mt19937::result_type> dist6_two(0, window_size_y);
		random_y = dist6_two(rng_two);
		has_been_eaten = false;

		std::cout << "(" << random_x << ", " << random_y << ")\n";
	}
	else
	{
		// do nothing as we already have our random number
	}
}

bool Eatable::HasBeenEaten()
{
	return has_been_eaten;
}

void Eatable::SetHasBeenEaten()
{
	has_been_eaten = true;
	std::cout << "Fruit has been eaten\n";
}

void Eatable::Hide()
{
	should_be_hidden = true;
}