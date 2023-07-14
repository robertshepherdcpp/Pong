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
};