/*
 *
 * Name: Andy Estes
 * File Name: main.cpp
 * Function: Runs a test of the hash function.
 *
*/
#include<string>
#include<iostream>
#include <fstream>
#include <cstdlib>

#include "hash.h" //include the .h file
using namespace std;

/*
 * main: main function to test the hash table
*/
int main(int argc, char* argv[])
{
	if (argv[1] == NULL) //If no arguments are entered
	{
		try
		{
			throw 612;
		}
		catch (int exception)
		{
			cout << "An exception occurred. Exception: Invalid_Parameters. "
			<< exception << '\n';
			return 0;
		}
	}

	int arrsize = atoi(argv[1]);//sets a command line argument for size

	if (arrsize < 400000) //if the array size is less than the data
	{
		try
		{
			throw 612;
		}
		catch (int exception)
		{
			cout << "An exception occurred. Exception: Invalid_Parameters. "
			<< exception << '\n';
			return 0;
		}
	}

	Hash table (arrsize); //calls the hash table

	ifstream openfile;
	string input;

	openfile.open("sort.dat");
  if(openfile.is_open()) //if the file opens
  {
		for (int i = 0; i < 400000; i++) //inputs the data into the table
		{
	  	openfile >> input;
      table.insert(input);
    }
  }
  else
	{
  	try
		{
			throw 702;
		}
		catch (int exception)
		{
			cout << "An exception occurred. Exception Invalid File Name. "
			<< exception << '\n';
			return 0;
		}
   }
  openfile.close(); //closes

  openfile.open("search.dat"); //opens the seearch file
  if(openfile.is_open())
	{
  	while(openfile >> input) //searches for the values from the file
		{
    	table.search(input);
    }
	}
  else //if file name is incorrect
	{
		try
		{
			throw 702;
		}
		catch (int exception)
		{
			cout << "An exception occurred. Exception Invalid File Name. "
			<< exception << '\n';
		}
		return 0;
	}
  openfile.close();

	table.getData(); //pulls the data for testing

return 0;
}

