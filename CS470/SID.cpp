/***********************************************************************
* Program:
*    Unit 3, ACLs
*    Brother Wilson, CS470
* Author:
*    Donovan Gregory
* Summary: 
*    This program tracks a collection of student grades
*    Currently, it performs no authentication and furthermore
*    is so trivially hack-able that it is a joke.  Hahaha.  Why
*    is noone laughing?  OK, as you guess, your job is to make
*    this program secure.  Enjoy!
************************************************************************/


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

#define nonStudents 2 
typedef short SID;


struct ACE {
   SID sid;
   bool read;
   bool write;
   string name;
};

struct ACL{
   ACE ace;
};

const ACE sidBob = {0,true,true,"all"};
const ACE sidHans = {1,false,true,"all"};
const ACE sidSam = {2,true,false,"Sam"};
const ACE sidSue = {3,true,false,"Sue"};
const ACE sidSly = {4,true,false,"Sly"};
const ACE sidHack = {-1,false,false,"Hack"};
const ACL acl[]={sidBob,sidHans,sidSam,sidSue,sidSly,sidHack};

struct Resource
{
   const char *filename;   // where it is located
};

const Resource resources[3] =
{
//   { "/home/cs470/unit3/sam.txt" },
//   { "/home/cs470/unit3/sue.txt" },
//   { "/home/cs470/unit3/sly.txt" }
{ "sam.txt" },
{ "sue.txt" },
{ "sly.txt" }
};


/*****************************************************************
 *****************************************************************
 *                       Student Grade class                     *
 *****************************************************************
 *****************************************************************/
struct Item
{
   float weight;
   float score;
};

/***************************************************
 * One instance of a student grade
 ***************************************************/
class StudentGrade
{
public:
   StudentGrade(const Resource & resource);
   ~StudentGrade();
   string getLetterGrade(); // output letter grade B+
   float  getNumberGrade(); // integral number grade 88
   void   displayScores(SID); // display scores on screen
   void   editScores(SID); // interactively edit score
   void   setScore( int iScore, float score);
   float  getScore( int iScore);
   void   setWeight(int iScore, float weight);
   float  getWeight(int iScore);
   string getName() { return name; };
private:
   bool change;
   string name;                    // student's name
   vector < Item > scores;         // list of scores and weightings
   const char * filename;
   
   void editScore(int);  // edit one score
};

/**********************************************
 * SET SCORE
 **********************************************/
void StudentGrade::setScore( int iScore, float score)
{
   assert(iScore >= 0 && iScore < scores.size());
   scores[iScore].score = score;
   change = true;
}

/**********************************************
 * GET SCORE
 **********************************************/
float StudentGrade::getScore(int iScore)
{
   assert(iScore >= 0 && iScore < scores.size());
   return scores[iScore].score;
}

/****************************************
 * SET WEIGHT
 ****************************************/
void StudentGrade::setWeight(int iScore, float weight)
{
   assert(iScore >= 0 && iScore < scores.size());
   if (weight >= 0.0)
   {
      scores[iScore].weight = weight;
      change = true;
   }
}

/**********************************************
 * GET WEIGHT
 **********************************************/
float StudentGrade::getWeight(int iScore)
{
   assert(iScore >= 0 && iScore < scores.size());
   return scores[iScore].weight;
}

/***********************************************
 * STUDENT GRADE
 * constructor: read the grades from a file
 **********************************************/
StudentGrade::StudentGrade(const Resource & resource) : change(false)
{
   filename = resource.filename;
   assert(filename && *filename);
   
   // open file
   ifstream fin(filename);
   if (fin.fail())
      return;

   // read name
   getline(fin, name);

   // read scores
   Item item;
   while (fin >> item.score >> item.weight)
      scores.push_back(item);

   // close up shop
   fin.close();
}

/**************************************************
 * DESTRUCTOR
 * Write the changes to the file if anything changed
 *************************************************/
StudentGrade::~StudentGrade()
{
   assert(filename && *filename);

   if (!change)
      return;
   
   // open file
   ofstream fout(filename);
   if (fout.fail())
      return;

   // header is the students name
   fout << name << endl;

   // write the data
   for (int iScore = 0; iScore < scores.size(); iScore++)
      fout << scores[iScore].score
           << "\t"
           << scores[iScore].weight
           << endl;

   // make like a tree
   fout.close();
}

