/***********************************************************************
 * Source File:
 *   Bird:  It flys
 * Author:
 *    Donovan Gregory
 * Summary:
 *    Birdie
 ************************************************************************/

#include "bird.h"
#include "standardbird.h"

using namespace std;


/*******************************************
 * Bird: Hit
 * what happens when a bird hits the bullet. 
 *******************************************/
StandardBird :: StandardBird()
{
  Point newPoint(0, 0);
  setPoint(newPoint);
  Velocity newSpeed(0, 0);
  setVelocity(newSpeed);
  points = 1;
}

StandardBird :: StandardBird(Point defaultPoint)
{
  setPoint(defaultPoint);
  if(posistion.getY() < 0)
    {
      int dx = 5;
      int dy = 3;
      Velocity newSpeed(dx, dy);
      setVelocity(newSpeed);
    }
  
  else
    {
      int dx = 5;
      int dy = -3;
      Velocity newSpeed(dx, dy);
      setVelocity(newSpeed);
    }
  points = 1;
  setAlive(true);
}

  
  


   
