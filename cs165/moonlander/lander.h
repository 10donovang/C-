/***********************************************************************
 * Header File:
 *    LANDER : A class representing the lander space ship
 * Author:
 *    Donovan Gregory
 * Summary:
 *    The space ship that fills your dreams and everything you wanted to 
 *    know about it. 
 ************************************************************************/

#ifndef LANDER_H
#define LANDER_H

#include "uiDraw.h"
#include "point.h"
#include "velocity.h"

/********************************************
 * Lander
 * Spaceship!
 ********************************************/
class Lander
{
public:
   // create the default spaceship
   Lander();
      
   // display the lander on the screen
   void draw();

   // set our starting posistion
   void setPoint(){Point startPoint(0.0, 150.0); this->posistion = startPoint;}
     
   // find our position
   Point getPoint() const {return posistion;}

   // find the current speed
   Velocity getVelocity() const {return speed;}

   //retrieves if the lander is alive
   bool isAlive()  {return alive;}

   //finds out if lander is landed
   bool isLanded() {return landed;}

   //finds the amount of fuel left
   int getFuel() const {return fuel;}

   //figures out if the lander has enough fuel to thrust
   bool canThrust();

   // Sets if flames are coming from bottom
   void setBottom(bool newBottom) {this->bottom = newBottom;}

   // Retrieves if flames are from bottom
   bool getBottom() {return bottom;}

   // Sets if Flames are coming from left
   void setLeft(bool newLeft) {this->left = newLeft;}

   // gets if flames are coming from left
   bool getLeft() {return left;}

   // sets if flames are coming from right
   void setRight(bool newRight) {this->right = newRight;}

   //gets if flames are coming from right
   bool getRight() {return right;}

   //sets landed
   void setLanded(bool land){this->landed = land;}

   //sets if alive
   void setAlive(bool live){this->alive = live;}

   // sets fuel
   void setFuel(int newFuel){this->fuel = newFuel;}

   // sets initial fuel
   void setInitialFuel(int intFuel){this->fuel = intFuel;}

   //Applies the gravity to lander
   void applyGravity(float newGravity);

   //Applies thruster left
   void applyThrustLeft();

   //Applies thruster to the right
   void applyThrustRight();

   //Applies thrust from the bottom
   void applyThrustBottom();

   //Advances the ship
   void advance();
   
   
private:

   Point posistion; //position of the lander
   Velocity speed; //speed of ship
   bool alive;
   bool landed;
   int fuel;
   bool bottom;
   bool left;
   bool right;
   
};


#endif
