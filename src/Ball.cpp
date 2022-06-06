#include "Ball.h"

Ball::Ball(b2World& world)
{
	m_balljumpSoundBuf.loadFromFile("ball jump sound.wav");
	m_ballSound = sf::Sound(m_balljumpSoundBuf);
	m_ballTex.loadFromFile("ball.png");
	m_ballImg.setTexture(m_ballTex);
	m_ballImg.setOrigin(m_ballTex.getSize().x / 2, 0);

	BodyDef.position = b2Vec2(600, 400);
	BodyDef.type = b2_dynamicBody;
	m_Body = world.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(0.2f, 0.2f);
	
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.9f;
	FixtureDef.friction = 0.5f;
	FixtureDef.restitution = 0.4f;
	FixtureDef.shape = &Shape;
	m_Body->CreateFixture(&FixtureDef);
}

void Ball::move(const DIRECTIONS dir)
{
	switch (dir)
	{
	case DIRECTIONS::UP: //make a clock and when passes one second then jump
		if (m_clock.getElapsedTime().asSeconds() >= 1.f)
		{
			m_ballSound.play();
			m_Body->ApplyForceToCenter(b2Vec2(0, 400), true);
			m_clock.restart();
		}
		break;
	case DIRECTIONS::RIGHT:
		m_Body->ApplyForceToCenter(b2Vec2(170, 0), true);
		break;
	case DIRECTIONS::LEFT:
		m_Body->ApplyForceToCenter(b2Vec2(-170, 0), true);
		break;
	}
}

void Ball::update(b2Vec2 pos, const float angle)
{
	pos.x = (pos.x <= float(m_ballTex.getSize().x / 2)) ? float(m_ballTex.getSize().x / 2) : pos.x;
	pos.y = (pos.y <= float(m_ballTex.getSize().y / 2)) ? float(m_ballTex.getSize().y / 2) : pos.y;
	pos.y = (680 - pos.y <= float(m_ballTex.getSize().y / 2)) ? 680 - float(m_ballTex.getSize().y / 2) : pos.y;
	m_ballImg.setPosition(pos.x, 600 - pos.y);
	//m_ballImg.setRotation(angle * 180 / b2_pi);
}

bool Ball::collidesWith(GameObject& object)
{
	return m_ballImg.getGlobalBounds().intersects(object.getSprite().getGlobalBounds());
}

void Ball::restartBall()
{
	m_ballImg.setPosition(600, 200);
	m_Body->SetTransform(b2Vec2(600, 400), m_Body->GetAngle());
}