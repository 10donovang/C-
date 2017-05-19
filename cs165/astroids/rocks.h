#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include <iostream>
#include "point.h"
#include "velocity.h"
#include "flyingObject.h"
#include"uiDraw.h"
#include <cmath>

using namespace std;

// Define the following classes here:
//   Rock
class Rock : public FlyingObject
{
 public:
  virtual int kill() = 0;
  void setPoints(int newPoints){this->points = newPoints;}
  virtual int size() = 0;
  

 private:
  int points;
};

//   BigRock
class BigRock :  public Rock
{
 public:
  BigRock();
  virtual void draw() {drawLargeAsteroid(getPoint(), BIG_ROCK_SPIN);}
  virtual int hit() {kill(); return points;}
  virtual int size(){return BIG_ROCK_SIZE;}
  virtual int kill() {setAlive(false); return 1;} 
 

 private:
  int points;
  bool alive;
  Point posistion;
  Velocity speed;
};
//   MediumRock
class MediumRock : public Rock
{
 public:
MediumRock();
 MediumRock(Point defaultPoint, float dx, float dy);
 virtual void draw() {drawMediumAsteroid(getPoint(), MEDIUM_ROCK_SPIN);}
 virtual int hit(){kill(); return points;}
 virtual int size(){return MEDIUM_ROCK_SIZE;}
 virtual int kill(){setAlive(false); return 3;}
 

 private:
 int points;
 bool alive;
 Point posistion;
 Velocity speed;
};

//   SmallRock
class SmallRock : public Rock
{
 public:
  SmallRock();
  SmallRock(Point defaultPoint, float dx, float dy);
  virtual void draw() {drawSmallAsteroid(getPoint(), SMALL_ROCK_SPIN);}
  virtual int hit(){kill(); return points;}
  virtual int size(){return SMALL_ROCK_SIZE;}
  virtual int kill(){setAlive(false); return 5;}

 private:
  int points;
  bool alive;
  Point Posistion;
  Velocity speed;
};

#endif /* rocks_h */
