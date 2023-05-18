#pragma once
#include "settings.h"

class HpBar_1 {
private:
	sf::RectangleShape hpBar, frame;
	float hpBarWidth;
public:
	HpBar_1() {
		hpBar.setSize(sf::Vector2f{ FRAME_WIDTH, FRAME_HEIGHT });
		hpBar.setFillColor(sf::Color::Blue);
		hpBar.setPosition(sf::Vector2f{ 21.5,7.f });
		frame.setSize(sf::Vector2f{ FRAME_WIDTH + 4 , FRAME_HEIGHT + 4 });
		frame.setFillColor(sf::Color::Black);
		frame.setPosition(sf::Vector2f{ 20,5.f });
	}
	void update(int playerHp) {
		if (playerHp < 0) {
			hpBarWidth = 0;
		}
		else {
			hpBarWidth = playerHp / 100.f * FRAME_WIDTH;
		}
		hpBarWidth = playerHp / 100.f * FRAME_WIDTH;
		hpBar.setSize(sf::Vector2f{ hpBarWidth,FRAME_HEIGHT });
	}
	void draw(sf::RenderWindow& window) {
		window.draw(frame);
		window.draw(hpBar);

	}
};