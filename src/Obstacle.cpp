#include "Obstacle.h"

Obstacle::Obstacle(std::shared_ptr<b2World>& world, sf::Texture& texture, const sf::Vector2f position)
	    : m_pos(position),
	     m_ObstacleImg(texture)
{
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(50 + m_pos.x , 600 - m_pos.y + 50);
	BodyDef.type = b2_staticBody;
	m_Body = world->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(70.5f, 50.5f);

	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;
	FixtureDef.friction = 0.5f;
	FixtureDef.restitution = 0.5f;
	FixtureDef.shape = &Shape;
	m_Body->CreateFixture(&FixtureDef);

	m_ObstacleImg.setPosition(m_pos.x, m_pos.y - texture.getSize().y);

}