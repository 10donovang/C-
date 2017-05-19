/***********************************************************************
 * Header File:
 *    VELOCITY: sets the speed of the lander
 * Author:
 *    Donovan Gregory
 * Summary:
 *    Speed is quite relative
 ************************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H



/********************************************
 * VELOCITY
 * Speed, its how fast one is going
 ********************************************/
class Velocity
{
public:
   // non-default speed
  Velocity (float x, float y)
  {
    setDx(x);
    setDy(y);
  }

   // default speed
   Velocity()
   {
      dx = 0;
      dy = 0;
   }
   
   // set's how much the Landers x posistion is affected   
   void setDx(float x);

   // set's how much the landers y posistion is affected
   void setDy(float y);

   // retrieve's the new spped for x
   float getDx(){return dx;}

   // retrieve's the new speed for y
   float getDy(){return dy;}

 
   
private:

   float dx;
   float dy;
};


#endif
