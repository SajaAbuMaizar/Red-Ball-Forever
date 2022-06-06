#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "box2d/box2d.h"
#include <iostream>
#include "MovingObject.h"

enum class DIRECTIONS {
	UP,
	RIGHT,
	LEFT
};

class Ball : public MovingObject
{
public:
	Ball(b2World& world);
	void move(const DIRECTIONS dir);
	void update(b2Vec2 pos1,const float angle);
	bool collidesWith(GameObject& object);
	sf::Sprite getSprite() const { return m_ballImg; };
	sf::Vector2f getPosition() const { return m_ballImg.getPosition(); };
	void draw(sf::RenderWindow& window) { window.draw(m_ballImg); };
	void restartBall();

private:
	b2Body* m_Body;
	b2BodyDef BodyDef;
	sf::Texture m_ballTex;
	sf::Sprite m_ballImg;
	sf::Clock m_clock;
	sf::SoundBuffer m_balljumpSoundBuf;
	sf::Sound m_ballSound;
};