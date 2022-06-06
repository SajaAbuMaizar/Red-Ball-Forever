#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StaticObject.h"

class Sky : public StaticObject
{
public:
	Sky(const int size);
	void draw(sf::RenderWindow& window);
	sf::Sprite getSprite() const { return m_skyImg[0]; };

private:
	sf::Texture m_skyTex;
	std::vector <sf::Sprite> m_skyImg;
};