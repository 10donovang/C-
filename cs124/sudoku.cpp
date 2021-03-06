/***********************************************************************
* Program:
*    Project Extra, Sudoku        
*    Brother Falin, CS124
* Author:
*    Donovan Gregory
* Summary: 
*    Write a program that will read a sudoku file into a multi char array
*    it will be able to edit the array, display the puzzle and show what
*    options are lef tin order to complete it. It will most important be 
*    able to save and quit from the file.  
*
*    Estimated:  2.0 hrs   
*    Actual:     2.0 hrs
*      The hardest part was getting the tiny detials that testBed wanted.
************************************************************************/

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cstdlib> 
#define ROWS 9
#define COL 9
using namespace std;
bool load(char file[][COL]);
void display(char fie [][COL]);
void edit(char file [][COL]);
bool save(char file[][COL]);
void showPossible(char file[][COL]);
void showOptions();
void options(char file[][COL]);
bool isPossible(char file[][COL], int cor1, int cor2, int possible);

/**********************************************************************
 * declares the variables file and fail. It then calls load which will
 * load the file into file and if it fails will set fail to false. It will
 * then call show options and display. Finally it will loop options until
 * the user decides to save and quit. 
 ***********************************************************************/
int main()
{
  char file[ROWS][COL];
  for(int i = 0; i < COL; i++)
     for(int j = 0; j < ROWS; j++)
        file[i][j] = '\0';
  bool fail = load(file);
  if (fail == false)
  {
     cout << "There is a problem with the file.\n";
     return 0;
  }
  showOptions();
  cout << endl;
  display(file);
  cout << endl;
  options(file);
  return 0;
}

/************************************************************************
 * Show options will display the different options that the user can
 * choose.
 ************************************************************************/

void showOptions()
{
   cout << "Options:\n"
	   << "   ?  Show these instructions\n" 
	   << "   D  Display the board\n"
	   << "   E  Edit one square\n"
	   << "   S  Show the possible values for a square\n"
        << "   Q  Save and Quit\n";
   return;
}

/*******************************************************************
 * options loops through the different options based on user input
 * until the user saves and quits
 *******************************************************************/

void options(char file[][COL])
{
  bool exit = false;
  char option[2];
  do
  {
     cout << "> ";
     cin.getline(option, 2);
     if(option[0] == 'd' || option[0] == 'D')
     {
        display(file);
        cout << endl;
     }

     else if(option[0] == 'e' || option[0] == 'E')
        edit(file);
     
     else if(option[0] == 's' || option[0] == 'S')
        showPossible(file);
     
     else if(option[0] == 'q' || option[0] == 'Q')
     {
        save(file);
        exit = true;
     }
     
     else if(option[0] == '?')
     {
        showOptions();
        cout << endl;
        cout << endl;
     }
     
     
     else
        cout << "Your choice was invalid. Please choose again.";
     
  }
  while (exit == false);
  return;
}

/*****************************************************************
 *  Load will load a file into the file array. And will return if it did
 * or did not it worked.
 *****************************************************************/
bool load(char file[][COL])
{
  char fileName[256];
  int numCounter = 0;
  bool possible;
  cout << "Where is your board located? ";
  cin.getline(fileName, 256);
  ifstream fin;
  fin.open(fileName);
  if (fin.fail())
    return false;
  for(int i = 0; i < COL; i++)
    {
      for(int j = 0; j < ROWS; j++)
	{
	  fin >> file[i][j];
          if(file[i][j] != '\0')
             numCounter++;
	}
    }
  fin.close();
  char temp;
  for(int k = 0; k < COL; k++)
     for(int v = 0; v < ROWS; v++)
     {
        temp = file[k][v];
        possible = isPossible(file, k, v, temp);
        if(possible == false)
           return false;
     }
  if (numCounter != 81)
     return false;
  
  if (file[ROWS][COL] == '\0')
    return false;
  else
    return true;
}

/**********************************************************
 * Display will display the current board based on the file
 * array.
 **********************************************************/

