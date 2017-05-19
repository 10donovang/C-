/***********************************************************************
 * Implementation File:
 *    LANDER : A class representing the lunar lander
 * Author:
 *    Donovan Gregory
 * Summary:
 *    The space ship that fills your dreams and everything you wanted to 
 *    know about it. 
 ************************************************************************/

#include "lander.h"

/********************************************
 * LANDER :: CONSTRUCTOR
 ********************************************/
Lander :: Lander()
{
  setPoint();
  setInitialFuel(500);
  canThrust();
  setAlive(true);
  setLanded(false);
  setBottom(false);
  setRight(false);
  setLeft(false);
}
  
/*************************************************
 * Function: draw
 * Purpose: draws the lander onto the screen along 
 * with the flames if needed
 *************************************************/ 

void Lander :: draw() 
{
  drawLander(getPoint());
  drawLanderFlames (getPoint(),
		    getBottom(),
		    getLeft(),
		    getRight());
}

/**************************************************************
 * Function canThrust
 * Purpose: To determine if the lander can thrust 
 * Output: Returns true or false
 **************************************************************/

bool Lander :: canThrust()
{
  if (getFuel() <= 0)
    return false;
  else
    return true;
}


/*************************************************************
 * Function: applyGravity
 * Purpose: To apply gravity to the speed velocity
 *************************************************************/

void Lander :: applyGravity(float newGravity)
{
  speed.setDy(newGravity);
}

void Lander :: applyThrustLeft()
{
  if (canThrust() && getFuel() >= 1)
    {
      speed.setDx(0.1);
      setFuel(getFuel()-1);
      setLeft(true);
    }
  else
    return;
}

void Lander :: applyThrustRight()
{
  if (canThrust() && getFuel() >= 1)
    {
      speed.setDx(-0.1);
      setFuel(getFuel()-1);
      setRight(true);
    }
  else
    return;
}

void Lander :: applyThrustBottom()
{
  if (canThrust() && getFuel() >= 3)
    {
      speed.setDy(-0.3);
      setFuel(getFuel()-3);
      setBottom(true);
    }
  else
    return;
}

void Lander :: advance()
{
  posistion.addX(speed.getDx());
  posistion.addY(speed.getDy());
  getPoint();
  setRight(false);
  setLeft(false);
  setBottom(false);
}
  

