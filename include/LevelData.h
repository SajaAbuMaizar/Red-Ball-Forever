#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

const int LIVES = 3;
const int POSITION_FITTER = 500;

class LevelData
{
public:
	LevelData ();
	void draw(sf::RenderWindow& window, const int img);
	void update(const sf::Vector2f pos, const int currlevel, const int currScore);
	void showResult(const std::pair<sf::Texture, sf::Texture>& result);

private:
	std::vector<sf::Texture> m_hearts;
	
	sf::Sprite m_heartImg;
	sf::Font m_font;
	sf::Text m_levelText;
	sf::Text m_scoreText;
};