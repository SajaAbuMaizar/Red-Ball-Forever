#pragma once
#include "StaticObject.h"

class Star : public StaticObject
{
public:
	Star(std::shared_ptr<b2World>& world, sf::Texture& starTex, const int position);
	void draw(sf::RenderWindow& window) { window.draw(m_starImg); };
	virtual sf::Sprite getSprite() const { return m_starImg; };
	virtual ~Star();

private:
	sf::Sprite m_starImg;
	int m_pos;

	b2Body* m_Body;
};