/****************************************
 * Edit only one score.
 ***************************************/
void StudentGrade::editScore(int iScoreEdit)
{
   float userInput;  // user inputed weight.
   
   assert(iScoreEdit >= 0 && iScoreEdit < scores.size());

   //
   // Score
   //
   
   // get new score
   cout << "Enter grade: ";
   cin  >> userInput;
         
   // validate
   while (userInput > 100 || userInput < 0)
   {
      cout << "Invalid grade.  Select a number between 0 and 100: ";
      cin  >> userInput;
   }
   setScore(iScoreEdit, userInput);

   //
   // Weight
   //
   
   // get the weight
   cout << "Enter the weight for the score or (0) for unchanged: ";
   cin >> userInput;
   
   // validate
   while (userInput > 1.0 || userInput < 0.0)
   {
      cout << "Invalid weight.  Select a number between 0 and 1: ";
      cin  >> userInput;
   }
   if (userInput != 0.0)
      setWeight(iScoreEdit, userInput);
         
   return;
}


/*********************************************
 * Edit scores until user says he is done
 *******************************************/
void StudentGrade::editScores(SID sid)
{
   // Give the user some feedback
   cout << "Editing the scores of "
        << name
        << endl;

   // display score list
   cout << "Score list\n"
        << "\tScore \tWeight\n";
   
      for (int iScore = 0; iScore < scores.size(); iScore++)
      {
         cout << "(" << iScore + 1 << ")"
            << "\t";
         if(sid != 1){
         float score = getScore(iScore);
         float weight = getWeight(iScore);

         cout << score << "%"
            << "\t"
            << weight;
         }
         cout << endl;
         
      }
   
   cout << "(0)\tExit\n";
   
   // prompt
   bool done = false;
   while (!done)
   {
      // prompt
      int iScoreEdit;
      cout << "Which score would you like to edit (0-"
           << scores.size()
           << "): ";
      cin  >> iScoreEdit;
      
      // validate score number
      while (iScoreEdit > scores.size() || iScoreEdit < 0)
      {
         cout << "Invalid number.  Select a number between 0 and "
              << scores.size()
              << ": ";
         cin  >> iScoreEdit;
      }

      // from 1 based to 0 based
      iScoreEdit--;

      // edit the score
      if (iScoreEdit != -1)
      {
         // edit score
         editScore(iScoreEdit);

         // continue
         char response;
         cout << "Do you want to edit another score? (Y/N) ";
         cin  >> response;
         done = (response == 'N' || response == 'n');
      } 
      else
         done = true;
   }

   return;
}

/************************************************
 * Display scores
 ***********************************************/
void StudentGrade::displayScores(SID sid)
{
   if (scores.size() == 0)
      return;

   // name
   cout << "Student name:\n\t"
        << name 
        << endl;

   // grade
   cout << "Grade:\n\t"
        << getNumberGrade() << "%"
        << " : "
        << getLetterGrade()
        << endl;

   // detailed score
   cout << "Detailed score:\n"
        << "\tScore \tWeight\n";
   for (int iScore = 0; iScore < scores.size(); iScore++)
      cout << "\t"
           << getScore(iScore) << "%"
           << "\t"
           << getWeight(iScore)
           << endl;
   
   // done
   return;
}

/***************************************************
 * Letter Grade include A- and C+
 ***************************************************/
string StudentGrade::getLetterGrade()
{
   const char chGrades[] = "FFFFFFDCBAA";
   int nGrade = (int)getNumberGrade();

   // paranioa will destroy ya
   assert(nGrade >= 0.0 && nGrade <= 100.0);

   // Letter grade
   string s;
   s += chGrades[nGrade / 10];

   // and the + and - as necessary
   if (nGrade % 10 >= 7 && nGrade / 10 < 9  && nGrade / 10 > 5)
      s += "+";
   if (nGrade % 10 <= 2 && nGrade / 10 < 10 && nGrade / 10 > 5)
      s += "-";

   return s;
}

