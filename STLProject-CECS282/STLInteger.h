#ifndef STLINTEGER_H_
#define STLINTEGER_H_
#include <vector> //for our vector
#include <iostream> //for cout
#include <string> //for strings
#include <ctime> //for random
#include <cstdlib> //for random
#include <algorithm>    // std::sort
#include <iomanip>      //For setw

using namespace std;

class STLInteger
{
public:
	//constructor
	STLInteger();
	//Function to generate our integers
	void generateInts();
	//function to sort our integers
	void sortInts();
	//function to print our integers by column
	void printColumns();
	//function to print the sum of our integers
	void printSum();
	//function to print the sum of our integers
	void printAverage();
	//function to print the number of each integer
	void printNumInts();
	//destructor
	virtual ~STLInteger();
private:
	//our stl we shall be using
	vector<int> integers;
};

#endif /* STLINTEGER_H_ */
