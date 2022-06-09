#pragma once
#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"
#include <iostream>
#include "MovingObject.h"


class Box : public MovingObject
{
public:
	Box(std::shared_ptr<b2World>& world, sf::Texture& boxTex, const sf::Vector2f position);
	void draw(sf::RenderWindow& window) { window.draw(m_boxImg); };
	sf::Sprite getSprite() const { return m_boxImg; };
	void update();
	virtual ~Box() = default;

private:
	b2Body* m_Body;
	sf::Vector2f m_pos;
	sf::Sprite m_boxImg;

};