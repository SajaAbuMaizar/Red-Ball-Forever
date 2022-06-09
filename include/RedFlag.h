#pragma once
#include "StaticObject.h"

class RedFlag : public StaticObject
{
public:
	RedFlag(b2World& world, const int size);
	void draw(sf::RenderWindow& window) { window.draw(m_redFlagImg); };
	sf::Sprite getSprite() const { return m_redFlagImg; };
	bool checkCollisionwithBall(GameObject& object);
	virtual ~RedFlag() = default;

private:
	sf::Texture m_redFlag;
	sf::Sprite m_redFlagImg;
};