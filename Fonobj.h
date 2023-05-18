#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"

class Fonobj {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Fonobj() {
		texture.loadFromFile(Fon_File_Name);
		sprite.setTexture(texture);
		sprite.setPosition(0, 0);
	}
	void update() {}
	sf::Sprite& getSprite() { return sprite; }
};