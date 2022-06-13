#include "Tree.h"

//The c-tor of the tree class
Tree::Tree(std::shared_ptr<b2World>& world,const sf::Texture& treeTex, const sf::Vector2f position)
	: m_pos(position),
	  m_treeImg(treeTex)
{
	m_treeImg.setOrigin(float(treeTex.getSize().x / 2), float(treeTex.getSize().y / 2));
	m_treeImg.setPosition(m_pos.x,m_pos.y - treeTex.getSize().y / 2);

	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(m_pos.x, SCALER - m_pos.y + treeTex.getSize().y / 2);
    //creating the body of the tree
	BodyDef.type = b2_staticBody;
	m_Body = world->CreateBody(&BodyDef);
	m_Body->SetLinearVelocity(b2Vec2(1, 0)); //move right 1 unit per second

	b2PolygonShape Shape;
	Shape.SetAsBox(100.5f, 600.5f);

	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.f;
	FixtureDef.friction = 0.5f;
	FixtureDef.restitution = 0.1f;
	FixtureDef.shape = &Shape;
	m_Body->CreateFixture(&FixtureDef);
}