#include "RedFlag.h"

//The c-tor of the red flag class
RedFlag::RedFlag(b2World& world, const int size)
{
	try
	{
		m_redFlag.loadFromFile("red flag.png");
	}
	catch (...)
	{
		std::cerr << "Can't Load program files\n";
	}
	m_redFlagImg.setTexture(m_redFlag);
	m_redFlagImg.setPosition(float((size - 3) * POS_SCALER), float((POS_SCALER*2) - m_redFlag.getSize().y));
    //creating the body of the red flag
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(float((size - 3) * POS_SCALER), 220.f);
	BodyDef.type = b2_staticBody;
	b2Body* Body = world.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(0.f, 0.f);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);

}

//This function checks if the red flag collided with the rederred object
//return true if collided, false otherwise
bool RedFlag::checkCollisionwithBall(GameObject& object)
{
	return m_redFlagImg.getGlobalBounds().intersects(object.getSprite().getGlobalBounds());
}