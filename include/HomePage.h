#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

const int WIDTH = 1000;
const int HEIGHT = 600;

class HomePage
{
public:
	HomePage();
	bool display();
	~HomePage() = default;

private:
	sf::RenderWindow m_homePage;
	sf::Texture m_background;
	sf::Texture m_playButton;
	sf::Texture m_playButtonClicked;
	sf::Texture m_controls;
};