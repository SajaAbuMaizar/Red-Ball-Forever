---------------------------------------------------------------------------------------------------------
------------------------------------ OOP2 Project - Red Ball Forever ------------------------------------
---------------------------------------------------------------------------------------------------------
------------------------------------------- Students and IDs -------------------------------------------- 
-------- Samah Rajabi (student number: 211558556) & Saja Abu Maizar (student number: 208072371) ---------
---------------------------------------------------------------------------------------------------------
----------------------------------------  General Description  ------------------------------------------
---------------------------------------------------------------------------------------------------------
Red Ball Forever is a 2D platform game starring a red rolling ball whose goal is to collect stars and
solve physics-based puzzles. The player joins the ball on its adventure spanning across a series of
levels with increasing difficulty. The player controles the ball's moves using the arrows of the
keyboard and leads it to a hole in order to win the level. In the game, there are some obstacles such as
water, enemy and boxes that would cause the ball to lose meaning the ball should avoid in order to reach
the hole.
---------------------------------------------------------------------------------------------------------
------------------------------------------------- Design ------------------------------------------------
---------------------------------------------------------------------------------------------------------

---------------------------------------------------------------------------------------------------------
--------------------------------------------- List of Files ---------------------------------------------
---------------------------------------------------------------------------------------------------------
Source files:-
--------------
 ● main.cpp: builds a Controller object and runs the function "Controller::run()". 
 ● Controller.cpp: manages the game and handles the user's input, displayes the home page and the game
   windows, calls for the functions of other objects to update thier data, collects data from them and 
   acts accordingly.
 ● Ball.cpp: builds the ball and adapts the SFML elements of the ball to the box2d elements, checks the
   the moves of the ball and updates its position in the game's window through out the levels.
 ● Ground.cpp: builds a ground object and places it in a certain place in the window debending on some
   data that the c-tor recieves.  Adapts the SFML elements of the ground block to the box2d elements.
 ● HomePage.cpp: displays the home page and controls window.
 ● Level.cpp: loads all the textures of ground and water and saves them in a vector (private member),
   reads the map of the current level from a file and calls for the Ground and Sea c-tors to add ground
   blocks and water blockes to the level's map.
 ● Sky.cpp: calculates the number of the sky sprites that are needed for the level and builds the
   background of the window (the sky).
 ● GameObject.cpp:
 ● MovingObject.cpp:
 ● LevelData.cpp: updates info about the current level, e.g the number of lives and the score.
 ● RedFlag.cpp: handles the red flag at the end of each level.
Headers:-
---------
 ● Controller.h: contains the Controller class that contains all the main elements (objects) of the game.
   such as  the ground and the ball.
 ● Ball.h: contains the Ball class that contains the ball data and manages its moves.
 ● Ground.h: contains the Ground class that a ground block.
 ● HomePage.h: contains the HomePage class.
 ● Level.h: contains the level class that contains a vector the elements of the map of the current level.
 ● Sky.h: contains the Sky class.
 ● GameObject.h: contains the (virtual) class GameObject that has 2 children: MovingObject & StaticObject.
 ● MovingObject.h: contains the (Virtual)class MovingObject that inrerates from class GameObject. 
 ● StaticObject.h: contains the (virtual) class StaticObject that inrerates from class GameObject.
 ● LevelData.h: contains the LevelData class.
 ● RedFlag.h: contains the RedFlag class.
Resources:
----------
Contains jpg and png files that are used in the game, in addition to txt files such as the files of
the levels' maps.
---------------------------------------------------------------------------------------------------------
-------------------------------------------- Data Structures --------------------------------------------
---------------------------------------------------------------------------------------------------------
Classes:
--------
 ● Controller: contains the private members and functions of the controller in addtion to the main objects
   of the game.
 ● HomePage: contains the members and functions of the HomePage.
 ● GameObject: (virtual) class that has two children: MovingObject and StaticObject.
 ● MovingObject: (virtual) class that inrerates from class GameObject. All the moving objects of the
   game inherates from it.
 ● StaticObject: (virtual) class that inrerates from class GameObject. All the static objects of the
   game inherates from it.
 ● Level: contains the members and functions of the Level, in addition to a vector of the ground and
   water blocks.
 ● LevelData: contains and updates info about the current level, e.g the number of lives and the score.
 ● Ball: contains the members and functions of the ball, inherates from class MovingObject.
    Inherartes from MovingObject.
 ● Ground: contains the members and functions of a ground block. Each level is made up by some grounds.
   It inheartes from class StaticObject.
 ● Sky: contains the members and functions of the sky (background).  Inherartes from StaticObject.
 ● RedFlag: handles the red flag at the end of each level. Inherartes from StaticObject.
Vectors:
--------
---------------------------------------------------------------------------------------------------------
------------------------------------------ Noteable Algorithms ------------------------------------------
---------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------
---------------------------------------------- Known Bugs -----------------------------------------------
---------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------
------------------------------------------- Additional Notes --------------------------------------------
---------------------------------------------------------------------------------------------------------