void display(char file[][COL])
{
  cout << "   A B C D E F G H I\n";
  for(int i = 0; i < ROWS; i++)
    {
       if(i == 3 || i == 6)
          cout << "   -----+-----+-----\n";
      cout << i+1 << "  ";
      for(int j = 0; j < COL; j++)
	{
	  if(file[i][j] == '0')
             file[i][j] = ' ';
	  if(j != 2 && j != 5 && j != 8)
	    cout << file[i][j] << ' ';
	  else if (j != 8)
	    cout << file[i][j] << '|';
	  else
	    cout << file[i][j] << endl;
	}
    }
  return;
}

/****************************************************************
 * showPossible will show the possible values in the future.
 ****************************************************************/
void showPossible(char file[][COL])
{
  char line[3];
  char fCor1[2];
  char fCor2[2];
  char poss[10];
  
  for(int h = 0; h < 3; h++)
  {
     fCor1[h] = '\0';
     fCor2[h] = '\0';
  }
  for (int h = 0; h < 10; h++)
    poss[h] = '\0';
  
  cout << "What are the coordinates of the square: ";
  cin.getline(line, 3);
  line[0] = toupper(line[0]);
  line[1] = toupper(line[1]);
  
  if(line[0] == 'A')
  {
     fCor1[0] = '0';
     fCor2[0] = line[1];
  }
  else if(line[1] == 'A')
  {
     fCor1[0] = '0';
     fCor2[0] = line[0];
  }
  else if(line[0] == 'B')
  {
     fCor1[0] = '1';
     fCor2[0] =  line[1];
  }
  else if(line[1] == 'B')
  {
     fCor1[0] = '1';
     fCor2[0] = line[0];
  }
  else if(line[0] == 'C')
  {
     fCor1[0] = '2';
     fCor2[0] = line[1];
  }
  else if(line[1] == 'C')
  {
     fCor1[0] = '2';
     fCor2[0] = line[0];
  }
  else if(line[0] == 'D')
  {
     fCor1[0] = '3';
     fCor2[0] = line[1];
  }
  else if(line[1] == 'D')
  {
     fCor1[0] = '3';
     fCor2[0] = line[0];
  }
  else if(line[0] == 'E')
  {
     fCor1[0] = '4';
     fCor2[0] = line[1];
  }
  else if(line[1] == 'E')
  {
     fCor1[0] = '4';
     fCor2[0] = line[0];
  }
  else if(line[0] == 'F')
  {
     fCor1[0] = '5';
     fCor2[0] = line[1];
  }
  else if(line[1] == 'F')
  {
     fCor1[0] = '5';
     fCor2[0] = line[0];
  }
  else if(line[0] == 'G')
  {
     fCor1[0] = '6';
     fCor2[0] = line[1];
  }
  else if(line[1] == 'G')
  {
     fCor1[0] = '6';
     fCor2[0] = line[0];
  }
  else if(line[0] == 'H')
  {
     fCor1[0] = '7';
     fCor2[0] = line[1];
  }
  else if(line[1] == 'H')
  {
     fCor1[0] = '7';
     fCor2[0] = line[0];
  }
  else if(line[0] == 'I')
  {
     fCor1[0] = '8';
     fCor2[0] = line[1];
  }
  else if(line[1] == 'I')
  {
     fCor1[0] = '8';
     fCor2[0] = line[0];
  }
  
  int cor2 = atoi(fCor1);
  int cor1 = atoi(fCor2) -1;
  bool possible;
  int pNums = 0;
  for(char y = '1'; y < 58; y++)
    {
      possible = isPossible(file ,cor1 , cor2, y);
      if(possible == true)
	{
	  poss[pNums] = y;
	  pNums++;
	}
    }
  cout << "The possible values for '" << line << "' are: ";
  for(int d = 0; d < pNums; d++)
    {
      if(d < pNums - 1)
	cout << poss[d] << ", ";
      else if(d == pNums - 1)
	cout << poss[d] << endl << endl;
    }
        
  return;
}



/***************************************************************
 * edit will allow the user to change a number based on the location
 * on the board and save it to the array.
 ***************************************************************/
