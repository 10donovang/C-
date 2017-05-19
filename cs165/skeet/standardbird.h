/***********************************************************************
 * Header File:
 *    Standard Bird : The representation of a normal bird. Tweet tweet.
 * Author:
 *    Donovan Gregory
 * Summary:
 *    Creates a bird on the screen and sends it in some direction. Killing
 *    it when it reaches the end of the screen
 ************************************************************************/


#ifndef STANDARDBIRD_H
#define STANDARDBIRD_H

#include <iostream>
#include "point.h"
#include "velocity.h"
#include "flyingobject.h"
#include "uiDraw.h"
#include "bird.h"

using namespace std;

/*********************************************
 * BIRD
 * Overview of birdies
 *********************************************/
class StandardBird : public Bird
{
public:
  StandardBird();
  StandardBird(Point defaultPoint);
  virtual void draw(){drawCircle(getPoint(), 7);}
  virtual int hit(){kill(); return points;}

 private:
  int points;
  bool alive;
  Point posistion;
  Velocity speed;
};


#endif
