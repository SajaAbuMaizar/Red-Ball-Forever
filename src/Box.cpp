#include "Box.h"

//the c-tor of the Box class
Box::Box(std::shared_ptr<b2World>& world, sf::Texture& boxTex, const sf::Vector2f position)
	                              : m_pos(position),
	                                m_boxImg(boxTex)
{
	m_boxImg.setOrigin(float(boxTex.getSize().x / 2), float(boxTex.getSize().y / 2));
    //creating the body of the box
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(m_pos.x - 10, 250);

	BodyDef.type = b2_staticBody;
	m_Body = world->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(80.5f, 105.5f);

	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.5f;
	FixtureDef.restitution = 0.1f;
	FixtureDef.shape = &Shape;
	m_Body->CreateFixture(&FixtureDef);

	m_boxImg.setPosition(m_pos.x, 350);
}

//This function updates the position if the box
void Box::update()
{
	m_boxImg.setPosition(m_boxImg.getPosition().x + 1, m_boxImg.getPosition().y);
}