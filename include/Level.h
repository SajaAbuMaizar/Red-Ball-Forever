#pragma once
#include "Controller.h"
#include "HomePage.h"
#include <SFML/Audio.hpp>

const int LEVELS = 3;

class Level
{
public:
	void startLevel();

private:
	HomePage m_homePage;
	int m_level = 1;

	sf::Music m_backgroundMusic;
};