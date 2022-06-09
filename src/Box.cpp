#include "Box.h"

Box::Box(std::shared_ptr<b2World>& world, sf::Texture& boxTex, const sf::Vector2f position)
	                              : m_pos(position),
	                                m_boxImg(boxTex)
{
	m_boxImg.setOrigin(boxTex.getSize().x / 2, boxTex.getSize().y / 2);

	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(m_pos.x - 10, 250);

	BodyDef.type = b2_staticBody;
	m_Body = world->CreateBody(&BodyDef);
	m_Body->SetLinearVelocity(b2Vec2(1, 0)); //move right 1 unit per second

	b2PolygonShape Shape;
	Shape.SetAsBox(80.5f, 105.5f);

	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.5f;
	FixtureDef.restitution = 0.1f;
	FixtureDef.shape = &Shape;
	m_Body->CreateFixture(&FixtureDef);

	m_boxImg.setPosition(m_pos.x, 350); //for tall and short grounds
}

void Box::update(b2Vec2 pos)
{
	m_boxImg.setPosition(m_boxImg.getPosition().x + 1, m_boxImg.getPosition().y);
	//m_boxImg.setPosition(pos.x, 600 - pos.y);
	std::cout << "sfml box :" << m_boxImg.getPosition().x << " " << m_boxImg.getPosition().y << '\n';
	//m_ballImg.setRotation(angle * 180 / b2_pi);
}