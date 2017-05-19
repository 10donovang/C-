/***********************************************************************
 * Header File:
 *   Flying Object : Anything that moves. Not the alien kind...Most likely.
 * Author:
 *    Donovan Gregory
 * Summary:
 *    The way all my objects shall fly. 
 ************************************************************************/


#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include <iostream>
#include "point.h"
#include "velocity.h"

/*********************************************
 * Flying Objects
 * Objects that fly.  
 *********************************************/
class FlyingObject
{
 public:
   // sets position
  void setPoint(Point newPoint){this->posistion = newPoint;}

   // sets speed
   void setVelocity(Velocity newSpeed){this->speed = newSpeed;}
     
   // find our position
   Point getPoint() const {return posistion;}

    //sets if alive
   void setAlive(bool live){this->alive = live;}

    //retrieves if the lander is alive
   bool isAlive() const {return alive;}

   // find the current speed
   Velocity getVelocity() const {return speed;}

   //Advances the object
   void advance();
   
   
private:

   Point posistion; //position of the lander
   Velocity speed; //speed of ship
   bool alive; // It's ALIVE!!!!!!
};

#endif // POINT_H
