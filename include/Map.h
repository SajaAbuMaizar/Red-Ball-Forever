#pragma once
#include <fstream>
#include <iostream>
#include "Ground.h"
#include "Sea.h"
#include "Star.h"
#include "Ball.h"
#include "Obstacle.h"
#include "Box.h"
#include "Tree.h"

const int GROUND_TEXTURES = 5;

enum GROUND_TYPES{
	LEFT_GROUND = 0,
	MIDDLE_GROUND,
	RIGHT_GROUND,
	LEFT_TALL_GROUND,
	RIGHT_TALL_GROUND,
	SEA_GROUND,
};

class Map
{
public:
	Map(const std::string fileName, std::shared_ptr<b2World>& world);
	void draw(sf::RenderWindow& window);
	void update();
	int getGroundAmount() const { return int(m_ground.size()); };
	bool checkCollisionWithStars(Ball& ball);
	bool checkCollisionWithSea(Ball& ball);
	std::pair<bool, sf::Vector2f> checkCollisionWithObstacle(Ball& ball);

private:
	std::vector<sf::Texture> m_groundTex;
	sf::Texture m_seaTex;
	sf::Texture m_boxTex;
	sf::Texture m_treeTex;
	sf::Texture m_ObstacleTex;
	sf::Texture m_starTex;
	std::vector<std::shared_ptr<Ground>> m_ground;
	std::vector<std::shared_ptr<Sea>> m_sea;
	std::vector<std::shared_ptr<Obstacle>> m_obstacle;
	std::vector<std::shared_ptr<Star>> m_star;
	std::vector<std::shared_ptr<Box>> m_box;
	std::vector<std::shared_ptr<Tree>> m_tree;

	sf::SoundBuffer m_starCollectSoundBuf;
	sf::Sound m_starSound;
};