/***************************************************
 * Number grade guarenteed to be between 0 - 100
 ***************************************************/
float StudentGrade::getNumberGrade()
{
   // add up the scores
   float possible = 0.0;
   float earned   = 0.0;
   for (int iScore = 0; iScore < scores.size(); iScore++)
   {
      earned   += scores[iScore].score * scores[iScore].weight;
      possible += scores[iScore].weight;
   }

   if (possible == 0.0)
      return 0.0;
   else
      return (earned / possible);
}

/*****************************************************************
 *****************************************************************
 *                           INTERFACE                           *
 *****************************************************************
 *****************************************************************/
class Interface
{
public:
   Interface();

   //void display();
   void interact(SID);
private:
   int promptForStudent();
   vector < StudentGrade > students;
};


/*************************************************
 * Prompt the user for which student it to be worked
 * with.  Return -1 for none
 *************************************************/
int Interface::promptForStudent()
{
   int iSelected;

   // prompt
   cout << "Which student's grade would you like to review?\n";
   for (int iStudent = 0; iStudent < students.size(); iStudent++)
      cout << '\t'
           << iStudent + 1
           << ".\t"
           << students[iStudent].getName()
           << endl;
   cout << "\t0.\tNo student, exit\n";
   cout << "> ";
   
   // get input
   cin >> iSelected;
   while (iSelected < 0 || iSelected > students.size())
   {
      cout << "Invalid selection.  Please select a number between 1 and "
           << students.size()
           << " or select -1 to exit\n";
      cout << ">";
      cin >> iSelected;
   }
   
   return --iSelected;
}

/***********************************************
 * update the student records interactively
 ***********************************************/
void Interface::interact(SID sid) 
{
   int iSelected;
   if(acl[sid].ace.name != "all"){
      students[sid - nonStudents].displayScores(sid - nonStudents);
      return;
   }
   else{
      while (-1 != (iSelected = promptForStudent()))
      {
         if(acl[sid].ace.write){
         // edit grades as necessary
         students[iSelected].editScores(sid);
         }
         
         if(acl[sid].ace.read){        
         // show the results
         students[iSelected].displayScores(sid);
         }
         // visual separater
         cout << "---------------------------------------------------\n";
   }
   }

   return;
}

/*****************************************************
 * CONSTRUCTOR
 * Populate the grades list from a file
 ****************************************************/
Interface::Interface()
{
   for (int i = 0; i < sizeof(resources) / sizeof(Resource); i++)
   {
      StudentGrade student(resources[i]);
      students.push_back(student);
   }
}

/**************************************************
 * DISPLAY
 * Display stuff
 *************************************************/
/*void Interface::display()
{
   for (int i = 0; i < students.size(); i++)
      students[i].displayScores();
}
*/
/**************************************************************
 * USER
 * All the users currently in the system
 *************************************************************/
struct User
{
   const char *name;
   const char *password;
};
const User users[] =
{
   { "Bob",  "passwordBob" },
   { "Hans", "passwordHans" },
   { "Sam",  "passwordSam" },
   { "Sue",  "passwordSue" },
   { "Sly",  "passwordSly" }
};




#define ID_INVALID -1

/**********************************************
 * authenticate the user
 *********************************************/
int authenticate()
{
   // prompt for username
   string name;
   cout << "Username: ";
   cin  >> name;

   // prompt for password
   string password;
   cout << "Password: ";
   cin  >> password;

   // search for username. If found, verify password
   for (int idUser = 0; idUser < sizeof(users) / sizeof(users[0]); idUser++)
      if (name     == string(users[idUser].name    ) &&
          password == string(users[idUser].password))
         return idUser;

   // display error
   //cout << "Failed to authenticate " << name << endl;
   return ID_INVALID;
}

/*********************************************
 * Main:
 *  open files
 *  edit scores
 *  save files
 ********************************************/
int main()
{
   SID sidUser = authenticate();
   
   if(sidUser == acl[5].ace.sid)
   {
      cout << "Error: Insufficient permissions to perform any action";
      return 0;
   }   
   Interface interface;

   interface.interact(sidUser);
   
   return 0;
}
