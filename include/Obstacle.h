#pragma once
#include "StaticObject.h"

class Obstacle : public StaticObject
{
public:
	Obstacle(std::shared_ptr<b2World>& world, const sf::Vector2f position);
	void draw(sf::RenderWindow& window) { window.draw(m_ObstacleImg); };
	sf::Sprite getSprite() const { return m_ObstacleImg; };

private:
	sf::Texture m_ObstacleTex;
	sf::Sprite m_ObstacleImg;
	sf::Vector2f m_pos;

	b2Body* m_Body;
};