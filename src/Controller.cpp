#include "Controller.h"

//The c-tor of the controller class
Controller::Controller(const int level) : m_window(sf::VideoMode(WIDTH, HEIGHT), "Red Ball Forever"),
                           m_world(std::make_unique<b2World>(b2Vec2(0.0f, -9.8f))),
                           m_ball(*m_world),
                           m_level(level),
                           m_score(0),
                           m_success(false),
                           m_availableLives(LIVES)
{
    try
    {
        m_lostResult.first.loadFromFile("result lose.jpg");
        m_lostResult.second.loadFromFile("replay.png");
        m_winResult.first.loadFromFile("win result.jpg");
        m_winResult.second.loadFromFile("play.png");
        m_skyTex.loadFromFile("sky.jpg");
    }
    catch (...)
    {
        std::cerr << "Can't load program files\n";
    }
    m_window.close();
}

//This function runs the current level
bool Controller::run()
{
    m_window.create(sf::VideoMode(WIDTH, HEIGHT), "Red Ball Forever");
    m_window.setFramerateLimit(360);
    //creating the level's objects and obstacles
    Map currentMap(createFileName(), m_world);
    Sky sky(m_skyTex ,currentMap.getGroundAmount());
    RedFlag redFlag(*m_world, currentMap.getGroundAmount());
    Monster monster(m_world, redFlag.getSprite().getPosition());
    while (m_window.isOpen())
    {
        m_world->Step(1 / 60.f, 8, 3);
        updateView();
        m_levelData.update(m_ball.getPosition(), m_level, m_score);//update the level's data

        m_window.clear(sf::Color::White);
        sky.draw(m_window);
        m_levelData.draw(m_window, m_availableLives);
        for (b2Body* BodyIterator = m_world->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
        {
            if (BodyIterator->GetType() == b2_dynamicBody) { //if the object is a ball then update and draw it
                m_ball.update(BodyIterator->GetPosition());
                m_ball.draw(m_window);
            }
            else if (BodyIterator->GetType() == b2_kinematicBody) {//if the object is a monster then update and draw it
                monster.update(BodyIterator->GetPosition());
                monster.draw(m_window);
            }
        }
        m_score = (currentMap.checkCollisionWithStars(m_ball)) ? m_score + 100 : m_score;//when collecting a star increase the score
        if (redFlag.checkCollisionwithBall(m_ball)) { //if the ball reaches the red flag(the end) then win the level
            m_success = true;
            m_levelData.showResult(m_winResult);
            return true;
        }
        if (currentMap.checkCollisionWithSea(m_ball) || monster.checkCollisionwithBall(m_ball)) { //if the ball collides with an sea or monster
            m_ball.restartBall(); //restart the ball from the original position
            m_availableLives--;
        }
        std::pair<bool, sf::Vector2f> obstacleResult = currentMap.checkCollisionWithObstacle(m_ball);
        if (obstacleResult.first) { //if the ball collided with an obstacle
            m_ball.changeTransform(obstacleResult.second);//move the ball behind the obstacle
            m_availableLives--;
        }
        if (m_availableLives == 0) { //if all game lives are lost then restart the level
            m_levelData.showResult(m_lostResult);
            return false;
        }
            
        currentMap.draw(m_window);
        redFlag.draw(m_window);
        m_window.display();

        for (auto event = sf::Event{}; m_window.pollEvent(event); )
        {
            switch (event.type) {
            case sf::Event::Closed:
                m_window.close();
                exit(0);
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    exit(0);
                if (updateDirection(event.key.code)) //when pressing a directional key then move the ball
                    m_ball.move(m_dir);
                break;
            } }
    }
    return true;
}

//This function updates the window viuew of the game accoring to the ball position
void Controller::updateView()
{
    if (m_ball.getPosition().x >= WIDTH / 2 && m_ball.getPosition().y >= HEIGHT / 2) { //move with the ball
        auto view = sf::View(sf::Vector2f(m_ball.getPosition().x, m_ball.getPosition().y - 50), sf::Vector2f(WIDTH, HEIGHT));
        m_window.setView(view);
    }
    else if (m_ball.getPosition().x < WIDTH / 2) {
        auto view = sf::View(sf::Vector2f(WIDTH / 2, m_ball.getPosition().y - 50), sf::Vector2f(WIDTH, HEIGHT));
        m_window.setView(view);
    }
    else if (m_ball.getPosition().y < HEIGHT / 2) {
        auto view = sf::View(sf::Vector2f(m_ball.getPosition().x, HEIGHT / 2 - 50), sf::Vector2f(WIDTH, HEIGHT));
        m_window.setView(view);
    }
}

//this function creats the file name based of the number of the level we are in
std::string Controller::createFileName()
{
    return (std::to_string(m_level) + ".txt");
}

//This function updates the current direction of the ball based on the key pressed by the user
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