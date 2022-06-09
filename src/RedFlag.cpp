#include "RedFlag.h"

RedFlag::RedFlag(b2World& world, const int size)
{
	m_redFlag.loadFromFile("red flag.png");
	m_redFlagImg.setTexture(m_redFlag);
	m_redFlagImg.setPosition(float((size - 2) * 200), float(400 - m_redFlag.getSize().y));

	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(float((size - 2) * 200), 220.f);
	BodyDef.type = b2_staticBody;
	b2Body* Body = world.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(0.f, 0.f);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);

}

bool RedFlag::checkCollisionwithBall(GameObject& object)
{
	return m_redFlagImg.getGlobalBounds().intersects(object.getSprite().getGlobalBounds());
}