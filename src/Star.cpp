#include "Star.h"

//The c-tor of the star class
Star::Star(std::shared_ptr<b2World>& world, sf::Texture& starTex, const int position)
	   : m_pos(position),
	     m_starImg(starTex)
{
	m_starImg.setOrigin(float(starTex.getSize().x / 2), 0.f);

	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(float(500 * m_pos), float(POS_SCALER*2));
	//creating the body of the star
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

	m_starImg.setPosition(float(500 * m_pos), 200.f); //for tall and short grounds
}

//implement Star class destructor
Star::~Star()
{
	m_Body->GetWorld()->DestroyBody(m_Body);
}