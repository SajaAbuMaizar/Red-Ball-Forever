---------------------------------------------------------------------------------------------------------
------------------------------------ OOP2 Project - Red Ball Forever ------------------------------------
---------------------------------------------------------------------------------------------------------
------------------------------------------- Students and IDs -------------------------------------------- 
-------- Samah Rajabi (student number: 211558556) & Saja Abu Maizar (student number: 208072371) ---------
---------------------------------------------------------------------------------------------------------
----------------------------------------  General Description  ------------------------------------------
---------------------------------------------------------------------------------------------------------
Red Ball Forever is a 2D platform game starring a red rolling ball whose goal is to collect stars.
The player joins the ball on its adventure across a series of levels with increasing difficulty.
The player controles the ball's moves using the arrows of the keyboard or the letters (A: right, D: left
W: up). He must lead it to the red flag at the end of each level in order to win the level.
In the game, there are some obstacles such as water, monster and spikes that would cause the ball to 
lose meaning the ball should avoid these obstaclesin order to reach the flag at the end of the map.
Here is how the collision of the ball with the different objects affects the player:
 ● collision with the red flag: the player wins the current level and levels up.
 ● collision with the monster: the player immediately loses the level and repeats it.
 ● collision with the sea: the player immediately loses the level and repeats it.
 ● collision with a spike: the player loses a life (out of three lives).
 ● collision with a star: adds 100 to the score.
For each level, the player has three lives. The game contains three levels.
---------------------------------------------------------------------------------------------------------
------------------------------------------------- Design ------------------------------------------------
---------------------------------------------------------------------------------------------------------
 ● The main creates a Level object and calls for the function Level::startLevel(); that displays the
homepage and starts the levels one after another in a for loop. For each level, the function creates
a Controller object that manages its level as follows:
 ● The controller contains, among the rest, the classes Ball and Map. The controller opens a window for
the level, creates a box2d world and initializes the Map of the current level (more about the map is
following), the function Controller::run() handles the game by initializing the elements of the game
such as Map and redFlag. Then, in a while loop, the function continues to handle the window of the game:
For each ineration, the function updates the positions and statuses of the box2d bodies and SFML elements
of the game, calls for functions that check the collision of the ball with other elements then takes
an action according to the results it recieves and displays the score on the window.
Finally, the controller handles the input of the player and calls for the function Ball::move() to handle
the ball's movement.
 ● The map object contains the "map" of the game; meaning that it contains the ground blocks, water
blocks, stars, Obstacles etc... . The map contains the initial sf::Textures of the elements that it
contains and it sends a "copy" of the needed texture for the c-tors, for example it sends the Sea c-tor
the Texture "Sea" by reference and the Sea object reserves an sf::Sprite copy of it as a private member.
The map builds the map of the current level by reading a file that contains data about the ground (and
sea) of the level, then it adds other elements, such as the stars, as needed. For each element that
it adds, the map calls for a suitable c-tor to create the element then saves the newly created element in
a suitable vector for furthur checkups. For example, the map calls for the c-tor of Ground then adds
the new ground to its private member "m_ground". Finally, the map runs over the vectors that it contains
to check collisions or to draw them on the window.
 ● The static Objects in the game, such as the stars or the obstacles, create the box2d body and shape
and the SFML object then reserves them as private members. They recieve the game's window to draw thier
sf::Sprite private member on it. In addition, they check their collision with the ball and return
the result to the map.
 ● The moving objects, such as the Ball, execute the same tasks as the static Objects in additon to
updateing thier positions and executing their movements.
 ● LevelData updates the player with info about the current game such as the number of lives that they
 still have and their score. At the end of each level, it opens a window that displays the result of
 the level. It recieves data from the controller, updates the level's info then displays them.
