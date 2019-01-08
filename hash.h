/*
 *
 * Name: Andy Estes
 * File Name: hash.h
 * Function: implements a hash table class that stores and retrieves items
 * within an array using a hash function.
 *
*/
#ifndef hash_h
#define hash_h

#include<string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

class Hash
{
	private:
/*
 * Variables
*/
	int ARRAY_SIZE; //defines the size the array will be using
	string* table = new string[ARRAY_SIZE]; //implements a private string
	double passed = 0, failed = 0, probe = 0; //variables for testing

	public:
/*
 * Constructor: Takes in a array size and builds the table
*/
	Hash(int PASSED_SIZE)
	{
		ARRAY_SIZE = PASSED_SIZE;
		table = new string[PASSED_SIZE];

		for (int i = 0; i < PASSED_SIZE; i++) //load the array with "NULL" values
		{
			table[i] = "NULL";
		}
	}

/*
 * HashCode: builds a key and then runs the hash function on the key to give it
 * an unique value. Polynomial hashing is used to minimize collisions.
*/
	unsigned int HashCode(string item)
	{
		int hash;
		int a = 37; //prime number mod
		unsigned int sum = 0; //unsigned sum that will never be negative

		for (int i = 0; i <30; i++)
		{
			char x = item.at(i); //turns an item into ASCII integers
			sum = (int(x) + (a * sum)); //totals up the sum for all 30 characters
		}														  //utilizes the polynomial method.

		hash = (sum % ARRAY_SIZE); //runs the hash function

		return hash;
	}

/*
 * Insert: inserts an item into the hash table array
 * an unique value. Polynomial hashing is used to minimize collisions.
 */
  void insert(string item)
  {
		int hash = HashCode(item); //runs the hash function
		int position = hash;			 //sets a position to the hash value

  	if(table[hash] == "NULL") //if the spae is empty, insert the value
		{
  		table[hash] = item;
		}
  	else //if the space is not null
		{
			while(table[position] != "NULL") //search for a NULL value
			{
				position++;

				if(position == ARRAY_SIZE) //if the hash reaches the end of the table
				{
					position = 0;
				}
				
				else if (position == hash && table[hash] != "NULL") //if the position reaches the hash value
				{
					cout<<"Hash Table is full. Cannot Insert a new value.\n";
					return;
				}									 //returns nothing because it is full.
    	}
			table[position] = item; //sets the item into the NULL position
  	}
   }

/*
 * Search: searches the list using the hash function. Linear probe occurs with
 * collisions
*/
  void search(string item)
	{
	  int hash = HashCode(item); //hash function
	  int position = hash;  //sets a position to the hash value
    string search_item = table[hash]; //sets a string for searching if it fails

	  probe++; //increases probe when looking for an item.

    if(table[hash] == item) //if item is fount the first time ( Big O(1))
		{
      passed++; //counter for sucessful searches
    }

    else //if item is not found
	  {
      while(search_item != item && search_item != "NULL")
		  {
        search_item = table[position]; //search for the item while not null
        position++;

        if(position == ARRAY_SIZE) //if the hash reaches the end of the table
          position = 0;

		  	else if (position == hash)  //if the position reaches the hash value
			  	failed++;

				probe++;
      }

      if(search_item == item) //if item matches
        passed++;

      else //else not a sucessful search
        failed++;
    }
  }

/*
 * getData: returns the amount of sucessful and uncessful searches, the number
 * of probes, and the average amount of probes.
*/
void getData()
{
	double AVG_probes	= (probe / (passed+failed));
	cout << fixed<<setprecision(0);
	cout<<"Number of Successful Searches: "<<passed<<"\n";
	cout<<"Number of Unsuccessful Searches: "<<failed<<"\n";
	cout<<"Number of Probes: "<<probe<<"\n";
	cout << fixed<<setprecision(4);
	cout<<"Average Probes: "<<AVG_probes<<"\n";
	cout<<"\n";
}

/*
 * ~Hash: Deletes the hash table to avoid memory leaks.
*/
  ~Hash()
  {
    delete[] table;
  }
};
#endif

