#include "Level.h"

void Level::startLevel()
{
    m_backgroundMusic.openFromFile("background music.wav");
    
    m_backgroundMusic.play();
    m_backgroundMusic.setLoop(true);
    if (m_homePage.display())
    {
        for (int level = 1 ; level <= LEVELS; level++)
        {
            Controller newLevel(level);
            if (!newLevel.run()) //if lost a game
                level--;
        }
    }
}