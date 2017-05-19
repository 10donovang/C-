#include "rocks.h"

using namespace std;
// Put your Rock methods here
/**********************************************************************
 * Source File:
 *   Rock: It crashes things in space
 * Author:
 *   Donovan Gregory
 * Summary:
 *    Giant Rock....IN SPACE
 **********************************************************************/

BigRock :: BigRock()
{
  int x = random(-199, 200);
  int y = random(-199, 200);
  while(x <= 100 && x >= -100 && y<= 100 && y >= -100 )
    {
      y = random(-199, 200);
      x = random(-199, 200);
    }
  Point defaultPoint(x, y);
  setPoint(defaultPoint);
  int angle = random(0, 360);
  float dx = 1 * (-cos(M_PI / 180.0 * angle));
  float dy = 1 *  (sin(M_PI / 180.0 * angle));
  Velocity newSpeed(dx, dy);
  setVelocity(newSpeed);
  points = 1;
  setAlive(true);
 
}

MediumRock :: MediumRock()
{
  Point newPoint(0, 0);
  setPoint(newPoint);
  Velocity newSpeed(0, 0);
  setVelocity(newSpeed);
  points = 3;
  setAlive(true);
}



SmallRock :: SmallRock()
{
  Point newPoint(0, 0);
  setPoint(newPoint);
  Velocity newSpeed(0, 0);
  setVelocity(newSpeed);
  points = 5;
  setAlive(true);
}




  
