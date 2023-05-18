#pragma once
#include "settings.h"

class HpBar_2 {
private:
	sf::RectangleShape hpBar, frame;
	float hpBarWidth;
public:
	HpBar_2() {
		hpBar.setSize(sf::Vector2f{ FRAME_WIDTH, FRAME_HEIGHT });
		hpBar.setFillColor(sf::Color::Red);
		hpBar.setPosition(sf::Vector2f{ 1482.f - FRAME_WIDTH,7.f });
		frame.setSize(sf::Vector2f{ FRAME_WIDTH + 4 , FRAME_HEIGHT + 4 });
		frame.setFillColor(sf::Color::Black);
		frame.setPosition(sf::Vector2f{ 1480.f - FRAME_WIDTH,5.f });

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