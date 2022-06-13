#include "Monster.h"

//The c-tor of the monster class
Monster::Monster(std::shared_ptr<b2World>& world, sf::Vector2f pos): m_pos(pos)
{
	try
	{
		m_MonsterTex.loadFromFile("Monster.png");
	}
	catch (...)
	{
		std::cerr << "Can't load program files\n";
	}
	m_MonsterImg.setTexture(m_MonsterTex);
	m_MonsterImg.setOrigin(float(m_MonsterTex.getSize().x / 2), float(m_MonsterTex.getSize().y / 2));
    //creating the body of the monster
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2((POS_SCALER/2), m_pos.y - 70);

	BodyDef.type = b2_kinematicBody;
	m_Body = world->CreateBody(&BodyDef);
	m_Body->SetLinearVelocity(b2Vec2(10, 0)); //move right 10 units per second

	b2PolygonShape Shape;
	Shape.SetAsBox(60.5f, 90.5f);

	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.5f;
	FixtureDef.restitution = 0.1f;
	FixtureDef.shape = &Shape;
	m_Body->CreateFixture(&FixtureDef);
}

//This function updates the monster position based on its position in the world
void Monster::update(b2Vec2 pos)
{
	m_MonsterImg.setPosition(pos.x, SCALER - pos.y);
}

//This function checks if the monster collided with the rederred object
//return true if collided, false otherwise
bool Monster::checkCollisionwithBall(GameObject& object)
{
	return m_MonsterImg.getGlobalBounds().intersects(object.getSprite().getGlobalBounds());
}