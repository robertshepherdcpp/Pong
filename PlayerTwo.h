#pragma once

#include<SFML/Graphics.hpp>

struct PlayerTwo
{
	PlayerTwo();

	void draw(sf::RenderWindow& window);

	void MoveUp();
	void MoveDown();

	sf::Texture texture;
	sf::Sprite sprite;

	int window_size_x = 0;
	int window_size_y = 0;

	float current_x = 120.f;
	float current_y = 60.f;
};