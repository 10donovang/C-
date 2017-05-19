/***********************************************************************
* Program:
*    Checkpoint 09a, Virtual Functions
*    Brother Ercanbrack, CS165
* Author:
*    Donovan Gregory
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your classes here
class Car
{
protected:
   string name;
public:
   Car(){string defaultName = "Unknown model"; setName(defaultName);}
   string getName() {return name;}
   void setName(string newName){this->name = newName;}
   virtual string getDoorSpecs ()
   {
      string doorSpecs = "Unknown Model";
      return doorSpecs;
   }
};

class Civic : public Car
{
public:
   Civic(){string ciName = "Civic"; setName(ciName);}
   string getDoorSpecs()
   {
      string doorSpecs1 = "4 doors";
      return doorSpecs1;
   }
};

class Odyssey : public Car
{
public:
   Odyssey(){string oName = "Odyssey"; setName(oName);}
   string getDoorSpecs()
   {
      string doorSpecs2 = "2 front doors, 2 sliding doors, 1 tail gate";
      return doorSpecs2;
   }
};

class Ferrari : public Car
{
public:
   Ferrari(){string fName = "Ferrari"; setName(fName);}
    string getDoorSpecs()
   {
      string doorSpecs3 = "2 butterfly doors";
      return doorSpecs3;
   }
};
/**********************************************************************
 * Function: attachDoors
 * Purpose: This function can accept any type of Car object. It will
 *  call the appropriate functions to display the name and the doors info.
 ***********************************************************************/

// TODO: Include your attachDoors function here
void attachDoors(Car *car)
{
   cout << "Attaching doors to " << car->getName() << " - "
        << car->getDoorSpecs() << endl;
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // You should not change main

   Civic *civic = new Civic;
   Odyssey *odyssey = new Odyssey;
   Ferrari *ferrari = new Ferrari;

   attachDoors(civic);
   attachDoors(odyssey);
   attachDoors(ferrari);

   return 0;
}


