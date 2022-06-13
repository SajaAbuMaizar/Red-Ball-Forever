#include "Sky.h"

//The c-tor of the sky class
Sky::Sky(sf::Texture& skyTex, const int size)
{
	m_skyImg.resize(size/6);
	int i = 0;
	for (auto& it: m_skyImg)
	{
		it.setTexture(skyTex);
		it.setPosition(float(i * skyTex.getSize().x),-100.f);
		i++;
	}
}

//This function draws all the skies
void Sky::draw(sf::RenderWindow& window)
{
	for (auto& it : m_skyImg)
	{
		window.draw(it);
	}
}