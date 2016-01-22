/*
 * MenuPlus.cpp
 *
 *  Created on: Apr 21, 2015
 *      Author: torch2424
 */

#include "MenuPlus.h"
#include <iostream> //for cout
#include <string> //for strings
#include <sstream> //for input
#include <vector> //for our vector

using namespace std;

MenuPlus::MenuPlus()
{
	//Set the menu to true;
	status = true;
	//set our user input to zero, since minimum will be one
	userInput = 0;
}

//Add an option to our vector
void MenuPlus::addOption(string option)
{
	options.push_back("option");
}

void MenuPlus::showMenu()
{
	//output our menu
	cout << "---Main Menu---" << endl;

	//output  all of our options with value
	//Using unsigned int to compare two unsigned values
	for (unsigned int i = 0; i < options.size(); ++i)
	{
		cout << (i + 1) << ". " << options[i] << endl;
	}

	//Prompt user to enter a number
	cout << endl;
	cout << "Please enter an option:" << endl;

}

//Function to return our menu's status
bool MenuPlus::getStatus()
{
	return status;
}

//get our user input
int MenuPlus::getInput()
{
	//Get the user option
	string input;
	//Getline easiest way to get string from console
	getline(cin, input);
	//String stream converts string to int
	stringstream ss;
	ss << input;
	int option;
	ss >> option;

	//Check for invalif options
	if (option > 0 && option < (options.size() + 1))
	{
		//return our input
		return option;
	}
	else
	{
		//prompt the user that the input was invalid
		cout << endl;
		cout << "That is not a valid option, please enter a number.";
		cout << endl;
		cout << endl;
		//return 0 so we only have to check for valid options
		return 0;
	}
}

void MenuPlus::pauseMenu()
{
	//inform user of pause
	cout << "---Paused!---" << endl;
	cout << "Please enter a character to continue program." << endl;
	//Get the user option
	string input;
	//Getline easiest way to get string from console, use this to pause
	getline(cin, input);

	//make a new line after the input
	cout << endl;
}

MenuPlus::~MenuPlus()
{
	//set the menu to false, since we are now being deleted
	status = false;
}

