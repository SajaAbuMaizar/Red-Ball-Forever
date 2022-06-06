#include "Star.h"

Star::Star(std::shared_ptr<b2World>& world, const int position) : m_pos(position)
{
	m_starTex.loadFromFile("Star.png");
	m_starImg.setTexture(m_starTex);
	m_starImg.setOrigin(m_starTex.getSize().x / 2, 0);

	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(500 * m_pos, 400);
	
	BodyDef.type = b2_staticBody;
	m_Body = world->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(10.5f,10.5f);

	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;
	FixtureDef.friction = 0.5f;
	FixtureDef.restitution = 0.5f;
	FixtureDef.shape = &Shape;
	m_Body->CreateFixture(&FixtureDef);

	m_starImg.setPosition(500 * m_pos, 200); //for tall and short grounds
}

//implement Star class destructor
Star::~Star()
{
	m_Body->GetWorld()->DestroyBody(m_Body);
}