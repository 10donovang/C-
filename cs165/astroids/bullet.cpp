#include "bullet.h"
#include <iostream>

using namespace std;


// Put your bullet methods here
/*******************************************
 * Bullet
 * Sets the default 
 *******************************************/
Bullet :: Bullet()
{
  Point startPoint(0, 0);
  setPoint(startPoint);
  setAlive(true);
  count = 0;
}



/**********************************************
 * Bullet: Kill
 * Death to this bullet
 **********************************************/
int Bullet :: hit()
{
  setAlive(false);
  return 0;
}

/************************************************
 * Bullet: Draw
 * Draws the bullet on the screen
 ************************************************/
void Bullet :: draw()
{
  drawDot(getPoint());
}

/*************************************************
 * Bullet: Fire
 * Fires the bullet at the birdie
 *************************************************/
void Bullet :: fire()
{
  int angle = getAngle();
  float dy = BULLET_SPEED * (cos(M_PI / 180.0 * angle));
  float dx = BULLET_SPEED * (sin(M_PI / 180.0 * angle));
  Velocity bulletSpeed(dx, dy);
  setVelocity(bulletSpeed);
}




