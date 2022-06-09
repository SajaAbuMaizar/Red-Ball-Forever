#include "Sea.h"

Sea::Sea(sf::Texture& texture, std::shared_ptr<b2World>& world, int pos) :
	m_seaImg(texture),
	m_pos(pos)
{
	b2BodyDef BodyDef;
	BodyDef.position.Set((POS_SCALER/2) + pos * POS_SCALER, POS_SCALER - (65));
	BodyDef.type = b2_staticBody;
	b2Body* Body = world->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(100.f, 60.f);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);

	m_seaImg.setPosition(m_pos * POS_SCALER, (POS_SCALER*2));

	//m_SeaImg.setOrigin(0, m_SeaTex.getSize().y);

}

bool Sea::checkCollision(GameObject& object)
{
	return m_seaImg.getGlobalBounds().intersects(object.getSprite().getGlobalBounds());
}