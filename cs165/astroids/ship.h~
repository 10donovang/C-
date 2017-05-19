#ifndef ship_h
#define ship_h

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include <iostream>
#include <cmath>
#include "flyingObject.h"

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5



// Put your Ship class here
class Ship: public FlyingObject
{
private:
   Point position;
   Velocity speed;
   bool alive;
   float angle;

public:

   /******************************
    * Ship: make ship
    ******************************/
   Ship();
   
   /*****************
    * Drawing
    *****************/
   virtual void draw();

   /*****************
    * Movement
    *****************/
   void moveLeft();
   void moveRight();
   void moveForward();

   /******************
    * hit: We've been
    * hit!
    ******************/
   virtual int hit();
};
#endif /* ship_h */
