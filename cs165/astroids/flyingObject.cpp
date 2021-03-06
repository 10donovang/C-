#include "flyingObject.h"
/***********************************************************************
 * Source File:
 *   Flying Object:  It flys
 * Author:
 *    Donovan Gregory
 * Summary:
 *    Moving the object
 ************************************************************************/
/*******************************************
 * Flying:
 * Default constructor
 *******************************************/
FlyingObject :: FlyingObject()
{
  count = 0;
}

/*******************************************
 * Flying: Advance
 * Advances the flying object. 
 *******************************************/
void FlyingObject::advance()
{
  posistion.addX(-speed.getDx());
  posistion.addY(speed.getDy());
   if(posistion.getX() >= 202)
    posistion.setX(posistion.getX() -399);
  else if(posistion.getX() <= -202)
    posistion.setX(posistion.getX() + 399);
  if(posistion.getY() >= 202 || posistion.getY() <= -202)
  posistion.setY(-posistion.getY());
  getPoint();
  count++;
}


// Put your FlyingObject method bodies here
