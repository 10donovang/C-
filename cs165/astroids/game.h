/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>
# include <iostream>

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "bullet.h"
#include "rocks.h"
#include "flyingObject.h"


#define CLOSE_ENOUGH 15

/***************************************
 * GAME
 * This is the game. Don't lose
 ***************************************/
class Game
{
 public:
  /*******************
   * Constructor
   * Starts the game
   *******************/
  Game(Point tl, Point br);
  ~Game();

  /********************************************
   * Function : handleInput
   * Description: Does whatever is pushed
   ********************************************/
  void handleInput(const Interface & ui);

  /********************************************
   * Function advance
   * Description: Moves everything forward a step
   ********************************************/
   void advance();
   
   /*********************************************
    * Function: draw
    * Description: draws everything for the game.
    *********************************************/
   void draw(const Interface & ui);
   
private:
   // The coordinates of the screen
   Point topLeft;
   Point bottomRight;
   
   int score;
   Ship ship;
   vector<Rock*> rocks;
   
  

   vector<Bullet> bullets;

 

   /*************************************************
    * Private methods to help with the game logic.
    *************************************************/
   bool isOnScreen(const Point & point);
   void advanceFlyingObjects();
   template <class T>
   float getClosestDistance(FlyingObject *obj1,  const T &obj2) const;
   void handleCollisions();
   void cleanUpZombies();
};

#endif /* GAME_H */
