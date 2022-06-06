#include "Ground.h"

Ground::Ground(sf::Texture& texture, std::shared_ptr<b2World>& world
	           ,int pos, const int type,const int side, const int prev) :
	                                                            m_groundImg(texture),
                                                                m_pos(pos),
	                                                            m_type(type), 
	                                                            m_side(side),
	                                                            m_prev(prev)
{
	b2BodyDef BodyDef;
	BodyDef.position.Set(100 + pos * 200, m_type * 200 - ((m_type - 1) * 65));
	BodyDef.type = b2_staticBody;
	b2Body* Body = world->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(100.f, 60.f * m_type);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f;
	FixtureDef.shape = &Shape;
	Body->CreateFixture(&FixtureDef);
	
	m_groundImg.setPosition(m_pos * 200, 400 - ((m_type - 1) * 200)); //for tall and short grounds

}