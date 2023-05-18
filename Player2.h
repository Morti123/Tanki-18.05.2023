#pragma once
#include "GameObj.h"
#include "cmath"
#include <list>
#include "Bullet_Player_2.h"
#include "textobj_2.h"

class Player2 : public GameObj {
private:
	float angle;
	float speed, speedx, speedy;
	int cd = fire_cooldown;
	std::list<Bullet_2*> bullet_2;
	sf::Clock timer;
	int damage;
	bool speed_bonus_act = false;
	int speed_bonus_act_time;
public:
	int hp_2 = Player_max_hp;
	Player2() {
		texture.loadFromFile(Player_2_File_Name);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(WINDOW_WIDTH - WINDOW_WIDTH / 15, WINDOW_HEIGHT / 2);
		angle = 0.f;
		damage = 25;
	}
	void update() {
		speed = 0.f;
		for (int i = 0; i < 5; i++) {
			angle += 0.5;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			for (int i = 0; i < 5; i++) {
				angle -= 0.5;
			}
			speed += dv;
		}
		sprite.setRotation(angle);
		if (sprite.getPosition().x <= 0 + Fon_offset) {
			sprite.setPosition(0 + Fon_offset, sprite.getPosition().y);
		}
		if (sprite.getPosition().x >= WINDOW_WIDTH - Fon_offset) {
			sprite.setPosition(WINDOW_WIDTH - Fon_offset, sprite.getPosition().y);
		}
		if (sprite.getPosition().y <= 0 + Fon_offset) {
			sprite.setPosition(sprite.getPosition().x, 0 + Fon_offset);
		}
		if (sprite.getPosition().y >= WINDOW_HEIGHT - 1.5 * Fon_offset) {
			sprite.setPosition(sprite.getPosition().x, WINDOW_HEIGHT - 1.5 * Fon_offset);
		}
		if (speed < 0) speed = 0.f;
		else if (speed > 2) speed = 2.f;
		speedx = speed * sin(angle * PI / 180);
		speedy = -speed * cos(angle * PI / 180);
		sprite.move(speedx, speedy);
		fire();
		for (auto bullet : bullet_2) {
			bullet->update();
		}
	}
	void fire() {
		int now = timer.getElapsedTime().asMilliseconds();
		if (now > fire_cooldown) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				auto bullet = new Bullet_2(sprite.getPosition(), angle);
				bullet_2.push_back(bullet);
				timer.restart();
			}
		}
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
		for (auto bullet : bullet_2) {
			window.draw(bullet->getSprite());
		}
	}
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }

	std::list<Bullet_2*>* getBullets() { return &bullet_2; }

	sf::Vector2f getPosition() { return sprite.getPosition(); }

	void decreaseHp(int damage) { hp_2 -= damage; }

	int getHp() { return hp_2; }

	void HP_UP(int hp);

	void Speed_Boost();
};
void Player2::HP_UP(int hp) { this->hp_2 += hp; }
void Player2::Speed_Boost() {
	speed_bonus_act = true;
	dv *= 2; Player_Max_Speed *= 2;
	speed_bonus_act_time = timer.getElapsedTime().asMilliseconds();
}