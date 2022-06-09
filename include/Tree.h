#pragma once
#include "StaticObject.h"

class Tree : public StaticObject
{
public:
	Tree(std::shared_ptr<b2World>& world, const sf::Texture& treeTex, const sf::Vector2f position);
	void draw(sf::RenderWindow& window) { window.draw(m_treeImg); };
	sf::Sprite getSprite() const { return m_treeImg; };
	virtual ~Tree() = default;

private:
	sf::Sprite m_treeImg;
	sf::Vector2f m_pos;
	b2Body* m_Body;
};