#include "HomePage.h"

HomePage::HomePage() : m_homePage(sf::VideoMode(WIDTH, HEIGHT), "Red Ball Forever Home Page")
{
    m_background.loadFromFile("backGroundHome.png");
    m_playButton.loadFromFile("playButton.jpg");
    m_controls.loadFromFile("controls.png");
}

//returns true if done
bool HomePage::display()
{
    int homeCounter = 0;
    sf::Sprite backGroundImg(m_background);
    sf::Sprite playButtonImg(m_playButton);
    playButtonImg.setOrigin(m_playButton.getSize().x/2,m_playButton.getSize().y/2);
    playButtonImg.setPosition(sf::Vector2f(WIDTH/2,HEIGHT/1.5));

    while (m_homePage.isOpen())
    {
        m_homePage.clear();

        m_homePage.draw(backGroundImg);
        m_homePage.draw(playButtonImg);

        m_homePage.display();

        for (auto event = sf::Event{}; m_homePage.pollEvent(event); )
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_homePage.close();
                exit(0);
            case sf::Event::MouseButtonReleased: //if the user pressed the mouse button
            {
                auto location = m_homePage.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                if (playButtonImg.getGlobalBounds().contains(location))//if the start button is pressed then enter the loop
                {
                    homeCounter++;
                    backGroundImg.setTexture(m_controls);
                    playButtonImg.setPosition(sf::Vector2f(WIDTH - m_playButton.getSize().x/2,HEIGHT - m_playButton.getSize().y / 2));
                    if (homeCounter == 2)
                    {
                        m_homePage.close();
                        return true;
                    }
                    break;
                }

            }
            }
        }
    }
    return false;
}