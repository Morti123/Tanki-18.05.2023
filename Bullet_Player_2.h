#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
class Bullet_2 {
private: sf::Sprite sprite;
	   sf::Texture texture;
	   float speedx, speedy;
	   bool a_hit;
	   int damage;
public:
	Bullet_2(sf::Vector2f playerPos, int playerAngle) {
		texture.loadFromFile(Bullet_2_File_Name);
		sprite.setTexture(texture);
		sprite.setRotation(playerAngle);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(playerPos);
		speedx = Bullet_speed * sin(playerAngle * PI / 180);
		speedy = -Bullet_speed * cos(playerAngle * PI / 180);
		a_hit = false;
		damage = Bullet_damage;
	}
	void update() {
		sprite.move(speedx, speedy);
	}
	sf::Sprite& getSprite() { return sprite; }
	auto getHitBox() { return sprite.getGlobalBounds(); }
	void hit() { a_hit = true; }
	bool getHit() { return a_hit; }
	auto getPosition() { return sprite.getPosition(); }
	int getDamage() { return damage; }
};
