#pragma once
#include "StaticObject.h"

class Star : public StaticObject
{
public:
	Star(std::shared_ptr<b2World>& world, const int position);
	void draw(sf::RenderWindow& window) { window.draw(m_starImg); };
	sf::Sprite getSprite() const { return m_starImg; };
	~Star();

private:
	sf::Texture m_starTex;
	sf::Sprite m_starImg;
	int m_pos;

	b2Body* m_Body;
};