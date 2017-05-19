/***********************************************************************
 * Implementation File:
 *    Velocity: The speed one travels
 * Author:
 *    Donovan Gregory
 * Summary:
 *    Settings speed and such
 ************************************************************************/

#include "velocity.h"

/************************************************************************
 * Function: setDX
 * Purpose: sets current x speed
 * Input: x
 ************************************************************************/

void Velocity :: setDx(float x)
{
  this->dx = getDx() + x;
}

/*************************************************************************
 * Function: setDY
 * Purpose: sets current y speed
 * Input: y
 *************************************************************************/

void Velocity :: setDy(float y)
{
  this->dy = getDy() - y;
}
