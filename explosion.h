#pragma once
#include "settings.h"

struct Explosion {
	static const int size = 9;
	sf::Texture textureArr[size];
	sf::Sprite spriteArr[size];
	sf::Clock clock;
	float time;
	int frame;
	sf::Vector2f pos;
};

void expInit(Explosion& exp, sf::Vector2f position) {
	for (int i = 0; i < Explosion::size; i++) {
		std::string fileName = EXP_FILE_NAME_TEMP + std::to_string(i) + ".png";
		exp.textureArr[i].loadFromFile(fileName);
		exp.spriteArr[i].setTexture(exp.textureArr[i]);
	}
	exp.clock.restart();
	exp.frame = 0;
	exp.pos = position;
}

void expUpdate(Explosion& exp) {}

void expDraw(sf::RenderWindow& window, Explosion& exp) {
	exp.time = exp.clock.getElapsedTime().asMilliseconds();
	if (exp.time > 100.f) {
		exp.frame++;
		if (exp.frame > 8) exp.frame = 0;
		exp.clock.restart();
	}
	sf::FloatRect bounds = exp.spriteArr[exp.frame].getGlobalBounds();
	exp.spriteArr[exp.frame].setPosition(
		exp.pos.x - bounds.width/2, 
		exp.pos.y - bounds.height / 2
	);
	window.draw(exp.spriteArr[exp.frame]);
}
