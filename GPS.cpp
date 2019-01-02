/*////////////////////////////////////////////////////////

Name: Andy Estes

File Name: GPS.cpp
File: GPS System

Purpose: Makes a list of exits using a file master.dat
and uses a group name and number from group.dat to find
the nearest exits.

/*////////////////////////////////////////////////////////

/*////////////////////////////////////////////////////////


Standard Template Library Includes


////////////////////////////////////////////////////////*/

#include <list> //For the doubly linked list
#include <string> //for the name datas
#include <iterator> //iterators to move through list
#include <iostream> //for cin, cout
#include <fstream> //for reading files
#include <algorithm> //for reading logic
#include <cmath> //for math functions

using namespace std;

/*////////////////////////////////////////////////////////


Data Structures & Functions


////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////

Data type: struct roaditems
Purpose: puts all necessary items into a struct.
Only two parameters are passed into the list

////////////////////////////////////////////////////////*/

struct roaditems
{
  string exitname;
  int milemarker;
  string groupname;

/*////////////////////////////////////////////////////////

Function: Operator Overload ==
Purpose: overloads the == to compare data within the struct.

////////////////////////////////////////////////////////*/

  bool operator==(const roaditems& groupitem)
  {
    if(groupitem.groupname == exitname)
        return true;
    else
        return false;
      }

};

/*////////////////////////////////////////////////////////

Function: compare_exits
Purpose: Essentially like an overload. Defines what items
in the struct are being compared and how

////////////////////////////////////////////////////////*/

bool compare_exits(roaditems& a,roaditems& b)
{

if (a.milemarker < b.milemarker)

{
  return true;
}

else
{
  return false;
}

}

/*////////////////////////////////////////////////////////

Function: compare_exits
Purpose: Essentially like an overload. Defines what items
in the struct are being compared and how

////////////////////////////////////////////////////////*/

void print(list <roaditems> &list_to_print)
{

  list<roaditems>::iterator myit; //iterator for passed in list

  for (myit = list_to_print.begin(); myit !=list_to_print.end(); ++myit)
  {
  cout<<myit->exitname<<" "<<myit->milemarker<<endl; //prints the list items
  }
  cout<<"\n";
}


/*////////////////////////////////////////////////////////


Main

////////////////////////////////////////////////////////*/

int main()
{

//Pre-declared variables

list <roaditems> masterlist; //list for the master list
list <roaditems> result; //list for closest exits
roaditems masterstruct;  //struct for the master list
roaditems exitresult;    //struct for closest exits
string exitname;         //holds exitnames from master.dat
string groupname;            //holds groupnames from group.dat
int miles;               //holds milmarker from master.dat
int size;                //holds groupsize from group.dat

//Filestream variables

fstream masterfile;      //filestream for master.dat
fstream group;           //filestream for master.dat


/*//////////////////////////////////////////////////////////////
Masterfile Section
//////////////////////////////////////////////////////////////*/

  masterfile.open ("master.dat");

  if (masterfile.is_open())
  {

    while (true)
    {

      masterfile>>exitname>>miles; //reads the data items from the file

      if(masterfile.eof())
      {
        break; //breaks out of the loop if the end of file has been reached
      }

      masterstruct.exitname = exitname; //holds the name in the master struct
      masterstruct.milemarker = miles;  //holds the milemarker in master struct

      masterlist.push_front(masterstruct); //pushes masterstruct into masterlist

    }

  masterlist.sort(compare_exits);
  //sorts the list using the exit compare function

  cout<<"\nHere is the full List of exits avalible:\n";
  print(masterlist); //prints the masterlist contents

  masterfile.close();

  }

  else
  {

    cout<<"Failed to Open.\n";

  }

/*//////////////////////////////////////////////////////////////
Groups Section
//////////////////////////////////////////////////////////////*/

  group.open ("groups.dat");

  cout<<"\n\n";

  if (group.is_open())
  {
    while (true)
  {

  masterstruct.groupname = "default"; //you should never get this item

  group>>groupname>>size; //reads the data items from the file

  if(group.eof())
  {
    break;
  }

  masterstruct.groupname = groupname; //reads the gorupname into the master struct
                                  //this value should NEVER be in the list

  cout<<"Finding exit name...\n";
  list<roaditems>::iterator findit; //creates an iterator to find a groupname

  findit = find(masterlist.begin(), masterlist.end(), (masterstruct));
//Function find() is overloaded. It compares two items within the masterstruct.

  if (findit->exitname == masterstruct.groupname)
  {

    cout<<"Exit Name Fount!\n";
    cout<<findit->exitname<<" "<<findit->milemarker<<endl;

    //Two iterators for comparing values within the master list.
    list<roaditems>::iterator left = findit;
    list<roaditems>::iterator right = findit;

    --left;
    ++right;

    cout<<"\nFinding Closest Exits...\n";

    //uses the STL size function to set a size integer.
    int list_size = masterlist.size();

    //Alters the size if the groupsize is larger than the masterlist size.
    if (list_size < size || list_size == size )
    {
      cout<<"There are not enough list items to satisfy the nearest exits.\n";
      cout<<"Finding all nearest exits to the desired exit name.\n";
      size = list_size-1;
    }

    //Tells the user they cant have a negative group size.
    if (size < 0)
    {
      cout<<"ERROR. You can't give me a size of negatives.\n";
    }

    //Tells the user they can't have a group size of 0.
    else if (size == 0)
    {
      cout<<"Size is 0. Cannot determine nearest exit.\n";
    }

    //this condition runs when all previous conditions are not met.
    else
    {

      while (size > 0)
      {

        for (int x = size; size > 0; --size)
        {

          int left_exit=0,  //Sets up the comparion for the exit numbers
              right_exit=0;

          //Uses Absolute value math to determine the closest exit
          left_exit = abs(left->milemarker-findit->milemarker);
          right_exit = abs(right->milemarker-findit->milemarker);

          if (left_exit < right_exit)
          {

            exitresult.exitname = left->exitname;
            exitresult.milemarker = left->milemarker;
            result.push_back(exitresult);

        left--;

        if (left == masterlist.end())
        {

          left = masterlist.end();
          --left;
        }

      }


        else if (right_exit < left_exit)
        {

          exitresult.exitname = right->exitname;
          exitresult.milemarker = right->milemarker;
          result.push_back(exitresult);

          right++;

          if (right == masterlist.end())
          {
            right = masterlist.begin();
          }

        }

      //Takes the high milemarker if the numbers are equal
      //The right will always be the larger amount since the list is sorted.
      else
      {
        exitresult.exitname = right->exitname;
        exitresult.milemarker = right->milemarker;
        result.push_back(exitresult);

        right++;

        if (right == masterlist.end())
        {
          right = masterlist.begin();
        }

      }
    }

  }
  cout<<"All closest exits for:"<<findit->exitname<<" "<<findit->milemarker<<endl;

  }

  }
  //If the item is not in the list.
  else
  {

    cout<<"ERROR. Item not found. Be smart, you're A COMPUTER SCIENTIST.\n";

  }

  print(result); //Prints the results of the closest exits

  result.clear(); //clears the list for the next set of exits.

  }

  group.close();

  }

  else
  {

    cout<<"Failed to Open."<<endl;
  }

  return 0;

}
