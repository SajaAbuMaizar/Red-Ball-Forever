#pragma once
#include "MovingObject.h"

class Monster : public MovingObject
{
public:
	Monster(std::shared_ptr<b2World>& world, sf::Vector2f pos);
	void update();
	void draw(sf::RenderWindow& window) { window.draw(m_MonsterImg); };
	sf::Sprite getSprite() const { return m_MonsterImg; };
	void update(b2Vec2 pos);
	bool checkCollisionwithBall(GameObject& object);
	virtual ~Monster() = default;

private:
	sf::Sprite m_MonsterImg;
	sf::Texture m_MonsterTex;
	b2Body* m_Body;
	sf::Vector2f m_pos;
};