void edit(char file[][COL])
{
  char line[3];
  char fCor1[2];
  char fCor2[2];
  char newNum;
  char possible[10];
  for(int h = 0; h < 3; h++)
  {
     fCor1[h] = '\0';
     fCor2[h] = '\0';
  } 
  
  cout << "What are the coordinates of the square: ";
  cin.getline(line, 3);
  line[0] = toupper(line[0]);
  line[1] = toupper(line[1]);
  
  if(line[0] == 'A')
  {
     fCor1[0] = '0';
     fCor2[0] = line[1];
  }
  else if(line[1] == 'A')
  {
     fCor1[0] = '0';
     fCor2[0] = line[0];
  }
  else if(line[0] == 'B')
  {
     fCor1[0] = '1';
     fCor2[0] =  line[1];
  }
  else if(line[1] == 'B')
  {
     fCor1[0] = '1';
     fCor2[0] = line[0];
  }
  else if(line[0] == 'C')
  {
     fCor1[0] = '2';
     fCor2[0] = line[1];
  }
  else if(line[1] == 'C')
  {
     fCor1[0] = '2';
     fCor2[0] = line[0];
  }
  else if(line[0] == 'D')
  {
     fCor1[0] = '3';
     fCor2[0] = line[1];
  }
  else if(line[1] == 'D')
  {
     fCor1[0] = '3';
     fCor2[0] = line[0];
  }
  else if(line[0] == 'E')
  {
     fCor1[0] = '4';
     fCor2[0] = line[1];
  }
  else if(line[1] == 'E')
  {
     fCor1[0] = '4';
     fCor2[0] = line[0];
  }
  else if(line[0] == 'F')
  {
     fCor1[0] = '5';
     fCor2[0] = line[1];
  }
  else if(line[1] == 'F')
  {
     fCor1[0] = '5';
     fCor2[0] = line[0];
  }
  else if(line[0] == 'G')
  {
     fCor1[0] = '6';
     fCor2[0] = line[1];
  }
  else if(line[1] == 'G')
  {
     fCor1[0] = '6';
     fCor2[0] = line[0];
  }
  else if(line[0] == 'H')
  {
     fCor1[0] = '7';
     fCor2[0] = line[1];
  }
  else if(line[1] == 'H')
  {
     fCor1[0] = '7';
     fCor2[0] = line[0];
  }
  else if(line[0] == 'I')
  {
     fCor1[0] = '8';
     fCor2[0] = line[1];
  }
  else if(line[1] == 'I')
  {
     fCor1[0] = '8';
     fCor2[0] = line[0];
  }
  
  int cor2 = atoi(fCor1);
  int cor1 = atoi(fCor2) -1;
   if(file[cor1][cor2] != ' ')
      {
         cout << "ERROR: Square \'" << line << "\' is filled\n" << endl;
         return;
      }
    
    
  cout << "What is the value at '" << line << "': ";
  cin >> newNum;
  cin.ignore();
  bool valid = isPossible(file, cor1, cor2, newNum);
  if (valid == true)
    {
      cout << endl;
      file[cor1][cor2] = newNum;
    }
  else
    {
      cout << "ERROR: Value '" << newNum << "' in square '" << line
	   << "' is invalid\n" << endl;
    }
  return;
}

/****************************************************************
 * save will ask the user for a new file name and then save the
 * file array to the file.
 ****************************************************************/

bool save(char file[][COL])
{
  string fileName;
  cout << "What file would you like to write your board to: ";
  getline(cin, fileName);
  ofstream fout;
  fout.open(fileName.c_str());
  if (fout.fail())
    return false;
  for(int i = 0; i < ROWS; i++)
    {
      for(int j = 0; j < COL; j++)
      {
         if(file[i][j] == ' ')
            file[i][j] = '0';
         fout << file[i][j];
      }
      fout << endl;
    }
  fout.close();
  cout << "Board written successfully\n";
  return true;
}
  
/*********************************************************
 * is Possible will check to see if the number given works
 * within the given position.
 ********************************************************/

bool isPossible(char file[][COL], int cor1, int cor2, int possible)
{
  
  for(int b = 0; b < COL; b++)
    {
      if (file[cor1][b] == possible)
	return false;
      else if (file[b][cor2] == possible)
	return false;
    }
   for(int v = (cor1 / 3) * 3; v <(cor1 / 3) * 3 + 3; v++)
      for(int w = (cor2 / 3) *3; w < (cor2 / 3) * 3 + 3; w++)
	      if(file[v][w] == possible)	
		  return false;
		
  
	    
      
  return true;
	    
	    
}
	
