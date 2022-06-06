#include "Sky.h"

Sky::Sky(const int size)
{
	m_skyTex.loadFromFile("sky.jpg");
	m_skyImg.resize(size/6);
	int i = 0;
	for (auto& it: m_skyImg)
	{
		it.setTexture(m_skyTex);
		it.setPosition(i * m_skyTex.getSize().x,-100.f);
		i++;
	}
}

void Sky::draw(sf::RenderWindow& window)
{
	for (auto& it : m_skyImg)
	{
		window.draw(it);
	}
}