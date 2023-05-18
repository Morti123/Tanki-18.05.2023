#pragma once
#include "settings.h"
#include "Player1.h"
#include "Player2.h"
class Bonus {
public:
	enum BonusType { RAGE, MEDKIT, SPEED_BOOST };
	Bonus(sf::Vector2f BoxPos, size_t bonustype);
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
	void update();
	void setDel();
	bool isToDel();
	void draw(sf::RenderWindow& window);
	bool offScreen();
	void act_1(Player1& player_1);
	void act_2(Player2& player_2);
private:
	sf::Sprite sprite;
	sf::Texture texture;
	BonusType type;
	sf::Clock timer;
	bool del = false;
};

Bonus::Bonus(sf::Vector2f BoxPos, size_t bonusType) {
	type = (BonusType)bonusType;
	switch (type) {
	case RAGE:
		this->type = type;
		texture.loadFromFile(RAGE_FILE_NAME);
		break;

	case MEDKIT:
		this->type = type;
		texture.loadFromFile(MEDKIT_FILE_NAME);
		break;

	case  SPEED_BOOST:
		this->type = type;
		texture.loadFromFile(SPEED_BOOST_FILE_NAME);
		break;
	}
	sprite.setTexture(texture);
	sprite.setPosition(BoxPos);
	timer.restart();
}

void Bonus::update() {
	int now = timer.getElapsedTime().asMilliseconds();
	if (now > 5000) {
		del = true;
	}
}

void Bonus::draw(sf::RenderWindow& window) { window.draw(sprite); }

sf::FloatRect Bonus::getHitBox() { return sprite.getGlobalBounds(); }

sf::Vector2f Bonus::getPosition() { return sprite.getPosition(); }

bool Bonus::isToDel() { return del; }

void Bonus::setDel() { del = true; }

void Bonus::act_1(Player1& player_1) {
	switch (type) {
	case  RAGE:

		break;
	case MEDKIT:
		player_1.HP_UP(50);
		break;
	case SPEED_BOOST:
		player_1.Speed_Boost();
		break;
	}
}
void Bonus::act_2(Player2& player_2) {
	switch (type) {
	case  RAGE:

		break;
	case MEDKIT:
		player_2.HP_UP(50);
		break;
	case SPEED_BOOST:
		player_2.Speed_Boost();
		break;
	}
}