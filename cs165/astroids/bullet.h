#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40

#include <iostream>
#include <cmath>
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "flyingObject.h"
#include "ship.h"

// Put your Bullet class here

/*********************************************
 * Flying Objects
 * Objects that fly.  
 *********************************************/
class Bullet : public FlyingObject
{
  
 public:
  Bullet();
  virtual int hit();
  void draw();
  void fire();

 
 
   
   
private:

   Point posistion; //position of the lander
   Velocity speed; //speed of ship
   bool alive; // It's ALIVE!!!!!!
   int count;
   float angle;
};



#endif /* bullet_h */
