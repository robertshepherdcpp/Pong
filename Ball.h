#pragma once

#include<SFML/Graphics.hpp>

#include "PlayerOne.h"
#include "PlayerTwo.h"

struct Ball
{
	Ball();

	void draw(sf::RenderWindow& window);
	void move(PlayerOne& first_player, PlayerTwo& second_player);

	sf::Texture texture;
	sf::Sprite sprite;

	int current_direction = 1;
	// 1 = Forwards
    // 2 = Backwards

	float current_x = 0;
	float current_y = 0;
};