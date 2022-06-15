#include "Level.h"

//This function starts the level
void Level::startLevel()
{
    try
    {
        m_backgroundMusic.openFromFile("background music.wav");
    }
    catch (...)
    {
        std::cerr << "Can't load program files\n";
    }
    
    m_backgroundMusic.play();
    m_backgroundMusic.setLoop(true);
    
    if (m_homePage.display()) //if the game has done displaying the home page
    {
        m_homePage.~HomePage();
        for (int level = 1; level <= LEVELS; level++)
        {
            Controller newLevel(level);
            if (!newLevel.run()) //if lost a game
                level--;
        }
    }

}