#include "Map.h"

Map::Map(const std::string fileName, std::shared_ptr<b2World>& world)
{
	m_groundTex.resize(GROUND_TEXTURES);
	m_groundTex[0].loadFromFile("left.png");
	m_groundTex[1].loadFromFile("middle.png");
	m_groundTex[2].loadFromFile("right.png");
	m_groundTex[3].loadFromFile("left edge.png");
	m_groundTex[4].loadFromFile("right edge.png");
	m_seaTex.loadFromFile("Sea.png");
	m_boxTex.loadFromFile("box.jpg");
	m_treeTex.loadFromFile("tree.png");
	m_ObstacleTex.loadFromFile("obsticle.png");
	m_starTex.loadFromFile("Star.png");
	m_starCollectSoundBuf.loadFromFile("star collect sound.wav");
	m_starSound = sf::Sound(m_starCollectSoundBuf);

	std::ifstream board_file;
	board_file.open(fileName);
	if (!board_file) //if opening the file faild. . .
	{
		std::cerr << "Error: File could NOT be opened !!!"; exit(1);
	}
	int pos = 0;
	int prev = -1;
	while (!board_file.eof())
	{
		int shape;
		board_file >> shape;
		switch (shape)
		{
			m_map.push_back(shape);
		case LEFT_GROUND: //left
			m_ground.push_back(std::make_shared<Ground>(m_groundTex[LEFT_GROUND], world, pos,1, LEFT_GROUND, prev));
			break;
		case MIDDLE_GROUND: //middle
			m_ground.push_back(std::make_shared<Ground>(m_groundTex[MIDDLE_GROUND], world, pos,1, MIDDLE_GROUND,prev));
			break;
		case RIGHT_GROUND: //right
			m_ground.push_back(std::make_shared<Ground>(m_groundTex[RIGHT_GROUND], world, pos,1, RIGHT_GROUND,prev));
			break;
		case LEFT_TALL_GROUND: //left tall edge
			m_ground.push_back(std::make_shared<Ground>(m_groundTex[LEFT_TALL_GROUND], world, pos, 2, LEFT_TALL_GROUND,prev));
			break;
		case RIGHT_TALL_GROUND: //right tall edge
			m_ground.push_back(std::make_shared<Ground>(m_groundTex[RIGHT_TALL_GROUND], world, pos, 2, RIGHT_TALL_GROUND,prev));
			break;
		case SEA_GROUND: //sea
			m_sea.push_back(std::make_shared<Sea>(m_seaTex, world, pos));
			break;
		}
		pos++;
		prev = shape;
	}

	int counter = 0;
	m_star.resize(pos/3);
	for (auto& it: m_star)
	{
		it = std::make_shared<Star>(world,m_starTex, counter);
		counter++;
	}
	
	counter = 0;
	sf::Vector2f tempPos;
	for (const auto& it : m_ground)
	{
		if (it->getSide() == MIDDLE_GROUND)
		{
			counter++;
			tempPos = it->getPosition();
		}
		if (counter == 7) //every 7 middle ground, insert an obstacle
		{
			m_obstacle.push_back(std::make_shared<Obstacle>(world,m_ObstacleTex, tempPos));
			counter = 0;
		}
	}

	//create box when there is a tall ground
	for (int i = 0 ; i < m_ground.size(); i++)
		if (m_ground[i]->getSide() == LEFT_TALL_GROUND && m_ground[i]->getPrev() != SEA_GROUND)
			m_box.push_back(std::make_shared<Box>(world, m_boxTex, m_ground[i-1]->getPosition()));

	m_tree.push_back(std::make_shared<Tree>(world, m_treeTex, sf::Vector2f(400,400)));//first tree(at the beginning of game)
	m_tree.push_back(std::make_shared<Tree>(world, m_treeTex, m_ground[m_ground.size() - 2]->getPosition()));//last tree(at the ending of game)
}

bool Map::checkCollisionWithStars(Ball& ball)
{
	for (int i = 0 ; i < m_star.size(); i++)
		if (ball.collidesWith(*m_star[i]))
		{
			m_starSound.play();
			m_star.erase(m_star.begin() + i);
			return true;
		}
	return false;
}

std::pair<bool, sf::Vector2f> Map::checkCollisionWithObstacle(Ball& ball)
{
	std::pair<bool, sf::Vector2f> result;
	result.first = false;
	for (int i = 0; i < m_obstacle.size(); i++)
		if (ball.collidesWith(*m_obstacle[i]))
		{
			result.first = true;
			result.second = m_obstacle[i]->getSprite().getPosition();
		}
			
	return result;
}

bool Map::checkCollisionWithSea(Ball& ball)
{
	for (int i = 0; i < m_sea.size(); i++)
		if (ball.collidesWith(*m_sea[i]))
			return true;
	return false;
}

void Map::draw(sf::RenderWindow& window)
{
	for (const auto& it : m_star)
		it->draw(window);
	for (const auto& it: m_ground)
		it->draw(window);
	for (const auto& it : m_sea)
		it->draw(window);
	for (const auto& it : m_obstacle)
		it->draw(window);
	for (const auto& it : m_box)
		it->draw(window);
	for (const auto& it : m_tree)
		it->draw(window);
}