---------------------------------------------------------------------------------------------------------
--------------------------------------------- List of Files ---------------------------------------------
---------------------------------------------------------------------------------------------------------
Source files:-
--------------
 ● main.cpp: builds a Level object and runs the function "Level::run()". 
 ● Controller.cpp: manages the game and handles the user's input, displayes the game
   windows, calls for the functions of other objects to update thier data, collects data from them and 
   acts accordingly.
 ● Map.cpp: loads all the textures of ground, water and the rest of the elements,
   reads the map of the current level from a file and calls for the objects c-tors to add ground blocks
   water blocks, stars, etc... to the current level's map. And saves them in vectors (private member) for
   further checkups.
   it also runs over the vectors that it contains to check collisions or to draw them on the window.
 ● Level.cpp: displays the homepage and starts the levels one after another in a for loop.
 ● HomePage.cpp: displays the home page and controls window.
 ● LevelData.cpp: updates info about the current level, e.g the number of lives and the score.
   At the end of each level it opens a window that displays the result of the level.
 ● GameObject.cpp: a virtual class that all the game's object inherit from.
 ● MovingObject.cpp: a virtual class that all the moving object inherit from.
 ● Ball.cpp: builds the ball and suits the SFML elements of the ball to the box2d elements, checks the
   the moves and collisions of the ball and updates its position in the game's window.
 ● Ground.cpp: builds a ground object and places it in a certain place in the window depending on some
   data that the c-tor recieves.  Suits the SFML elements of the ground block to the box2d elements.
 ● Sea.cpp: builds a sea object and places it in a certain place in the window depending on some
   data that the c-tor recieves.  Suits the SFML elements of the sea block to the box2d elements,
   and checks collision with the ball. 
 ● Star.cpp: builds a star object and places it in a certain place in the window depending on some
   data that the c-tor recieves.  Suits the SFML elements of the star to the box2d elements,
   and checks collision with the ball.
 ● Box.cpp: builds a box object and places it in a certain place in the window depending on some
   data that the c-tor recieves.  Suits the SFML elements of the box to the box2d elements,
   and checks collision with the ball.
 ● Obstacle.cpp: builds an obstacle object (spikes) and places it in a certain place in the window
   depending on some data that the c-tor recieves. 
   Suits the SFML elements of the obstacle to the box2d elements, and checks collision with the ball.
 ● Monster.cpp: builds a monster object, places it in a certain place in the window and continues to
   update its position through out the level.
   Suits the SFML elements of the monster to the box2d elements, and checks collision with the ball.
 ● RedFlag.cpp: handles the red flag at the end of each level.
 ● Sky.cpp: calculates the number of the sky sprites that are needed for the level and builds the
   background of the window (the sky).
 ● Tree.cpp: builds a star object and places it in a certain place in the window depending on some
   data that the c-tor recieves. The trees are added at the beginning and at the end of each level to
   restrict the movement of the ball. 
Headers:-
---------
 ● Controller.h: contains the Controller class.
 ● HomePage.h: contains the HomePage class.
 ● Level.h: contains the level class.
 ● LevelData.h: contains the LevelData class.
 ● Map.h: contains the Map class that contains vectors of elements of the map of the current level.
 ● Ball.h: contains the Ball class that contains the ball data and manages its moves.
 ● Ground.h: contains the Ground class that contains a ground block.
 ● Sea.h: contains the Sea class that contains a sea block.
 ● Star.h: contains the Star class.
 ● Monster.h: contains the Monster class.
 ● Box.h: contains the Box class.
 ● Obstacle.h: contains the Obstacle class.
 ● RedFlag.h: contains the RedFlag class.
 ● Sky.h: contains the Sky class.
 ● Tree.h: contains the Tree class.
 ● GameObject.h: contains the (virtual) class GameObject that has 2 children: MovingObject & StaticObject.
 ● MovingObject.h: contains the (Virtual) class MovingObject that inrerates from class GameObject. 
 ● StaticObject.h: contains the (virtual) class StaticObject that inrerates from class GameObject.
 
Resources:
----------
Contains jpg, png and wav files that are used in the game, in addition to txt files such as the files of
the levels' maps.
---------------------------------------------------------------------------------------------------------
-------------------------------------------- Data Structures --------------------------------------------
---------------------------------------------------------------------------------------------------------
Classes:
--------
 ● Controller: contains the private members and functions of the controller in addtion to the main objects
   of the game.
 ● HomePage: contains the members and functions of the HomePage.
 ● Level: contains the members and functions of the current Level.
 ● LevelData: contains and updates info about the current level, e.g the number of lives and the score.
 ● Map: contains the members and functions of the Map, in addition to vectors of the ground blocks,
   the water blocks, stars... .
 ● GameObject: (virtual) class that has two children: MovingObject and StaticObject.
 ● MovingObject: (virtual) class that inrerates from class GameObject. All the moving objects of the
   game inherates from it.
 ● StaticObject: (virtual) class that inrerates from class GameObject. All the static objects of the
   game inherates from it.
 ● Ball: contains the members and functions of the ball, inherates from class MovingObject.
    Inherartes from MovingObject.
 ● Ground: contains the members and functions of a ground block. Each level is made up by some grounds.
   It inheartes from class StaticObject.
 ● Sea: contains the members and functions of a sea block. Each level is made up by some sea blocks.
   It inheartes from class StaticObject.
 ● Sea: contains the members and functions of a star. Each level is made up by some stars.
   It inheartes from class StaticObject.
 ● Monster: contains the members and functions of a monster.    It inheartes from class MovingObject.
 ● Obstacle: contains the members and functions of an Obstacle. Each level is made up by some Obstacles.
   It inheartes from class StaticObject.
 ● Obstacle: contains the members and functions of a box. Each level is made up by some boxes.
   It inheartes from class StaticObject.
 ● Sky: contains the members and functions of the sky (background).  Inherartes from StaticObject.
 ● RedFlag: handles the red flag at the end of each level. Inherartes from StaticObject.
  ● Tree: contains the members and functions of the Tree.  Inherartes from StaticObject.
Vectors:
--------
Most of the vectors in the game contains smart pointers "shared_ptr" as thier cells, each pointer
points (usually) to an object of a certain class.
---------------------------------------------------------------------------------------------------------
------------------------------------------ Noteable Algorithms ------------------------------------------
---------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------
---------------------------------------------- Known Bugs -----------------------------------------------
---------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------
------------------------------------------- Additional Notes --------------------------------------------
---------------------------------------------------------------------------------------------------------
