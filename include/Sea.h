#pragma once
#include "StaticObject.h"

class Sea : public StaticObject
{
public:
	Sea(sf::Texture& texture, std::shared_ptr<b2World>& world, int pos);
	bool checkCollision(GameObject& object);
	void draw(sf::RenderWindow& window) { window.draw(m_seaImg); };
	sf::Sprite getSprite() const { return m_seaImg; };
	sf::Vector2f getPosition() const { return m_seaImg.getPosition(); };
	virtual ~Sea() = default;

private:
	sf::Sprite m_seaImg;
	int m_pos;
};