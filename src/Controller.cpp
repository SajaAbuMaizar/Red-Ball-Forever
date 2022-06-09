#include "Controller.h"

Controller::Controller(const int level) : m_window(sf::VideoMode(WIDTH, HEIGHT), "Red Ball Forever"),
                           m_world(std::make_unique<b2World>(b2Vec2(0.0f, -9.8f))),
                           m_ball(*m_world),
                           m_level(level),
                           m_score(0),
                           m_success(false),
                           m_availableLives(LIVES)
{
    m_lostResult.first.loadFromFile("result lose.jpg");
    m_lostResult.second.loadFromFile("replay.png");
    m_winResult.first.loadFromFile("win result.jpg");
    m_winResult.second.loadFromFile("play.png");
    m_skyTex.loadFromFile("sky.jpg");
    m_window.close();
}

bool Controller::run()
{
    m_window.create(sf::VideoMode(WIDTH, HEIGHT), "Red Ball Forever");
    m_window.setFramerateLimit(360);
    ///
    Map currentMap(createFileName(), m_world);
    Sky sky(m_skyTex ,currentMap.getGroundAmount());
    RedFlag redFlag(*m_world, currentMap.getGroundAmount());
    Monster monster(m_world, redFlag.getSprite().getPosition());
    while (m_window.isOpen())
    {
        m_world->Step(1 / 60.f, 8, 3);
        updateView();
        m_levelData.update(m_ball.getPosition(), m_level, m_score);

        m_window.clear(sf::Color::White);
        sky.draw(m_window);
        m_levelData.draw(m_window, m_availableLives);
        for (b2Body* BodyIterator = m_world->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
        {
            if (BodyIterator->GetType() == b2_dynamicBody)
            {
                m_ball.update(BodyIterator->GetPosition());
                m_ball.draw(m_window);
            }
            else if (BodyIterator->GetType() == b2_kinematicBody)
            {
                monster.update(BodyIterator->GetPosition());
                monster.draw(m_window);
            }
        }
        m_score = (currentMap.checkCollisionWithStars(m_ball)) ? m_score + 100 : m_score;
        if (redFlag.checkCollisionwithBall(m_ball))
        {
            m_success = true;
            m_window.close();
            m_levelData.showResult(m_winResult);
            return true;
        }
        if (currentMap.checkCollisionWithSea(m_ball) ||
             monster.checkCollisionwithBall(m_ball))
        {
            m_ball.restartBall();
            m_availableLives--;
        }
        std::pair<bool, sf::Vector2f> obstacleResult = currentMap.checkCollisionWithObstacle(m_ball);
        if (obstacleResult.first)
        {
            m_ball.changeTransform(obstacleResult.second);
            m_availableLives--;
        }
        if (m_availableLives == 0)
        {
            m_levelData.showResult(m_lostResult);
            return false;
        }
            
        currentMap.draw(m_window);
        redFlag.draw(m_window);
        m_window.display();

        for (auto event = sf::Event{}; m_window.pollEvent(event); )
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::KeyPressed:
                if (updateDirection(event.key.code))
                {
                    m_ball.move(m_dir);
                }
                break;
            }
        }
    }
    return true;
}

void Controller::updateView()
{
    if (m_ball.getPosition().x >= WIDTH / 2 && m_ball.getPosition().y >= HEIGHT / 2) //move with the ball
    {
        auto view = sf::View(sf::Vector2f(m_ball.getPosition().x, m_ball.getPosition().y - 50), sf::Vector2f(WIDTH, HEIGHT));
        m_window.setView(view);
    }
    else if (m_ball.getPosition().x < WIDTH / 2)
    {
        auto view = sf::View(sf::Vector2f(WIDTH / 2, m_ball.getPosition().y - 50), sf::Vector2f(WIDTH, HEIGHT));
        m_window.setView(view);
    }
    else if (m_ball.getPosition().y < HEIGHT / 2)
    {
        auto view = sf::View(sf::Vector2f(m_ball.getPosition().x, HEIGHT / 2 - 50), sf::Vector2f(WIDTH, HEIGHT));
        m_window.setView(view);
    }
}

//this function creats the file name based of the number of the level we are in
std::string Controller::createFileName()
{
    return (std::to_string(m_level) + ".txt");
}

std::optional<DIRECTIONS> Controller::updateDirection(const sf::Keyboard::Key key)
{
    switch(key)
    {
    case sf::Keyboard::Up:
    case sf::Keyboard::W:
        m_dir = DIRECTIONS::UP;
        return DIRECTIONS::UP;
    case sf::Keyboard::Right:
    case sf::Keyboard::D:
        m_dir = DIRECTIONS::RIGHT;
        return DIRECTIONS::RIGHT;
    case sf::Keyboard::Left:
    case sf::Keyboard::A:
        m_dir = DIRECTIONS::LEFT;
        return DIRECTIONS::LEFT;
    }
    return {};
}