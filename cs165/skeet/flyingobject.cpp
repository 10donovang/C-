/***********************************************************************
 * Source File:
 *   Flying Object:  It flys
 * Author:
 *    Donovan Gregory
 * Summary:
 *    Moving the object
 ************************************************************************/

#include "flyingobject.h"


/*******************************************
 * Flying: Advance
 * Advances the flying object. 
 *******************************************/
void FlyingObject::advance()
{
  posistion.addX(speed.getDx());
  posistion.addY(speed.getDy());
  getPoint();
}



   
