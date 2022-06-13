#include "HomePage.h"

//The c-tor of the HomePage class
HomePage::HomePage() : m_homePage(sf::VideoMode(WIDTH, HEIGHT), "Red Ball Forever Home Page")
{
    try
    {
        m_background.loadFromFile("backGroundHome.png");
        m_playButton.loadFromFile("playButton.jpg");
        m_playButtonClicked.loadFromFile("playButtonClicked.jpg");
        m_controls.loadFromFile("controls.png");
    }
    catch (...)
    {
        std::cerr << "Can't load program files\n";
    }
}

//This function displays the home page of the game
//returns true if done with displaying the home page
bool HomePage::display()
{
    int homeCounter = 0;
    sf::Sprite backGroundImg(m_background);
    sf::Sprite playButtonImg(m_playButton);
    playButtonImg.setOrigin(float(m_playButton.getSize().x/2),float(m_playButton.getSize().y/2));
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
                if (playButtonImg.getGlobalBounds().contains(location)){//if the start button is pressed then enter the loop
                    homeCounter++; //to count which home page is displayed
                    backGroundImg.setTexture(m_controls);
                    playButtonImg.setPosition(sf::Vector2f(float(WIDTH - m_playButton.getSize().x / 2), float(HEIGHT - m_playButton.getSize().y / 2)));
                    if (homeCounter == 2) { //if we displayed all the home pages then return from the function
                        m_homePage.close();
                        return true;
                    }
                }
                break;
            }
            case sf::Event::MouseMoved:
            {
                auto location = m_homePage.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
                if (playButtonImg.getGlobalBounds().contains(location))//if the mouse is on the play button
                    playButtonImg.setTexture(m_playButtonClicked);
                else
                    playButtonImg.setTexture(m_playButton);
                break;
            }
            }
        }
    }
    return false;
}