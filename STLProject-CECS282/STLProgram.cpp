#include "MenuPlus.h" //Our menu object
#include "STLInteger.h" // Our STL object handler
#include <iostream> //for cout
#include <string> //for strings
#include <sstream> //for input
#include <vector> //for our vector

using namespace std;



int main()
{
	//create our stl object that will handle our stl for us
	STLInteger stl;
	//create our menu object to handle UI requests
	MenuPlus menu;

	stl.generateInts();
	stl.sortInts();
	stl.printColumns();
	stl.printSum();
	menu.pauseMenu();
	stl.printAverage();
	stl.printNumInts();
}



