#pragma once
#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"
#include <iostream>

class GameObject
{
public:
	GameObject() = default;
	virtual sf::Sprite getSprite() const = 0;

private:

};