#pragma once

#include<SFML/Graphics.hpp>

struct PlayerOne
{
	PlayerOne();

	void draw(sf::RenderWindow& window);

	void MoveUp();
	void MoveDown();

	sf::Texture texture;
	sf::Sprite sprite;

	int window_size_x = 0;
	int window_size_y = 0;

	static constexpr float current_x = 5.f;
	float current_y = 60.f;
};