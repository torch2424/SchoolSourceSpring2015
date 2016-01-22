#include "STLInteger.h"
#include <vector> //for our vector
#include <iostream> //for cout
#include <string> //for strings
#include <ctime> //for random
#include <cstdlib> //for random
#include <algorithm>    // std::sort
#include <iomanip>      //For setw

using namespace std;

STLInteger::STLInteger()
{
	// set the seed for random
	srand((unsigned) time( NULL));
}

void STLInteger::generateInts()
{
	//Generate 10,000 integers with random using a lop and store in our vector
	for (int i = 0; i < 10000; ++i)
	{
		//generate numbers between 1 and 100
		integers.push_back((rand() % 100) + 1);
	}
}

void STLInteger::sortInts()
{
	//sort our ints from least to greatest using sort
	sort(integers.begin(), integers.end());
}

void STLInteger::printColumns()
{
	//First show user we are printing our columns
	cout << "Printing integers..." << endl;

	//loop to print every integer
	for (int i = 0; i < integers.size(); ++i)
	{
		//if it is the 15th integer and it is not the first one, print a new line
		if(i % 15 == 0 && i != 0)
		{
			cout << endl;
		}

		//Using setw print our formatted columns
		//Using setw to set the width of our columns,a nd left to left align our text
		cout << left << setw(5) << integers[i];
	}

	//Print end line for formatting now that we are finished
	cout << endl << endl;
}

void STLInteger::printSum()
{
	//First show user we are printing the sum
	cout << "The sum of our integers is: " << endl;

	//create our sum, make unsigned since number will be large
	unsigned int sum = 0;

	//loop to add every integer
	for (int i = 0; i < integers.size(); ++i)
	{
		//add our int to the sum
		sum = sum + integers[i];
	}

	//print our sum, and endl for formatting
	cout << sum << endl << endl;
}

void STLInteger::printAverage()
{
	//First show user we are printing the average
	cout << "The average of our integers is: " << endl;

	//create our sum, make unsigned since number will be large
	unsigned int sum = 0;

	//loop to add every integer
	for (int i = 0; i < integers.size(); ++i)
	{
		//add our int to the sum
		sum = sum + integers[i];
	}

	//now divide our sum by the number of integers for the average
	int average = sum / integers.size();

	//print our sum, and endl for formatting
	cout << average << endl << endl;
}

void STLInteger::printNumInts()
{
	//Create a loop that will access every number (1 - 100)
	for(int i = 1; i < 101; ++i)
	{
		//count how many of that number are in our stl
		int count = 0;
		for(int j = 0; j < integers.size(); ++j)
		{
			if(i == integers[j]) ++count;
		}

		//Then print the info!
		cout << left << setfill(' ') << setw(4) <<  i << setw(4) << ": "<< setw(4)  << count;

		//print anewline since we want columns, or a space
		if(i % 6 == 0) cout << endl;
		else cout << setw(5) << " ";
	}

	//print a newline for formatting
	cout << endl;
}

STLInteger::~STLInteger()
{
	// TODO Auto-generated destructor stub
}

