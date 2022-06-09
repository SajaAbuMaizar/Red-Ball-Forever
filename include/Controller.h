#pragma once
#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"
#include <iostream>
#include <optional>
#include "HomePage.h"
#include "Ground.h"
#include "Ball.h"
#include "Map.h"
#include "Sky.h"
#include "RedFlag.h"
#include "LevelData.h"
#include "Monster.h"



class Controller
{
public:
	Controller(const int level);
	bool run();
	~Controller() = default;
	

private:
	std::pair<sf::Texture, sf::Texture> m_lostResult;
	std::pair<sf::Texture, sf::Texture> m_winResult;
	sf::RenderWindow m_window;
	HomePage m_homePage;
	std::shared_ptr<b2World> m_world;
	Ball m_ball;
	LevelData m_levelData;
	int m_level;
	int m_score;
	bool m_success;
	int m_availableLives;
	sf::Texture m_skyTex;
	
	
	DIRECTIONS m_dir = DIRECTIONS::RIGHT;

	std::optional<DIRECTIONS> updateDirection(const sf::Keyboard::Key key);
	std::string createFileName();
	void updateView();
};