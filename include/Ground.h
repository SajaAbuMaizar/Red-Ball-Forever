#pragma once
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"
#include "StaticObject.h"

const int FITTER = 65;

class Ground : public StaticObject
{
public:
	Ground(sf::Texture& texture, std::shared_ptr<b2World>& world,
		  int pos, const int type, const int side, const int prev);
	void draw(sf::RenderWindow& window) { window.draw(m_groundImg); };
	sf::Sprite getSprite() const { return m_groundImg; };
	int getSide() const { return m_side; };
	int getPrev() const { return m_prev; };
	sf::Vector2f getPosition() const { return m_groundImg.getPosition(); };
	virtual ~Ground() = default;
	

private:
	b2ChainShape m_groundChain;
	sf::Sprite m_groundImg;
	int m_pos;
	int m_type; //tall or short
	int m_side; //left or right or middle
	int m_prev;
};