/***********************************************************************
 * Header File:
 *   Flying Object : Anything that moves. Not the alien kind...Most likely.
 * Author:
 *    Donovan Gregory
 * Summary:
 *    The way all my objects shall fly. 
 ************************************************************************/


#ifndef BULLET_H
#define BULLET_H
#define BULLET_SPEED 10.0

#include <iostream>
#include <cmath>
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "flyingobject.h"
#include "rifle.h"

/*********************************************
 * Flying Objects
 * Objects that fly.  
 *********************************************/
class Bullet : public FlyingObject
{
  
 public:
  Bullet();
  void kill();
  void draw();
  void fire(Point startPoint, float angle);
   
   
private:

   Point posistion; //position of the lander
   Velocity speed; //speed of ship
   bool alive; // It's ALIVE!!!!!!
};

#endif // POINT_H
