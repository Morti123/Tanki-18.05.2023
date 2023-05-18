#pragma once
#include "settings.h"

class Box {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f speed;
	int damage, Up;
public:
	enum BoxSize { BOX, MisteryBox, STONE };
	Box(std::string fileName, BoxSize size, sf::Vector2f pos) {
		texture.loadFromFile(fileName);
		sprite.setTexture(texture);
		sprite.setPosition(pos);
	}

	void update() {}

	sf::Sprite& getSprite() { return sprite; }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
	sf::Vector2f getPosition();
};
sf::Vector2f Box::getPosition() { return sprite.getPosition(); }