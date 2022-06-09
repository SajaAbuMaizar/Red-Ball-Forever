#pragma once
#include <SFML/Graphics.hpp>
#include "box2d/box2d.h"
#include <iostream>

const int SCALER = 600;
const int POS_SCALER = 200;

class GameObject
{
public:
	GameObject() = default;
	virtual sf::Sprite getSprite() const = 0;

private:

};